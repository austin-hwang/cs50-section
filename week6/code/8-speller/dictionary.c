#include <stdbool.h>
#include "dictionary.h"

bool check(const char *word)
{
    unsigned int hcode = hash(word);
    htnode *trav = hashtable[hcode];
    while (trav != NULL)
    {
        if (!strcasecmp(trav->word, word))
        {
            return true;
        }
        trav = trav->next;
    }
    return false;
}

unsigned int hash(const char *word)
{
    unsigned int hash = 5381;
    int c;
    while ((c = (tolower(*word++))))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % SIZE;
}

bool load(const char *dictionary)
{
    dsize = 0;
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }
    while (true)
    {
        htnode *newnode = malloc(sizeof(htnode));
        if (newnode == NULL)
        {
            return false;
        }
        fscanf(source, "%s", newnode->word);
        if (feof(source))
        {
            free(newnode);
            break;
        }
        unsigned int hcode = hash(newnode->word);
        newnode->next = hashtable[hcode];
        hashtable[hcode] = newnode;
        dsize++;
    }
    fclose(source);
    return true;
}

unsigned int size(void)
{
    return dsize;
}

bool unload(void)
{
    for (int i = 0; i < SIZE; i++)
        vacate_list(hashtable[i]);
    return true;
}

void vacate_list(htnode *head)
{
    if (head == NULL)
    {
        return;
    }
    vacate_list(head->next);
    free(head);
}
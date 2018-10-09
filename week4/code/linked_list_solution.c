#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct node
{
    string word;
    struct node* next;
}
node;

bool unload(node* root);

bool addToEnd(node* root, node* newNode);

bool add(node* root, node* newNode, int index);

bool addToFront(node* root, node* newNode);

void printAll(node* root);

// Let's add a few more entries to this linked list.
int main(void)
{
    node* root = malloc(sizeof(node));
    node* node1 = malloc(sizeof(node));
    root->word = "START";
    root->next = node1;
    node1->word = "hello,";
    
    node* node2 = malloc(sizeof(node));
    node1->next = node2;
    node2->word = "world!";
    
    printf("%s\n", node1->word);
    printf("%s\n", node2->word);
    printf("-------------\n");

    node* endNode = malloc(sizeof(node));
    endNode->word = "it's a great day!";
    
    // 1. Implement addToEnd() so the following line adds "it's a great day"
    // as a new node at the end of the linked list.
    addToEnd(root, endNode);
    
    node* frontNode = malloc(sizeof(node));
    frontNode->word = "wow!";
    
    // 2. Implement addToFront() so the following line adds "wow!"
    // as a new node to the front of the linked list (before "hello").
    addToFront(root, frontNode);
    
    node* newNode = malloc(sizeof(node));
    newNode->word = "beautiful";
    int index = 2;
    
    // 3. Implement add() so the following line adds "beautiful"
    // as a new node after "hello", using an integer index)
    add(root, newNode, index);
    
    // 4. Print all the strings from the nodes in the linked list
    printAll(root);
    
    // 5. Unload all memory used once done with the program.
    unload(root);
}

bool unload(node* root)
{
    while(root != NULL)
    {
        node* temp = root;
        root = root->next;
        free(temp);
    }
    
    return true;
}

void printAll(node* root)
{
    root = root->next;
    while(root != NULL)
    {
        printf("%s\n", root->word);
        root = root->next;
    }
}

bool addToEnd(node* root, node* newNode)
{
    while(root->next != NULL)
    {
        root = root->next;
    }
    
    root->next = newNode;
    return true;
}

bool addToFront(node* root, node* newNode)
{
    newNode->next = root->next;
    root->next = newNode;
    return true;
}

bool add(node* root, node* newNode, int index)
{
    while(index > 0)
    {
        if(root == NULL)
        {
            return false;
        }
        
        root = root->next;
        index--;
    }
    
    newNode->next = root->next;
    root->next = newNode;
    return true;
}


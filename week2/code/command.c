#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    // check if user inputted a name
    if (argc < 2)
    {
        printf("Usage: ./main [name]\n");
        return 1;
    }
    
    // print "hello, [name]!"
    printf("hello, %s!\n", argv[1]);
}


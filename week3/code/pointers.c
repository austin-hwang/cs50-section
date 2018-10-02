#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    int *x;
    int *y;
    int z;

    x = malloc(sizeof(int));
    // can also be written as int *x = malloc(sizeof(int))

    *x = 42;
    
    // Which one will throw an error? Comment that line out.
    printf("%i\n", *x);
    printf("%i\n", x);
    printf("%p\n", x);

    y = x;
    
    // What will these lines print?
    printf("%i\n", *x);
    printf("%i\n", *y);

    *y = 13;
    
    // What will these lines print?
    printf("%i\n", *x);
    printf("%i\n", *y);
    
    z = *x;
    
    // What will this line print?
    printf("%i\n", z);
    
    // Will these lines print the same thing?
    printf("%p\n", &z);
    printf("%p\n", x);
    
    // Type a line to make z and x have the same address!
}



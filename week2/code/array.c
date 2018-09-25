// The below code attempts to run a launch-style countdown, from 9 to 0, but unfortunately encounters a runtime error. Fix the bug!
#include <cs50.h>
#include <stdio.h>

#define COUNT 10

int main(void)
{
    int countdown[COUNT] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    for (int i = 0; i <= COUNT; i++)
    {
        if (i == 9)
        	printf("%d!\n", countdown[i]);
    	else
    		printf("%d..", countdown[i]);
    }    
}


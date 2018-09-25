#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    // Answer to Warmup 1
    for (float i = 4.0; i <= 20.0; i += 4.0)
    {
        printf("%.1f\n", i);
    }
    
    // or
    for (float i = 0; i < 6; i++)
    {
        printf("%.1f\n", i * 4);
    }
    
    // Alternative Answer to Warmup 1
    float counter = 4.0;
    while(counter <= 20.0)
    {
        printf("%.1f\n", counter);
        counter += 4.0;
    }
    
    // Answer to Warmup 2: FALSE
    bool test = ((10 / ((15 % 6) + 1)) > 2) && (((8 / 3) + 2) == 4);
    printf("%d\n", test);
    
    // Let's fix three! (this will crash the program)
    for (i = 0, i < 10, i++)
    {
        print("This is number: %i\n");
    }
    
    // Fixed version
    for (int i = 0; i < 10; i++)
    {
        printf("This is number: %i\n", i);
    }
    
}


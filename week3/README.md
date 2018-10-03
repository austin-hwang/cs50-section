# Section #3

## Shorts

- [Shorts Playlist](https://www.youtube.com/playlist?list=PLhQjrBD2T381ZT0gioVUa3mRNgl9yGWlE)


## Outline

- Problem solving strategies 
- File I/O 
- Memory and Pointers
- Dynamic Memory Allocation

### Problem Solving Strategies 

- We are starting to reach the point in the course where the "take a big swing at it and see what sticks" approach to problem solving is going to start to get painful.
- See *notes/solveit.pdf* for more info

### File I/O (15 minutes)

- So far, you've pretty much only printed out to `stdout` and taken input after prompting the user (with `get_string()`, for example). However, it is just as easy to write out to a file or read in from a file, this time using system commands and the C standard library, instead of input/output redirection.
- The basic structure for file I/O is this example, which covers many of the basics.  

```c
#include <stdio.h>

int main(void)
{
    // open file "input.txt" in read only mode
    FILE* in = fopen("input.txt", "r");

    // always make sure fopen() doesn't return NULL!
    if(in == NULL)
        return 1;
    else
    {
        // open file "output.txt" in write only mode
        FILE* out = fopen("output.txt", "w");

        // make sure you could open file
        if(out == NULL)
            return 2;

        // get character
        int c = fgetc(in);

        while(c != EOF)
        {
            // write chracter to output file
            fputc(c, out);
            c = fgetc(in);
        }

        // close files to avoid memory leaks!
        fclose(in);
        fclose(out);
    }
}
```
- When you `fopen()` a file, you are really creating a `FILE` pointer, or a _reference_ that points to something known in C as a "file structure"
  - You are then, in effect, passing around this reference to other functions like `fread()` or `fwrite()`, which then operate on that specific file.
- Just as important as `fopen()` is `fclose()`, which if omitted will cause your program to leak memory. `fclose()` kind of 'recycles' memory, making it available again. 
- Memory and resources are limited (which is why we care so much about using them efficiently).
- Common I/O functions:
  - `fopen()` -- creates a file reference
  - `fread()` -- reads some amount of data from a file
  - `fwrite()` -- writes some amount of data to a file
  - `fgets()` -- reads a single string from a file (typically, a line)
  - `fputs()` -- writes a single string to a file (typically, a line)
  - `fgetc()` -- reads a single character from a file
  - `fputc()` -- writes a single character from a file
  - `fseek()` -- like rewind and fast forward on YouTube, to navigate around a file
  - `ftell()` -- like the timer on YouTube, tells you where you are in a file (how many bytes in)
  - `fclose()` -- closes a file reference, used once done working with the file

### Pointers 

- Pointers are a tool that give us a way to literally pass information between functions.
- Memory. It's limited. We have some amount of memory available to us (probably like 8 GB on average), and each data type we've talked about so far takes up a certain amount.
  - `int`s take up 4 bytes. So do `float`s.
  - `char`s take up 1 byte.
  - `double`s and `long long`s take up 8.
- Memory is basically a huge array of cells. Every single one of them has an *address* and can hold a certain amount of data (specifically, 1 byte's worth).
- Super bold. Super italic. Super important takeaway:
  - _**A POINTER IS JUST AN ADDRESS**_
  - _**A POINTER IS JUST AN ADDRESS**_
  - _**A POINTER IS JUST AN ADDRESS**_
  - _**A POINTER IS JUST AN ADDRESS**_
- A pointer is a data item whose _value_ is a memory address and whose _type_ describes the data you will find if you visit that memory address.
- If we know exactly where in memory a variable lives, then we can find it from any function, thus allowing us to pass that data around.
- If we have some variable we know of, particularly one that lives on the stack and has a name, we can find its address by prepending a `&`.
- To access the data at an address, we need to **dereference** it, using the `*` operator.
  - If you know where your neighbor lives, are you hanging out with them? No! You need to knock on their door (aka dereferencing their address!) to interact with them.
- Segmentation faults happen when we try to dereference `NULL` pointers.
- So if we have `int *p;`, then here is what we know:
  - The value of `p` is an address.
  - We can dereference `p` with the `*` operator. (We know both of these things because of `p`'s data type.)
  - If we do dereference `p` (aka `*p`), then what we'll find at that address is an `int`.
- In the CS50 library, a `string` is just another way of saying a `char *`. A pointer to a character.
  - Here's why we need `\0`. The only way to refer to a string is by a pointer to its first character (aka where its first character lives in memory), so we need some way to mark the end.

### Memory Management & `malloc`

- When running a program, you can divide memory into 2 basic regions: the heap and the stack.
- The _stack_ is a contiguous block of memory set aside when a program starts running. Held in every stack frame is some metadata, any variables held in "read-only" memory, and most importantly, all local variables.
- Each function that's called gets its own stack frame, meaning, if my `main()` function called a function `sum()`, then the stack frame for `sum()` would be on top of `main()` (if we visualize the stack as growing up, **which is what we do in CS50**)! We have effectively 'pushed' `sum()` on top of `main()`. If we ever want to get to the variables held in `main()` again, we'd first have to 'pop' the `sum()` stack frame off by returning a value from it. Since each function has its own stack frame, its variables are protected from other functions and localized with their own scope.
- A question then becomes, if, when running a program, the size of a function's stack frame is dependent largely on its local variables, what if the number of variables and their sizes can't be determined before runtime? what if they depend on, say, user input? You can't just create a massive stack frame to cover all possibilities!
- Memory allocated during runtime is called dynamically allocated memory and it's held on the *heap*.
- The heap is essentially a region of unused memory that can be allocated with a call to `malloc()`. A call, such as:
```c
int* ptr = malloc(sizeof(int));
```
will create space for 4 bytes (or, if you have a ridiculously old system, 2 bytes, depending on what the size of an `int` is on that machine) on the heap, returning a pointer to this space. This space can then be used to store data, it can be passed between functions, and unlike stack variables, it won't be lost when a function returns.
- Similar to `fclose()`, any memory allocated with `malloc()` needs to be freed, otherwise you'll leak memory. Always remember to use `free()`!
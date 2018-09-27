# Section #2

## Outline

* [Debugging](#Debugging)
* [Arrays](#Arrays)
* [Functions and variable scope](#Functions)
* [Command-line arguments](#Command-Line-Arguments) 

### Debugging 

* `help50` can prepend calls to, e.g., `make` or `clang` to help explain the sometimes confusing error messages that can result, such as `help50 make hello`
* `style50` can check the style of your code using `style50 hello.c`

### Arrays

* How do you make arrays?
  * `<datatype> <name>[<size>]`;
    * `char alpha[26];`
    * `int score[5];`
* To initialize an array, you can do it two ways:

```c
int score[5];
score[0] = 0; // zero index all arrays!
score[1] = 1;
score[2] = 2;
```

or

```c
int score[] = {0, 1, 2}; // size based on the number of entries
```

* Although we can use the `string` declaration to declare strings, `strings` are really just arrays of characters.
* So, if I declare some `string s = "rob bowden"`; then I can index into this like any other array:
  * `s[0]` is `'r'`
  * `s[1]` is `'o'`
  * `s[10]`, which is one past the length of that string, is `'\0'`.
  * `s[11]`, random character printed out of range

### Functions 

* Functions (1) take something in [parameters], (2) do something [body], and finally (3) spit out an answer [return value].
* We often times introduce functions using the black box approach to functions. We may not actually care what happens inside the function, as long as it does what we expect it to do.
  * An excellent analogy for this is a soda machine. A soda vending machine typically takes two inputs (some amount of money and a selection for what type of soda is desired), and has a predictable output (a can of the desired soda)
  * It's just sort of the "contract" we make when we use a soda machine that if we give it the proper inputs, we get the proper outputs. If we don't, that's a bug (and many folks have probably encountered this bug -- dollar bills getting rejected or getting the wrong soda because the machine wasn't loaded properly)

* Why do we want functions?
  * Organization
    * As our programs get larger, breaking that program into smaller subparts can be super-helpful for us to organize our thoughts and program.
  * Simplification
    * Those small parts are a lot easier to debug and write than having to write the entire program at once. Keep it simple!
  * Reusability
    * They allow us to minimize the amount of code we need to write. If, say, I wrote a function `bool isRob(string s)` to tell me, true/false, whether a string is equivalent to "Rob", I only need to write that function once. In the future I can just refer to this function to test strings without having to repeatedly code the same thing.

* One function everyone has seen already is `int main(void)`
  * `int` is the return type. The return value of `main` is basically just a signal to the terminal or some other program that everything worked okay, and leave the rest alone. 
  * `main` is the name of the function (every program needs a `main()` function - it signifies to the computer where to start running your code)
  * `void` is the parameter, which, in this case, is nothing; `main` takes no inputs.

* With functions, we have __variable scope__
  * If I have a program like the below, this will print out 3, 2, and then 0. In the first case, this is because the variable takes on the last value. In the second case, the print statement is in the scope where `a` has been reassigned to 2. In the last case, the print statement is in the scope where `a` has been reassigned to 0.

```c
#include <stdio.h>

// prototypes
void scope1(void);
void scope2(void);

int main(void)
{
    scope1();
    scope2();
}

void scope1(void)
{
    int a = 4;
    {
        a = 3;
    }

    printf("%d\n", a); // what will this print?
}

void scope2(void)
{
    int a = 4;
    {
        a = 2;
        printf("%d\n", a); // what will this print?
    }
    a = 0;

    printf("%d\n", a); // what will this print?
}
```

### Command-Line Arguments

* Command line arguments are a way to pass arguments into a program
* When we pass arguments to our program via the command line, we have to modify our prototype for `main`.
  * So now, `int main(void)` becomes `int main(int argc, string argv[])` - this lets the program know that it needs to expect and process command line parameters.
  * In this, `argc` is an integer representing the number of arguments passed to the command line
  * `argv[]` is an array of strings that were passed into the program
  * If, for example, in my terminal window I type in `./mario 8`, what will `argc` and `argv` be?
    * `argc` is `2`
    * `argv` is `["./mario", "8"] // an array of length two`
    * But remember that these are strings, which means we're talking about the string `8`, not the number 8!
  * You can also treat these arguments as a multi-dimensional array. What is `argv[0][2]`?
    * Output: `m`

# Section #1

## Shorts

Good videos to watch for quick walkthroughs!

* [Command Line](https://www.youtube.com/watch?v=lnYKOnz9ln8)
* [Data Types](https://www.youtube.com/watch?v=q6K8KMqt8wQ)
* [Operators](https://www.youtube.com/watch?v=7apBtlEkJzk)
* [Conditional Statements](https://www.youtube.com/watch?v=FqUeHzvci10)
* [Loops](https://www.youtube.com/watch?v=QOvo-xFL9II)

## Outline

* Resources Review 
* Variables, Data Types, Operators
* Conditional Statements and boolean expressions
* Looping 

### Resources Review 

* List of resources
  * Walkthroughs, which are embedded in the problem specifications;
  * Scribe notes (for example, [these ones from Week 0](https://cs50.harvard.edu/2018/fall/weeks/0/notes/)), which are posted one day after the lecture is given;
  * Office hours a calendar of which is posted on the course's website;
  * Other sections to attend in the event of a time conflict, a calendar of which is posted on the course's website;
  * Shorts, on the [Curriculum](https://cs50.harvard.edu/2018/fall/weeks/) page;
  * [Reference50](https://reference.cs50.net/), which is linked on the course's website; and
  * CS50 Discourse, the course's discussion forum

### Variables, Data Types, Operators

* Different data types in C
  * Native data types
    * `int`
    * `char`
    * `long`
    * `float`
    * `double`
  * Qualifiers
    * `unsigned`
  * CS50 types
    * `string`
    * `bool`
* Different ways to increment a variable
  * `x = x + 1`
  * `x += 1`
  * `x++`
* Common operators
  * Logical operators (`&&`, `||`, and `!`)
  * Relational operators (`<`, `<=`, `>=`, `>`, `==`, `!=`)
  * Difference between `==` and `=`
    * First one checks for equality (boolean), second one assigns value

### Conditional Statements and boolean expressions 

* `if`
* `if-else`
* `if-else if-else`
* `switch` statements
* Boolean expressions
  * `if (x < 5)`
* Compound expressions:
  * `while (x < 5 && y < 10)`
  * `else if ((x > 10 && y < 5) || z != 14)`
* Infinite loops:
  * `while (true)`
  * `for ( ; ; )`

### Looping

* Three different types of loops:
  * `while`
  * `do`
  * `for`

```c
int i = 0;
while (i < 10)
{
   printf("%i\n", i);
   i++;
}

int j = 0;
do
{
   printf("%i\n", j);
   j++;
}
while (j < 10);

for (int k = 0; k < 10; k++)
{
   printf("%i\n", k);
}
```
# Section #6

## Shorts

- [Week 6 Shorts Playlist](https://www.youtube.com/playlist?list=PLhQjrBD2T380Ze8wxWJBPgo2XZzYlnN0N)

## Outline

- Python


### Python

#### Variables

- Important info:
  - Variables are declared by assignment
  - Variables in Python do not have explicit data types
  - Python variables **do** have underlying data types, namely:
    - `number`
    - `string`
    - `list`
    - `tuple`
    - `dictionary`

- C:
```c
int coursenum = 50;
string coursename = "Introduction to Computer Science I";
```
- Python:
```python
coursenum = 50
coursename = "Introduction to Computer Science I"
```
- Examples located in:

0. `string.c`, `string.py`
1. `temperature.c`, `temperature.py`

#### Conditionals

- Important info:
  - The keywords `and`, `or`, and `not` replace their symbolic representations in C.
  - `else if` is replaced by `elif`.
  - `switch` statements do not have a clean equivalent in Python and should probably be ignored.
  - The code subject to a conditional is introduced by `:` instead of `{`.
  - All code subject to the conditional **must** be indented in order things to work as intended.
  - The conditional is terminated by returning to the previous indentation level.
  - `print` statements have newlines added by default, unless you override that behavior.
  - Comments can be introduced with the `#` symbol.
  - Comparators (and assignments) are not necessarily binary operators.
- C:

```c
int x = get_int();
if (x < 0)
{
    printf("x is negative\n");
}
else if (x > 0)
{
    printf("x is positive\n");
}
else
{
    printf("x is zero\n");
}
```

- Python:

```python
x = cs50.get_int()
if x < 0:
    print("x is negative")
elif x > 0:
    print("x is positive")
else:
    print("x is zero")
```

- C:

```c
int y = get_int();
int z = get_int();
if (y == 0 && z == 0)
{
    printf("y and z are both zero\n");
}
else if (y > 0 && z > 0)
{
    printf("y and z are both positive\n");
}
else
{
    printf("At least one of y or z is negative or zero\n");
}
```

- Python:

```python
y = cs50.get_int()
z = cs50.get_int()
if y == z == 0:
    print("y and z are both zero")
elif y > 0 and z > 0:
    print("y and z are both positive")
else:
    print("At least one of y or z is negative or zero")
```

- Examples located in:

2. `conditions.c`, `conditions.py`
3. `logical.c`, `logical.py`

#### Loops

- Important info:
    - ** `for` and `while` are the two primary iterating constructs in Python.
    - `for`, in particular, has extreme flexibility relative to its C cousin.
    - `do-while` does not exist in Python and has to be hacked with a `while True:` and a `break`
    - The code subject to a loop is introduced by `:` instead of `{`.
    - All code subject to the loop **must** be indented in order things to work as intended.
    - The loop is terminated by returning to the previous indentation level.
- C:
```c
int i = 0;
while(i < 100)
{
    printf("%i\n", ++i);
}

for(int j = 0; j < 100; j += 2)
{
    printf("%i\n", j);
}
```
- Python:
```python
i = 0
while i < 100:
    print(i)
    i += 1

for j in range(0, 101, 2):
    print(j)
```

- Examples located in:

4. `quack.c`, `quack.py`
5. `argv{0,1,2}.c`, `argv{0,1,2}.py`

#### Arrays/Lists

- Important info:
  - Arrays in Python are called lists.
  - Lists are created by assigning a variable equal to an expression in square brackets.
  - Methods called on lists can mutate their values, including:
    - `x.append(value)`
    - `x.extend([list])`
    - `x.insert(location, value)`
    - `x.remove(value)`
    - As well as `copy()`, `sort()`, `count()`, and others
  - The length of a list can be obtained by calling the `len()` function, passing the list as a parameter.
  - Lists can contain values of mixed data types.
  - Lists are only ordered if you sort them.

- C:
```c
int grades[10] = {87, 61, 90, 83, 78, 99, 93, 55, 81, 76};

// SELECTION SORT
for (int i = 0; i < 10; i++)
{
    int min = i;
    for (int j = i; j < 10; j++)
    {
        if (grades[j] < grades[min])
        {
            min = j;
        }
    }

    int temp = grades[min];
    grades[min] = grades[i];
    grades[i] = temp;
}

// ILLEGAL
grades[10] = 100;

// PRINT GRADES
for (int k = 0; k < 11; k++)
{
    printf("%i\n", grades[k]);
}
```
- Python:
```python
grades = [87, 61, 90, 83, 78, 99, 93, 55, 81, 76]

# SORT
grades.sort()

# LEGAL
grades.append(100)

# PRINT GRADES
for grade in grades:
    print(grade)
```

- Examples located in:

6. `string{0,1}.c`, `string0.py`
7. `capitalize{0,1,2}.c`, `capitalize2.py`

#### Tuples

- Important info:
  - Tuples are a data type in Python for a collection of ordered, immutable data.
  - Comparable to a C `struct` whose contents can never be changed.
    - A good example of this is an x, y coordinate
  - Tuples can be iterated across like other data types representing collections.

```python
three_d_coordinate = (5, 3, 0)

# notice that tuples are ordered as well
for dimension in three_d_coordinate:
    # override default print behavior
    print(dimension, end=" ")

print()

# a list of tuples
coordinates = [(2, 1, 0), (-1, -5, 6), three_d_coordinate, (8, 1, 0)]

# plot only the surface points (z = 0) but notice that the list will NOT necessarily the tuples print in order
for x, y, z in coordinates:
    if z == 0:
        print(f"({x}, {y})")
```

#### Dictionaries

- Important info:
  - Dictionaries are effectively the equivalent of a hash table in C.
  - Alternatively, you can think of a dictionary like an array (list) that you can index into using keywords, rather than numerical indices.
  - Dictionaries consist of key-value pairs, where the keys are integers or strings, and the values are anything (including other dictionaries, lists, or tuples)
  - Dictionaries are created by assigning a set of key-value pairs in curly braces, each set separated by commas, to a variable.
  - Dictionaries are like structures where the contents ARE mutable.
  - Methods called on dictionaries can mutate their values, including:
    - `x.clear()`
    - `x.update({dict})`
    - `x.keys()`
    - `x.values()`
    - `x.items()`

```python
doug = {"name": "Doug", "age": 30, "class": 2009, "Python expert": False}
for key, value in doug.items():
    print(key + "--" + str(value))
```

- Examples located in:
8. `dictionary.c`, `dictionary.py`

#### Functions

- Important info:
  - Functions are introduced with the `def` keyword.
  - Functions have names and parameter lists, just like in C.
  - Python files are interpreted, not compiled, which means they are read top to bottom, left to right.
  - Code does not necessarily, but can be, bound up in a `main()` function, though that requires special extra syntax.
  - Functions do not require a prototype, but do need to be defined before they are called.
  - Python functions can return multiple values if need be, and may also return tuples, lists, and dictionaries.
- C:
```c
float square(float x);

int main(void)
{
    float base = get_float();
    printf("%f\n", square(base));
    return 0;
}

float square(float x)
{
    return x * x;
}
```
- Python:
```python
def square(x):
    return x ** 2

base = cs50.get_float()
print(square(base))
```

- Examples located in:

9. `positive.c`, `positive.py`
10. `cough{0,1,2,3,4}.c`, `cough{0,1,2,3,4}.py`

#### Objects

- Important info:
  - Objects are similar to structures in C in that they have fields. Additionally they have methods which are functions that are inherently part of that object, and may only be called directly by those objects.
  - You define the methods and properties of an object inside of a class.
  - Classes are created using the `class` keyword. Class names conventionally start with a capital letter.
  - At a minimum, a class must contain a method called `__init__`, which sets the initial values of properties in the object.
  - All methods of classes must include the `self` parameter as their first parameter, which is a reference to the object that is invoking the method.
    - When calling a method in a program, however, the `self` parameter is omitted (it is assumed to apply to the object that is invoking the method in the first place).

**In student.py**:
```python
class Student():

    def __init__(self, name, year="Freshman"):
        self.name = name
        self.year = year

    def endYear(self):
        if self.year == "Freshman":
            self.year = "Sophomore"
        elif self.year == "Sophomore":
            self.year = "Junior"
        elif self.year == "Junior":
            self.year = "Senior"
        else:
            self.year = "Alum"

    def info(self):
        print(f"{self.name} is a {self.year}.")
```

**In sample.py**:
```python
from student import Student

# create two new students, one is a freshman
maria = Student("Maria", "Senior")
newkid = Student("John Harvard")

# everyone graduates at the end of the year
maria.endYear()
newkid.endYear()

# new years, now!
maria.info()
newkid.info()
```

#### Miscellany

- The equivalent of `include` in Python is `import`.
- There is no `++` operator in Python, must use `+= 1`.
- No Python statement needs to end with a semicolon.
- `//` does integer division (familiar from C).
- `/` does floating point division always.

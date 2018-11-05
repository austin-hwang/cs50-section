# Section #7

## Shorts

- [Week 7 Shorts Playlist](https://www.youtube.com/playlist?list=PLhQjrBD2T383avGUWA_h8DeDDSleg8eh_)

## Outline

- Decorators
- Flask 
- Jinja 

### Decorators

- A *decorator* in Python is a function that modifies the behavior of other functions, typically applying some extra functionality thereto.
- Decorators are used to "set the route" associated with a function in pset8.
- The below example demonstrates the behavior of applying the `override` decorator to the function `one()`:

```python
def override(func):
    def incr():
        return func() + 1
    return incr

@override
def one():
    return 1

print(one()) # prints 2, since its behavior has been overridden (its return value has been increased by 1, thanks to `override()`)
```

- In pset8, you can use the `@app.route()` decorator, typically to specify the URL associated with a function and which methods (HTTP GET, HTTP POST) apply.
- There is also a decorator called `@login-required`, to ensure that certain functions (e.g., `buy()` are only called if the user is logged in, regardless of whether they visit the page and submit data via HTTP GET or HTTP POST)

### Flask


- Flask is a Python-based web microframework that automates the process of building simple web apps.
- Applications are typically written in a file called `application.py`, and the behavior of the entire Flask site springs from there.
- The simplest Flask app might look something like this:

```python
from flask import Flask

app = Flask(__name__)

@app.route("/")
def index():
    return "You are at the index!"
```

- To run this application, you need only type `flask run` from within the directory containing the target `application.py`. Then click on the link that appears in the terminal.
- The application will be rebuilt on the fly when you make edits to the source files, so there's no need to start and stop the application. For example, we could edit our `application.py` as follows:

```python
from flask import Flask

app = Flask(__name__)

@app.route("/")
def index():
    return "You are at the index!"

@app.route("/sample")
def sample():
return "You have reached the sample page!"
```

- If I save, and then visit `/sample` from my application's index, I'll see the new code without having to anything else.

- Thanks to Flask, it's very easy to write a simple dynamic web application.

```python
from flask import Flask
from datetime import datetime
from pytz import timezone

app = Flask(__name__)

@app.route("/")
def time():
	now = datetime.now(timezone('America/New_York'))
	return f"The current date and time is {now}."
```

- By default, the file Flask is looking for will be called `application.py`. We can change this by modifying one of our environment variables in CS50 IDE:

```
export FLASK_APP=<filename>
```

### Jinja

- Jinja is a Python inspired templating language, which is similar in spirit to the ability we had to interweave PHP and HTML inside of a single `.php` file.
- Basically, you define a simple `layout.html` or equivalent, leaving some parts as "fill-ins" using Jinja's syntax (this is your page template), and then other `.html` files "extend" this template, filling in those gaps left in the template, sort of like a code-based mad libs!


### JavaScript

- JavaScript is a dynamic programming language used by web browsers on the client side that allows users to communicate asynchonously with the browser.
- What you should focus on is that, while Python has been used by us as a server side programming language, JavaScript is "client side," meaning it is faster since there is no need to interact with another device.
- It's hard to classify JavaScript. It has characteristics of:
  - functional programming
  - object-oriented programming
  - imperative programming
- It is seemingly multi-paradigm. There are a few basic labels that can be attached to it, though.
  - JavaScript is, like Python, usually interpreted, meaning there is no need to compile it explicitly.
  - It is dynamically typed with local variables signified with the `let` tag.
  - Its ability to use the DOM (document object model) to dynamically change HTML is one reason why it is so widely used throughout the world wide web.

#### Basics

- The basic logic and data structures of JavaScript look very similar to C:

```JavaScript
// a simple variable
let age = 19;

// an array
let array = [1, 2, 3, 4, 5];

// string
let str = "Happy birthday, Maria!";

// an object
let teacher = {name: "David", course: 50};
```

- Notice that semicolons are back!
- Conditions and loops, likewise, look similar to C:

```JavaScript
// while loop
while (true)
{
    // do something
}

// for loop
for (initialization; condition; update)
{
    // do something
}

// if condition
if (true)
{
    // do something
}
```


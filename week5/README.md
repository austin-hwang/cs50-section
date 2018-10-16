# Section #5

## Shorts

  * [CSS](https://www.youtube.com/watch?v=Ub3FKU21ubk)
  * [HTML](https://www.youtube.com/watch?v=YK78KhMf7bs)
  * [HTTP](https://www.youtube.com/watch?v=4axL8Gfw2nI)
  * [Internet primer](https://www.youtube.com/watch?v=04GztBlVo_s)
  * [IP](https://www.youtube.com/watch?v=A1g9SokDJSU)
  * [JavaScript](https://www.youtube.com/watch?v=Z93IaNfavZw)
  * [TCP](https://www.youtube.com/watch?v=GP7uvI_6uas)

## Outline
- TCP/IP
- HTTP
- HTML
- CSS
- JavaScript

### TCP/IP

- A 'protocol' is a standard set of rules (e.g. handshaking is a protocol for when you meet someone). The internet has a number of protocols, including TCP, IP, and HTTP, for describing how communication over the internet should happen. Without these standard ways of communicating information, computers would not be able to guarantee that the receiver would get the information or that the receiving computer would know what to do with it.
- For computers (and other devices) to communicate with each other over the internet, they each need to have IP addresses.
- IP addresses are (in IPv4) of the format #.#.#.#, where each # is an 8-bit number in the range from 0 to 255.
- When a user types in a web address (like google.com) into their web browser, a Domain Name System (DNS) server lets the user's browser know the IP address of the web address that was typed in.

### HTTP

- An HTTP request looks something like:
```
GET / HTTP/1.1
Host: www.google.com
```
- The first part of this HTTP request is the request method.
  - Typically when a user types a link into their web browser, or when a user clicks on a link, they are sending a particular type of HTTP request called GET.
  - Web browsers can also send a different type of request, called POST, which is often used for transmission of data, as with the submission of a form. We'll use POST requests more later in the semester.
  - There are other types of request methods for different purposes (including PATCH, PUT, DELETE, etc.)
- The next part of the HTTP request is the endpoint (page) that the user is requesting. `/` means the root of the web page (likely the main page of the website).
- `HTTP/1.1` specifies the version of the HTTP protocol being used.
- The `Host` specifies the domain name the user is requesting a page from.
- When a server receives an HTTP request, it processes that request and gives back an HTTP response. That HTTP response contains both the content of the response, as well as an HTTP status code.
- Status codes:
  - 200: OK
  - 301: Moved Permanently (redirected)
  - 404: Not Found
  - 500: Server Error

### HTML

- HTML is a markup language (not considered a programming language). It's a way of describing the structure of a web page: web browsers take that HTML, and render it appropriately to the user.
- You can see the HTML for any web page by clicking "View Source" on a page in a web browser.
- A basic website looks like:
```
<!DOCTYPE html>
<html lang="en">
    <head>
        <title>hello, world</title>
    </head>
    <body>
        hello!
    </body>
</html>
```
- `<!DOCTYPE html>` specifies that this is an HTML5 document.
- HTML is composed of "tags" that generally start with `<tagname>` and end with `</tagname>` with the contents of the tag in between the two. Together, this describes an HTML element.
- Some tags, e.g. `<img>` don't require end tags, since conceptually there's nothing that would go between the start of an image and the end of an image.
- Certain tags have required attributes. The `<img>` tag, for instance, requires a `src` attribute indicating what image should be rendered, as well as an `alt` attribute that is some text to describe the image in case it can't be loaded.
- You can link between pages using the `<a href="otherpage">` tag.
- HTML tags can also take optional attributes.
- The `lang` attribute of the `<html>` tag is generally considered best practice, as of HTML5.
- All HTML elements can have an `id` or `class` attribute. The `id` is a unique identifier, so only one element on the page should ever have a particular `id`. The `class` attribute is a way of identifying one or more elements, and can therefore apply to multiple elements. `id` and `class` prove particularly useful when using CSS or JS.
- Tags can be nested within one another, to indicate sub-structure.
- Indentation in HTML isn't strictly necessary, but it's generally good style to keep everything visually aligned.
- HTML validators can be used to check whether your HTML is actually valid.

### CSS

- CSS (Cascading Style Sheets) is a way of styling our HTML webpages.
- You can add styling to an HTML element inline as with
```
<p style="color:blue;">
    Hello, world!
</p>
```
- In the above example, we added a `style` attribute to an HTML element. The style attribute contents include a CSS property (`color`) and a CSS value (`blue`). Multiple CSS properties can be separated from each other via semicolons.
- But better design would be to separate our HTML (structure of the page) from our CSS (aesthetics of the page). We could instead put this in the `<style>` section of the `<head>` of a webpage.
```
<style>
    p
    {
        color: blue;
    }
</style>
```
- In the above example, `p` is a CSS selector: it says "select all of the `p` elements on the page, and style them as below".
- There are other CSS selectors, too. Among the most common are `#foo`, which selects the element that has `id` of `foo`, and `.bar` which selects all elements that have a `class` of `bar`.
- Better design still would be to move our CSS to a separate file (so that it can be used by multiple different HTML documents). We can then use a `<link>` tag in our HTML to link the CSS file to our HTML file. The `href` attribute will be set to the CSS file, and the `rel` attribute will be set to `"stylesheet"`.
- Show some examples of CSS properties that are interesting to you: this could include `font-size`, `margin`, `padding`, `background-color`, `text-align`, etc.

### JavaScript

- JavaScript is a programming language used by web browsers on the client side that allows code to run inside the web browser.
- The Document Object Model is a tree that represents our HTML document. Each node represents an HTML element, and its children are the HTML elements nested within it.
- JavScript allows for manipulation of the DOM (Document Object Model) after the page has already loaded. This allows us to dynamically change the structure of the webpage, and lets us make our web pages more interactive, interesting, and useful.

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

- `alert` is a function that can be used to show an alert to the user.
- JavaScript can be used to add "event handlers" that listen for particular events on our webpage. If we had a function called `foo`, we could add:
```
<button onclick="foo">Click Here!</button>
```
to our code, so that clicking on a button would trigger the running of some code.

#### Manipulating the DOM

- `document.querySelector` is a function we can use to select an element from the DOM. `document.querySelector('#foo')` selects an element with an `id` of `foo` (we can use the same CSS selectors we used in CSS here in `querySelector`).
- Once we've queried for an HTML element, we can change its contents by setting the `innerHTML` property:
```js
let p = document.querySelector('#foo');
p.innerHTML = "New paragraph contents.";
```
- We can also set attributes of HTML elements using JS.
```js
let body = document.querySelector('body');
docuemnt.querySelector('#red').onclick = function() {
    body.style.backgroundColor = 'red';
}
```
- When a user clicks on the element with id `red` in the above example, the background of the whole page turns red.
- Note that in JavaScript, functions are values (just like a number or a string). This means that we can set an attribute of a JS object (like the `onclick` attribute) equal to a function.
- The above example also makes use of an "anonymous function" in JS: functions in JS don't need to have names.
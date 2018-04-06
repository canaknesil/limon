# Zambak

Zambak is a high-level, dynamically typed, interpreted programming language that supports imperative, functional programming paradigms. It is designed to be simple and powerfull at the same time.

## Expressions

A Zambak program consists of zero or more *expression*s seperated by whitespaces. Every *expression* produces a value: an *integer value*, *floating point value*, *boolean value*, *character value*, *string value*, *procedure value*, *array value*, or a *null value*. The same set of values can be bound to a variable. A variable has a binding at any time; in other words, it cannot be unbound.

### Variable Definition Expression

**Grammar:**
    
    def VARIABLE

Defines *variable* and initializes it as a *null value*. 

Returns *null value*.

**Example:**

    def myNum

### Variable Assignment Expression

**Grammar:** 

    VARIABLE = EXPRESSION

Evaluates *expression* and assignes the produced value to *variable*.

Returns the assigned value.

**Example:**

    myNum = 3

### Variable Definition and Assignment Expression

Variable definition and assignment can be also performed with a single expression.

**Grammar:** 

    def VARIABLE = EXPRESSION

Defines *variable*, evaluates *expression*, and assigns the produced value to the variable.

Returns the assigned value.

**Example:**

    def myNum = 3

### Variable Expression

**Grammar:** 

    VARIABLE

Returns the binding of *variable*.

### Print Expression

**Grammar:** 

    [print EXPRESSION ]

Evaluates *expression* and prints its value to standart output. All the values are printable. 

Returns the printed value.

**Example:**

    [print 1 + 3]

**Output:**

    4

### Scan Expression

**Grammar:**

    [scan]

Scans a token from standart input until a whitespace.

Returns the scaned string as a *string value*. If encounters the end of file, returns empty string: "". 

**Example:**

    [print "Enter a word. I will duplicate it: "]
    def word = [scan]

    [print word + word + "\n"]

**Output:**

    Enter a word. I will duplicate it: Zambak
    ZambakZambak

### Conditional Expression

**Grammar:** 

    ( EXPRESSION1 ? EXPRESSION2 : EXPRESSION3 )

Evaluates *expression1*. If it produces *#true*, evaluates *expression2* and returns its value. If *#false*, evaluates *expression3* and returns its value.

**Example 1:**
    
    def n = 1
    [print (n == 1 ? "This is One\n" : "This is not One") + "\n"]

**Output:**

    This is One

*Expression3* may not specified:

    ( EXPRESSION1 ? EXPRESSION2 )

In this case, if *expression1* is evaluated to *#false*, *null value* is returned. 

**Example 2:**
    
    def n = 2
    [print (n == 1 ? "This is One\n") + "\n"]

**Output:**

    #<null>

Conditional expression can also be used with multiple consecutive conditions:

    ( EXPRESSION ? EXPRESSION
      ...
      EXPRESSION ? EXPRESSION
      : EXPRESSION )

Or:

    ( EXPRESSION ? EXPRESSION
      ...
      EXPRESSION ? EXPRESSION )

In this case, the value or the correspondent of the first predicate that is evaluated to *#true* is returned.

**Example 3:**

    def msg = "msg-b"

    def m
    (msg == "msg-a ? m = 1
     msg == "msg-b ? m = 2
     msg == "msg-c ? m = 3
     : m = -1)

    [print m + "\n"]

**Output:**

    2

### Array Constant Expression

**Grammar:**

    {# EXPRESSION1 ... }

Evaluates specified one or more *expression* seperated by whitespace and creates an *array value* with their values. 

**Example:**

    def favMovies = {#"Star Ward" "Harry Poter" "Issiz Adam"}

### Array Creation Expression

**Grammar:**

    [# EXPRESSION ]

Evaluates *expression* which produces an *integer value* N and create an *array value* with size N. Initializes all the elements to *null value*.

### Array|String Get Expression

**Grammar:**

    [# EXPRESSION1 EXPRESSION2 ]

Evaluates *expression1* which produces an *array value* or a *string value*. Evaluates *expression2* which produces an *integer value* N. Returns the N'th element|character of the array|string.

### Array|String Set Expression

**Grammar:**

    [# EXPRESSION1 EXPRESSION2 EXPRESSION3 ]

Evaluates *expression1* which produces an *array value* or a *string value*. Evaluates *expression2* which produces an *integer value* N. Evaluates *expression3* and assigns its value to the N'th element|character of the array|string. 

Returns the assigned value. 

**Example 1:** Array

    def arr = [#3]
    [#arr 0 "Can Aknesil"]
    [#arr 1 "is"]
    [#arr 2 "awesome"]

    [print [#arr 0] + " " + [#arr 1] + " " + [#arr 2] + " ;)\n"]

**Output:**

    Can Aknesil is awesome ;)

**Example 2:** String

    def name = "Can"
    [#name 1 'A']
    [#name 2 'N']

    [print name + "\n"]

**Output:**

    CAN

### Size-Of Expression

**Grammar:**

    [sizeof EXPRESSION ]

Evaluates *expression* which produces an *array value* or a *string value*. Returns size of the array|string. 

### Procedure Expression

**Grammar:**

    @ ( PATAMETER_LIST ) { EXPRESSION ... }
    
Creates a *procedure value*. *Parameter-list* is a list of zero or more identifiers seperated by whitespaces. The body consists of zero or more expressions seperated by whitespaces. When the procedure is called, all the *expression*s in the body are evaluated in order and the value of the last one is returned.

### Call Expression

**Grammar:**

    [ EXPRESSION1 EXPRESSION2 ... ]

Evaluates *expression1* that produces a *procedure value*. Evaluates following zero or more *expression* which the arguments to the procedure. Calls the procedure with the arguments. 

**Example 1:** Anonymous procedures

    [print [@(n) { n * n } 12] + "\n"]

**Output:**

    144

**Example 2:**

    def count = 0
    def next = @() {
        count += 1
    }

    [print [next] + "\n"]
    [print [next] + "\n"]

**Output:**

    1
    2

**Example 3:** Higher-order procedures

    def createPoint = @(_x, _y) {
        def x = _x
        def y = _y

        def error = @() {
            [print "No Method Error\n"]
        }

        @(msg) {
            (msg == "getX" ? @() { x }
             msg == "getY" ? @() { y }
             msg == "setX" ? @(_x) { x = _x }
             msg == "setY" ? @(_y) { y = _y }
             : [error] )
        }
    }

    def aPoint = [createPoint 1 2]

    [print [[aPoint "getX"]] + "\n"]
    [print [[aPoint "getY"]] + "\n"]

    [[aPoint "setX"] 3]
    [[aPoint "setY"] 4]

    [print [[aPoint "getX"]] + "\n"]
    [print [[aPoint "getY"]] + "\n"]

**Output:**

    1
    2
    3
    4

**Example 4:** Recursive procedures

    def sum = @(array, from, to) {
        (from == to ? [#array from]
         : [#array from] + [sum array from+1 to])
    }

    def myArray = {#1 2 3}
    [print [sum myArray 0 [sizeof myArray]] + "\n"]

**Output:**

    6

### Multiple-Expression Expression

**Grammar:**

    ( EXPRESSION ... )

Evaluates specified one or more *expression* in order and returns the value of the last one.

Can be used where multiple expressions are needed:

    def a def b
    def pred = true

    (pred ? (
        a = "The predicate is true"
        b = 1
    ) : (
        a = "The predicate is false"
        b = 2
    ))

Can also be used to define precedence:

    [print (2 + 3) * 5]
    [print "\n"]

**Output:**

    25

### Scope Expression

**Grammar:**

    { EXPRESSION ... }

Same as *Multiple-Expression Expression* except that this one evaluates its body in a new variable scope. 

**Example 1:**

    def a = 1
    {
        def a = 3
        [print a + "\n"]
    }

**Output:**

    3

**Example 2:**

    def pred = true

    (pred ? {
        def a = "The predicate is true"
        [print a + "\n"]
    } : {
        def a = "The predicate is false"
        [print a + "\n"]
    })

**Output:**

    The predicate is true

### While Expression

**Grammar:**

    (while EXPRESSION1 ? EXPRESSION2 )

Evaluates *expression1* which procudes a *boolean value*. If it is *#true*, *expression2* is evaluated. This is repeted while *expression1* procudes *#true*. If *expression1* produces *#false* one time, the last value produced by *expression2* is returned. If *expression1* produces *#false* in the first time, *null value* is returned. 

**Example:**

    def i = 0
    (while i < 3 ? (
        [print i + " "]
        i += 1
    ))

**Output:**

    0 1 2


## Values


## Comments
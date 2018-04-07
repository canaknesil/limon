# Zambak

Zambak is a high-level, dynamically typed, interpreted programming language that supports imperative, functional programming paradigms. It includes a Garbage Collector. It is designed to be simple and powerfull at the same time.

## Expressions

A Zambak program consists of zero or more *expression*s seperated by whitespaces. Every *expression* produces a value: an *integer value*, *floating point value*, *boolean value*, *character value*, *string value*, *procedure value*, *array value*, or a *null value*. The same set of values can be bound to variables. A variable has a binding at any time; in other words, it cannot be unbound. And it can have bindings of different types at different times. 

### Integer Expression

**Grammar:**

    A_POSITIVE_INTEGER

Creates an *integer value*.

**Examples:**

    0
    125

If a negative integer is desired, *unary minus operator* must be used:

    (-3)

### Floating Point Expression

**Grammar:**

    ZERO_OR_MORE_DIGIT . ONE_OR_MORE_DIGIT

Creates a *floating point value*.

An arbitrary precision may also be specified:

    ZERO_OR_MORE_DIGIT . ONE_OR_MORE_DIGIT p AN_INTEGER

The positive integer comming after 'p' is the desired minimum presicion in decimal digits.

**Examples:**

    .5
    12.7
    12.7p50 // minimum of 50 decimal digits of precision

Integers and floating point numbers are specified in base 10 by default. However, they can be also specified in binary and hexadecimal formats in the following way:

    // Binary:
    0b1001   // 9
    0b101.1  // 5.5

    // Hexadecimal
    0x1A   // 26
    0xA.8  // 10.5

### Boolean Expression

**Grammar:**

    true
    false

Creates *boolean value*.

### String Expression

**Grammar:**

    " RAW_STRING "

Creates a *string value*.

**Example:**

    "Can Aknesil\n"

*Raw-string* may contain the following escape sequences:

* \a : Alert (beep)
* \b : Backspace
* \f : Form feed
* \n : New line
* \r : Carriage return
* \t : Horizontal tab
* \v : Vertical tab
* \" : Double quotation mark
* \\ : Backslash
* \? : Question mark

Characters can be gotten or set with *Array|String Get|Set Expression*.

### Character Expression

**Grammar:**

    ' RAW_CHARACTER '

Creates a *character value*.

**Examples:**

    'c'
    '\n'

*Raw-character* may contain the following escape sequences:

* \a : Alert (beep)
* \b : Backspace
* \f : Form feed
* \n : New line
* \r : Carriage return
* \t : Horizontal tab
* \v : Vertical tab
* \' : Single quotation mark
* \\ : Backslash
* \? : Question mark

For creating characters from ASCII integer values, casting from an integer value must be performed.

### Null Expression

**Grammar:**

    null

Creates a *null value*. This type of value represents absence of value.

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

Evaluates *expression* and assigns the produced value to *variable*.

Returns the assigned value.

**Example:**

    myNum = 3

### Variable Definition and Assignment Expression

Variable definition and assignment can also be performed with a single expression.

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

Evaluates *expression1*. If it produces *true*, evaluates *expression2* and returns its value. If *false*, evaluates *expression3* and returns its value.

**Example 1:**
    
    def n = 1
    [print (n == 1 ? "This is One" : "This is not One") + "\n"]

**Output:**

    This is One

*Expression3* may not specified:

    ( EXPRESSION1 ? EXPRESSION2 )

In this case, if *expression1* produces *false*, *null value* is returned. 

**Example 2:**
    
    def n = 2
    [print (n == 1 ? "This is One") + "\n"]

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

In this case, the value of the correspondent of the first predicate that produces *true* is returned.

**Example 3:**

    def msg = "msg-b"

    def m
    (msg == "msg-a" ? m = 1
     msg == "msg-b" ? m = 2
     msg == "msg-c" ? m = 3
     : m = (-1))

    [print m + "\n"]

**Output:**

    2

### Array Constant Expression

**Grammar:**

    {# EXPRESSION1 ... }

Evaluates specified one or more *expression* seperated by whitespace and creates an *array value* with their values. 

**Example:**

    def favMovies = {#"Star Wars" "Harry Poter" "Issiz Adam"}

### Empty Array Expression

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
    
Creates a *procedure value*. *Parameter-list* is a list of zero or more identifiers seperated by whitespaces. The body consists of one or more *expression*s seperated by whitespaces. When the procedure is called, all the *expression*s in the body are evaluated in order and the value of the last one is returned.

### Call Expression

**Grammar:**

    [ EXPRESSION1 EXPRESSION2 ... ]

Evaluates *expression1* that produces a *procedure value*. Evaluates following zero or more *expression* which are the arguments to the procedure. Calls the procedure with the arguments. 

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

    def createPoint = @(_x _y) {
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

    def sum = @(array from to) {
        (from == to ? [#array from]
        : [#array from] + [sum array from+1 to])
    }

    def myArray = {#1 2 3}
    [print [sum myArray 0 [sizeof myArray] - 1] + "\n"]

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

Same as *Multiple-Expression Expression* except that *scope expression* evaluates its body in a new variable scope. 

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

Evaluates *expression1* which procudes a *boolean value*. If it is *true*, *expression2* is evaluated. This is repeted while *expression1* procudes *true*. If *expression1* produces *false* one time, the last value produced by *expression2* is returned. If *expression1* produces *false* in the first time, *null value* is returned. 

**Example:**

    def i = 0
    (while i < 3 ? (
        [print i + " "]
        i += 1
    ))

**Output:**

    0 1 2

### String Cast Expression

**Grammar:**

    [2str EXPRESSION ]

Evaluates *expression*. Convert its value to *string value*. It is the same string that is printed if *print expression* were used. Every type of value can be casted to string.

**Example:**

    def str = [2str 12] + [2str 8]
    [print str + "\n"]

**Output:**

    128

### Character Cast Expression

**Grammar:**

    [2char EXPRESSION ]

Evaluates *expression* which should produces an *integer value* N. Returns *character value* corresponding to the ASCII value N. 

**Example:**

    def c = [2char 0x41]
    [print c + "\n"]

**Output:**

    A

### Integer Cast Expression

**Grammar:**

    [2int EXPRESSION ]

Evalutes *expression*. If it produces a *character value*, returns the corresponding ASCII value; a *floating point value*, returns an *integer value* removing its part after the dot. 

**Examples:**

    [print [2int 'A'] + "\n"]
    [print [2int 5.2] + "\n"]
    [print [2int (-3.12)] + "\n"]

**Output:**

    65
    5
    -3

### Floating Point Cast Expression

**Grammar:**

    [2float EXPRESSION]

Evaluates *expression* which produces an *integer value* and returns its *floating point value* version. 

## Unary and Binary Operation Expressions

**Grammer:**

    EXPRESSION1 + EXPRESSION2   // Addition
    EXPRESSION1 - EXPRESSION2   // Substraction
    EXPRESSION1 * EXPRESSION2   // Multiplication
    EXPRESSION1 / EXPRESSION2   // Division
    EXPRESSION1 % EXPRESSION2   // Remainder

    EXPRESSION1 == EXPRESSION2  // Equal?
    EXPRESSION1 != EXPRESSION2  // Not equal?
    EXPRESSION1 < EXPRESSION2   // Lower than?
    EXPRESSION1 > EXPRESSION2   // Greater than?
    EXPRESSION1 <= EXPRESSION2  // Lower than or equal?
    EXPRESSION1 >= EXPRESSION2  // Greater than or equal?

    EXPRESSION1 & EXPRESSION2   // And
    EXPRESSION1 | EXPRESSION2   // Or

    ( - EXPRESSION )            // Unary minus
    ! EXPRESSION                // Not

### Short-hand Operation and Assignemts

A binary operation and variable assignment can be done in a single expression:

**Grammer:**

    VAR += EXPRESSION
    VAR -= EXPRESSION
    VAR *= EXPRESSION
    VAR /= EXPRESSION
    VAR %= EXPRESSION
    VAR &= EXPRESSION
    VAR |= EXPRESSION

### Operator Precedeuce and Associativity

From higher precedence to lower:

* Unary minus (right)
* \* , / , % (left)
* \+ , - (left)
* < , > , <= , >= , == , != (left)
* ! (right)
* & (left)
* | (left)
* = , += , -= , *= , /= , %= , &= , |= (right)
    
### Unary and Binary Operations Typing & Details

**Addition:**

Note: All addition operations produces same type of values also in reverse order ("1 + 2" and "2 + 1")

* *string value* + any value -> *string value* (Concatenation)
* *integer value* + *integer value* -> *integer value*
* *integer value* + *character value* -> *character value*
* *character value* + *character value* -> *string value* (Concatenation)
* *floating point value* + *floating point value* -> *floating point value*
* *floating point value* + *integer value* -> *floating point value*

**Substraction:**

* *integer value* - *integer value* -> *integer value*
* *character value* - *integer value* -> *character value*
* *character value* - *character value* -> *integer value*
* *floating point value* - *floating point value* -> *floating point value*
* *floating point value* - *integer value* -> *floating point value*
* *integer value* - *floating point value* -> *floating point value*

**Multiplication & Division:**

Note: All addition operations produces same type of values also in reverse order ("1 * 2" and "2 * 1")

* *integer value* * *integer value* -> *integer value*
* *floating point value* * *floating point value* -> *floating point value*
* *floating point value* * *integer value* -> *floating point value*

**Remainder:**

* *integer value* % *integer value* -> *integer value*

**Equal? & Not equal?:**

Equal? operation checks if the inputs are of the same type. If different, returns directly *false*. If same, checks contents. For *array value*, all the elements are compared. Every procedure value are considered different by default unless they are the same value. 

* any value == any value -> *boolean value*

**Lower than & Greater than & Lower than or equal? & Greater than or equal?:**

* *interger value* < *integer value* -> *boolean value*
* *string value* < *string value* -> *boolean value*
* *character value* < *character value* -> *boolean value*
* *floating point value* < *floating point value* -> *boolean value*
* *interger value* < *floating point value* -> *boolean value*
* *floating point value* < *integer value* -> *boolean value*

**And & Or:**

* *boolaen value* & *boolean value* -> *boolean value*

**Unary Minus:**

* \- *integer value* -> *integer value*
* \- *floating point value* -> *floating point value*

**Not:**

* ! *boolean value* -> *boolean value*

## Comments
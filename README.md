# Zambak

Zambak is a high-level, dynamically typed, interpreted programming language that supports imperative, functional programming paradigms. It is designed to be simple and powerfull at the same time.

## Expressions

A Zambak program consists of zero or more *expression*s seperated by whitespaces. Every *expression* produces a value: an *integer value*, *floating point value*, *boolean value*, *character value*, *string value*, *procedure value*, *array value*, or a *null value*. The same set of values can be bind to a variable. 

### Variable Definition Expression

**Grammer:**
    
    def VARIABLE

Defines *variable* and initializes it as a *null value*. 

Returns *null value*.

**Example:**

    def myNum

### Variable Assignment Expression

**Grammer:** 

    VARIABLE = EXPRESSION

Evaluates *expression* and assignes the produced value to *variable*.

Returns the assigned value.

**Example:**

    myNum = 3

### Variable Definition and Assignment Expression

Variable definition and assignment can be also performed with a single expression.

**Grammer:** 

    def VARIABLE = EXPRESSION

Defines *variable*, evaluates *expression*, and assigns the produced value to the variable.

Returns the assigned value.

**Example:**

    def myNum = 3

### Variable Expression

**Grammer:** 

    VARIABLE

Returns the binding of *variable*.

### Conditional Expression

**Grammer:** 

    ( EXPRESSION1 ? EXPRESSION2 : EXPRESSION3 )

Evaluates *expression1*. If it produces *#true*, evaluates *expression2* and returns its value. If *#false*, evaluates *expression3* and returns its value.

*expression3* may not specified:

    ( EXPRESSION1 ? EXPRESSION2 )

In this case, if *expression1* is evaluated to *#false*, *null value* is returned. 

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

**Example 1:**
    
    def n = 1
    def str = (n == 1 ? "This is one\n" : "This is not one")

**Example 2:**

    def msg = "msg-b"
    def m
    (msg == "msg-a ? m = 1
     msg == "msg-b ? m = 2
     msg == "msg-c ? m = 3
     : m = -1)

### Procedure Expression

**Grammer:**

    @ ( PATAMETER_LIST ) { EXPRESSION ... }
    
Creates a *procedure value*. *parameter-list* is a list of zero or more identifiers seperated by whitespaces. The body consists of zero or more expressions seperated by whitespaces. 

**Example 1:**





## Values


## Comments
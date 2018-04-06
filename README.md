# Zambak

Zambak is a high-level, imperative, functional, dynamically typed, interpreted programming language for general purpose. It is designed to be simple and powerfull at the same time.

## Expressions

A Zambak program consists of zero, one, or more *expressions* seperated by whitespaces.

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

There is a version of conditional expression where *expression3* is not specified:

    ( EXPRESSION1 ? EXPRESSION2)

In this case, if *expression1* is evaluated to *#false*, *null value* is returned. 

Conditional expression can also be used with multiple consecutive conditions:

    ( EXPRESSION ? EXPRESSION
      EXPRESSION ? EXPRESSION
      ...
      : EXPRESSION)

In this case, the value or the correspondent of the first predicate that is evaluated to *#true* is returned.

**Example:**




## Values


## Comments
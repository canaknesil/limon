# Variables and Scope

In Limon, variables are defined with `def` keyword. 

```
limon> def count = 3
3

limon> count
3
```

## Properties of Limon Variables

- Variable names can include digits (0-9), letters (a-z, A-Z) and
  underscore (_). They cannot start with digits. 

- They do not have types and they can be bound to values
  of any type (including procedures) during their lives. 

```
limon> def count = 4
4

limon> count = 2.1
2.1

limon> count = true
#<true>

limon> count = @(n) { n+1 }
#<procedure>
```

- The same variable can be defined more than one time in the same
  scope, the second overwriting the first.
  
```
limon> def num = 3
3

limon> def num = 4
4
```

- A variable is bound to a value any time. There cannot be a variable
  without a value bound to it.

- A variable can be defined without initialization. In this case,
  `null` value is automatically assigned.
  
```
limon> def to_be_initialized
#<null>
```

- A variable definition or assignment evaluates to the assigned
  value. 

```
limon> def val = (def a = 3)
3

limon> val
3
```

Multiple variables can be assigned directly from an array with the
following syntax.

```
limon> (def arr = [# 1 2 3]
        def a
        def b
        def c)
#<null>

limon> (...a b c) = arr
[# 1 2 3]

limon> a
1

limon> b
2

limon> c
3
```

## Variable Scope

Limon has lexical scoping. 

There are 2 structures in Limon that enables creation of a new
variable scope: Scope expression and procedures.

- **Scope expression**

```
limon> def a = :outer
:outer

limon> {
         def a = :inner
         [println a]
       }
:inner
#<null>

limon> a
:outer
```

Scope expression evaluates to the value of the last expression inside
the block. In this case, its `null` that `println` procedure call
returns. 

- **Procedures**

When called every procedure is evaluated in a new scope where
arguments are bound.

```
limon> def num = 3
3

limon> def inc = @(num) {
         num += 1
       }
#<procedure>

limon> [inc num]
4

limon> num
3
```

A procedure has access to variables in the scope where it is
defined. 

```
limon> def num = 3
3

limon> def print_n = @() {
         [println num]
       }
#<procedure>

limon> [print_n]
3
#<null>
```

This enables to construct closers, explained in [Procedures](@ref)
section. 


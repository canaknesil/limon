# Limon Documentation

Limon is a high-level, dynamically typed programming
language that supports both imperative and functional programming
paradigms. It is designed to be elegant, simple, and powerful, without
performance constraints. 

A notable feature of Limon is infinite recursion without stack
overflow. This is achieved by the trampolined continuation passing
interpreter.

## Getting Started

Limon REPL (Read Evaluate Print Loop) can be started by invoking
`limon` executable without any parameters.

```
$ limon

limon> 5
5

limon> 2 + 3
5
```

Pressing `enter` in the REPL will evaluate the typed expression if
syntax is complete. Otherwise, it will let you typing on next lines
until the expression is syntactically correct. This expressions with
multiples lines can be entered.

```
limon> 1 +
       2 +
       3
6
```

To exit Limon REPL, type CTRL-D. 

## Limon in General

A Limon program consists of zero or more expressions separated by
whitespace. Every expression produces a value.

In Limon, there is no C like statements. In programs with more than
one expression, the values generated by the expressions except the
last one are ignored. The value of the last expression becomes the
end-value of the program.

Here is an example with 3 expressions:

1. def a=5
2. a+=2
3. a

```
limon> def a=5 a+=2 a
7
```

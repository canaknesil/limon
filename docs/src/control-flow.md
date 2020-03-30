# Control Flow

## Compound Expression

Compound expression is one or more expressions inside parenthesis.

```
limon> [println (def a = 5
                 [# a a+1 a+2])]
[# 5 6 7]
#<null>
```

Precedence of mathematical operations can be achieved by putting the
precedent operation inside the compound expression.

```
limon> (1 + 4) * 2
10
```

Note that expressions in the compound expression are evaluated without
creating a new scope. If a new scope is desired scope expression
should be used.

```
limon> [println {def a = 5
                 [# a a+1 a+2]}]
[# 5 6 7]
#<null>

limon> a

Internal Limon Exception: Variable 'a' not defined
...
```

## Conditional Evaluation

Conditional evaluation can be achieved with the language structure
`(expression_1 ? expression_2 : expression_3)`.

```
limon> (true ? 1 : 2)
1

limon> (false ? 1 : 2)
2
```

More than one condition can be stated. The following expressions are
identical. 

```
limon> def a = 2
2

limon> (a == 1 ? :one
        a == 2 ? :two
        a == 3 ? :tree
        : :none)
:two

limon> (a == 1 ? :one
        : (a == 2 ? :two
           : (a == 3 ? :three
              : :none)))
:two
```

*expression_3* (the expression after `:`) can be omitted. In this
case, if all the conditions evaluate to `false`, `null` is returned.

```
limon> a = 4
4

limon> (a == 1 ? :one
        a == 2 ? :two
        a == 3 ? :tree)
#<null>
```

Note that all three expressions `(exp1 ? exp2 : exp3)` are
expressions, not expression lists. So to run multiple expressions, use
compound or scope expression.

```
limon> (first ? (
          def size = 2
          [# size]
        ) : (
          def size = 3
          [# size]
        )
       )
[# 2]

limon> (first ? {
          def size = 2
          [# size]
        } : {
          def size = 3
          [# size]
        }
       )
[# 2]
```

Note that there is no short-circuit evaluation. All expressions of a boolean
operation are evaluated. 

```
limon> def say = @() { [println_str "Hey!"] true }
#<procedure>

limon> ([say] & [say] ? :this : :that)
Hey!
Hey!
:this
```

## Repeated Evaluation

In Limon, there are no built-in language structures explicitly for
repeated evaluation. However, this can be achieved by recursive
procedure calls.

```
limon> def do_range = @(i n f) {
         (i != n ? (
           [f i]
           [do_range i+1 n f]
         ))
       }
#<procedure>

limon> [do_range 0 4 println]
0
1
2
3
#<null>
```

`do_range` procedure defined above is an iterative procedure. The
recursive call to itself is a tail call, which means there is nothing to do
after the call except returning the evaluated value. 

In Limon, recursive calls does not grow the stack, iterative calls
neither grows the stack, nor grows the control context. This means
`do_range` procedure can be invoked with infinite larger number of
recursion with constant memory usage.

```
limon> [do_range 0 40000 @(i) { 
          (i % 10000 == 0 ? [println i])
       }]
0
10000
20000
30000
#<null>
```

This is achieved by the trampolined continuation passing interpreter. 

## Exception Handling

Limon exceptions can be raised with `raise` keyword. They can be
caught by try-catch language structure.

```
limon> def divide = @(n1 n2) {
         (n2 == 0 ? [raise :division_by_zero_exception]
          : n1 / n2)
       }
#<procedure>

limon> [divide 3 0]
Uncaught exception: :division_by_zero_exception

Error while running command.

limon> try {
         [divide 3 0]
       } catch (exc) {
         [print_str "In catch clause with exception "]
         [println exc]
       }
In catch clause with exception :division_by_zero_exception
#<null>

limon> try {
         [divide 3 2]
       } catch (exc) {
         [print_str "In catch clause with exception "]
         [println exc]
       }
1
```

```
limon> def is_a_defined = try {
         a
         true
       } catch (e) {
         false
       }
#<false>

limon> is_a_defined
#<false>

limon> def a = 4
4

limon> is_a_defined = try {
         a
         true
       } catch (e) {
         false
       }
#<true>

limon> is_a_defined
#<true>
```

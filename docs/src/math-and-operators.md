# Math and Operators

In Limon, elementary mathematical operations have their own special
syntax. Rather than procedure calls, they can be typed in regular
mathematical notation.

```
limon> 1 + 3
4

limon> (1 + 3) * 2
8

limon> 1 + 3 * 2
7
```

## Limon Operators

Binary operands with mathematical notation support:

- `+` (addition)
- `-` (substruction)
- `*` (multiplication)
- `/` (division)
- `%` (remainder) 

- `==` (equal)
- `!=` (not equal)
- `<` (lower than)
- `>` (greater than)
- `<=` (lower than or equal)
- `>=` (greater than or equal)

- `&` (and)
- `|` (or)

Unary operations with mathematical notation support:

- `!` (not)
- `-` (unary minus)

Important note: Unary minus operation MUST be enclosed by
parenthesis. This is to avoid confusion.

```
limon> (-(1 + 3))
-4
```

Short-cut assignment is supported for `+`, `-`, `*`, `/`, `%`, `&`,
and `|`. 

```
limon> def a = 5
5

limon> a += 1
6
```

## Precedence and Associativity

Parenthesis, `(`, `)`,  can be used to specify precedence. Otherwise, default
precedence rules are applied.

Precedence and associativity (from most precedent to least):

| Operator   | Associativity |
| :--------: | :-----------: |
| `*`, `/`, `%` | Left |
| `+`, `-` | Left |
| `<`, `>`, `<=`, `>=`, `==`, `!=` | Left |
| `!` | Right |
| `&`, `\|` | Left |
| `=`, `+=`, `-=`, ... (assignments) | Right |

There is no need to define precedence for unary minus since it is always
enclosed by parenthesis.

## Operator Semantics

Semantic behavior of all the operators (along with many other Limon
syntax) are defined in the Base library. So, operator behaviors can
be modified or extended by either modifying the Base library, or
redefined some procedures defined in the Base library.



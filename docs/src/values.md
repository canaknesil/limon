# Built-in Values

Limon has the following built-in values:

## Integer Value

Integer value in Limon can represent integers of arbitrary
precision from -infinity to +infinity, without overflow.

```
limon> def factorial = @(n) {
         (n == 0 ? 1 : n * [factorial n-1])
       }
#<procedure>

limon> [factorial 3]
6

limon> [factorial 30]
265252859812191058636308480000000

limon> [factorial 300]
306057512216440636035370461297268629388588804173576999416776741259476533176716867465515291422477573349939147888701726368864263907759003154226842927906974559841225476930271954604008012215776252176854255965356903506788725264321896264299365204576448830388909753943489625436053225980776521270822437639449120128678675368305712293681943649956460498166450227716500185176546469340112226034729724066333258583506870150169794168850353752137554910289126407157154830282284937952636580145235233156936482233436799254594095276820608062232812387383880817049600000000000000000000000000000000000000000000000000000000000000000000000000
```

Integer literals can be binary and hexadecimal:

```
limon> 11 == 0b1011 & 11 == 0xb & 11 == 0xB
#<true>
```

Note: Unary minus operation should be enclosed in parenthesis. This
is to prevent syntax confusion. 

```
limon> (-4)
-4
```

## Floating Point Value

Floating values in Limon have 64 bit precision by default. However, 32
and 16 bit precision can be used by extending floating point literals
with `p32` and `p16`.

Basic operations on floating point numbers with different precision
promote the lower precision one to the higher precision.

```
limon> [# def f16 = 1.0p16 / 3.0p16 + 0.0p64
          def f32 = 1.0p32 / 3.0p32 + 0.0p64
          def f64 = 1.0p64 / 3.0p64]
[# 0.333251953125 0.3333333432674408 0.3333333333333333]

limon> def abs = @(a b) {
          def diff = a - b
          diff = (diff > 0.0 ? diff : (-diff))
       }
#<procedure>

limon> [assert [abs f64 f32] < [abs f64 f16]]
#<true>
```

## Character Value

Characters can be printed in two ways. `print` procedure prints the
characters as they are. For example `'\n'` will be displayed as a real
new line. `show` procedure prints a representation of them for
esthetic purposes.

Limon REPL prints characters with `show`.

```
limon> def printchar = @(c) { [print c] [print '\n'] null }
#<procedure>

limon> def showchar = @(c) { [show c] [print '\n'] null }
#<procedure>

limon> [printchar 'a']
a
#<null>

limon> [printchar '\n']


#<null>

limon> [showchar 'a']
'a'
#<null>

limon> [showchar '\n']
'\n'
#<null>
```

## Boolean Value

```
limon> true
#<true>

limon> false
#<false>
```

## Symbol Value

Symbols values can be though as immutable strings. They are
generally used to represent names without complexity of strings. 

Syntax rules for symbols are the same as variables, except there
should be one colon `:` at the beginning.

```
limon> def perform_operation = @(op n1 n2) {
         (op == :addition     ? n1 + n2
          op == :substruction ? n1 - n2
          : :op_not_defined)
       }
#<procedure>

limon> [perform_operation :addition 2 3]
5

limon> [perform_operation :substruction 2 3]
-1

limon> [perform_operation :multiplication 2 3]
:op_not_defined
```

Unique symbols can be defined with `gensym` procedure. Any identical
symbol created using `gensym` cannot be created.

```
limon> [gensym]
:##253

limon> [gensym]
:##254
```

## Null Value

In Limon there is no absence of value. Every variable must be bound to
a value. Null value can be used to represent the absence of value.

```
limon> def increment_if_exists = @(n) {
         ([valuetype n] != :null ? n+1 : :null_input)
       }
#<procedure>

limon> [increment_if_exists 4]
5

limon> [increment_if_exists null]
:null_input
```

## Array Value

Arrays, in Limon, provide a way to have a list of values, where access
(get and set) to every index has constant time complexity. 

Once created their size cannot be changed. 

One array can store values of different types.

Passing arrays from variable to another does not copy the elements.

An empty array can be created with `make_array` procedure. All the
indices are automatically set to `null`.

```
limon> [make_array 8]
[# #<null> #<null> #<null> #<null> #<null> #<null> #<null> #<null>]
```

Arrays also can be created with array literal with the following
syntax:

```
def info_fields = [# :name :surname :age]
[# :name :surname :age]
```

`sizeof` procedure can be used to return size of an array.

```
limon> (def arr = [#]
        [sizeof arr])
0
```

`aget` and `aset` procedures can be used to get and set array fields.

```
limon> (def arr1 = [# 1 2]
        def arr2 = arr1)
[# 1 2]

limon> [aset arr1 0 55]
55

limon> arr1
[# 55 2]

limon> arr2
[# 55 2]
```

```
limon> def copy_arr = @(arr) {
         def size = [sizeof arr]
         def arr2 = [make_array size]
         
         def copy_index = @(idx) {
           (idx != size ? (
              [aset arr2 idx [aget arr idx]]
              [copy_index idx+1]))
         }
         [copy_index 0]
         
         arr2
       }
#<procedure>

limon> def arr1 = [# 1 1 1]
[# 1 1 1]

limon> def arr2 = [copy_arr arr1]
[# 1 1 1]

limon> [aset arr1 0 2]
2

limon> arr1
[# 2 1 1]

limon> arr2
[# 1 1 1]
```

Note: This is not the shortest way to copy an array.

### Character Arrays

In Limon, there is no built-in string value. They are represented as
array of characters. In the Base library, string functions that
operate on arrays of characters are implemented (like print_str).

```
limon> [println "Limon"]
[# 'L' 'i' 'm' 'o' 'n']
#<null>

limon> [println_str "Limon"]
Limon
#<true>

limon> [valuetype "Limon"]
:array

limon> [valuetype [aget "Limon" 0]]
:char
```

## Procedure Value

In Limon, procedures can be created with the following syntax: 

@( *arguments* ) { *body* }

*arguments* are variables names separated with whitespace. *body* is
one or more expressions separated by whitespace.

The syntax of a procedure call is as follows:

[ *procedure* *arguments* ]

*procedure* is any expression that will evaluate to a procedure
value. *arguments* are zero or more expressions separated by
whitespace.

Some examples:

```
limon> @(a b) { [println a+b] }
#<procedure>

limon> [@(a b) { [println a+b] } 4 5]
9
#<null>

limon> (def add = @(a b) { a+b }
        def sub = @(a b) { a-b })
#<procedure>

limon> def apply_op = @(op a b) {
         [op a b]
       }
#<procedure>

limon> [apply_op add 2 4]
6

limon> [apply_op sub 2 4]
-2
```

Check out [Procedures](@ref) for more detail.

## Value Type

Types of the values can be learned with `valuetype` function, which
returns a symbol.

```
limon> [valuetype 1]
:integer

limon> [valuetype 1.1]
:float

limon> [valuetype 'a']
:char

limon> [valuetype true]
:bool

limon> [valuetype :limon]
:symbol

limon> [valuetype null]
:null

limon> [valuetype [#]]
:array

limon> [valuetype @(){1}]
:procedure
```

## Conversion

Some values can be converted to others with `convert` procedure. 

```
limon> [convert 3 :float]
3.0

limon> [convert 'a' :integer]
97

limon> [convert 3 :float]
3.0

limon> def c = [convert 'a' :integer]
97

limon> c += 2
99

limon> [convert c :char]
'c'
```

# Procedures

In Limon, procedure values are first-class objects. They are treated like
every other value: They can be created inside procedures, can be
returned from procedures, can be passed as an argument during a
procedure call, can be bound to variables, etc. 

All the procedures are anonymous, they don't have names and can be
passed around freely.

Example:

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
`do_range` procedure can be invoked with infinite number of
recursion with constant memory usage.

This is achieved by the trampolined continuation passing interpreter. 

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




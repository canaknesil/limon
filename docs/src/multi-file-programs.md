# Multi-File Programs

In Limon, `run` keyword can be used to evaluate code in another in the
scope it is invoked.

```
$ cat > hello.lmn
def hello = @() { [println_str "Hello World!"] }

$ limon

limon> [run "hello.lmn"]
#<procedure>

limon> [hello]
Hello World!
#<true>
```

`run` can be used anywhere in a Limon program, such as inside scope
expression or inside procedures. If `run` is evaluated in a new scope,
definitions inside the evaluated file won't be visible to
outside. This can be useful if all the environment of evaluated file
is only needed in a limited portion of the program.

```
limon> {
         [run "hello.lmn"]
         [hello]
       }
Hello World!
#<true>

limon> hello

Internal Limon Exception: Variable 'hello' not defined
Location: 'REPL' between lines 1-1, columns 1-6

Error while running command.
```

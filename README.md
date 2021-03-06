<p align="center">
  <img src="./docs/src/assets/logo.png">
</p>

# Limon Language

Limon is a **high-level**, **dynamically typed** programming
language that supports both **imperative** and **functional programming**
paradigms. It is designed to be elegant, simple, and powerful, without
performance constraints. 

A notable feature of Limon is **infinite recursion without stack
overflow**. This is achieved by the trampolined continuation passing
interpreter. 

### A Simple Example - Cons Cell

![Cons Cell Code Example](docs/images/cons-cell-example-2.png)

## Dependencies

- [Julia](https://julialang.org/) 1.4 or higher. 

Once installed, `julia`
executable should be made accessible. This can be done by adding the
following line to `~/.bashrc`.

```
export PATH=$PATH:<julia-installation-directory>/bin
```

- GNU Make
- g++

- PackageCompiler.jl

This package is only needed during building. It can be installed with
the built-in package manager of Julia.

```
using Pkg
Pkg.add("PackageCompiler")
```


### Additional dependencies for developers who want to develop Limon parser

- GNU Bison 3.5 or higher
- Flex 2.6 or higher

## Compilation

Run `make` in the project directory. This will generate the parser
executable and Limon system image.

```
$ make
mkdir -p lib
...
 Activating environment at `~/Documents/proj/limon/Project.toml`
[ Info: PackageCompiler: creating system image object file, this might take a while...
```

And run `make check` to make sure everything works fine. This should
return without any error.

## Usage

To start Limon REPL, run `limon` executable located in `bin`
directory. You can also run a Limon file by providing the filename as
an argument.

Run`limon --help` for more usage information. 

**[EMACS Mode for Limon](https://github.com/canaknesil/limon-mode.el)** 
features syntax coloring and automatic indentation.

## Documentation

**[Limon Documentation](https://can.aknesil.com/limon/documentation/)**

## Contributers

Can Aknesil - <https://github.com/canaknesil/>

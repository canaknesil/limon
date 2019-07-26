# Limon

Limon is a high-level, dynamically typed, interpreted programming
language that supports both imperative and functional programming
paradigms. It is designed to be simple and powerfull at the same time.

### A Simple Example - Cons Cell

![Cons Cell Code Example](docs/images/cons-cell-example-crop.png)

## Dependencies

Make, G++, Flex, and GNU Bison for compilation; GNU Readline, and GNU
Multiple Precision Arithmetic Library (GMP) for execution.

On Ubuntu, all except GMP can be installed with apt-get:

    sudo apt-get install build-essential flex bison libreadline-dev

GMP can be downloaded from <https://gmplib.org/>. It should be
installed with C++ enabled.

    ./configure --enable-cxx
    make
    make install

## Compilation & Usage

Run `make` in the project directory. `limon` executable will be
created in `bin` directory. Run it without any arguments to start the
Limon REPL. Run `limon --help` for command-line usage information.

## Documentation

The Limon Documentation can be found [here](docs/limon-documentation.md).

## Contributers

Can Aknesil - <https://github.com/canaknesil/>

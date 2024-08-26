# Quadratic equation solver
*Created at the MIPT summer school for first-year students of the program "System Programming and Applied Math"*

Simple CLI program for solving equations of the form ax² + bx + c = 0 with any coeefficients

## Dependencies

- `gcc`
- `make`
- `doxygen (optional)`

## Run program

Clone the project

```bash
git clone https://github.com/
cd mipt-
```

Compile code

```bash
make
```

Finally, run executable file

```bash
quad.exe
```

## Get information about arguments

```bash
quad.exe -h
```

## Get documentation

```bash
doxygen
```

See it in FireFox:

```bash
firefox doxygen/html/index.html
```

Or just open `doxygen/html/index.html` in another browser

## Possible arguments

Can be called in any order and any number of times

- solve           Solving quadratic equation. Coefficients must be in form `-s <a> <b> <c>` 
- help  	  Gives information about argumets
- test_file_help  Gives information about format of file with tests
- test            Testing internal functions
- epsilon         Printing current value of constant for NonZero()


### Abbreviations in tooltips and code:
coef  = coefficient
coefs = coefficients
sol   = solution
info  = information


 
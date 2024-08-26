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

## Possible arguments

Can be called in any order and any number of times

- <pre>solve           <\pre>Solving quadratic equation. Coefficients must be in form `-s <a> <b> <c>` 
- <pre>help  	       Prints information about argumets</pre>
- <pre>test_file_help  Gives information about format of file with tests</pre>
- <pre>test            Testing internal functions</pre>
- <pre>epsilon         Printing current value of constant for NonZero()</pre>
<!-- cat               Prints poltorashka --!>

## Get documentation

```bash
doxygen
```

See it in FireFox:

```bash
firefox doxygen/html/index.html
```

Or just open `doxygen/html/index.html` in another browser


### Abbreviations in tooltips and code:
- coef  = coefficient
- coefs = coefficients
- sol   = solution
- info  = information


 
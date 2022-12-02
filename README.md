# How to Open

1. Open WSL terminal
2. Move to the project folder: `cd ~/cpp`
3. Open VS Code: `code .`

# How to build

## From Terminal

### Manually

```sh
g++ <-std=c++xx> <-Wall> <-O0> program.cpp <-o output_file>
```

#### Example

```sh
g++ -std=c++14 -Wall -O0 program.cpp -o program.out
```

### Using Make

```sh
make all
```

## From VS Code

### Options

1. **Terminal** &rarr; **Run Build Task**
2. `Ctrl + Shift + b`
3. Press **Debug C/C++ File** button

# How to Run

## Manually

From the project folder: `./program.out`

## Using Make

```sh
make run
```

# How to Clean

## Manually

```sh
rm -f *.o
rm -f /usr/local/bin/program.out
```

## Using Make

```sh
make clean
```

------------

# Common errors

## Make ends with error

Remember to go inside the folder of the specific program before running `make`

------------

# Sources

+ cplusplus https://cplusplus.com/
  + Standard C++ Library reference https://cplusplus.com/reference/
  + Recomendado por Santiago (Usa C++11) https://cplusplus.com/doc/tutorial/
+ Online Markdown editor https://pandao.github.io/editor.md/en.html
+ makefile https://github.com/luchocurti/makefile_template

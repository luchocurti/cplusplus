# How to Open a Project

1. Open WSL terminal
2. Move to the project folder: `cd ~/cpp`
3. Open VS Code: `code .`

# How to build (from chap 01 to 18)

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
make [-s] all
```

## From VS Code

### Options

1. **Terminal** &rarr; **Run Build Task**
2. `Ctrl + Shift + b`
3. Press **Debug C/C++ File** button

# How to build (from chapter 18 onwards)

```sh
mkdir -p build/
cd build/
cmake ..
make
[make install]
```

# How to Run (from chap 01 to 18)

## Manually

From the project folder: `./program.out`

## Using Make

```sh
make [-s] run
```

# How to Run (from chapter 18 onwards)

From the build folder: `./main`

# How to Clean (from chap 01 to 18)

## Manually

```sh
rm -f *.o
rm -f /usr/local/bin/program.out
```

## Using Make

```sh
make [-s] clean
```

# How to Clean (from chapter 18 onwards)

```sh
cd project_name/
rm -rf build/*
```

------------

# Common errors

## Make ends with error

Remember to go inside the folder of the specific program before running `make`

------------

# Sources

+ cplusplus https://cplusplus.com/
  + Standard C++ Library reference https://cplusplus.com/reference/
  + C++ tutorials from the basics to the newest C++11 https://cplusplus.com/doc/tutorial/
+ Modern C++ Course For CV - 2020 https://www.ipb.uni-bonn.de/teaching/cpp-2020/
+ Modern C++ Course For CV - 2021 https://www.ipb.uni-bonn.de/teaching/cpp-2021/
+ Online Markdown editor https://pandao.github.io/editor.md/en.html
+ makefile https://github.com/luchocurti/makefile_template

# Modular Madness

### Module operations:
- echo : The output string is the input string concatenated to itself.
- reverse : The output string is the input string reversed.
- delay: The output string is the previous input string. The initial output is “hello”.
- noop: The input appears unchanged at the output

### Module calls from standard input
1. Module definition, adds a new module to the network
use of module:
	module \<name_of_the_module\> \<operation\>
2. Connection command, connects the output of one module to the input of another module ( similar to pipe function in bash)
use of connection:
	connect \<name_of_the_module1\> \<name_of_the_module2\>
3. Process command, feeds input into the first module in the network process <...list of strings to be processed>

### Compiling and running the program
```
[~]$ g++ modular_madness.cpp
```
or
```
[~]$ clang++ modular_madness.cpp
```

### Code samples

```
module name1 reverse
module name2 delay
connect name1 name2
process hello world
hello olleh dlrow
```

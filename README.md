# Pipex

<p align="center">
  <img src="https://github.com/ArenKae/ArenKae/blob/main/42%20badges/pipexe.png" alt="Pipex 42 project badge"/>
</p>

Pipex is a unix project aimed at better understanding shell redirections and processes in C. We will learn more about pipe(), fork(), dup2() and execve(), all very important functions for the infamous [minishell](https://github.com/ArenKae/minishell) !

The pipex program takes an input file, performs a command on it, pipes the result to another command which then writes its result to an output file. The result is virtually identical to this kind of shell command :
```bash
$ < input_file command1 | command2 > output file
```

---

## Status
Finished 12/06/2023. Grade: 100/100

## Usage
- Clone this repository and ```cd``` into it. Use ```make``` to compile, then launch the program with :
```bash
./pipex <input_file> <command1> <command2> <output_file>
```

- The output will be written to the specified output file. If the output file exists, it will be overwritten.

- Each command can be given arguments and options if surrounded by quotation marks. For example:
```bash
./pipex example.txt "cat" "grep x" outfile.txt
```
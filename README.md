# Pipex

<p align="center">
  <img src="https://github.com/ArenKae/ArenKae/blob/main/42%20badges/pipexe.png" alt="Pipex 42 project badge"/>
</p>

Pipex is a Unix project designed to deepen the understanding of shell redirections and process management in C. Through this project, we will learn more about ```pipe()```, ```fork()```, ```dup2()``` and ```execve()```, all of which are very important functions for the infamous [minishell](https://github.com/ArenKae/minishell) !

The pipex program takes an input file, performs a command on it, pipes the result to another command which then writes its result to an output file. The result is virtually identical to this kind of shell command :
```bash
$ < input_file command1 | command2 > output file
```
### Shell Redirection Explanation:
In a traditional Unix shell like Bash :
- ```< input_file``` redirects the standard input (fd=0) of a command to read from input_file instead of the terminal.
- ```|``` (pipe) sends the output of ```command1``` as input to ```command2```.
- ```> output_file``` redirects the standard output (fd=1) of a command to output_file`, overwriting it if it exists.

---

## Status
✅ Completed on: 12/06/2023
</br>
🏆 Grade: 100/100

## Usage
- Clone this repository and ```cd``` into it. Use ```make``` to compile, then launch the program with :
```bash
./pipex <input_file> <command1> <command2> <output_file>
```

- Each command can take arguments and options when enclosed in quotation marks. For example:
```bash
./pipex example.txt "cat" "grep x" outfile.txt
```
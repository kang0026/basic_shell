# Basic_Shell
### Assignment1-part2  Building a shell 
(The basic shell supporting both external and internal commands)

## Pseudo Code

Print out a prompt; <br />
Read a line from the user; <br />
Parse the line into the program name and an array of parameters; <br />
Use the fork() system call to spawn a new child process; <br />
The child process then uses the exec() system call (or one of its variants) to launch the specified program; <br />
The parent process (the shell) uses the wait() system call (or one of its variants) to wait for the child to terminate; <br />
Once the child (the launched program) finishes, the shell repeats the loop by jumping to 1. <br />

## Functionality 

1. recognizes the internal commands: exit, pwd, history and cd.
2. uses strtok_r() for parsing
3. fork() and execvp(), wait()
4. handles errors gracefully (No input, unkwown commands, errors)
5. supports pipe with pipe() and dup2() system calls

`(test: cat textfile | gzip -c | gunzip -c | tail -n 10)`

## Usage
1. make run / make clean
2. gcc my_shell.c -> ./a.out

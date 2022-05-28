# 42sh

## What is the 42sh ?
To sum it up, do you know what [tcsh](https://en.wikipedia.org/wiki/Tcsh) is ?<br>
Well, the 42sh is a similar shell, and the last of the 3 year-end project given in our first year ([here is the pdf](https://github.com/Lukacms/42sh/assets/B-PSU-210_42sh.pdf)).<br>
Out of all what was required, we did:
* Handling the execution line, notably the simple and double quotes
* Pipes and multi-pipes
* Magic quotes (try putting "ls \`ls\`" in bash / zsh / tcsh)
* Redirections (simples and doubles, left and right)
* Separators && and ||
* Commands "buit-in" : env, cd, echo, exit, alias, unalias, history, setenv, unsetenv
* Globing : *, [], ?, ~
* Environement variables
* Alias handling
* Nice prompt
* etc...

## How to use the project
* Clone the project
```
git clone git@github.com:Lukacms/42sh.git 42sh
```
* Go into the folder (`cd 42sh`)
* Compile the project
```
make re ; make clean
```
* Launch the shell
```
./42sh
```
* Enjoy !

## How to use the Makefile we did
A Makefile is used to compile the code, and it use the following rules:

| Command          | Result                                          |
| ---------------- | ----------------------------------------------- |
| `make`           | Builds a ```42sh``` executable.          |
| `make clean`     | Cleans build dumps, keeping the executable.     |
| `make fclean`    | Removes all of the files created by the build.  |
| `make debug`    | Compile with `-g` flag if you need to debug the program.  |
| `make tests_run`    | Execute the (few) criterion tests.  |
| `make coverage` (after tests_run)    | Display the total coverage done by the tests.  |
| `make re`        | Calls `make fclean` and then `make`.            |

## Authors
* Luka Camus
* Nolann Bougrainville
* Nils Martin
* Adrien Ricou

---

## Add to the project
* This project is finished since 29/05/2022, 23:42
* Epitech Students, don't steal this code !! (or only if you want a -84 ;))

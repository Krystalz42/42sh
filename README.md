# 42sh (42 School's shell project)

## Installing

```
git clone https://github.com/krystalz42/42sh
cd 42sh
make
./42sh
```

## The shell support the following features

### Jobs control
Binary can be executed in foreground and in background
### Expansion
Following character has been expand :
`~ / $$ / $? $ENV_VARIABLE`
### Alias
Alias works and are stored in `~/.42sh_rc`
### Globbing
`? *` followed by a tabulation
### Completion
Completion on binary and directory with tabulation
### Operator Tokens
#### Redirections :
`">" ">>" "<" "<<" "<&" ">&" "|"`
#### logical operators :
`"||" "&&" `
#### command separators :
`";" "&"`
### Builtins
```
env
unsetenv
setenv
alias
history
hash
jobs
foreground
background
cd
```
## Running the tests
_The usage has been made for all builtins_ `help`

### Few test possibles

```
42sh > echo "ls=ls -G" >> ~/.42sh_rc
42sh > ls
42sh > ls -lR / | wc &
42sh > jobs -r
42sh > fg %1
^C
42sh > base64 /dev/random | head -c 1000 | grep 42 | wc -l | sed -e 's/1/YES/g' -e 's/0/NO/g'
42sh > echo $$
42sh > false || true && ls
42sh > true && true && ls
42sh > cd ./[Press Tabulation]
```
## Authors

* **Alexandre Roulin** - ** - [Krystalz](https://github.com/krystalz42)
* **Jefferson Le Quellec** - ** - [Jle-quel](https://github.com/jle-quel)

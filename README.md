# 42sh (Shell project in 42 school)

## Installing

```
git clone https://github.com/krystalz42/42sh
cd 42sh
make
./42sh
```

## The shell support the following feature

### Jobs control
Binary can be execute in foreround and in background
### Expansion
Following character has been expand :
`~ / $$ / $? $ENV_VARIABLE`
### Alias
Alias work and stored in `~/.42sh_rc`
### Globbing
`? *` followed by a tabulation
### Completion
Completion on binary and directory with tabulation
### Operator Token
#### Redirections :
`">" ">>" "<" "<<" "<&" ">&" "|"`
#### logical operator :
`"||" "&&" `
#### command separator :
`";" "&"`
### Builtin
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
## Runing the tests
_The usage have been make for all builtins_ `help`

### Few test possible

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

# 42sh (Shell project in 42 school)

## Installing

```
git clone https://github.com/krystalz42/42sh
cd 42sh
make
./42sh
```

## Content

The shell support the following feature

### Alias

Alias work and stored in `~/.42sh_rc`

### Globbing

*\*\?* followed by a tabulation

### Completion

Completion with tabulation on binary and directory

### Operator Token

*Redirections :*

`">" ">>" "<" "<<" "<&" ">&" "|"`

_logical operator :_

`"||" "&&" `

_command separator :_

`";" "&"`

**Builtin**

```
env
unsetenv
setenv
history
hash
jobs
foreground
background
cd
```

## Runing the tests


_The usage have been make for all builtins_

```
42sh > help
```

**Few test possible**

```
42sh > ls -lR / | wc &
42sh > jobs -r
42sh > fg %1
^C
42sh > base64 /dev/random | head -c 1000 | grep 42 | wc -l | sed -e 's/1/YES/g' -e 's/0/NO/g'
```

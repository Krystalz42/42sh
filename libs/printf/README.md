# ft_printf
### 42 - Project #4 (Algorithms Branch)

An implementation of libc's printf function.

## Purpose

The goal of this project is to recode printf function so that you are able to use it in later projects. This project
also introduces you to new concepts such as variadic functions and arrays of function pointers. The only allowed functions and system calls for this project are: ```write, malloc, free, and the functions of stdarg(3)``` 

The ft_printf function
is prototyped as follows:

```C
int ft_printf(const char *format, ...);
```

The PDF of this project can be found [here].

## Bonus

As a bonus, I decided to add a few features to ft_printf that the standard function doesn't have. The first one is colors:
```C
ft_printf("%{red}Hello World!%{eoc}");
```
This will output "Hello World!" in red on the stdout. Some background colors have been implemented as well.

The other additional feature is the binary specifier. If you call the function like this:
```C
ft_printf("%b", 63);
```
"111111" will be written on the stdout. This specifier also works with some printf's sub-specifiers (like padding).

## Additional functions

I also decided to implement other functions of the printf function family. Their prototypes are the follwoing:

```C
int ft_dprintf(int fd, const char *format, ...);
int ft_sprintf(char *str, const char *format, ...);
int ft_snprintf(char *str, size_t size, const char *format, ...);
int ft_asprintf(char **ret, const char *format, ...);
int ft_vasprintf(char **ret, const char *format, va_list ap);
```

For a better reference on these functions:
```
man 3 printf
```

## How can I use these functions?

```
git clone https://github.com/giacomoguiulfo/42-ft_printf.git
make
```
Then include the "libftprintf.h" on your .c file, and finally compile your program like this:
```
gcc example.c -o example -L. -lftprintf -I includes
```

[here]: https://github.com/giacomoguiulfo/42-ft_printf/blob/master/ft_printf.en.pdf

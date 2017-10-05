#include <term.h>

#include <stdlib.h>
#include <stdio.h>
#include <term.h>

int main(void)
{
printf("%d\n", tgetent(NULL, "xterm-256color"));

}

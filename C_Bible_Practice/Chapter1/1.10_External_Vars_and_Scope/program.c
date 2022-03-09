// The variables in main, are private or local to main.
// Becuase they are declared within main, no other function can access them.
// Same is true for other functions and their variables

// It is possible to define vars that are external to all functions.
// They are globally accessible, they must be defined exactly once
// The declaration may be an explicit 'extern' statement or may be implicit from context
// Lets rewrite 1.9 with external varaigbles

// If the def of the external var occurs in source before its used in a particular function, you can ommit extern
// In our program are redundant. the uses of extern
// If the program is in several source files, and var is defines in file1 and used in file2 and 3
// then extern is needed in file2 and 3 to connect.

#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getLine(void);
void copy(void);

int main(int argc, char const *argv[])
{
    int len;
    extern int max;
    extern char longest[];
    max = 0;
    while ((len = getLine()) > 0)
        if (len > max)
        {
            max = len;
            copy();
        }
    if (max > 0) /* there was a line */
        printf("%s", longest);
    return 0;
}
int getLine()
{
    int c, i;
    extern char line[];
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

void copy()
{
    int i;
    extern char line[], longest[];
    i = 0;
    while ((longest[i] = line[i]) != '\0')
        i++;
}
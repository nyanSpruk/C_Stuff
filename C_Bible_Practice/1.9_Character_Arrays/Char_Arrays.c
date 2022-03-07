// Most common array in C is char array.
// Lets write a program that reads a set of text lines and prints the longest.

#include <stdio.h>

#define MAXLINE 1000 // Maximum input line length

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(int argc, char const *argv[])
{
    int len;               // Current line length
    int max;               // Maximum length seen so far
    char line[MAXLINE];    // Current input line
    char longest[MAXLINE]; // Longest line saved
    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    if (max > 0) // There was a line
        printf("%s\n", longest);
    return 0;
}

// Getline: read a line into s, return length
int getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

// Copy: copy 'from' into 'to' assume 'to' is big enough
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}

// At end of each line array a \0 to mark the end of line
// A line "hello\n" is stored in C like h e l l o \n \0

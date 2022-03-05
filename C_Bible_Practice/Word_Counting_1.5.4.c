#include <stdio.h>

#define IN 1  // Inside a word
#define OUT 0 // Outside a word

int main(int argc, char const *argv[])
{
    int inp, lineCounter, wordCounter, charCounter, state;
    state = OUT;
    lineCounter = wordCounter = charCounter = 0;
    while ((inp = getchar()) != EOF)
    {
        charCounter++;
        if (inp == '\n')
            lineCounter++;
        if (inp == ' ' || inp == '\n' || inp == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            wordCounter++;
        }
    }
    printf("Chars: %d, words: %d, lines: %d\n", charCounter, wordCounter, lineCounter);
    return 0;
}

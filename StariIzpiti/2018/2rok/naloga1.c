#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d ", &n);
    bool prvi = true;
    int counter = 0;
    int sum = 0;
    int tempCounter = 0;
    for (int i = 0; i < n; i++)
    {
        char znak = getchar();
        if (znak == '+' && prvi)
        {
            tempCounter++;
            prvi = false;
        }
        else if (znak == '+' && !prvi)
        {
            sum += tempCounter;
            counter++;
            tempCounter = 1;
        }
        else if (!prvi && znak != '+')
        {
            tempCounter++;
        }
    }
    printf("%d\n", (sum / counter));
    return 0;
}

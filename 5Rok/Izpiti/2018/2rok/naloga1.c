#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    int n;
    scanf("%d ", &n);
    char znak;
    bool prviPlus = false;
    int sum = 0;
    int counter = 0;
    int stPonovitev = 0;
    while ((znak = getchar()) != '\n')
    {
        if (!prviPlus && znak == '+')
        {
            counter++;
            prviPlus = true;
        }
        if (prviPlus && znak == '+')
        {
            sum += counter;
            counter = 1;
            stPonovitev++;
        }
        if (prviPlus && znak == '-')
        {
            counter++;
        }
    }
    printf("%d\n", sum / stPonovitev);
}

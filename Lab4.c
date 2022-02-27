#include <stdio.h>
#include <string.h>
#include "lib_mylib.h"

int main()
{
    char plansza[10][10];
    memset(plansza, '1', 100);
    initializeTab(plansza);

    int maxiloscruchow;
    printf("Maximum number of steps allowed: ");
    scanf("%i", &maxiloscruchow);
    int lr = 0; //liczba ruchow
    int lk = 0; //liczba krzyzykow
    printPlansza(plansza);

    while ((lk < 64) && (lr < maxiloscruchow))
    {
        int nw, nk; //numer wiersza, numer kolumny
        printf("Number of steps: %i \n", lr);
        lr++;
        printf("Enter line number: ");
        scanf("%i", &nw);
        printf("Enter column number : ");
        scanf("%i", &nk);
        lk = lk + changeto5(plansza, nw, nk);
        printPlansza(plansza);
    }

    winorlost(lk);
    return 0;
}
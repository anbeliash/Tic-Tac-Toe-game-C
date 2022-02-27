#include <stdio.h>
#include <string.h>
#include "lib_mylib.h"

void initializeTab(char plansza[10][10])
{
    for (int i = 1; i < 9; i++)
        for (int j = 1; j < 9; j++)
            plansza[i][j] = 'O';
}

void printPlansza(char plansza[10][10]) //wyswietlenie planszy
{
    printf("  1 2 3 4 5 6 7 8");
    for (int i = 1; i < 9; i++)
    {
        printf("\n++++++++++++++++++\n");
        printf("%i+", i);
        for (int j = 1; j < 9; j++)
        {
            printf("%c+", plansza[i][j]);
        }
    }
    printf("\n");
}
int changeOpposite(char plansza[10][10], int wiersz, int kolumna) //zmiana pola na przeciwny
{
    int lk = 0;
    if (plansza[wiersz][kolumna] == 'X')
    {
        plansza[wiersz][kolumna] = 'O';
        lk = -1;
    }
    else if (plansza[wiersz][kolumna] == 'O')
    {
        plansza[wiersz][kolumna] = 'X';
        lk = 1;
    }
    return lk;
}
int changeto5(char plansza[10][10], int wiersz, int kolumna) //zmiana wybranego pola i 4 obok
{
    int lk1, lk2, lk3, lk4, lk5;
    lk1 = changeOpposite(plansza, wiersz, kolumna);
    lk2 = changeOpposite(plansza, wiersz + 1, kolumna);
    lk3 = changeOpposite(plansza, wiersz - 1, kolumna);
    lk4 = changeOpposite(plansza, wiersz, kolumna + 1);
    lk5 = changeOpposite(plansza, wiersz, kolumna - 1);
    return lk1 + lk2 + lk3 + lk4 + lk5;
}
void winorlost(int lk)
{
    if (lk < 64)
    {
        printf("LOST");
    }
    else
    {
        printf("WIN");
    }
}
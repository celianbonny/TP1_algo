#define _CRT_SECURE_NO_WARNINGS   // Visual Studio : autorise scanf
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "tour.h"

#ifdef _WIN32
#include <windows.h>        // pour afficher correctement les accents dans la console
#endif

// 2.1 Menu
int main()
{
    char choix[100];
    int deja[NB_TOURS];     // clefs des questions deja posees (une par tour)
    int fini = 0;
    int tour;
    int etat;

#ifdef _WIN32
    SetConsoleOutputCP(65001);      // console en UTF-8 pour les accents
#endif
    srand(time(NULL));              // pour tirer les questions au hasard

    while (fini == 0)
    {
        printf("\n--- MENU ---\n");
        printf("[J]ouer\n");
        printf("[Q]uitter\n");
        printf("Votre choix : ");
        scanf("%99s", choix);

        if (EGAL(choix, "Q"))
        {
            fini = 1;
        }
        else if (EGAL(choix, "J"))
        {
            tour = 1;
            etat = 1;
            while (tour <= NB_TOURS && etat == 1)
            {
                etat = TOUR(tour, deja);
                tour = tour + 1;
            }
            if (etat == 2)
            {
                fini = 1;
            }
        }
        // sinon : on redemande
    }

    printf("A bientot !\n");
    return 0;
}
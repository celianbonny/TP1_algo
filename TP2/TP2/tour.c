// tour.c : le deroulement d'un tour de jeu
#define _CRT_SECURE_NO_WARNINGS   // Visual Studio : autorise scanf
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#include "questions.h"
#include "tour.h"

// Renvoie 1 si la clef est deja dans le tableau (qui contient "taille" clefs)
// "static" : utilisable seulement dans tour.c, donc pas besoin de la mettre dans tour.h
static int DEJAPOSEE(int clef, int* liste, int taille)
{
    int i;

    for (i = 0; i < taille; i = i + 1)
    {
        if (liste[i] == clef)
        {
            return 1;
        }
    }
    return 0;
}

// 2.2 TOUR
int TOUR(int tour, int* deja)
{
    int clef;
    int valide = 0;
    char** q;
    char saisie[100];

    // On tire une clef au hasard, et on recommence tant que la question a deja ete posee
    clef = rand() % NB_QUESTIONS;
    while (DEJAPOSEE(clef, deja, tour - 1) == 1)
    {
        clef = rand() % NB_QUESTIONS;
    }
    deja[tour - 1] = clef;          // on retient la question posee

    // Affichage
    q = UNEQUESTION(clef);
    printf("\n=== Tour %d/%d : %.0f euros en jeu ===\n", tour, NB_TOURS, POGNON(tour));
    printf("%s\n", q[0]);
    printf("A) %s\n", q[1]);
    printf("B) %s\n", q[2]);
    printf("C) %s\n", q[3]);
    printf("D) %s\n", q[4]);

    // Saisie : on redemande tant que ce n'est pas A, B, C ou D
    while (valide == 0)
    {
        printf("Votre reponse (A, B, C ou D) : ");
        scanf("%99s", saisie);
        if (strlen(saisie) == 1 && DANSLISTE(saisie[0], "ABCD", 1) == 1)
        {
            valide = 1;
        }
    }

    // Resultat : q[5] contient la lettre de la bonne reponse
    if (EGAL(saisie, q[5]) == 0)
    {
        printf("Perdu ! La bonne reponse etait %s) %s. Vous perdez la cagnotte.\n",
            q[5], q[q[5][0] - 'A' + 1]);
        return 0;
    }

    printf("Bravo ! Cagnotte : %.0f euros\n", POGNON(tour));

    if (tour == NB_TOURS)
    {
        printf("Vous avez gagne la partie !\n");
        return 2;
    }

    // Continuer ou arreter ?
    valide = 0;
    while (valide == 0)
    {
        printf("[c]ontinuer ou [a]rreter ? ");
        scanf("%99s", saisie);
        if (strlen(saisie) == 1 && DANSLISTE(saisie[0], "CA", 1) == 1)
        {
            valide = 1;
        }
    }

    if (EGAL(saisie, "A"))
    {
        printf("Vous encaissez %.0f euros. Au revoir !\n", POGNON(tour));
        return 2;
    }
    return 1;
}
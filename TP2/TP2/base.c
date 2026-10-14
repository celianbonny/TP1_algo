#include <string.h>
#include <ctype.h>
#include "base.h"


// 1.1 EGAL
int EGAL(char* gauche, char* droite)
{
#ifdef _WIN32
    if (_stricmp(gauche, droite) == 0)
    {
        return 1;
    }
#else
    if (strcasecmp(gauche, droite) == 0)
    {
        return 1;
    }
#endif
    return 0;
}

// 1.2 DANSLISTE
int DANSLISTE(char val, char* liste, int ignorerCasse)
{
    int i = 0;

    while (liste[i] != '\0')
    {
        if (ignorerCasse == 1)
        {
            if (tolower(val) == tolower(liste[i]))
            {
                return 1;
            }
        }
        else
        {
            if (val == liste[i])
            {
                return 1;
            }
        }
        i = i + 1;
    }
    return 0;
}

// 1.3 POGNON
double POGNON(int tour)
{
    double argent = 1000;
    int i;

    for (i = 2; i <= tour; i = i + 1)
    {
        argent = argent * 2.16;
    }
    return argent;
}
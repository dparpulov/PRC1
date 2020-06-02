#ifndef _ANIMAL_H
#define _ANIMAL_H

typedef enum
{
    Cat,
    Dog,
    GuineaPig,
    Parrot
} SPECIES;


#define MaxNameLength 25
#define NumberOfSpecies 4

typedef struct
{
    char    Name[MaxNameLength];
    SPECIES Species;
    int     Age;
} ANIMAL;

#endif

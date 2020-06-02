/*
 * Menu animal_shelter.c
 *
 *  
 */

#include <stdio.h>
#include "animal.h"
#include "administration.h"

int main (void)
{
    printf ("PRC assignment 'Animal Shelter' (version april 2019)\n");
    
    ANIMAL animalArray[animalArraySize] = { {"Reks", Dog, 2}, {"Beks", Cat, 1}, {"Keks", GuineaPig, 5} };
    //ANIMAL animalArray[animalArraySize];
    //int animalArrayLength = sizeof(animalArray) / sizeof(ANIMAL);
    
    int choice = -1;
    while (choice != 0)
    {
        printf ("\nMENU\n====\n");
        printf ("1: Show Animals \n");
        printf ("2: Add Animal \n");
        printf ("3: Remove Animal \n");
        printf ("4: Find Animal by name \n");
        printf ("5: Find number of all animals \n");
        printf ("6: Find if 1 more animal can be added \n");
        printf ("0: quit \n");
                
        scanf ("%d", &choice);

        switch (choice)
        {
        case 1: //Show Animals
            printf("show Animals\n");
            showAnimals(animalArray);
            break;
        case 2: //Add Animal
            printf("add Animal\n");

            ANIMAL newAnimal;
            int species = 0;
            printf("Animal name: ");
            scanf("%s", newAnimal.Name);

            printf("Animal age: ");
            scanf("%d", &newAnimal.Age);

            printf("0. Cat 1. Dog 2. GuineaPig 3.Parrot \n");

            printf("Animal species: ");
            scanf("%d", &species);

            if (species == 0)
                newAnimal.Species = Cat;
            else if (species == 1)
                newAnimal.Species = Dog;
            else if (species == 2)
                newAnimal.Species = GuineaPig;
            else if (species == 3)
                newAnimal.Species = Parrot;

            //ANIMAL newAnimal = { "Flex", Parrot, 90 };
            ANIMAL* newAnimalp = &newAnimal;
            if (addAnimal(newAnimalp, animalArray) == 0)
            {
                showAnimals(animalArray);
            }
            else {
                printf("Shelter is full");
            }
            break;
        case 3: //Remove Animal
            printf("remove Animal\n");

            char animalNameToRemove[10];
            printf("Write the name of the animal that is going to be removed: \n");
            scanf("%s", animalNameToRemove);

            removeAnimal(animalNameToRemove, animalArray);
            break;
        case 4://find by name
            printf("find by name\n");

            char animalNameToSearch[MaxNameLength];
            printf("Write the name of the animal you are searching for: \n");
            scanf("%s", animalNameToSearch);

            if (checkForName(animalNameToSearch, animalArray) == 1){
                printf("You found %s\n", animalNameToSearch);
            }
            break;
        case 5://find number of animals in the shelter
            printf("find number of animals\n");
            printf("There are %d animals in the shelter\n", countAnimals());

            break;
        case 6://find if there is room for 1 more animal
            printf("find if 1 more animal can be added\n");
            printf("There is room for %d animals in the shelter\n", roomInShelter());

            break;
        case 0:
            break;
        default:
            printf ("ERROR: invalid choice: %d\n", choice);
            break;
		}
	}
    return 0;
}

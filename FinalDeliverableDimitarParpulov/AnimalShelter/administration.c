#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "administration.h"


int nrOfAnimalsInArray = 3;

//const int arraySize = 5; //Should be defined only in the header file (this is a global const) 
//implement your own functions
//Shows all animals
void showAnimals(ANIMAL* animalArray){
	int i;

	for (i = 0; i < nrOfAnimalsInArray; i++){
		char specieName[MaxNameLength];
		getSpecies(animalArray[i].Species, specieName);
		printf("%s is a %s and it is %d years old\n", animalArray[i].Name, specieName, animalArray[i].Age); //species must not show a number
	}
}

//Adds an animal to the shelter
int addAnimal(ANIMAL* animalPtr, ANIMAL* animalArray) {
	//int arrayLen = arraySize;

	if (nrOfAnimalsInArray < animalArraySize)
	{
		animalArray[nrOfAnimalsInArray] = *animalPtr;
		nrOfAnimalsInArray++;
		return 0;
	}

	return -1;
}

int removeAnimal(char* animalName, ANIMAL* animalArray)
{
	int i;
	int j;
	int animalsRemoved = 0;
	for (i = 0; i < animalArraySize; i++)
	{
		if (strcmp(animalArray[i].Name, animalName) == 0)
		{
			//printf("You are removing: %s is a %d and it is %d years old\n", animalArray[i].Name, animalArray[i].Species, animalArray[i].Age);
			animalsRemoved++;
			//printf("Animals removed %d\n", animalsRemoved);

			for (j = i; j < animalArraySize; j++)
			{
				memmove(&animalArray[j], &animalArray[j + 1], sizeof(ANIMAL));
			}
			strcpy(animalArray[animalArraySize].Name, "");
			animalArray[animalArraySize].Species = 0;
			animalArray[animalArraySize].Age = 0;

			nrOfAnimalsInArray--;
			i--;
			
		}
	}
	if (animalsRemoved > 0)
	{
		return 1;
	}

	return 0;
}

int checkForName(char* animalName, ANIMAL* animalArray)
{
	int i;
	for (i = 0; i < animalArraySize; i++)
	{
		if (strcmp(animalArray[i].Name, animalName) == 0)
		{
			return 1;
		}
	}
	return 0;
}

int countAnimals()
{	
	return nrOfAnimalsInArray;
}

int roomInShelter()
{
	int spaceLeft = animalArraySize - nrOfAnimalsInArray;
	return spaceLeft;
}

void getSpecies(int input, char* speciesName) {
	switch (input)
	{
	case 0:
		strcpy(speciesName, "Cat");
		break;
	case 1:
		strcpy(speciesName, "Dog");
		break;
	case 2:
		strcpy(speciesName, "GuineaPig");
		break;
	case 3:
		strcpy(speciesName, "Parrot");
		break;
	default:
		strcpy(speciesName, "No species");
		break;
	}
}
#ifndef _ADMINISTRATION_H

#define _ADMINISTRATION_H
#define animalArraySize 5
//#define nrOfAnimalsInArray 0

#include "animal.h"

//remove global const extern

//extern int nrOfAnimalsInArray;
//extern const int arraySize;
//extern ANIMAL animalArrayTwo[3];
// specify your own functions

	void showAnimals(ANIMAL animalArray[]);

	int addAnimal(ANIMAL* AnimalPtr, ANIMAL animalArray[]);

	int removeAnimal(char* animalName, ANIMAL* animalArray);

	int checkForName(char* animalName, ANIMAL* animalArray);

	int countAnimals();

	int roomInShelter();

	void getSpecies(int input, char* speciesName);
#endif

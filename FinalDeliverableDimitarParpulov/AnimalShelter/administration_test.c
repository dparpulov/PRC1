#include <string.h>
#include <stdlib.h>
#include "unity.h"
#include "administration.h"

//int animalsInShelter = 0;
//int animalArrayLength = 5;
ANIMAL animalArray[5];
ANIMAL testAnimal = { "reks", 1, 1 };
ANIMAL* newAnimalp = &testAnimal;

void setUp(void)
{
    // This is run before EACH test

    //ANIMAL* newAnimalp = &testAnimal;

}

void tearDown(void)
{
    // This is run after EACH test
}

//1
void test_addAnimalPass(void) {
    //ANIMAL animalArray[arraySize];
    //ANIMAL testAnimal = { "ReksTest", 1, 1 };

    //ANIMAL* newAnimalp = &testAnimal;

    TEST_ASSERT_EQUAL(0, addAnimal(newAnimalp, animalArray));
    TEST_ASSERT_EQUAL_STRING(testAnimal.Name, animalArray[0].Name);
    TEST_ASSERT_EQUAL(testAnimal.Species, animalArray[0].Species);
    TEST_ASSERT_EQUAL(testAnimal.Age, animalArray[0].Age);
}

//2
void test_addAnimalFail(void) {
    //int animalArrayLength = sizeof(animalArray) / sizeof(ANIMAL);
    //ANIMAL animalArray[arraySize];
    //ANIMAL testAnimal = { "ReksTest", 1, 1 };
    //ANIMAL* newAnimalp = &testAnimal;

    for (int i = 0; i < 5; i++) {
        addAnimal(newAnimalp, animalArray);
    }

    TEST_ASSERT_EQUAL(-1, addAnimal(&testAnimal, animalArray));
}

//3
void test_removeAnimalPass(void) {
    //ANIMAL* newAnimalp = &testAnimal;

    for (int i = 0; i < 5; i++) {
        addAnimal(newAnimalp, animalArray);
    }

    //char animalNameToRemove[10] = "ReksTest";
    
    TEST_ASSERT_EQUAL(1, removeAnimal("reks", animalArray));
    TEST_ASSERT_EQUAL(0, countAnimals());
}

//4
void test_removeAnimalFail(void) {
    //ANIMAL animalArray[arraySize];

    //char animalNameToRemove[10] = "lol";
    
    TEST_ASSERT_EQUAL(0, removeAnimal("reks", animalArray));
}

//5
void test_findAnimalPass(void) {
    //ANIMAL animalArray[arraySize];
    //ANIMAL testAnimal = { "Reks", 1, 1 };
    //ANIMAL* newAnimalp = &testAnimal;

    for (int i = 0; i < 5; i++) {
        addAnimal(newAnimalp, animalArray);
    }

    TEST_ASSERT_EQUAL(1, checkForName("reks", animalArray));
}

//6
void test_findAnimalFail(void) {
    //ANIMAL animalArray[arraySize];

    TEST_ASSERT_EQUAL(0, checkForName("lol", animalArray));
}

//7
void test_countAnimals(void) {
    //ANIMAL animalArray[arraySize];
    //ANIMAL testAnimal = { "ReksTest", 1, 1 };
    //ANIMAL* newAnimalp = &testAnimal;

    for (int i = 0; i < 5; i++) {
        addAnimal(newAnimalp, animalArray);
    }

    TEST_ASSERT_EQUAL(5, countAnimals());
}

//8
void test_isFullPass(void) {
    //ANIMAL animalArray[arraySize];
    //ANIMAL testAnimal = { "ReksTest", 1, 1 };
    //ANIMAL* newAnimalp = &testAnimal;

    for (int i = 0; i < 5; i++) {
        addAnimal(newAnimalp, animalArray);
    }

    TEST_ASSERT_EQUAL(0, roomInShelter());
}

//9
void test_isFullFail(void) {
    //ANIMAL animalArray[arraySize];
    //ANIMAL testAnimal = { "ReksTest", 1, 1 };
    //ANIMAL* newAnimalp = &testAnimal;

    for (int i = 0; i < 5; i++) {
        addAnimal(newAnimalp, animalArray);
    }

    TEST_ASSERT_EQUAL(-1, addAnimal(newAnimalp, animalArray));
}

int main (void)
{
    UnityBegin();

    RUN_TEST(test_addAnimalPass, 1);
    RUN_TEST(test_addAnimalFail, 2);
    RUN_TEST(test_removeAnimalPass, 3);
    RUN_TEST(test_removeAnimalFail, 4);
    RUN_TEST(test_findAnimalPass, 5);
    RUN_TEST(test_findAnimalFail, 6);
    RUN_TEST(test_countAnimals, 7);
    RUN_TEST(test_isFullPass, 8);
    RUN_TEST(test_isFullFail, 9);

    return UnityEnd();
}

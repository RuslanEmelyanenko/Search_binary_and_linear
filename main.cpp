/*
 Сгенерировать массив на 1000 рандомных элементов и найти в нем элемент, который вводит с клавиатуры пользователь.
 Сделать эту задачу в 2 вариантах: с помощью бинарного поиска и линейного.
 */
#include <iostream>
using namespace std;
#define RAND_SIZE 1000

void printOnConsole(string massage);
void printOnConsole(int parametr);
void printRandArr(int array[], int size);
int binarySearch(int array[], int key, int size);
int linearSearch(int array[], int key, int size);
int countRepit(int array[], int key, int size);

int main() {
    int randArr[RAND_SIZE], key, findedKeyIndex = 0, findedKeyIndex_2 = 0;
    int index = -1;
    printOnConsole ("Array of random numbers per 1000 elements: ");
    printRandArr (randArr, RAND_SIZE);
    printOnConsole ("\nEnter elemnt value that you want to find in array from 1 to 999: ");
    cin >> key;
    
    // 1. Binary search
    findedKeyIndex = binarySearch(randArr, key, RAND_SIZE);

    if(findedKeyIndex != index) {
        printOnConsole("1.1 Key was found at position ");
        printOnConsole(findedKeyIndex);
    } else {
        printOnConsole("1.1 Key wasn't founded:(");
    }
    
    // 2. Linear search
    findedKeyIndex_2 = linearSearch(randArr, key, RAND_SIZE);

    if(findedKeyIndex_2) {
        printOnConsole("\n1.2 Key was found at position ");
        printOnConsole(findedKeyIndex_2);
    } else {
        printOnConsole("\n1.2 Key wasn't founded:(");
    }
    
    printOnConsole("\nKey repit it: ");
    printOnConsole(countRepit(randArr, key, RAND_SIZE));
    printOnConsole("\n");
    
    return 0;
}

void printOnConsole(string massage) {
    cout << massage;
}

void printOnConsole(int parametr) {
    cout << parametr << " ";
}

void printRandArr(int array[], int size) {
    for(int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
        printOnConsole(array[i]);
    }
}

// 1. Binary bearch
int binarySearch(int array[], int key, int size){
    int index = -1, left = 0, right = size - 1, middle = (left + right) / 2;
    
    while (true) {
        middle = (left + right) / 2;
        
        if(key < array[middle]) {
            right = middle - 1;
        }
        else if (key > array[middle]) {
            left = middle + 1;
        }
        else {
            return middle;
        }
        
        if(left > right) {
            return index;
        }
    }
    
    return index;
}
// 2. Linear search
int linearSearch(int array[], int key, int size) {
    int index = 0;
    for(int i = 0; i < size; i++) {
        if(key == array[i]) {
            index = array[i];
            index = i;
        }
    }
    
    return index;
}

int countRepit(int array[], int key, int size) {
    int counter = 0;
    
    for(int i = 0; i < size; i++) {
        if(key == array[i]) {
            counter++;
        }
    }
    
    return counter;
}

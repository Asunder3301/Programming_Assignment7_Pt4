//Miguel Bautista
//CISP-1010 W01
//Programmming Assignment7 Question-3
//30 November 2025
//Description: Selection Sort
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void swapFunction(int& a, int& b);
void selectionSort(int array[], int size);
void printArray(int array[], int size);

int main() {
    const int SIZE = 25;
    int values[SIZE];
    string fileName = "PA7.txt";
    ifstream inputFile(fileName);

    if (!inputFile) {
        cout << "File does not exist" << endl;
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        inputFile >> values[i];
    }

    inputFile.close();

    selectionSort(values, SIZE);
    printArray(values, SIZE);

    return 0;
}

void swapFunction(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int array[], int size) {
    int minIndex, minValue;

    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = array[start];

        for (int index = start + 1; index < size; index++) {
            if (array[index] < minValue) {
                minValue = array[index];
                minIndex = index;
            }
        }
        swapFunction(array[minIndex], array[start]);
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}
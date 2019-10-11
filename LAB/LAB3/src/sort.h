

#ifndef SRC_SORT_H
#define SRC_SORT_H

#include <cstdlib>
#include <iostream>
//#define TIMING
void swap(int, int, int *);
void printArray(int *, int);
void printSearch(int, int);

void bubbleSort(int *, int);

void insertSort(int *, int);

void selectionSort(int *, int);

void mergeSort(int *, int);

void quickSort(int *, int, int);

int rSelect(int *, int, int, int);
int dSelect(int *, int, int, int);

#endif //SRC_SORT_H

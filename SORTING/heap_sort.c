#include<stdio.h>
#include<stdlib.h>
#include "sorting.h"

#define PARENT(n) n/2
#define LEFT(n) (n << 1) + 1
#define RIGHT(n) (n << 1) + 2

void build_max_heap(int array[], int size);
void max_heapify(int array[], int i, int size);
void swap(int array[], int i, int j);

void heap_sort(int array[], int size) {
    build_max_heap(array, size);
    int heap_size = size -1, i;
    
    for(i = heap_size; i > 0; i--) {
        swap(array, i, 0);
        heap_size --;
        max_heapify(array, 0, heap_size);
    }
}

void build_max_heap(int array[], int size) {
    int i;
    for(i = (size/2)-1; i >= 0; i--) {
        max_heapify(array, i, size);  
    }
}

void max_heapify(int array[], int i, int size) {
    int left  = LEFT(i);
    int right = RIGHT(i);
    int largest = i;

    if(left <= size && array[left] > array[largest])
        largest = left;

    if(right <= size && array[right] > array[largest])
        largest = right;

    if(largest != i) {
        swap(array, i, largest);
        max_heapify(array, largest, size);
    }
}

void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

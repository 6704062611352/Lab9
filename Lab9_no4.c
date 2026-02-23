#include <stdio.h>

void swapValue(int *a, int *b, int *c);
void swapArray(int *a, int *b, int size);

int main() {
    int a = 1, b = 2, c = 3;
    printf("Before swap function: a=%d, b=%d, c=%d\n", a, b, c);
    
    swapValue(&a, &b, &c); 
    
    printf("After swap function: a=%d, b=%d, c=%d\n", a, b, c);
    
    printf("\n-------------------------\n");
    int arr1[3] = {10, 20, 30};
    int arr2[3] = {99, 88, 77};
    int size = 3;

    printf("Before calling swapArray():\n");
    printf("arr1 = [%d, %d, %d]\n", arr1[0], arr1[1], arr1[2]);
    printf("arr2 = [%d, %d, %d]\n", arr2[0], arr2[1], arr2[2]);
    swapArray(arr1, arr2, size); 

    printf("\nAfter calling swapArray():\n");
    printf("arr1 = [%d, %d, %d]\n", arr1[0], arr1[1], arr1[2]);
    printf("arr2 = [%d, %d, %d]\n", arr2[0], arr2[1], arr2[2]);

    return 0;
}


void swapValue(int *a, int *b, int *c) {
    int temp = *a; 
    *a = *b;     
    *b = *c;     
    *c = temp;    
}


void swapArray(int *a, int *b, int size) {
    for (int i = 0; i < size; i++) {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

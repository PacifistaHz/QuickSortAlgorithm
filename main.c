#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonksiyon Prototipleri
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);
void printArray(int arr[], int size);
int contains(int arr[], int size, int value);

int main() {
    int i, N;
    printf("QUICK SORT ALGORITMASI\n");
    printf("Kac adet sayi uretilecek: ");
    scanf("%d", &N);
    int *arr = (int *)malloc(N * sizeof(int));
    srand(time(0));
    printf("Dizi Elemanlari: ");
    for (i = 0; i < N; i++) {
        int num;
        do {
            num = rand() % 100;
        } while (contains(arr, i, num));
        arr[i] = num;
        printf("%d ", arr[i]);
    }
    quickSort(arr, 0, N-1);
    printf("\nSiralanmis Dizi Elemanlari: ");
    printArray(arr, N);
    free(arr);
    return 0;
}

// Bu fonksiyon, bir dizide belirli bir değerin olup olmadığını kontrol eder
int contains(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1;
        }
    }
    return 0;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

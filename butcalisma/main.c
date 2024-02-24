#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i; // En büyük elemaný kök olarak kabul et
    int left = 2 * i + 1; // Sol çocuk indeksi
    int right = 2 * i + 2; // Sað çocuk indeksi

    // Sol çocuk, kökten daha büyükse
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Sað çocuk, en büyük olan þu anki kök veya sol çocuktan daha büyükse
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Eðer en büyük eleman kök deðilse, swap yap ve tekrar heapify iþlemi uygula
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    // Sonuncu alt aðaçtan baþlayarak heapify iþlemi uygula
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {29, 68, 35, 87, 66, 71, 38, 94, 22};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Dizinin orijinal hali: ");
    printArray(arr, n);

    buildHeap(arr, n);

    printf("Heap olarak düzenlenmiþ hali: ");
    printArray(arr, n);

    return 0;
}

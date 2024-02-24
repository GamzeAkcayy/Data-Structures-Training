#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i; // En b�y�k eleman� k�k olarak kabul et
    int left = 2 * i + 1; // Sol �ocuk indeksi
    int right = 2 * i + 2; // Sa� �ocuk indeksi

    // Sol �ocuk, k�kten daha b�y�kse
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Sa� �ocuk, en b�y�k olan �u anki k�k veya sol �ocuktan daha b�y�kse
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // E�er en b�y�k eleman k�k de�ilse, swap yap ve tekrar heapify i�lemi uygula
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    // Sonuncu alt a�a�tan ba�layarak heapify i�lemi uygula
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

    printf("Heap olarak d�zenlenmi� hali: ");
    printArray(arr, n);

    return 0;
}

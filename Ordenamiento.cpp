#include<iostream>

void InsertionSort(int arr[], int n) {
for (int i = 1; i < n; i++) {
int key = arr[i];
int j = i - 1;
while (j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j--;
}
arr[j + 1] = key;
}
}

int main(){
    
    int arr[] = {8, 5, 2, 7, 4, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    InsertionSort(arr, n);

    std::cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    

    return 0;
}

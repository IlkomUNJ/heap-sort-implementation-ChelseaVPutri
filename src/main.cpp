#include <iostream>
using namespace std;

void maxHeapify(int arr[], int arr_length, int index) {
    int largest = index; 
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < arr_length && arr[left] > arr[largest]) {
        largest = left;
    } else {
        largest = index;
    }

    if(right < arr_length && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != index) {
        swap(arr[index], arr[largest]);
        maxHeapify(arr, arr_length, largest);   
    }
}

void buildMaxHeap(int arr[], int arr_length) {
    int start_index = (arr_length / 2) - 1; //index yg bukan daun
    for(int i = start_index; i >= 0; i--) {
        maxHeapify(arr, arr_length, i);
    }
}

void printArray(int arr[], int arr_size) {
    // int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Array: " << endl;
    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    // int arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, arr_size);
    buildMaxHeap(arr, arr_size);
    printArray(arr, arr_size);
}
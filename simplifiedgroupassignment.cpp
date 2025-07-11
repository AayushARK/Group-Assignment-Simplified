#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
   
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    
    int L[100], R[100]; 

    for (i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; j = 0; k = low;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
int exponentialSearch(int arr[], int n, int key) {
    if (arr[0] == key)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= key)
        i = i * 2;
    int low = i / 2;
    int high = (i < n) ? i : n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
int main() {
    int arr[100];
    int n;

    cout << "Enter number of elements (max 100): ";
    cin >> n;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; 
    }

    cout << "Original array: ";
    printArray(arr, n);

    int sortChoice;
    cout << "Choose sorting algorithm:\n1. Quick Sort\n2. Merge Sort\nYour choice: ";
    cin >> sortChoice;

    if (sortChoice == 1)
        quickSort(arr, 0, n - 1);
    else
        mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    int key;
    cout << "Enter number to search: ";
    cin >> key;

    int searchChoice;
    cout << "Choose search algorithm:\n1. Binary Search\n2. Exponential Search\nYour choice: ";
    cin >> searchChoice;

    int index;
    if (searchChoice == 1)
        index = binarySearch(arr, n, key);
    else
        index = exponentialSearch(arr, n, key);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}


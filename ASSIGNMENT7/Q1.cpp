#include <iostream>
using namespace std;
void selectsort(int arr[], int n) {
    int i, j, posi, temp;
    for (i = 0; i < n - 1; i++) {
        posi = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[posi])
                posi = j;
        }
        temp = arr[i];
        arr[i] = arr[posi];
        arr[posi] = temp;
    }
}
void insertsort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void bubblesort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void mergeboth(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a1[100], a2[100];
    for (int i = 0; i < n1; i++)
    a1[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
    a2[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (a1[i] <= a2[j])
            arr[k++] = a1[i++];
        else
            arr[k++] = a2[j++];
    }
    while (i < n1)
        arr[k++] = a1[i++];

    while (j < n2)
        arr[k++] = a2[j++];
}
void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        mergeboth(arr, l, mid, r);
    }
}
void quicksort(int arr[], int low, int high) {
    if (low >= high)
        return;
    int i = low, j = high;
    int pivot = arr[(low + high) / 2];
    int temp;
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
        }
    }
    if (low < j)
    quicksort(arr, low, j);
    if (i < high)
    quicksort(arr, i, high);
}
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int arr[100], n, ch;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    while (1) {
        cout << "Sorting Menu";
        cout << "1. Selection Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Quick Sort\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            selectsort(arr, n);
            cout << "Selection Sort: ";
            display(arr, n);
            break;
        case 2:
            insertsort(arr, n);
            cout << "Insertion Sort: ";
            display(arr, n);
            break;
        case 3:
            bubblesort(arr, n);
            cout << "Bubble Sort: ";
            display(arr, n);
            break;
        case 4:
            mergesort(arr, 0, n - 1);
            cout << "Merge Sort: ";
            display(arr, n);
            break;
        case 5:
            quicksort(arr, 0, n - 1);
            cout << "Quick Sort: ";
            display(arr, n);
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }
    return 0;
}


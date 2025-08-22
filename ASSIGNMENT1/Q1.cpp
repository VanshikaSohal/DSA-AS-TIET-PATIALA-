#include <iostream>
#include<vector>
using namespace std;
int n;
vector<int> arr;
void create() {
    cout << "Enter number of elements: ";
    cin >> n;    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}
void display() {
	
vector<int> arr(n);
    if (n == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void insert() {
	
vector<int> arr(n);
    int posi, value;
    cout << "Enter position where you want to insert the element: ";
    cin >> posi;
    cout << "Enter value: ";
    cin >> value;
    if (posi < 1 || posi > n + 1) {
        cout << "Invalid position" << endl;
    }
    for (int i = n; i >= posi; i--)
    arr[i] = arr[i - 1];
    arr[posi - 1] = value;
    n++;
}
void del() {
	int posi;
    cout << "Enter position to delete: ";
    cin >> posi;
    if (posi < 1 || posi > n) {
        cout << "Invalid position" << endl;
        return;
    }
    for (int i = posi - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}
void linearsearch() {
	
vector<int> arr(n);
    int target;
    cout << "Enter element to search: ";
    cin >> target;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << "Element found at position: " << i + 1 << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}
int main() {
    int choice;
    do {
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
			create();
			break;
            case 2:
			display();
			break;
            case 3:
			insert();
			break;
            case 4:
			del();
			break;
            case 5:
			linearsearch(); 
			break;
            case 6:
			cout << "Exiting";
			break;
            default: 
			cout << "Invalid choice!" << endl;
        }
    }
	while (choice != 6);
    return 0;
}


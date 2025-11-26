#include <iostream>
using namespace std;
void reverse() {
    int n;
    int arr[100];
    cout << "Enter size of array (max 100): ";
    cin >> n;
    if (n <= 0 || n > 100) {
        cout << "Invalid size" << endl;
        return;
    }
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void transpose() {
    int r, c;
    int mat[20][20], trans[20][20];
    cout << "Enter rows and cols (max 20): ";
    cin >> r >> c;
    if (r <= 0 || c <= 0 || r > 20 || c > 20) {
        cout << "Invalid dimensions!" << endl;
        return;
    }
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            trans[j][i] = mat[i][j];
    cout << "Transpose Matrix: \n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
            cout << trans[i][j] << " ";
        cout << endl;
    }
}
void multiply() {
    int r1, c1, r2, c2;
    int a[20][20], b[20][20], result[20][20];
    cout << "Enter rows and cols of first matrix (max 20): ";
    cin >> r1 >> c1;
    cout << "Enter rows and cols of second matrix (max 20): ";
    cin >> r2 >> c2;
    if (r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0 ||
        r1 > 20 || c1 > 20 || r2 > 20 || c2 > 20) {
        cout << "Invalid size" << endl;
        return;
    }
    if (c1 != r2) {
        cout << " multiplication NOT possible!" << endl;
        return;
    }
    cout << "Enter first matrix:\n";
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            cin >> a[i][j];
		}
	}
    cout << "Enter second matrix:\n";
    for (int i = 0; i < r2; i++){
        for (int j = 0; j < c2; j++){
            cin >> b[i][j];
		}
	}

	for (int i = 0; i < r1; i++){
        for (int j = 0; j < c2; j++){
            result[i][j] = 0;
	}
	}
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
    cout << "Result :\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
}
int main() {
    int choice;
    do {
        cout << " MENU \n";
        cout << "1. Reverse Array ";
        cout << "2. Transpose Matrix ";
        cout << "3. Matrix Multiplication ";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: reverse(); 
			break;
            case 2: transpose();
			break;
            case 3: multiply(); 
			break;
            case 4: cout << "Exiting";
			break;
            default: 
			cout << "Invalid choice" << endl;
        }
    } while (choice != 4);
    return 0;
}

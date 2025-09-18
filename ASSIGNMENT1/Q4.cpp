#include <iostream>
#include<vector>
using namespace std;
void reversearray() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of the array : ";
    for (int i = 0; i < n; i++)
    {
	cin>>arr[i];
	}
    for (int i = 0; i <n/2; i++)
    {
    swap(arr[i], arr[n - i - 1]);	
	}
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++)
    {
    cout << arr[i] << " , ";	
	}
    cout << endl;
}
void transpose() {
    int r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    int mat[r][c], trans[c][r];
    cout << "Enter matrix: ";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
         cin >> mat[i][j];	
		}
} 
    for (int i = 0; i < r; i++)
    {
    	for (int j = 0; j < c; j++)
    	{
    	  trans[j][i] = mat[i][j];	
		}
	}
    cout << "Transpose matrix: ";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
        {
        cout << trans[i][j] << " ";
		}
        cout << endl;
    }
}
void multiply() {
    int r1, c1, r2, c2;
    cout << "Enter rows and cols of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and cols of second matrix: ";
    cin >> r2 >> c2;
    if (c1 != r2) {
        cout << "Matrix multiplication not possible!" << endl;
        return;
    }
    int a[r1][c1], b[r2][c2], result[r1][c2];
    cout << "Enter first matrix:\n";
    for (int i = 0; i < r1; i++)
    {
    	for (int j = 0; j < c1; j++)
    	{    		
            cin >> a[i][j];
		}
	}
    cout << "Enter second matrix:\n";
    for (int i = 0; i < r2; i++)
    {
    	for (int j = 0; j < c2; j++)
    	{
    		cin >> b[i][j];
		}
	}
    for (int i = 0; i < r1; i++)
    {
    	for (int j = 0; j < c2; j++)
    	{
    	  result[i][j] = 0;
		}
	}
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
    cout << "Result matrix: ";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
        {
          cout << result[i][j] << " ";
		}
        cout << endl;
    }
}
int main() {
    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Reverse Array\n";
        cout << "2. Transpose Matrix\n";
        cout << "3. Multiply Matrices\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: 
			reversearray();
			break;
            case 2:
			transpose();
			break;
            case 3:
			multiply();
			break;
            case 4: 
			cout << "Exiting"; 
			break;
            default: 
			cout << "Invalid choice";
        }
    } 
	while (choice != 4);
    return 0;
}


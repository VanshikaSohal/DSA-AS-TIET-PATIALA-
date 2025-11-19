#include <iostream>
using namespace std;
const int MAX = 100;
int create(int triplets[MAX][3], int &rows, int &cols) {
    int nnz;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "Enter number of non-zero elements: ";
    cin >> nnz;
    for (int i = 0; i < nnz; i++) {
        cout << "Enter row index of element " << i+1 << ": ";
        cin >> triplets[i][0];
        cout << "Enter column index of element " << i+1 << ": ";
        cin >> triplets[i][1];
        cout << "Enter value of element " << i+1 << ": ";
        cin >> triplets[i][2];
    }
    return nnz;
}
void display(int triplets[MAX][3], int nnz) {
    cout << "Triplet representation (row, col, value):\n";
    for (int i = 0; i < nnz; i++) {
        cout << triplets[i][0] << " " << triplets[i][1] << " " << triplets[i][2] << endl;
    }
}
int transpose(int triplets[MAX][3], int nnz, int trans[MAX][3]) {
    for (int i = 0; i < nnz; i++) {
        trans[i][0] = triplets[i][1];
        trans[i][1] = triplets[i][0];
        trans[i][2] = triplets[i][2];
    }
    return nnz;
}
int add(int A[MAX][3], int nnzA, int B[MAX][3], int nnzB, int sum[MAX][3]) {
    int i = 0, j = 0, k = 0;
    while (i < nnzA && j < nnzB) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            sum[k][0] = A[i][0];
			sum[k][1] = A[i][1]; 
			sum[k][2] = A[i][2];
            i++;
			k++;
        } else if (B[j][0] < A[i][0] || (A[i][0] == B[j][0] && B[j][1] < A[i][1])) {
            sum[k][0] = B[j][0]; 
			sum[k][1] = B[j][1];
			sum[k][2] = B[j][2];
            j++;
			k++;
        } else {
            sum[k][0] = A[i][0];
			sum[k][1] = A[i][1]; 
		    sum[k][2] = A[i][2] + B[j][2];
            i++;
		    j++;
			k++;
        }
    }
    while (i < nnzA)
	{ 
	sum[k][0] = A[i][0];
	sum[k][1] = A[i][1];
    sum[k][2] = A[i][2]; 
	i++;
	k++;
    }
    while (j < nnzB)
	{ 
	sum[k][0] = B[j][0]; 
	sum[k][1] = B[j][1];
	sum[k][2] = B[j][2];
	j++;
	k++;
	}
    return k;
}
int multiply(int A[MAX][3], int nnzA, int B[MAX][3], int nnzB, int mul[MAX][3]) {
    int k = 0;
    for (int i = 0; i < nnzA; i++) {
        for (int j = 0; j < nnzB; j++) {
            if (A[i][1] == B[j][0]) {
                int r = A[i][0];
                int c = B[j][1];
                int val = A[i][2] * B[j][2];
                bool found = false;
                for (int t = 0; t < k; t++) {
                    if (mul[t][0] == r && mul[t][1] == c) {
                        mul[t][2] += val;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    mul[k][0] = r; mul[k][1] = c; mul[k][2] = val;
                    k++;
                }
            }
        }
    }
    return k;
}
int main() {
    int choice, rows1, cols1, rows2, cols2;
    int matrix1[MAX][3], matrix2[MAX][3], result[MAX][3];
    int nnz1 = 0, nnz2 = 0, nnzR = 0;
    do {
        cout << "Matrix Operations Menu:";
        cout << "1. Create Matrix 1\n";
        cout << "2. Create Matrix 2\n";
        cout << "3. Transpose Matrix 1\n";
        cout << "4. Add Matrices\n";
        cout << "5. Multiply Matrices\n";
        cout << "6. Display Matrix 1\n";
        cout << "7. Display Matrix 2\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Creating Matrix 1:";
                nnz1 = create(matrix1, rows1, cols1);
                break;
            case 2:
                cout << "Creating Matrix 2:";
                nnz2 = create(matrix2, rows2, cols2);
                break;
            case 3:
                cout << "Transpose of Matrix 1:";
                nnzR = transpose(matrix1, nnz1, result);
                display(result, nnzR);
                break;
            case 4:
                if (rows1 == rows2 && cols1 == cols2) {
                    cout << "Addition of Matrix 1 and Matrix 2:";
                    nnzR = add(matrix1, nnz1, matrix2, nnz2, result);
                    display(result, nnzR);
                } else {
                    cout << "Dimensions do not match for addition.";
                }
                break;
            case 5:
                if (cols1 == rows2) {
                    cout << "Multiplication of Matrix 1 and Matrix 2:";
                    nnzR = multiply(matrix1, nnz1, matrix2, nnz2, result);
                    display(result, nnzR);
                } else {
                    cout << "Cannot multiply matrices with these dimensions";
                }
                break;
            case 6:
                cout << "Matrix 1:";
                display(matrix1, nnz1);
                break;
            case 7:
                cout << "Matrix 2:";
                display(matrix2, nnz2);
                break;
            case 0:
                cout << "Exiting program";
                break;
            default:
                cout << "Invalid choice, try again.";
        }
    } while(choice != 0);
    return 0;
}


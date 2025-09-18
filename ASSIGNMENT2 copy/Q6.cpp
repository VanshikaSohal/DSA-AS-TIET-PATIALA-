#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> create(int &rows, int &cols) {
    int nnz;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "Enter number of non-zero elements: ";
    cin >> nnz;

    vector<vector<int>> triplets(nnz, vector<int>(3));
    for (int i = 0; i < nnz; i++) {
        cout << "Enter row index of element " << i+1 << ": ";
        cin >> triplets[i][0];
        cout << "Enter column index of element " << i+1 << ": ";
        cin >> triplets[i][1];
        cout << "Enter value of element " << i+1 << ": ";
        cin >> triplets[i][2];
    }
    return triplets;
}

void display(const vector<vector<int>> &triplets) {
    cout << "Triplet representation (row, col, value):\n";
    for (auto &t : triplets) {
        cout << t[0] << " " << t[1] << " " << t[2] << endl;
    }
}

vector<vector<int>> transpose(const vector<vector<int>> &triplets) {
    vector<vector<int>> trans = triplets;
    for (auto &t : trans) {
        swap(t[0], t[1]);
    }
    return trans;
}

vector<vector<int>> add(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    vector<vector<int>> sum;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            sum.push_back(A[i]);
            i++;
        } else if (B[j][0] < A[i][0] || (A[i][0] == B[j][0] && B[j][1] < A[i][1])) {
            sum.push_back(B[j]);
            j++;
        } else {
            sum.push_back({A[i][0], A[i][1], A[i][2] + B[j][2]});
            i++; j++;
        }
    }
    while (i < A.size()) sum.push_back(A[i++]);
    while (j < B.size()) sum.push_back(B[j++]);
    return sum;
}

vector<vector<int>> multiply(const vector<vector<int>> &A, const vector<vector<int>> &B, int A_rows, int A_cols, int B_cols) {
    vector<vector<int>> mul;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            if (A[i][1] == B[j][0]) {
                int r = A[i][0];
                int c = B[j][1];
                int val = A[i][2] * B[j][2];
                bool found = false;
                for (auto &t : mul) {
                    if (t[0] == r && t[1] == c) {
                        t[2] += val;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    mul.push_back({r, c, val});
                }
            }
        }
    }
    return mul;
}
int main() {
    int choice, rows1, cols1, rows2, cols2;
    vector<vector<int>> matrix1, matrix2, result;
    do {
        cout << "\nMatrix Operations Menu:\n";
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
                cout << "Creating Matrix 1:\n";
                matrix1 = create(rows1, cols1);
                break;
            case 2:
                cout << "Creating Matrix 2:\n";
                matrix2 = create(rows2, cols2);
                break;
            case 3:
                cout << "Transpose of Matrix 1:\n";
                result = transpose(matrix1);
                display(result);
                break;
            case 4:
                if (rows1 == rows2 && cols1 == cols2) {
                    cout << "Addition of Matrix 1 and Matrix 2:\n";
                    result = add(matrix1, matrix2);
                    display(result);
                } else {
                    cout << "Dimensions do not match for addition.\n";
                }
                break;
            case 5:
                if (cols1 == rows2) {
                    cout << "Multiplication of Matrix 1 and Matrix 2:\n";
                    result = multiply(matrix1, matrix2, rows1, cols1, cols2);
                    display(result);
                } else {
                    cout << "Cannot multiply matrices with these dimensions.\n";
                }
                break;
            case 6:
                cout << "Matrix 1:\n";
                display(matrix1);
                break;
            case 7:
                cout << "Matrix 2:\n";
                display(matrix2);
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while(choice != 0);
    return 0;}


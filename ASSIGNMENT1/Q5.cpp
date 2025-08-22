#include <iostream>
using namespace std;
int main() {
    int row, col;
    cout << "Enter rows: ";
    cin >> row;
    cout << "Enter cols: ";
    cin >> col;
    int matrix[row][col];
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < row; i++) {
        int rowsum = 0;
        for (int j = 0; j < col; j++)
            rowsum += matrix[i][j];
        cout << "Sum of row " << i+1 << " is " << rowsum << endl;
    }
    for (int j = 0; j < col; j++) {
        int colsum = 0;
        for (int i = 0; i < row; i++)
            colsum += matrix[i][j];
        cout << "Sum of column " << j+1 << " is " << colsum << endl;
    }
    return 0;
}


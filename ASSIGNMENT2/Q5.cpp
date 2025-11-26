#include <iostream>
using namespace std;
int lowerTriangularIndex(int i, int j) {
    return (i*(i+1))/2 + j;
}
int triDiagonalIndex(int i, int j, int n) {
    if (i - j == 1)
        return i - 1;         
    else if (i == j)
        return n - 1 + i;      
    else if (j - i == 1)
        return 2*n - 1 + i;   
    else
        return -1;             
}
void q5a() {
    int n;
    cout << "Enter size of diagonal matrix: ";
    cin >> n;
    int* arr = new int[n]();
    cout << "Enter diagonal elements:\n";
    for(int i = 0; i < n; i++)
    cin >> arr[i];
    cout << "Diagonal Matrix:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) cout << arr[i] << " ";
            else cout << "0 ";
        }
        cout << "\n";
    }

    delete[] arr;
}
void q5b() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;
    int size = 3*n - 2;
    int* arr = new int[size]();
    cout << "Enter lower diagonal (n-1 elements):\n";
    for(int i=0; i<n-1; i++) 
    cin >> arr[i];
    cout << "Enter main diagonal (n elements):\n";
    for(int i=0; i<n; i++) 
    cin >> arr[n-1 + i];
    cout << "Enter upper diagonal (n-1 elements):\n";
    for(int i=0; i<n-1; i++)
    cin >> arr[2*n -1 + i];
    cout << "Tri-diagonal Matrix:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int idx = triDiagonalIndex(i,j,n);
            if(idx != -1)
            cout << arr[idx] << " ";
            else
            cout << "0 ";
        }
        cout << "\n";
    }

    delete[] arr;
}
void q5c() {
    int n;
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;
    int size = n*(n+1)/2;
    int* arr = new int[size]();
    cout << "Enter lower triangular elements row-wise:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            int idx = lowerTriangularIndex(i,j);
            cin >> arr[idx];
        }
    }
    cout << "Lower Triangular Matrix:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i>=j) cout << arr[lowerTriangularIndex(i,j)] << " ";
            else cout << "0 ";
        }
        cout << "\n";
    }

    delete[] arr;
}
void q5d() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;
    int size = n*(n+1)/2;
    int* arr = new int[size]();
    cout << "Enter upper triangular elements row-wise (j >= i):\n";
    int idx = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            cin >> arr[idx++];
        }
    }
    cout << "Upper Triangular Matrix:\n";
    idx = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j>=i) 
                int index = i*n - (i*(i+1))/2 + (j - i);   
                cout << arr[index] << " ";
            else cout << "0 ";
        }
        cout << "\n";
    }
    delete[] arr;
}
void q5e() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;
    int size = n*(n+1)/2;
    int* arr = new int[size]();
    cout << "Enter lower triangular part row-wise:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            int idx = lowerTriangularIndex(i,j);
            cin >> arr[idx];
        }
    }
    cout << "Symmetric Matrix:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i>=j)
                cout << arr[lowerTriangularIndex(i,j)] << " ";
            else
                cout << arr[lowerTriangularIndex(j,i)] << " ";
        }
        cout << "\n";
    }
    delete[] arr;
}
int main() {
    int choice;
    cout << "Select matrix type:\n";
    cout << "1. Diagonal\n2. Tri-diagonal\n3. Lower Triangular\n4. Upper Triangular\n5. Symmetric\n";
    cin >> choice;
    switch(choice) {
        case 1:
        q5a();
        break;
        case 2:
        q5b();
        break;
        case 3:
        q5c();
        break;
        case 4:
        q5d();
        break;
        case 5:
        q5e();
        break;
        default: 
        cout << "Invalid choice";
    }
    return 0;
}


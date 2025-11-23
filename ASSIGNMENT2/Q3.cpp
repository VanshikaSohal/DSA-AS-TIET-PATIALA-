#include <iostream>
using namespace std;
int missing(int arr[], int n) {
    int expectedsum = (n + 1) * (n + 2) / 2; 
    int actualsum = 0;
    for (int i = 0; i < n; i++)
        actualsum += arr[i];
    return expectedsum - actualsum;
}
int usingbinarysearch(int low,int high,int A[],int n){
    int missing=0;
    while(low<=high){
    int mid=(low+high)/2;
    if(A[mid]==mid+1){
        low=mid+1;
    }
    else if(A[mid]>mid+1){
        high=mid-1;
    }
    }
    missing=low+1;
    return missing;
}
int main() {
    int n;
    cout << "Enter the number of elements : " << endl;
    cin >> n;
    int arr[100]; 
    cout << "Enter elements of an array: " << endl;
    for (int i = 0; i < n; i++)
    cin >> arr[i];
    cout << "Missing Number is: " << missing(arr, n) << endl;
     int missingvalue=usingbinarysearch(0,n-1,A,n);
    cout<<"Missing value is "<<missingvalue<<endl;
    return 0;
}

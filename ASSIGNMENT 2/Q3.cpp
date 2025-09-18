#include <iostream>
#include<vector>
using namespace std;
int missing(vector<int>& arr, int n) {
    int expectedsum = (n+1)*(n+2)/2; 
    int actualsum = 0;
    for (int i = 0; i < n; i++)
       actualsum += arr[i];
    return expectedsum - actualsum;
}
int main() {
	int n;
    cout<<"Enter the number of elements of an array: "<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of an array: "<<endl;
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	cout << "Missing Number is: " << missing(arr, n) << endl;
    return 0;
}


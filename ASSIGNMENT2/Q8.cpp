#include <iostream>
#include <algorithm> 
#include<vector>
using namespace std;
int distinctcount(vector<int>& arr,int n)
{
	n=arr.size();
	sort(arr.begin(), arr.end());
    int count = 1; 
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            count++;
        }
    }
    cout << "Total distinct elements are: " << count << endl;
    return count;
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    distinctcount(arr,n);
    return 0;
}


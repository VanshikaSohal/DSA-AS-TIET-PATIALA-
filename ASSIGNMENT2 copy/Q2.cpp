#include <iostream>
#include<vector>
using namespace std;
void bubblesort(vector<int>& arr, int n) {
	n=arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; 
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) 
		{
			break;
		}
    }
}
int main() {
	int n;
	cout<<"Enter size of an array: "<<endl;
	cin>>n;
	vector<int> arr(n);
	cout<<"Enter the values of an array: "<<endl;
	  for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
    bubblesort(arr, n);
    cout << "Sorted array is : ";
    for (int i = 0; i < n; i++){
    cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}


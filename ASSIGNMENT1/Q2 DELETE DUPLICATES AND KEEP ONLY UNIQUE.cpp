#include<iostream>
using namespace std;
void deldupli(int arr[],int &n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;)
		{
			if(arr[i]==arr[j])
				{
					for(int k=j;k<n;k++){
						arr[k]=arr[k+1];
					}
					n--;
				}
				else{
					j++;
				}		
		}
	}
}
int main()
{
    int arr[] = {1, 2, 3, 2, 4, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    deldupli(arr, n);
    cout << "Array after removing duplicates:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

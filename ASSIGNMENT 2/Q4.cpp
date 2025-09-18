#include <iostream>
#include <cstring>
#include<vector>
#include <cctype>
#include<algorithm>
using namespace std;
int main() {
    char str1[100], str2[100];
    int choice;

    while (1) {
        cout << "\nString Related Programs:\n";
        cout << "1. Concatenate one string to another\n";
        cout << "2. Reverse a string\n";
        cout << "3. Delete all vowels from a string\n";
        cout << "4. Sort strings in alphabetical order\n";
        cout << "5. Convert character from uppercase to lowercase\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1: {
                cout << "Enter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                strcat(str1, str2);
                cout << "Concatenated string: " << str1 << endl;
                break;
            }
            case 2: {
                cout << "Enter a string: ";
                cin.getline(str1, 100);
                int len = strlen(str1);
                for (int i = 0; i < len / 2; i++) {
                    char temp = str1[i];
                    str1[i] = str1[len - i - 1];
                    str1[len - i - 1] = temp;
                }
                cout << "Reversed string: " << str1 << endl;
                break;
            }
            case 3: {
                cout << "Enter a string: ";
                cin.getline(str2, 100);
                int j = 0;
                for (int i = 0; str2[i] != '\0'; i++) {
                    char ch = tolower(str2[i]);
                    if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
                        str2[j++] = str2[i];
                    }
                }
                str2[j] = '\0';
                cout << "String without vowels: " << str2 << endl;
                break;
            }
            case 4: {
                int n;
                cout << "Enter number of strings: ";
                cin >> n;
                cin.ignore();
                vector<string> arr(n);
                cout << "Enter " << n << " strings:\n";
                for (int i = 0; i < n; i++) {
                    getline(cin, arr[i]);
                }
                sort(arr.begin(), arr.end());
                cout << "Strings in alphabetical order:\n";
                for (const string &s : arr) {
                    cout << s << endl;
                }
                break;
            }
            case 5: {
            string str;
            cout<<"Enter the string: "<<endl;
            cin>>str;
            for (auto &c : str) {
            c = tolower(c);
            }
            cout << str << endl;
            break;
            }
            default:{
                cout<<"Invalid choice"<<endl;
            }
          }
    }
    return 0;
}


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBegin(int x) {
    Node* n = new Node();
    n->data = x;
    n->next = head;
    head = n;
}

void insertEnd(int x) {
    Node* n = new Node();
    n->data = x;
    n->next = NULL;
    if (!head) { head = n; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
}
void insertAfter(int val, int x) {
    Node* temp = head;
    while (temp && temp->data != val) temp = temp->next;
    if (!temp) return;
    Node* n = new Node();
    n->data = x;
    n->next = temp->next;
    temp->next = n;
}
void insertBefore(int val, int x) {
    if (!head) return;
    if (head->data == val) { insertBegin(x); return; }
    Node* temp = head;
    while (temp->next && temp->next->data != val) temp = temp->next;
    if (!temp->next) return;
    Node* n = new Node();
    n->data = x;
    n->next = temp->next;
    temp->next = n;
}

void deleteBegin() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = NULL; 
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteNode(int val) {
    if (!head) return;
    if (head->data == val) 
    {
        deleteBegin();
        return; }
    Node* temp = head;
    while (temp->next && temp->next->data != val) temp = temp->next;
    if (!temp->next) return;
    Node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
void searchNode(int val) {
    Node* temp = head;
    int pos = 1;
    while (temp && temp->data != val) { temp = temp->next; pos++; }
    if (!temp) cout << "Not Found\n";
    else cout << "Position: " << pos << endl;
}

void displayList() {
    Node* temp = head;
    while (temp) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;
}

int main() {
    int choice, val, val2;
    do {
        cout << "Singly Linked List Menu";
        cout << "1. Insert at Beginning 2. Insert at End 3. Insert After 4. Insert Before ";
        cout << "5. Delete from Beginning 6. Delete from End 7. Delete Specific Node ";
        cout << "8. Search Node 9. Display List 10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1: cin >> val; insertBegin(val); break;
            case 2: cin >> val; insertEnd(val); break;
            case 3: cin >> val >> val2; insertAfter(val, val2); break;
            case 4: cin >> val >> val2; insertBefore(val, val2); break;
            case 5: deleteBegin(); break;
            case 6: deleteEnd(); break;
            case 7: cin >> val; deleteNode(val); break;
            case 8: cin >> val; searchNode(val); break;
            case 9: displayList(); break;
            case 10: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice\n";
        }
    } while (choice != 10);
}


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertEnd(int x) {
    Node* n = new Node();
    n->data = x;
    n->next = NULL;
    if (!head) { head = n; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
}

int countKey(int key) {
    Node* temp = head;
    int count = 0;
    while (temp) { if (temp->data == key) count++; temp = temp->next; }
    return count;
}

void deleteAll(int key) {
    while (head && head->data == key) { Node* t = head; head = head->next; delete t; }
    Node* temp = head;
    while (temp && temp->next) {
        if (temp->next->data == key) {
            Node* t = temp->next;
            temp->next = temp->next->next;
            delete t;
        } else temp = temp->next;
    }
}

void displayList() {
    Node* temp = head;
    while (temp) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;
}

int main() {
    int n, x, key;
    cout << "Enter number of nodes: "; cin >> n;
    for(int i=0;i<n;i++){ cin >> x; insertEnd(x); }
    cout << "Enter key: "; cin >> key;
    cout << "Count: " << countKey(key) << endl;
    deleteAll(key);
    cout << "Updated Linked List: "; displayList();
}


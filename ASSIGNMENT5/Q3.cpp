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

void displayList() {
    Node* temp = head;
    while (temp) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;
}

void findMiddle() {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    if (slow) cout << "Middle: " << slow->data << endl;
}

int main() {
    int n, x;
    cout << "Enter number of nodes: "; cin >> n;
    for(int i=0;i<n;i++){ cin >> x; insertEnd(x); }
    displayList();
    findMiddle();
}


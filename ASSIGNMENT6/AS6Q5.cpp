#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head = NULL;
void insertLast(int val){
    Node* n = new Node;
    n->data = val;
    if(!head){
        head = n;
        n->next = n;
        return;
    }
    Node* temp = head;
    while(temp->next != head) temp = temp->next;
    temp->next = n;
    n->next = head;
}
void displayWithHead(){
    if(!head) return;
    Node* temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
    cout << head->data << endl;
}
int main(){
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Enter value for node " << i+1 << ": ";
        cin >> val;
        insertLast(val);
    }
    cout << "Circular Linked List: ";
    displayWithHead();
    return 0;
}


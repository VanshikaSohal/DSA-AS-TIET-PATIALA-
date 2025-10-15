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
void displayWithHeadRepeat(){
    if(!head) return;
    Node* temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
    cout << head->data << endl;
}
int main(){
    insertLast(20);
    insertLast(100);
    insertLast(40);
    insertLast(80);
    insertLast(60);
    displayWithHeadRepeat();
    return 0;
}


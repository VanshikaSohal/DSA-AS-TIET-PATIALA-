#include<iostream>
using namespace std;
struct DNode{
    int data;
    DNode* next;
    DNode* prev;
};
DNode* dhead = NULL;
void dInsertLast(int val){
    DNode* n = new DNode;
    n->data = val;
    n->next = NULL;
    n->prev = NULL;
    if(!dhead){
        dhead = n;
        return;
    }
    DNode* temp = dhead;
    while(temp->next) temp = temp->next;
    temp->next = n;
    n->prev = temp;
}
int dSize(){
    int count = 0;
    DNode* temp = dhead;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}
struct CNode{
    int data;
    CNode* next;
};
CNode* chead = NULL;
void cInsertLast(int val){
    CNode* n = new CNode;
    n->data = val;
    if(!chead){
        chead = n;
        n->next = n;
        return;
    }
    CNode* temp = chead;
    while(temp->next != chead) temp = temp->next;
    temp->next = n;
    n->next = chead;
}
int cSize(){
    if(!chead) return 0;
    int count = 0;
    CNode* temp = chead;
    do{
        count++;
        temp = temp->next;
    }while(temp != chead);
    return count;
}
int main(){
    dInsertLast(10);
    dInsertLast(20);
    dInsertLast(30);
    cout << "Size of Doubly Linked List: " << dSize() << endl;
    cInsertLast(20);
    cInsertLast(100);
    cInsertLast(40);
    cInsertLast(80);
    cInsertLast(60);
    cout << "Size of Circular Linked List: " << cSize() << endl;
    return 0;
}


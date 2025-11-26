#include <iostream>
using namespace std;
struct DNode {
    char data;
    DNode* next;
    DNode* prev;
};
DNode* head = NULL;
void insertLast(char val) {
    DNode* n = new DNode;
    n->data = val;
    n->next = NULL;
    n->prev = NULL;
    if (!head) {
        head = n;
        return;
    }
    DNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    n->prev = temp;
}
bool isPalindrome() {
    if (!head || !head->next) 
		return true;
    DNode* left = head;
    DNode* right = head;
    while (right->next) 
		right = right->next;
    while (left != right && left->prev != right) {
        if (left->data != right->data) return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}
void display() {
    DNode* temp = head;
    while (temp) {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    insertLast('m');
    insertLast('a');
    insertLast('d');
    insertLast('a');
    insertLast('m');
    cout << "Doubly Linked List: ";
    display();
    if (isPalindrome())
        cout << "Palindrome" << endl;
    else
        cout << " Not a Palindrome" << endl;
    return 0;
}

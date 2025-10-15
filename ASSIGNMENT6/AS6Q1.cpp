#include<iostream>
using namespace std;
struct CNode{
    int data;
    CNode* next;
};
CNode* chead = NULL;
void cInsertFirst(int val){
    CNode* n = new CNode;
    n->data = val;
    if(!chead){
        chead = n;
        n->next = n;
        return;
    }
    CNode* temp = chead;
    while(temp->next != chead) temp = temp->next;
    n->next = chead;
    temp->next = n;
    chead = n;
}
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
void cInsertAfter(int key, int val){
    if(!chead) return;
    CNode* temp = chead;
    do{
        if(temp->data == key){
            CNode* n = new CNode;
            n->data = val;
            n->next = temp->next;
            temp->next = n;
            return;
        }
        temp = temp->next;
    }while(temp != chead);
}
void cInsertBefore(int key, int val){
    if(!chead) return;
    CNode* temp = chead;
    CNode* prev = NULL;
    do{
        if(temp->data == key){
            CNode* n = new CNode;
            n->data = val;
            if(prev == NULL){
                CNode* last = chead;
                while(last->next != chead) last = last->next;
                n->next = chead;
                last->next = n;
                chead = n;
            }else{
                n->next = temp;
                prev->next = n;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }while(temp != chead);
}
void cDeleteNode(int key){
    if(!chead) return;
    CNode* temp = chead;
    CNode* prev = NULL;
    do{
        if(temp->data == key){
            if(temp == chead){
                CNode* last = chead;
                while(last->next != chead) last = last->next;
                if(chead->next == chead){
                    delete chead;
                    chead = NULL;
                    return;
                }
                chead = chead->next;
                last->next = chead;
                delete temp;
                return;
            }else{
                prev->next = temp->next;
                delete temp;
                return;
            }
        }
        prev = temp;
        temp = temp->next;
    }while(temp != chead);
}
bool cSearchNode(int key){
    if(!chead) return false;
    CNode* temp = chead;
    do{
        if(temp->data == key) return true;
        temp = temp->next;
    }while(temp != chead);
    return false;
}
void cDisplay(){
    if(!chead) return;
    CNode* temp = chead;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != chead);
    cout << chead->data << endl;
}
struct DNode{
    int data;
    DNode* next;
    DNode* prev;
};
DNode* dhead = NULL;
void dInsertFirst(int val){
    DNode* n = new DNode;
    n->data = val;
    n->prev = NULL;
    n->next = dhead;
    if(dhead) dhead->prev = n;
    dhead = n;
}
void dInsertLast(int val){
    DNode* n = new DNode;
    n->data = val;
    n->next = NULL;
    if(!dhead){
        n->prev = NULL;
        dhead = n;
        return;
    }
    DNode* temp = dhead;
    while(temp->next) temp = temp->next;
    temp->next = n;
    n->prev = temp;
}
void dInsertAfter(int key, int val){
    DNode* temp = dhead;
    while(temp){
        if(temp->data == key){
            DNode* n = new DNode;
            n->data = val;
            n->next = temp->next;
            n->prev = temp;
            if(temp->next) temp->next->prev = n;
            temp->next = n;
            return;
        }
        temp = temp->next;
    }
}
void dInsertBefore(int key, int val){
    DNode* temp = dhead;
    while(temp){
        if(temp->data == key){
            DNode* n = new DNode;
            n->data = val;
            n->next = temp;
            n->prev = temp->prev;
            if(temp->prev) temp->prev->next = n;
            else dhead = n;
            temp->prev = n;
            return;
        }
        temp = temp->next;
    }
}
void dDeleteNode(int key){
    DNode* temp = dhead;
    while(temp){
        if(temp->data == key){
            if(temp->prev) temp->prev->next = temp->next;
            else dhead = temp->next;
            if(temp->next) temp->next->prev = temp->prev;
            delete temp;
            return;
        }
        temp = temp->next;
    }
}
bool dSearchNode(int key){
    DNode* temp = dhead;
    while(temp){
        if(temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}
void dDisplay(){
    DNode* temp = dhead;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    int choice, pos, val, key;
    while(1){
        cout << "--- MENU ---";
        cout << "1. Circular Insert";
        cout << "2. Circular Delete";
        cout << "3. Circular Search";
        cout << "4. Circular Display";
        cout << "5. Doubly Insert";
        cout << "6. Doubly Delete";
        cout << "7. Doubly Search";
        cout << "8. Doubly Display";
        cout << "9. Exit";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "1:First 2:Last 3:After 4:Before\nEnter position: ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> val;
                if(pos == 1) cInsertFirst(val);
                else if(pos == 2) cInsertLast(val);
                else if(pos == 3){
                    cout << "After which key? ";
                    cin >> key;
                    cInsertAfter(key, val);
                }else{
                    cout << "Before which key? ";
                    cin >> key;
                    cInsertBefore(key, val);
                }
                break;
            case 2:
                cout << "Enter node to delete: ";
                cin >> key;
                cDeleteNode(key);
                break;
            case 3:
                cout << "Enter node to search: ";
                cin >> key;
                cout << (cSearchNode(key) ? "Found" : "Not Found") << endl;
                break;
            case 4:
                cDisplay();
                break;
            case 5:
                cout << "1:First 2:Last 3:After 4:Before : Enter position: ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> val;
                if(pos == 1) dInsertFirst(val);
                else if(pos == 2) dInsertLast(val);
                else if(pos == 3){
                    cout << "After which key ";
                    cin >> key;
                    dInsertAfter(key, val);
                }else{
                    cout << "Before which key ";
                    cin >> key;
                    dInsertBefore(key, val);
                }
                break;
            case 6:
                cout << "Enter node to delete: ";
                cin >> key;
                dDeleteNode(key);
                break;
            case 7:
                cout << "Enter node to search: ";
                cin >> key;
                cout << (dSearchNode(key) ? "Found" : "Not Found") << endl;
                break;
            case 8:
                dDisplay();
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid choice!";
        }
    }
}


#include <iostream>
#include <climits>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
Node* insert(Node* root, int key) {
    if (!root) 
	return createNode(key);
    if (key < root->data) 
	root->left = insert(root->left, key);
    else if (key > root->data)
	root->right = insert(root->right, key);
    return root;
}
bool searchrecursive(Node* root, int key) {
    if (!root) 
	return false;
    if (root->data == key) 
	return true;
    if (key < root->data) 
	return searchrecursive(root->left, key);
    else
	return searchrecursive(root->right, key);
}
bool searchiterative(Node* root, int key) {
    while (root) {
        if (root->data == key) 
		return true;
        if (key < root->data) 
		root = root->left;
        else
		root = root->right;
    }
    return false;
}
int max(Node* root) {
    if (!root) 
	return INT_MIN;
    while (root->right) 
	root = root->right;
    return root->data;
}
int min(Node* root) {
    if (!root) 
	return INT_MAX;
    while (root->left) 
	root = root->left;
    return root->data;
}
Node* inorderSuccessor(Node* root, Node* node) {
    Node* succ = NULL;
    while (root) {
        if (node->data < root->data)
		{ 
		succ = root; 
		root = root->left;
		}
        else 
		root = root->right;
    }
    return succ;
}
Node* inorderPredecessor(Node* root, Node* node) {
    Node* pred = NULL;
    while (root) {
        if (node->data > root->data)
		{ 
		pred = root; 
		root = root->right;
		 }
        else
		root = root->left;
    }
    return pred;
}
void inordertraversal(Node* root) {
    if (!root) 
	return;
    inordertraversal(root->left);
    cout << root->data << " ";
    inordertraversal(root->right);
}
int main() {
    Node* root = NULL;
    int choice, key;
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    int n = sizeof(values)/sizeof(values[0]);
    for(int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }
    cout << "BST: ";
    inordertraversal(root);
    cout<<endl;
    while (true) {
        cout << "BST Menu ";
        cout << "1. Search (Recursive)\n";
        cout << "2. Search (Iterative)\n";
        cout << "3. Maximum element\n";
        cout << "4. Minimum element\n";
        cout << "5. Inorder Successor\n";
        cout << "6. Inorder Predecessor\n";
        cout << "7. Inorder Traversal\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value to search: ";
                cin >> key;
                cout << (searchrecursive(root, key) ? "Found" : "Not Found") << endl;
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> key;
                cout << (searchiterative(root, key) ? "Found" : "Not Found") << endl;
                break;
            case 3:
                cout << "Maximum element: " << max(root) << endl;
                break;
            case 4:
                cout << "Minimum element: " << min(root) << endl;
                break;
            case 5:
                cout << "Enter node value for successor: ";
                cin >> key;
                {
                    Node* temp = inorderSuccessor(root, createNode(key));
                    if(temp) cout << "In-order Successor: " << temp->data << endl;
                    else cout << "No successor exists\n";
                }
                break;
            case 6:
                cout << "Enter node value for predecessor: ";
                cin >> key;
                {
                    Node* temp = inorderPredecessor(root, createNode(key));
                    if(temp)
					cout << "Inorder Predecessor: " << temp->data << endl;
                    else
					cout << "No predecessor exists";
                }
                break;
            case 7:
                cout << "Inorder Traversal: ";
                inordertraversal(root);
                cout << endl;
                break;
            case 8:
                exit(0);
            default:
                cout << "Invalid choice";
        }
    }
    return 0;
}


#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }
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
Node* findmin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}
Node* deletenode(Node* root, int key) {
    if (!root) {
        cout << "Value " << key << " not found in BST.\n";
        return NULL;
    }
    if (key < root->data) 
        root->left = deletenode(root->left, key);
    else if (key > root->data) 
        root->right = deletenode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findmin(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}
int maxdepth(Node* root) {
    if (!root)
        return 0;
    int l = maxdepth(root->left);
    int r = maxdepth(root->right);
    return max(l, r) + 1;
}
int mindepth(Node* root) {
    if (!root)
        return 0;
    if (!root->left)
        return mindepth(root->right) + 1;
    if (!root->right)
        return mindepth(root->left) + 1;
    return min(mindepth(root->left), mindepth(root->right)) + 1;
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
    while (true) {
        cout << " BST Menu ";
        cout << "1. Insert element\n";
        cout << "2. Delete element\n";
        cout << "3. Maximum depth of BST\n";
        cout << "4. Minimum depth of BST\n";
        cout << "5. Display In-order Traversal\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> key;
                root = insert(root, key);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> key;
                root = deletenode(root, key);
                break;
            case 3:
                cout << "Maximum depth: " << maxdepth(root) << endl;
                break;
            case 4:
                cout << "Minimum depth: " << mindepth(root) << endl;
                break;
            case 5:
                cout << "Inorder Traversal: ";
                inordertraversal(root);
                cout << endl;
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice";
        }
    }
    return 0;
}

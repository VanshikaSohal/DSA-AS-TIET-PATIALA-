#include <iostream>
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
bool check(Node* root, int minVal, int maxVal) {
    if (!root) 
	return true;
    if (root->data <= minVal || root->data >= maxVal) 
	return false;
    return check(root->left, minVal, root->data) && check(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return check(root, INT_MIN, INT_MAX);
}
int main() {
    Node* root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(30);
    root->left->left = createNode(5);
    root->left->right = createNode(15); 
    if (isBST(root))
	cout << "Tree is BST";
    else
	cout << "Tree is NOT BST";
    return 0;
}


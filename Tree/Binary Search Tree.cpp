#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class BST{
public:
    int data;
    BST* left, *right;
public:
    BST(int _data = 0){
        data = _data;
        left = right = NULL;
    }
    bool isEmpty();
    int Length(BST* root);
    void printInorder(BST* root);
    void printPreorder(BST* root);
    void printPostorder(BST* root);
    int getDepth(BST* root);
    BST* Insert(BST*root, int value);
    BST* Delete(BST* root, int value);
    bool findNode(BST* root, int value);
    BST* getMin(BST* root);
    BST* getMax(BST* root);
    int getData(BST* root);
};

// check if binary tree is empty
bool BST::isEmpty(){
    return this == NULL;
}

// get length of binary tree
int BST::Length(BST *root) {
    if(!root)
        return 0;
    return 1 + Length(root -> left) + Length(root -> right);
}

// print binary tree in inorder
void BST::printInorder(BST *root) {
    if(!root)
        return;
    printInorder(root -> left);
    cout << root ->data << " ";
    printInorder(root ->right);
}

// print binary tree in preorder
void BST::printPreorder(BST *root) {
    if(!root)
        return;
    cout << root ->data << " ";
    printPreorder(root -> left);
    printPreorder(root -> right);
}

// print binary tree in postorder
void BST::printPostorder(BST *root) {
    if(!root)
        return;
    printPostorder(root -> left);
    printPostorder(root -> right);
	cout << root ->data << " ";
}

// get depth of binary tree
int BST::getDepth(BST *root) {
    if(!root)
        return 0;
    return 1 + max(getDepth(root -> right), getDepth(root -> left));
}

// insert node to binary tree
BST* BST::Insert(BST* root, int value) {
    if(!root) {
        return new BST(value);
    }
    if(root -> data > value)
        root -> left = Insert(root -> left, value);
    else
        root -> right = Insert(root -> right, value);
    return root;
}

// get minimun value of binary tree
BST* BST::getMin(BST* root) {
    if(!root)
		return root;
	if(!root -> left)
		return root;
	return getMin(root -> left);
}

// get maximum value of binary tree
BST* BST::getMax(BST* root) {
    if(!root)
        return root;
    if(!root -> right)
        return root;
    return getMax(root -> right);
}

// delete node in binary tree
BST* BST:: Delete(BST* root, int value){
    if(!root) 
        return root;
    if(value < root -> data)
        root -> left = Delete(root -> left, value);
    else if(value > root -> data)
        root -> right = Delete(root -> right, value);
    else {
        if(!root -> left && !root -> right) {
            return NULL;
        }
        else if(!root -> left){
            BST* temp = root -> right;
            free(root);
            return temp;
        }else if(!root -> right){
            BST* temp = root -> left;
            free(root);
            return temp;
        }
        BST* temp = getMin(root -> right);
        root -> data = temp -> data;
        root -> right = Delete(root -> right, temp -> data);
    }
    return root;
}

// find node in binary tree
bool BST::findNode(BST* root, int value) {
    if(!root)
        return 0;
    if(root -> data == value)
        return 1;
    if(root -> data > value)
        return findNode(root -> left, value);
    else
        return findNode(root -> right, value);
}

int main()
{
    freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    BST *tree = NULL;
	tree = tree -> Insert(tree, 50);
	tree = tree -> Insert(tree, 30);
	tree = tree -> Insert(tree, 20);
	tree = tree -> Insert(tree, 40);
	tree = tree -> Insert(tree, 70);
	tree = tree -> Insert(tree, 60);
	tree = tree -> Insert(tree, 80);
	cout << "Inorder: ";
	tree -> printInorder(tree);
	cout << endl;
	cout << "Preorder: ";
	tree -> printPreorder(tree);
	cout << endl;
	cout << "Postorder: ";
	tree -> printPostorder(tree);
	cout << endl;
	cout << "Length: " << tree -> Length(tree) << endl;
	cout << "Depth: " << tree -> getDepth(tree) << endl;
	cout << "Min: " << tree ->getMin(tree) -> data << endl;
	cout << "Max: " << tree ->getMax(tree) -> data << endl;
	tree -> Delete(tree, 20);
	tree -> printInorder(tree);
    return 0;
}

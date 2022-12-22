#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class BST{
private:
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

bool BST::isEmpty(){
    return this == NULL;
}
// count size of binary tree
int BST::Length(BST *root) {
    if(!root)
        return 0;
    return 1 + Length(root -> left) + Length(root -> right);
}
void BST::printInorder(BST *root) {
    if(!root)
        return;
    printInorder(root -> left);
    cout << root ->data << " ";
    printInorder(root ->right);
}
void BST::printPreorder(BST *root) {
    if(!root)
        return;
    cout << root ->data << " ";
    printPreorder(root -> left);
    printPreorder(root -> right);
}
void BST::printPostorder(BST *root) {
    if(!root)
        return;
    printPostorder(root -> right);
    printPostorder(root -> left);
    cout << root ->data << " ";
}
int BST::getDepth(BST *root) {
    if(!root)
        return 0;
    return 1 + max(getDepth(root -> right), getDepth(root -> left));
}
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

BST* BST::getMin(BST* root) {
    BST* current = root;
    while (current && current -> left != nullptr) current = current -> left;
    return current;
}
BST* BST::getMax(BST* root) {
    if(!root)
        return root;
    if(!root -> right)
        return root;
    return getMax(root -> right);
}

BST* BST:: Delete(BST* root, int key){
    if(!root) return root;
    if(key < root -> data)
        root -> left = Delete(root -> left, key);
    else if(key > root -> data)
        root -> right = Delete(root -> right, key);
    else {
        if(!root -> left && !root -> right) return NULL;
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
int BST::getData(BST *root) {
    return root -> data;
}
int main()
{
    freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    BST *tree = NULL, obj;
    tree = obj.Insert(tree, 10);
    obj.Insert(tree, 8);
    obj.Insert(tree, 7);
    obj.Insert(tree, 9);
    obj.printPostorder(tree);
    cout << '\n';
    obj.printPreorder(tree);
    cout << '\n';
    obj.printInorder(tree);
    cout << '\n';
    cout << obj.getDepth(tree) << endl;
    cout << obj.Length(tree) << endl;
    cout << obj.findNode(tree, 7) << endl;
    cout << obj.findNode(tree, 11) << endl;
    cout << obj.getData(obj.getMin(tree)) << endl;
    cout << obj.getData(obj.getMax(tree)) << endl;
    obj.Delete(tree, 10);
    obj.printInorder(tree);
    return 0;
}

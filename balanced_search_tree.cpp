#include <iostream>
using namespace std;

struct node{
    int val;
    node *right;
    node *left;

    node(int n){
        val = n;
        right = NULL;
        left = NULL;
    }
};

node* balanced(int arr[], int start, int end){
    if (start > end){
        return NULL;
    }
    int mid = (start + end)/2;
    node *root = new node(arr[mid]);
    root -> left = balanced(arr, start, mid - 1);
    root -> right = balanced(arr, mid+1, end);
    return root;
}

void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int arr[] = {10,20,30,40,50};
    node* root = balanced(arr, 0, 4);
    preorder(root);
    cout<<endl;
    return 0;
}
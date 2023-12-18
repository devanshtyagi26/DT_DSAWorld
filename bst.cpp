#include <iostream>
#include <queue>
using namespace std;

struct node {
    int val;
    struct node* right;
    struct node* left;

    node(int n) {
        val = n;
        right = left = NULL;
    }
};

node* insertBST(node* root, int n) {
    if (root == NULL) {
        return new node(n);
    }

    if (n < root->val) {
        root->left = insertBST(root->left, n);
    } else {
        root->right = insertBST(root->right, n);
    }

    return root;
}

node* findMin(node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

node* deleteBST(node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->val) {
        root->left = deleteBST(root->left, value);
    } else if (value > root->val) {
        root->right = deleteBST(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the in-order successor (smallest
        // in the right subtree) or predecessor (largest in the left subtree)
        node* temp = findMin(root->right);

        // Copy the in-order successor's value to this node
        root->val = temp->val;

        // Delete the in-order successor
        root->right = deleteBST(root->right, temp->val);
    }

    return root;
}

node* searchAndUpdateBST(node* root, int x, int y) {
    // Step 1: Delete the node with value x
    root = deleteBST(root, x);

    // Step 2: Insert the node with updated value y
    root = insertBST(root, y);

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

void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void levelOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
        q.pop();

        cout << current->val << " ";

        if (current->left != NULL) {
            q.push(current->left);
        }

        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

int getHeight(node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    node* root = NULL;
    root = insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 5);
    insertBST(root, 7);
    insertBST(root, 8);
    insertBST(root, 3);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    int valueToDelete;
    cout << "Enter the value to delete: ";
    cin >> valueToDelete;

    root = deleteBST(root, valueToDelete);

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl << endl;   

    cout << "Inorder traversal before update: ";
    inorder(root);
    cout << endl;

    int x, y;
    cout << "Enter the value x to search and update: ";
    cin >> x;
    cout << "Enter the new value y: ";
    cin >> y;

    root = searchAndUpdateBST(root, x, y);

    cout << "Inorder traversal after update: ";
    inorder(root);
    cout << endl << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl << endl;

    cout << "Level-by-level traversal: ";
    levelOrderTraversal(root);
    cout << endl<<endl;
    cout << "Height of the BST: " << getHeight(root) << endl;
    return 0;
}

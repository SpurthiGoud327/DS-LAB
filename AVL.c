// C program to implement AVL Tree
#include <stdio.h>
#include <stdlib.h>

// Structure for an AVL Tree node
struct Node
{
int key;
struct Node* left;
struct Node* right;
int height;
};
// Function to get the height of a node
int getHeight(struct Node* n)
{
if (n == NULL)
return 0;
return n->height;
}
// Function to create a new AVL tree node
struct Node* createNode(int key)
{
struct Node* node = (struct Node*)malloc(sizeof(struct Node));
node->key = key;
node->left = NULL;
node->right = NULL;
node->height = 1; // New node is initially a leaf
return node;
}
// Function to get the maximum of two integers
int max(int a, int b)
{
return (a > b) ? a : b;
}

// Function to get the balance factor of a node
int getBalanceFactor(struct Node* n)
{
if (n == NULL)
return 0;
return getHeight(n->left) - getHeight(n->right);
}
// Function to perform a right rotation
struct Node* rightRotate(struct Node* y)
{
struct Node* x = y->left;
struct Node* T2 = x->right;
// Perform rotation
x->right = y;
y->left = T2;
// Update heights
y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
// Return new root
return x;
}
// Function to perform a left rotation
struct Node* leftRotate(struct Node* x)
{
struct Node* y = x->right;
struct Node* T2 = y->left;
// Perform rotation
y->left = x;
x->right = T2;

// Update heights
x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
// Return new root
return y;
}
// Function to insert a key into the AVL tree
struct Node* insert(struct Node* node, int key)
{
// Perform normal BST insertion
if (node == NULL)
return createNode(key);
if (key < node->key)
node->left = insert(node->left, key);
else if (key > node->key)
node->right = insert(node->right, key);
else
return node; // Duplicate keys not allowed
// Update height of this ancestor node
node->height = 1 + max(getHeight(node->left), getHeight(node->right));
// Get the balance factor to check for imbalance
int balance = getBalanceFactor(node);

// Perform rotations based on imbalance type
// Left Left Case
if (balance > 1 && key < node->left->key)
return rightRotate(node);
// Right Right Case
if (balance < -1 && key > node->right->key)
return leftRotate(node);
// Left Right Case
if (balance > 1 && key > node->left->key)
{
node->left = leftRotate(node->left);
return rightRotate(node);
}
// Right Left Case
if (balance < -1 && key < node->right->key)
{
node->right = rightRotate(node->right);
return leftRotate(node);
}
// Return the unchanged node pointer
return node;
}
// Function for inorder traversal (Left, Root, Right)
void inOrder(struct Node* root)
{
if (root != NULL)
{
inOrder(root->left);
printf("%d ", root->key);
inOrder(root->right);

}
}
// Main function to test AVL Tree operations
int main()
{
struct Node* root = NULL;
// Insert nodes into the AVL tree
root = insert(root, 1);
root = insert(root, 2);
root = insert(root, 4);
root = insert(root, 5);
root = insert(root, 6);
root = insert(root, 3);
// Display the inorder traversal
printf("Inorder traversal of AVL tree: ");
inOrder(root);
return 0;
}

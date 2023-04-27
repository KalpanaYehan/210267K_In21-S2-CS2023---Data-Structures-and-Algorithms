#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == NULL)
    return;
  
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
  // If the tree is empty, return a new node
  if (root == NULL) {
    struct node *newnode = new node;
    newnode->key = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
  }
  
  else if (key < root->key) {
    root->left = insertNode(root->left, key);
  }
  else if (key > root->key) {
    root->right = insertNode(root->right, key);
  }
  // Return the  node pointer
  return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Base case
  if (root == NULL) {
    return root;
  }
  //if the key that need to be deleted, is smaller than the root's key
  //then it is in the left subtree
  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  }
  
  //if the key that need to be deleted, is greater  than the root's key
  //then it is in the right subtree
  else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  }
  // If key is same as root's key, then this is the node to be deleted
  else {
    // Node with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root->left;
      delete root;
      return temp;
    }
    
    // Node with two children: Get the inorder successor
    struct node *temp = root->right;
    while (temp->left != NULL) {
      temp = temp->left;
    }
    
    // Copy the inorder successor's content to this node
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
  
  return 0;
}

#include <iostream>
using namespace std;

struct Node {
  int key;
  struct Node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct Node *root) {
  if (root != NULL) {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }
}

// Insert a node
struct Node *insertNode(struct Node *root, int key) {
  if (root == NULL) {
    struct Node *newNode = new Node;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }

  if (key < root->key) {
    root->left = insertNode(root->left, key);
  } else if (key > root->key) {
    root->right = insertNode(root->right, key);
  }

  return root;
}

struct Node *findMinNode(struct Node *root) {
  struct Node *current = root;

  while (current && current->left != NULL) {
    current = current->left;
  }

  return current;
}

// Deleting a node
struct Node *deleteNode(struct Node *root, int key) {
  if (root == NULL) {
    return root;
  }

  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  } else {

    if (root->left == NULL) {
      struct Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct Node *temp = root->left;
      free(root);
      return temp;
    }

    struct Node *temp = findMinNode(root->right);

    root->key = temp->key;

    root->right = deleteNode(root->right, temp->key);
  }

  return root;
}

// Driver code
int main() {
  struct Node *root = NULL;

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

}

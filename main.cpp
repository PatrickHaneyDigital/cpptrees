#include <iostream>

using namespace std;

struct BstNode {
  int data;
  BstNode* left;
  BstNode* right;
};

BstNode* CreateLeaf(int data) {
  BstNode* newNode = new BstNode();
  newNode->data = data;
  newNode->left=newNode->right=NULL;
  return newNode;
}

BstNode* InsertLeaf(BstNode* root, int data) {
  if (root == NULL) {
    root = CreateLeaf(data);
  }
  else if (data <= root->data) {
    root->left = InsertLeaf(root->left, data);
  }
  else {
    root->right = InsertLeaf(root->right, data);
  }
  return root;
}

bool SearchTreeWithTraversal(BstNode* root, int data) {
  if (root == NULL) {
    cout << "Did not find :(" << endl;
    return false;
  }
  else if (data == root->data) {
    cout << "Found " << data << "!";
    return true;
  }
  else if (data <= root->data) {
    cout << "Searched " << root->data << endl;
    return SearchTreeWithTraversal(root->left, data);
  }
  else {
    cout << "Searched " << root->data << endl;
    return SearchTreeWithTraversal(root->right, data);
  }
}

int main(){
  BstNode* root = InsertLeaf(root,5);
  InsertLeaf(root,10);
  InsertLeaf(root,9);
  InsertLeaf(root,8);
  int number;
  cout << "Insert a number to search the tree with: ";
  cin >> number;
  SearchTreeWithTraversal(root, number);
}

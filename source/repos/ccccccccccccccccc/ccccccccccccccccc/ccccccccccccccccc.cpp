//Nguyen Kim Linh
//20233495
//               ..╱ | 、 ♡
//               (˚ˎ 。7      ⋆
//                | 、˜〵
//                じしˍ, )ノ
               
#include <iostream> 
#include <string>
#include <iomanip>
using namespace std;

#define TVALUE int
struct Node {
    TVALUE data;
    Node* left;
    Node* right;

    Node(TVALUE value) {
        data = value;
        left = right = NULL;
    }
};

Node* createNode(TVALUE data) {
    return new Node(data);
}

void insertNode(Node*& root, TVALUE data) {
    if (root == NULL) {
        root = createNode(data);
        return;
    }
    if (root->left == NULL)
        insertNode((root)->left, data);
    else if (root->right == NULL)
        insertNode(root->right, data);
    else
        insertNode(root->left, data);
}

/*
    Preorder - M L R
    Inorder - L M R
    Postorder - L R M
*/
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    preorder(root->left);
    preorder(root->right);
    cout << root->data << " ";
}
int main() {
    Node* root = createNode(1);
    insertNode(root, 10);
    insertNode(root, 9);
    insertNode(root, 7);
    insertNode(root, 15);
    insertNode(root, 15);
    preorder(root);
}

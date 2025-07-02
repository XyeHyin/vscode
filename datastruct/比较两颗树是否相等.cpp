#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool dfs(Node *root1, Node *root2) {
    if (root1 == nullptr && root2 == nullptr)return true;
    if (root1 == nullptr || root2 == nullptr)return false;
    if (root1->data != root2->data)return false;
    return dfs(root1->left, root2->left) && dfs(root1->right, root2->right);
}
int main() {
    Node *tree1 = new Node(1);
    tree1->left = new Node(2);
    tree1->right = new Node(3);
    tree1->left->left = new Node(4);
    tree1->left->right = new Node(5);
    Node *tree2 = new Node(1);
    tree2->left = new Node(2);
    tree2->right = new Node(3);
    tree2->left->left = new Node(4);
    tree2->left->right = new Node(5);
    if (dfs(tree1, tree2)) cout << "两棵二叉树相等" << endl;
    else cout << "两棵二叉树不相等" << endl;
    return 0;
}
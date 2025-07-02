#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int val) : val(val), left(0), right(0) {}
};

int dfs(Node *root) {
    if (root == 0)
        return 0;
    if (root->left == 0 && root->right == 0)
        return 1;
    return dfs(root->left) + dfs(root->right);
}

int main() {
    // 创建一个示例树
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    int leafCount = dfs(root);
    cout << "叶节点数量: " << leafCount << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

vector<int> path; // 全局变量

bool findPath(Node *root, int p) {
    if (root == nullptr)
        return false;
    path.push_back(root->val);
    if (root->val == p)
        return true;
    if ((root->left && findPath(root->left, p)) ||
        (root->right && findPath(root->right, p))) {
        return true;
    }
    path.pop_back();
    return false;
}

void printPath(Node *root, int p) {
    if (findPath(root, p)) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    } else {
        cout << "节点 " << p << " 不在树中" << endl;
    }
}

int main() {
    // 创建一个示例树
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int p = 5; // 指定节点
    printPath(root, p);

    return 0;
}
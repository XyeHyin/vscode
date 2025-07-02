#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> &postorder, int &index, int n) {
    if (index < 0)
        return NULL;
    TreeNode *root = new TreeNode(postorder[index--]);
    if (index >= 0)
        root->right = buildTree(postorder, index, n);
    if (index >= 0)
        root->left = buildTree(postorder, index, n);
    return root;
}

void preorder(TreeNode *root, vector<int> &result) {
    if (!root)
        return;
    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}

void postorder(TreeNode *root, vector<int> &result) {
    if (!root)
        return;
    postorder(root->right, result);
    postorder(root->left, result);
    result.push_back(root->val);
}

int countRedBeans(TreeNode *root, unordered_set<int> &redBeans) {
    if (!root)
        return 0;
    int count = redBeans.count(root->val) ? 1 : 0;
    count += countRedBeans(root->left, redBeans);
    count += countRedBeans(root->right, redBeans);
    return count;
}

bool removeNode(TreeNode *&root, int val) {
    if (!root)
        return false;
    if (root->val == val) {
        root = NULL;
        return true;
    }
    return removeNode(root->left, val) || removeNode(root->right, val);
}

int main() {
    int N, K;
    cin >> N;
    vector<int> postorder(N);
    for (int i = 0; i < N; ++i)
        cin >> postorder[i];
    cin >> K;
    vector<int> picks(K);
    for (int i = 0; i < K; ++i)
        cin >> picks[i];

    int index = N - 1;
    TreeNode *root = buildTree(postorder, index, N);

    unordered_set<int> redBeans(postorder.begin(),
                                postorder.begin() + (N + 1) / 2);
    unordered_set<int> removedNodes;

    for (int pick : picks) {
        if (removedNodes.count(pick)) {
            cout << "Zao Jiu Cai Diao Le!" << endl;
        } else if (!removeNode(root, pick)) {
            cout << "Kan Qing Chu Le?" << endl;
        } else {
            removedNodes.insert(pick);
            cout << countRedBeans(root, redBeans) << endl;
        }
    }

    vector<int> result;
    preorder(root, result);
    if (result.empty()) {
        cout << "Kong Le!" << endl;
    } else {
        for (int i = 0; i < result.size(); ++i) {
            if (i > 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;
    }

    return 0;
}
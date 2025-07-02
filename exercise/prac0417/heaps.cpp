#include <bits/stdc++.h>
using namespace std;

vector<int> tree;
vector<int> postOrder;
int n;

void PostOrder(int index)
{
    if (index >= n)
        return;
    PostOrder(index * 2 + 1);
    PostOrder(index * 2 + 2);
    postOrder.push_back(tree[index]);
}

int main()
{
    int m;
    cin >> m >> n;
    while (m--)
    {
        tree.resize(n);
        postOrder.clear();
        for (int i = 0; i < n; i++)
            cin >> tree[i];
        PostOrder(0);
        bool isMax = true, isMin = true;
        for (int i = 0; i < n; i++)
        {
            if ((i * 2 + 1 < n && tree[i] < tree[i * 2 + 1]) || (i * 2 + 2 < n && tree[i] < tree[i * 2 + 2]))
                isMax = false;
            if ((i * 2 + 1 < n && tree[i] > tree[i * 2 + 1]) || (i * 2 + 2 < n && tree[i] > tree[i * 2 + 2]))
                isMin = false;
        }
        if (isMax) cout << "Max Heap\n";
        else if (isMin) cout << "Min Heap\n";
        else cout << "Not Heap\n";
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                cout << " ";
            cout << postOrder[i];
        }
        cout << "\n";
    }
    return 0;
}
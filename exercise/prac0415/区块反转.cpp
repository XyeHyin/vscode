#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int address, data, next;
    int order;
};

int main()
{
    int first = 0, n = 0, k = 0, address = 0;
    cin >> first >> n >> k;
    vector<Node> node(100000);
    for (int i = 0; i < n; i++)
    {
        cin >> address;
        node[address].address = address;
        cin >> node[address].data >> node[address].next;
    }
    int p = first;
    vector<Node> nodes;
    while (p != -1)
    {
        nodes.push_back(node[p]);
        p = node[p].next;
    }
    for (int i = 0; i < nodes.size() / k; i++)
    {
        reverse(nodes.begin() + i * k, nodes.begin() + (i + 1) * k);

    }
    reverse((nodes.end()-nodes.size()%k) , nodes.end());
    reverse(nodes.begin(), nodes.end());
    for (int i = 0; i < nodes.size() - 1; i++)
    {
        nodes[i].next = nodes[i + 1].address;
    }
    nodes[nodes.size() - 1].next = -1;
    for (int i = 0; i < nodes.size(); i++)
    {
        if (nodes[i].next != -1)
        {
            printf("%05d %d %05d\n", nodes[i].address, nodes[i].data, nodes[i].next);
        }
        else
        {
            printf("%05d %d %d\n", nodes[i].address, nodes[i].data, nodes[i].next);
        }
        }
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> base(n);
    vector<int> sum(n);
    for (int i = 0; i < sum.size(); i++)
    {
        cin >> base[i];
        for (int j = 0; j < base[i].size();j++){
            sum[i] += base[i][j] - '0';
        }
    }
    set<int> ans;
    for (int i = 0; i < sum.size(); i++)
    {
        ans.insert(sum[i]);
    }
    std::cout << ans.size()<<endl;
    for (auto i = ans.begin(); i != ans.end(); i++){
        if (i != ans.begin()) std::cout << " ";
       std:: cout << *i;
    }
       std:: cout << endl;
}
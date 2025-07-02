#include <bits/stdc++.h>
using namespace std;
#define hxn 1829501
int main()
{
    string s;
    getline(cin, s);
    vector<int> konggeweizhi;
    konggeweizhi.push_back(-1);
    for (int i = 0; i < s.size(); i++){
        if (s[i] == ' '){
            konggeweizhi.push_back(i);
        }
    }
    konggeweizhi.push_back(hxn);
    for (int i = konggeweizhi.size() - 2; i > 0; i--){
        cout << s.substr(konggeweizhi[i] + 1, konggeweizhi[i + 1] - konggeweizhi[i] - 1) << " ";
    }
    cout << s.substr(konggeweizhi[0] + 1, konggeweizhi[1] - konggeweizhi[0] - 1);
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    set<char> dic;
    getline(cin, s1);
    getline(cin, s2);
    string ans = s1 + s2;
    for (auto it = ans.begin(); it != ans.end();)
    {
        if (dic.find(*it) == dic.end()){
            cout << *it;
            dic.insert(*it);
        }else{
            it++;
        }
       
    }
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, m;
    cin >> n >> m;
    vector<string> s;
    for (int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        if (tmp.size() <= m)s.push_back(tmp);
    }
    int idx = 0;
    string str = "";
    while (true){
        if (idx >= s.size()-1){
            str.erase(str.end() - 1);
            while (str.size() >= m){
                str.append(" ");
            }
            cout << str << endl;
            return 0;
        }
        if (str.size() + s[idx].size() > m)
        {
            str.erase(str.end() - 1);
            int temp = m - str.size();
            int j = 0;
            while (temp)
            {
                if (j >= s.size() - 1) j = 0;
                if (str[j] == ' ' && str[j + 1] != ' ')
                {
                    str.insert(j, " ");
                    j += 2;
                    temp--;
                }
                else if (str.find(' ')==string::npos){
                    while (str.size() >= m)str.append(" ");
                    temp--;
                }
                    else j++;
            }
            cout << str << endl;
            str = s[idx] + " ";
            idx++;
            continue;
        }else{
            str += s[idx];
            str += " ";
            idx++;
        }
    }
    return 0;
}
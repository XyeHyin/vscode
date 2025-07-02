#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, m;
    cin >> n >> m;
    string str = "";
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        bool flag=0;
        if(s.size()>n&&i==n-1){
            str.erase(str.end() - 1);
            while (str.size() != m){
                str.append(" ");
            }
            cout << str << endl;
            return 0;
        }
        if(s.size()>n) continue;
            if (str.size() + s.size() > m){
                str.erase(str.end() - 1);
                int temp = m - str.size();
                int j = 0;
                while (temp){
                    if (j >= n - 1)
                        j = 0;
                    if (str[j] == ' ' && str[j + 1] != ' '){
                        str.insert(j, " ");
                        j +=2;
                        temp--;
                    }
                    else j++;
                }
                cout << str << endl;
                str = s+" ";
            }else{
                str += s;
                str += " ";
            }
            if (i == n - 1){
                str.erase(str.end() - 1);
                while (str.size() != m)
                {
                    str.append(" ");
                }
                cout << str << endl;
                return 0;
            }
    }
    return 0;
}
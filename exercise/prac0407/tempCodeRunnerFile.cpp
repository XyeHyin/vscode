#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, ans;
    string n1, n2;
    cin >> s >> n1 >> n2;
    if (n1.size() < n2.size())
    {
        n1.insert(0, n2.size() - n1.size(), '0');
    }
    else if (n1.size() > n2.size())
    {
        n2.insert(0, n1.size() - n2.size(), '0');
    }
    if(s.size()<n1.size()){
        s.insert(0,n1.size()-s.size(),'0');
    }
    int jinWei = 1;
    for (int i = n1.size() - 1; i >= 0; i--)
    {
        int n = n1[i] - '0' + n2[i] - '0' + jinWei-1;
        jinWei = 0;
        int radix = s[i] == '0' ? 10 : s[i] - '0';
        bool flag = false;
        while (n != 0)
        {
            if(!flag){
           ans.insert(0,to_string(n % radix));
              flag = true;
        }
            n /= radix;
            jinWei++;
        }
    }
    if (jinWei!=-1)
    {
        ans.insert(0, to_string(jinWei));
    }
    int flag = 0;
    if(ans.empty()){
        cout << "0";
    }else{
        for (int i = 0; i < ans.size();i++){
              if(ans[i]!=0){
                  flag = i+1;
                  break;
              }
        }
        for (int i = flag; i < ans.size();i++)
            cout << ans[i];
    }
}

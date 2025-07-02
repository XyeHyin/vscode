#include <bits/stdc++.h>
using namespace std;
int main(){
    int count=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        count+=(s[i]-'0');
    }
    string hanzi[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    string ans=to_string(count);
    for(int i=0;i<ans.size();i++){
        if(i!=0){
            cout<<" ";
        }
        cout<<hanzi[ans[i]-'0'];
    }
}
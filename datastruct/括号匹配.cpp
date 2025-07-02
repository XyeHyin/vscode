#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(cin>>s){
    stack<char> st;
    for (int i = 0;i<s.size();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'||(s[i]=='/'&&s[i+1]=='*')){
            st.push(s[i]);
            if(s[i]=='/'&&s[i+1]=='*'){
                st.push(s[i+1]);
                i++;
            }
        }else{
            if(st.empty()){
                cout << "NO" << endl;
                return 0;
            }
            if(s[i]==')'&&st.top()=='('){
                st.pop();
            }else if(s[i]==']'&&st.top()=='['){
                st.pop();
            }else if(s[i]=='}'&&st.top()=='{'){
                st.pop();
            }else if(s[i]=='*'&&s[i+1]=='/'&&st.top()=='*'){
                st.pop();
                st.pop();
                i++;
            }
        }
    }
    if(st.empty()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    }
        return 0;
}
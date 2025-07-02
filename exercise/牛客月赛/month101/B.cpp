#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> st;
    st.push(s[0]);
    for(int i = 1; i < n; i++){
        if(!st.empty()&&st.top()=='f'&&s[i]=='c'){
            st.pop();
        }else if(!st.empty()&&st.top()=='t'&&s[i]=='b'){
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    cout << st.size() << endl;
    return 0;
}
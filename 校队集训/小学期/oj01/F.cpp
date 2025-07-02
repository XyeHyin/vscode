#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    int cntn = 0, cntm = 0;
    string cntnn="", cntmm="";
    if(s2.substr(0,n)==s1){
        cntn = 1;
    }
    if(s2.substr(s2.size()-n,n)==s1){
        cntm = 1;
    }
    if(cntn+cntm==2){
        cout << 0 << endl;
        return 0;
    }else if(cntn==1&&cntm==0){
        cout << 1 << endl;
        return 0;
    }else if(cntn==0&&cntm==1){
        cout << 2 << endl;
        return 0;
    }else if(cntn+cntm==0){
       cout<<3<<endl;
    }


        return 0;
}
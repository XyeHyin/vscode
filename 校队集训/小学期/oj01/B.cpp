#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1, s2;
    cin>>s1>>s2;
    
    if(s2=="jin"){
        cout << "wow You got a golden shovel shovel !" << endl;
    }
    if(s1=="lh"&&s2!="jin"){
        cout << "mystery guest !" << endl;
    }else if(s1!="lh"&&s2!="jin"){
        cout << "regrettably" << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    if(s.size() %2!=0){
        printf("Error: %d digit(s)", s.size()); 
        return 0;
    }
    int pos=s.size()/2;
    string s1 = s.substr(0, pos);
    string s2 = s.substr(pos, pos);
    bool flag = false;
    for (int i = 0; i < s1.size() - 1;i++){
         if(s1[i]!=s2[i]){
            flag = true;
            break;
         }
    }
        if ((s2[s2.size() - 1] - '0') - (s1[s1.size() - 1] - '0') == 2&&!flag)
        {
            printf("Yes : %s - %s = 2", s2.c_str(), s1.c_str());
            return 0;
        }
        else
        {
            printf("No : %s - %s != 2", s2.c_str(), s1.c_str());
            return 0;
        }
}
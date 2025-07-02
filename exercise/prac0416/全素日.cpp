#include <bits/stdc++.h>
using namespace std;
bool isprime(int x)
{
    if (x == 1 || x == 0)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
int main(){
    string s;
    cin >> s;
    bool flag=true;
    int len = s.size();
    for (int i = 0; i < len;i++){
        cout << s << " ";
        if(isprime(stoi(s))){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
            flag = false;
        }
        s.erase(0, 1);
    }
    if(flag) cout<<"All Prime!"<<endl;
    return 0;
}
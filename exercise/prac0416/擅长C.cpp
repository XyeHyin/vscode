#include <bits/stdc++.h>
using namespace std;
int main(){
    char c[26][7][5]={0};
    for (int i = 0; i < 26;i++){
        for (int j = 0; j < 7;j++){
            for (int k = 0; k < 5;k++){
              cin>>c[i][j][k];
            }
        }
    }
    string s;
    cin >> s;
    vector<int> vec;
    for (int i = 0; i < s.size();i++){
        if(s[i]>='A'&&s[i]<='Z'){
         vec.push_back(i);        
    }
    }
    for (int j = 0; j < 7;j++){
        for (int i = 0; i < s.size(); i++)
        {
            for(int j=0;j<5;j++){
                cout << c[s[i] - 'A'][j][i] << " ";
            }
            cout << endl;
        }
        cout << endl;
        }
}
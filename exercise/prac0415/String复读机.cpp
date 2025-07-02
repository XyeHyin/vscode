#include <bits/stdc++.h>
using namespace std;
string dicnary = "String";
int main(){
    string s;
    cin >> s;
    vector<int> arr(6,0);
    for (int i = 0; i < s.size();i++){
        if(dicnary.find(s[i]) != string::npos){
           arr[dicnary.find(s[i])]++;
        }
    }
    while(true){
        for (int i = 0; i < 6;i++){
            if(arr[i]>0){
                cout << dicnary[i];
                arr[i]--;
            }
            if (all_of(arr.begin(), arr.end(), [](int i){ return i == 0; }))
            {
                return 0;
            }   
    }
}
cout << endl;
return 0;
}
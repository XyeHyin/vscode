#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    int x;
    cin >> x;
    vector<int> arr;
    int position;
    for (int i = 1; i < s.size();i++){
         if(s[i]==','){
             arr.push_back(s[i - 1] - '0');
             position = i;
         }
    }
    arr.push_back(stoi(s.substr(position+1, s.size() - position)));
    int sum = 0;
    for (int i = 0; i < arr.size();i++){
        sum += arr[i] * pow(x,i);
    }
    cout << sum;
}
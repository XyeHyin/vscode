#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> day;
    int i = 1;
    while(day.size()<n){
        for(int j=0;j<i;j++){
            day.push_back(i);
            if(day.size()>=n)break;
        }
        i++;
    }
    cout<<accumulate( day.begin(), day.end(), 0 );
        return 0;
}
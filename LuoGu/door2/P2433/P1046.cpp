#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> apples(10);
    for (int i = 0; i < 10;i++){
        cin >> apples[i];
    }
    int h;
    cin >> h;
    h += 30;
    int count = 0;
    for (int i = 0; i < 10;i++){
        if(apples[i]<=h){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
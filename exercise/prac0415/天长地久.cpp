#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    for (int i = 0; i < N;i++){
        int k, m, n, a;
        cin >> k >> m;
        if(m/k>9){
            cout << "No Solution" << endl;
            continue;
        }
        vector<int> arr;
        for (int j = 2; j < m;j++){
            if(__gcd(j,m)>2){
                arr.push_back(j);
            }
        }
        for (int i = 0; i < arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout << endl;
    }
}   
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    unordered_map<int, int> count;
    int ans = 0;
    for (int i = 0; i < n; i++){
        count[a[i]]++;
        if (i >= k){
            if (count[a[i - k]] == 1){
                count.erase(a[i - k]);
            }else{
                count[a[i - k]]--;
            }
        }
        if (count.size() == k){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
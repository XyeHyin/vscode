#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second=i;
    }
    sort(a.begin(), a.end(),[](pair<int,int> a,pair<int,int> b){
        return a.first<b.first;
    });
    for(int i=0,j=a.size()-1;i<j;){
       if(a[i].first+a[j].first==k){
           cout<<min(a[i].second,a[j].second)<<" "<<max(a[i].second,a[j].second)<<endl;
           return 0;
       }else if(a[i].first+a[j].first<k){
           i++;
       }else{
           j--;
       }
    }
    cout<<-1<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second > b.second;
}
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[i].first = a;
        s.insert(a);
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[i].second = a;
    }
    sort(v.begin(),v.end(),cmp);
    v.erase(v.begin()+s.size(),v.end());
    int sum = 0;
    for(int i = 0;i<n;i++){
            sum += v[i].second;
        
    }
    std::cout << sum << endl;
    return 0;
}
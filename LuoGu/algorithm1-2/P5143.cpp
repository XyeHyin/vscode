#include <bits/stdc++.h>
using namespace std;
struct clamber{
    int x, y,z;
};
int main(){
    int n;
    cin >> n;
    vector<clamber> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    sort(a.begin(),a.end(),[](clamber a,clamber b){
        return a.z < b.z;
    });
    double ans = 0;
    for (int i = 1;i<n;i++){
        ans += sqrt(pow(a[i].x - a[i - 1].x, 2) + pow(a[i].y - a[i - 1].y, 2)+pow(a[i].z - a[i - 1].z, 2));
    }
    cout << fixed << setprecision(3) << ans;
        return 0;
}
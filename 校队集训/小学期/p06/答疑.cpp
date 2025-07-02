#include <bits/stdc++.h>
using namespace std;
#define int long long
int summing=0;
struct student{
    long long s, a, e, sum,sum2;
};
bool cmp(student a, student b){
        return a.sum < b.sum;
}

signed main(){
    int n;
    cin >> n;
    vector<student> v(n);
    for (int i = 0;i<n;i++){ 
        cin >> v[i].s >> v[i].a >> v[i].e;
        v[i].s /= 1000;v[i].a /= 1000;v[i].e /= 1000;
        v[i].sum = v[i].s + v[i].a;
        v[i].sum2 = v[i].s + v[i].a + v[i].e;
    }
   sort(v.begin(), v.end(), cmp);
    vector<int> ans;
    summing += v[0].s + v[0].a;
    int answe=v[0].s + v[0].a;
    for (int i = 1; i < n;i++){
        summing += v[i].s + v[i].a+v[i-1].e;
        answe+=summing;
        }
    answe *= 1000;
    cout << answe;
    

        return 0;
}
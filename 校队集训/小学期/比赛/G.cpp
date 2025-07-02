#include <bits/stdc++.h>
using namespace std;
struct aa{

    string id;
    int n;
};
bool cmp(aa a, aa b) { return a.n > b.n; }
int main(){
    int n;
    cin >> n;
    vector<aa> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i].id >> a[i].n;
    }
    sort(a.begin(), a.end(), cmp);

    for (int i = 0; i < n;i++){
        cout << a[i].id << endl;
    }
        return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c, d,e;
    cin >> a >> b>>c>>d>>e;
    int tmp=c+d+e;
    if(!tmp){
        cout << "冠军是百灵鸟老师: "<<a<<"+"<<3<<endl;
        return 0;
    }else if(c+d+e==3){
        cout<<"冠军是小黄莺老师: "<<b<<"+"<<3<<endl;
        return 0;
    }
    if(a>b&&tmp<3){
        cout << "冠军是百灵鸟老师: "<<a<<"+"<<3-tmp<<endl;
    }else if(a<b&&tmp>0){
        cout<<"冠军是小黄莺老师: "<<b<<"+"<<tmp<<endl;
    }

    return 0;
}
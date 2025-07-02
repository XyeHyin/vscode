#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    ll gongbeishu = 1;
    ll fenzi = 0;
    ll gongyueshu = -1;
    bool flag = false;
    bool havezheng = false;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++){
        scanf("%lld/%lld", &a[i], &b[i]);
    }
    for (int i = 0; i < n; i++){
        gongbeishu *= b[i];
    }
    for (int i = 0; i < n; i++){
        fenzi +=(ll)(a[i] * gongbeishu / b[i]);
    }
    ll fenzi1 = fenzi;
    if (fenzi % gongbeishu != 0)
    {
        ll temp = gongbeishu;
        while (temp != 0)
        {
            ll remainder = fenzi1 % temp;
            fenzi1 = temp;
            temp = remainder;
        }
        gongyueshu = fenzi1;
        flag = true;
    }
    else
    {
        gongyueshu = gongbeishu;
    }
    ll keyuefenzi = (fenzi % gongbeishu) / gongyueshu;
    ll keyuefenmu = gongbeishu / gongyueshu;
    ll buyuefenzi = (fenzi % gongbeishu);
    ll buyuefenmu = gongbeishu;
    if ((int)fenzi / gongbeishu != 0){
        cout << int(fenzi / gongbeishu) << " ";
    }
    if ((fenzi < 0 && gongbeishu > 0) || (fenzi > 0 && gongbeishu < 0)){
        cout << '-';
    }
    if (flag){
        if (havezheng){
            cout << ' ';
        }
        if (keyuefenzi != 0){
            cout << abs(keyuefenzi) << "/" << abs(keyuefenmu) << endl;
        }
    }
    else{
        if (havezheng){
            cout << ' ';
        }
        if (buyuefenzi != 0){
            cout << abs(buyuefenzi) << "/" << abs(buyuefenmu) << endl;
        }
    }
}
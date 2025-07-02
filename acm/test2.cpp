#include <bits/stdc++.h>
using namespace std;
struct XyeHyin{
    string name;
    int pv, v;
};
int main(){
    int n;
    cin >> n;
    vector<XyeHyin> a(n);   
    for(int i = 0; i < n; i++){
        cin >> a[i].name >> a[i].pv >> a[i].v;
    }
    int ans = 0;
    bool flag = false;
    string lsyname = "";
    pair<string,string> hxnname;
    do{
    int anslsy = 0, anshxn = 0;
    anslsy+=a[0].pv*2;
    for(int i = 1; i < n; i++){
        anslsy+=a[i].v;
    }
    anshxn+=a[0].pv;
    anshxn+=a[n-1].v*2;
    for(int i = 1; i < n-1; i++){
        anshxn+=a[i].v;
    }
    int tmp = ans;
    if(anslsy>=ans&&anshxn>=ans){
        if(anslsy>=anshxn){
            ans = anslsy;
            lsyname = a[0].name;
            flag = true;
        }else{
            ans = anshxn;
            hxnname = {a[0].name, a[n-1].name};
            flag = false;
        }
        continue;
    }
    if(anslsy>=ans){
        ans = anslsy;
        lsyname = a[0].name;
        flag = true;
    }else if(anshxn>=ans){
        ans = anshxn;
        hxnname = {a[0].name, a[n-1].name};
        flag = false;
    }
    }while(next_permutation(a.begin(), a.end(), [](XyeHyin a, XyeHyin b){
        return a.name<b.name;
    }));
    if(flag){
        cout << "LSY" << endl;
        cout << ans << endl;
        cout << lsyname << endl;
        for (int i = 0;i<n;i++){
            if(a[i].name == lsyname){
                a.erase(a.begin()+i);
                break;
            }
        }
        sort(a.begin(), a.end(), [](XyeHyin a, XyeHyin b){
            return a.name<b.name;
        });
        for(int i = 0; i < n-1; i++){
            cout << a[i].name << endl;
        }
    }else{
        cout << "HXN" << endl;
        cout << ans << endl;
        cout << hxnname.first << endl;
        int erasea = 0, eraseb = 0;
        for(int i=0;i<n;i++){
            if(a[i].name == hxnname.first){
                erasea = i;
            }
            if(a[i].name == hxnname.second){
                eraseb = i;
            }
        }
        a.erase(a.begin()+erasea);
        a.erase(a.begin()+eraseb);
        sort(a.begin(), a.end(), [](XyeHyin a, XyeHyin b){
            return a.name<b.name;
        });
        for(int i = 0; i < n-2; i++){
            cout << a[i].name << endl;
        }
        cout << hxnname.second << endl;
    }
    return 0;
}
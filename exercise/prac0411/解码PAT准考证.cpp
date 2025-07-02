#include <bits/stdc++.h>
using namespace std;
struct xyehyin{
    string s;
    int num;
};
struct request{
    int nu;
    string str;
} a[1005];
bool cmp(xyehyin a, xyehyin b){
    if (a.num != b.num) return a.num > b.num;
    else return a.s < b.s;
    
}
bool cmp1(pair<string, int> a, pair<string, int> b){
    if(a.second!=b.second){
        return a.second > b.second;
    }else{
        return a.first < b.first;
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<xyehyin> v(n);
    for (int i = 0; i < n;i++){
        cin>>v[i].s>>v[i].num;
    }
    vector<request> r(m);
    for (int i = 0; i < m;i++){
        cin >> r[i].nu >> r[i].str;
    }
    for (int i = 0; i < m;i++){
        cout<<"Case "<<i+1<<": "<<r[i].nu<<" "<<r[i].str<<endl;
        if(r[i].nu==1){
              vector <xyehyin> temp;
                for (int j = 0; j < n;j++){
                    if(v[j].s[0]==r[i].str[0]){
                        temp.push_back(v[j]);
                    }
                }
                if(temp.size()==0){
                    cout<<"NA"<<endl;
                    continue;}
                sort(temp.begin(), temp.end(), cmp);
                for (int j = 0; j < temp.size();j++){
                    cout << temp[j].s << " " << temp[j].num << endl;
                    continue;
                }
        }else if(r[i].nu==2){
            int sum = 0,count=0;
            for (int j = 0;j<v.size();j++){
                if(v[j].s.substr(1,3)==r[i].str){
                    sum += v[j].num;
                    count++;
                }
            }
            if(count==0){
                cout<<"NA"<<endl;
                continue;
            }
            cout << count << " " << sum << endl;
            continue;
        }else if (r[i].nu == 3)
        {
            unordered_map<string, int> m;
            for (int j = 0; j < n; j++)
            {
                if (v[j].s.substr(4, 6) == r[i].str)
                {
                    m[v[j].s.substr(1, 3)]++;
                }
            }
            vector<pair<string, int>> m1(m.begin(), m.end());
            sort(m1.begin(), m1.end(), cmp1);
            if (m1.size() == 0)
            {
                cout << "NA" << endl;
                continue;
            }
            for (auto it = m1.begin(); it != m1.end(); it++)
            {
                cout << it->first << " " << it->second << endl;
                continue;
            }
        }
    }
}
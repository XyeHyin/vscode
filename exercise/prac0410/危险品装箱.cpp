#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    map<int,vector<int>> box;
    for (int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        box[a].push_back(b);
        box[b].push_back(a);
    }
    for (int i = 0; i < M;i++){
        int k;
        cin >> k;
        vector<int> item(k);
        for (int j = 0; j < k; j++){
            cin >> item[j];
        }
        bool flag = false;
        vector<int> dangerous;
        for (int j = 0; j < k;j++){
            for(auto it=box[item[j]].begin();it!=box[item[j]].end();it++){
                dangerous.push_back(*it);
            }
        }
        for(auto it=item.begin();it!=item.end();it++){
            for(auto it2=dangerous.begin();it2!=dangerous.end();it2++){
                if(*it==*it2){
                    flag = true;
                    break;
                }
            }
        }
            if (flag)
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
    }
}

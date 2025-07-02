#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, Q;
    string s;
    cin >> n >> Q>>s;
    for (int i = 0; i < Q;i++){
        string t;
        cin >> t;
        vector<int> start;
        vector<int> end;
        for (int j = 0; j < n;j++){
            if(s[j]==t[0]&&s[j+1]!=t[0]){
                start.push_back(j);
            }
        }
        for (int j = 0;j<start.size();j++){
            for (int k = start[j]; k < n;k++){
                if(s[k]==t[t.size()-1]&&s[k-1]!=t[t.size()-1]){
                    end.push_back(k);
                }
            }
        }
        // for (int j = 0;j<start.size();j++){
        //     cout << start[j] << " "<<end[j]<<endl;
        // }

            vector<string> answ;
            for(int j = 0;j<start.size();j++){
               answ.push_back(s.substr(start[j], end[j] - start[j] + 1));
           }
           int ans = 0;
           for(int l = 0;l<answ.size();l++){
                vector<char> c;
                for (int j = 0;j<answ[l].size();j++){
                    for (int k = 0; k < t.size();k++){
                        if(answ[l][j]==t[k]){
                            c.push_back(answ[l][j]);
                            break;
                        }
                    }
                }
                set<char> s2(c.begin(), c.end());
                if(s2.size()!=c.size()){
                    ans = 0;
                    break;
                }
                if (answ[l].size() > ans)
                ans = answ[l].size();
                    
           }
        cout << ans << endl;
    }
}
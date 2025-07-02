#include <bits/stdc++.h>
using namespace std;
struct grade{
    int chinese, math, english, xuehao, zongfen;
};
bool cmp(grade a,grade b){
    if(a.zongfen!=b.zongfen) return a.zongfen > b.zongfen;
    else if(a.chinese!=b.chinese)return a.chinese > b.chinese;
    else return a.xuehao < b.xuehao;
}
int main(){
    
    int n;
    cin >> n;
    vector<grade> Grade(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> Grade[i].chinese >> Grade[i].math >> Grade[i].english;
        Grade[i].xuehao = i;
        Grade[i].zongfen = Grade[i].chinese + Grade[i].math + Grade[i].english;
     }
     sort(Grade.begin(), Grade.end(), cmp);
     for (int i = 0; i < 5;i++){
         cout << Grade[i].xuehao << " " << Grade[i].zongfen << endl;
     }
}
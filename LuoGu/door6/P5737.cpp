#include <bits/stdc++.h>
using namespace std;
bool isRun(int year){
    if(year%400==0)return true;
   if(year%4==0&&year%100!=0) return true;
    return false;
}
int main(){
    int start, end;
    cin >> start >> end;
    int count = 0;
    vector<int> run;
    for (int i = start; i <= end;i++){
        if(isRun(i)){
            count++;
            run.push_back(i);
        }
    }
    cout << count << endl;
    for (int i = 0; i < run.size();i++){
        cout << run[i] << " ";
    }
    return 0;
}
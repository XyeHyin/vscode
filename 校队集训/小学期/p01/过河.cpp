#include <bits/stdc++.h>
using namespace std;
//0 С͵ 1 ���� 2 �ְ� 3 ���� 4 Ů��1 5 ����1 6 Ů��2  7����2
vector<int> a(8, 0);
bool boat = 0;
bool check(int fir, int sec){
    if(a[0]^a[1]){
        for(int i = 2; i < 8; i++){
            if(a[i] == a[0]){
                return 0;
            }
        }
    }
    if(a[2]==a[4]||a[2]==a[6]){
        if(a[2]!=a[3])
        return 0;
    }
    if(a[3]==a[5]||a[3]==a[7]){
        if(a[3]!=a[2])
        return 0;
    }
    if(sec-fir>2){
        if(a[0]!=a[1]){
            return 0;
        }
    }
}
int main(){
    return 0;
}
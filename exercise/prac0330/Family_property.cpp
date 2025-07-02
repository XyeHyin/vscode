#include <bits/stdc++.h>
using namespace std;
int father[1005];
int findFather(int x){
    return father[x] = (father[x] == x ? x:father[x]= findFather(father[x])); 
}
void merge(int x, int y){
    int fx = findFather(x);
    int fy = findFather(y);
    if(fx!=fy) father[fx] = fy;
}
int main(){
    int P, Q;
    for (int i = 0; i < P;i++){
        father[i] = i;
    }
    for (int i = 0; i < P;i++){
        int N;
        cin >> N;
        for (int i = 0; i < N;i++){
            
        }
    }
}
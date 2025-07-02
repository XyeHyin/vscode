#include <bits/stdc++.h>
using namespace std;
struct T{
    int from, to;
    bool operator < (const T &right) const{
        return to<right.to;
}
};
int main(){
    deque<int> d;
    map<int, set<T>> m;
    d.push_back(3);
    int i, j, from, to;
    for (i = 5;;i+=2){
        int sqrti = (int)sqrt(i);
        for (j = 0; d[j] <= sqrti;j++){
            if(i%d[j]==0) break;
        }
        if(d[j]<sqrti) d.push_back(i);
    }
    { to = i;
     }
    return 0;
}
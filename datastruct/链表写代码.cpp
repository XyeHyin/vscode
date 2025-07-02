#include <bits/stdc++.h>
using namespace std;
int main(){
    list<int> l;
    l.remove(1);
    l.remove_if([](int x){return x == 1;});
    return 0;
}
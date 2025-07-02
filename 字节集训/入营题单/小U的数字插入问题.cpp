#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b) {
    string s=to_string(a);
    int maxx=0;
    for(int i=0;i<=s.size();i++){
       string t=s;
       t.insert(i,to_string(b));
       if(stoi(t)>maxx){
           maxx=stoi(t);
       }
    }
    return maxx;
    return 0;
}

int main() {
    cout << (solution(76543, 4) == 765443) << endl;
    cout << (solution(1, 0)==10) << endl;
    cout << (solution(44, 5) == 544) << endl;
    cout << (solution(666, 6) == 6666) << endl;
    return 0;
}
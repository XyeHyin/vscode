#include <bits/stdc++.h>
using namespace std;
struct Student{
    int id, xueye, suzhil;
    int total;
};
int main(){
    int n;
    cin >> n;
    Student students;
    for(int i = 0; i < n; i++){
        cin >> students.id >> students.xueye >> students.suzhil;
          int a=students.xueye,b=students.suzhil;
          int total = a + b;
          if(total>140&&a*7+b*3>=800) cout<<"Excellent"<<endl;
          else cout<<"Not excellent"<<endl;   
    }

    return 0;
}
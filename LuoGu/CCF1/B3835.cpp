    #include <bits/stdc++.h>
    using namespace std;
    int main(){
        int a, b;
        cin>>a>>b;
        int dic[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(a%4==0&&a%100!=0||a%400==0) dic[2]=29;
        cout<<dic[b]<<endl;
        return 0;
    }
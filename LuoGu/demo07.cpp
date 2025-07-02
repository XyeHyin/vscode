#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    double p, s;
    cin >> a >> b >> c;
    p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%.1lf", s);
}
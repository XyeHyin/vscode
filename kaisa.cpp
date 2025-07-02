#include <bits/stdc++.h>
using namespace std;

int main(){
    int temp,n;
    char s[60];
    scanf("%s", s);
    for (int i = 0; s[i]; i++){
        if(s[i]<'n'){
            n = 18 + (s[i] - 'a');
        }else {
            n = 17 + (s[i] - 'a');
        }
            temp = (s[i] - 'a' + n) % 26+'a';

    }
        putchar(temp);
    return 0;
}
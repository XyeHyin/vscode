#include <bits/stdc++.h>
using namespace std;
int main()
{
    int hong[3], lan[3], count;
    cin >> hong[0] >> hong[1] >> hong[2] >> lan[0] >> lan[1] >> lan[2];
    for (int i = 0; i < 3; i++){
         if (hong[i] == lan[i]){
            count++;
        }
    }
    cout << count;
}
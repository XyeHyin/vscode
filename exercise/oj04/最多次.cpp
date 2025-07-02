#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n;
    int arr[10005]={0};
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        arr[m]++;
    }
    int cnt=0,ans = 0;
    for (int i = 0; i < 10005; i++)
    {
        if(arr[i]==1){
            ans = i;
            break;
        }
        }
    
    cout << ans << endl;
}
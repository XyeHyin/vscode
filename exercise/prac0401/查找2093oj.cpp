#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M,query,count=0;
    cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N;i++){
        cin >> a[i];
    }
    for (int i = 0; i < M;i++){
       
        cin >> query;
        int left=0 , right = N-1;
        bool flag = false;
        while(left<=right){
            int mid = (left + right) / 2;
            if(a[mid]>query) {
                right = mid - 1;
            }
            else if(a[mid]<query){
                left = mid + 1;
            }
            else if(a[mid]==query){
                if(mid==0){
                    cout << 1 << " ";
                    flag = true;
                    break;
                }
                for(int i=mid;i>=0;i--){
                    if(a[i]!=query){
                        cout << i + 2 << " ";
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    cout << -1 << " ";
                }
                break;
            }
        }
        if(left>right&&!flag){
            cout << -1 << " ";
        }
    }
    cout << endl;
    return 0;
}
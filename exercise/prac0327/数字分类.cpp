#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool haveA[5];
    int cnt[5];
    int n=0,sumA4=0;
    bool A2 = false;
    memset(cnt, 0, sizeof(cnt));
    memset(haveA, false, sizeof(haveA));
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 5 == 0 && nums[i] % 2 == 0)
        {
            cnt[0] += nums[i];
            haveA[0] = true;
        }
        if (nums[i] % 5 == 1)
        {
            if (!A2)
            {
                cnt[1] += nums[i];
                A2 = true;
            }
            else
            {
                cnt[1] -= nums[i];
                A2 = false;
            }
            haveA[1] = true;
        }
        if (nums[i] % 5 == 2)
        {
            cnt[2]++;
            haveA[2] = true;
        }
        if (nums[i] % 5 == 3)
        {
            sumA4+=nums[i];
            cnt[3]++;
            haveA[3] = true;
        }
        if(nums[i]%5==4){
            cnt[4] = max(cnt[4],nums[i]);
            haveA[4] = true;
        }
    }
    for (int i = 0; i < 5;i++){
        if(haveA[i]){
            if(i==3){
                printf("%.1f",(double)sumA4/cnt[i]);
            }else{
                printf("%d",cnt[i]);
            }
        }else{
            printf("N");
        }
        if(i!=4){
            printf(" ");
        }
    }
}
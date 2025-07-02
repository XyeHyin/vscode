#include <bits/stdc++.h>
using namespace std;

int main(){
    int K;
    cin >> K;
    vector<int> nums(K);
    for (int i = 0; i < K; i++){
        cin >> nums[i];
    }

    int maxSum = 0, start = 0, end = K - 1;
    for (int i = 0; i < K; i++){
        for (int j = i; j < K; j++){
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            if (sum > maxSum || (sum == 0 && end == K - 1))
            {
                maxSum = sum;
                start = i;
                end = j;
            }
        }
    }

    if (maxSum < 0)maxSum = 0;
    cout << maxSum << " " << nums[start] << " " << nums[end];
}
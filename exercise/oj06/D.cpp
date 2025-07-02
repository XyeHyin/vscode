#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> arr2(arr.begin(), arr.end());
    sort(arr2.begin(), arr2.end());
    int left = 0, right = n - 1;
    bool flag = false;
    int leftValue, rightValue;
    while (left < right){
        int sum = arr2[left] + arr2[right];
        if (sum == k){
            leftValue = arr2[left];
            rightValue = arr2[right];
            flag = true;
            break;
        }
        else if (sum < k) left++;
        else right--;
    }
    if (flag){
        int ansl = find(arr.begin(), arr.end(), leftValue) - arr.begin();
        int ansr;
        if (leftValue == rightValue) ansr = find(ansl + arr.begin() + 1, arr.end(), rightValue) - arr.begin();
        else ansr = find(arr.begin(), arr.end(), rightValue) - arr.begin();
        if (ansl > ansr) swap(ansl, ansr);
        cout << ansl << " " << ansr << endl;
    }else cout << "-1" << endl;
    return 0;
}
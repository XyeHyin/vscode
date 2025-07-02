#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findMinimumTime(vector<int> &strength, int K) {
        vector<int> a = strength;
        sort(a.begin(), a.end());
        int minn = 0x3f3f3f3f;
        do{
            int ans = 0, X = 1, p = 0;
            for(int i = 0; i < a.size(); i++){
                ans += ceil(a[i]*1.0 / X);
                X += K;
            }
            minn = min(minn, ans);
        }while(next_permutation(a.begin(), a.end()));
        return minn;
    }
};
int main() {
    ios::sync_with_stdio(0);
    Solution s;
    vector<int> strength = {2,5,4};
    int K = 2;
    cout << s.findMinimumTime(strength, K);
    return 0;
}
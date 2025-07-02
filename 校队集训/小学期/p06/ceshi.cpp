#include <iostream>
using namespace std;
int main() {
    int i, j;
    double dp[1013] = {0, 1};
    for (i = 2; i < 1013; ++i)
        for (j = i; j >= 1; --j)
            dp[j] = dp[j - 1] / (2 * i - 1) + dp[j] * (2 * i - 2) / (2 * i - 1);
    for (i = 0; i <= 100; ++i)
        cout << i << " " << dp[i] << endl;
}
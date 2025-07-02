#include <bits/stdc++.h>
int solution(std::string dna1, std::string dna2) {
    int m = dna1.size();
    int n = dna2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (dna1[i - 1] == dna2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min({dp[i - 1][j - 1], dp[i - 1][j],
                                         dp[i][j - 1]});
            }
        }
    }
    return dp[m][n];
}

int main() {
    std::cout << (solution("AGCTTAGC", "AGCTAGCT") == 2) << std::endl;
    std::cout << (solution("AGCCGAGC", "GCTAGCT") == 4) << std::endl;
    std::cout << (solution("AGT", "AGCT") == 1) << std::endl;
    std::cout << (solution("AACCGGTT", "AACCTTGG") == 4) << std::endl;
    std::cout << (solution("ACGT", "TGC") == 3) << std::endl;
    std::cout << (solution("A", "T") == 1) << std::endl;
    std::cout << (solution("GGGG", "TTTT") == 4) << std::endl;
    return 0;
}
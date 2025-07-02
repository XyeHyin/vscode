#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::string solution(int n, std::vector<int> sums) {
    std::sort(sums.begin(), sums.end());
    std::vector<int> result(n);

    for (int i = 2; i < sums.size(); ++i) {
        int a = (sums[0] + sums[1] - sums[i]) / 2;
        if ((sums[0] + sums[1] - sums[i]) % 2 != 0)
            continue;

        result[0] = a;
        result[1] = sums[0] - a;
        result[2] = sums[1] - a;

        std::unordered_map<int, int> count;
        for (int sum : sums)
            count[sum]++;

        bool valid = true;
        for (int j = 3; j < n; ++j) {
            result[j] = sums[j - 1] - result[0];
            for (int k = 0; k < j; ++k) {
                int sum = result[j] + result[k];
                if (count[sum] > 0) {
                    count[sum]--;
                } else {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                break;
        }

        if (valid) {
            std::sort(result.begin(), result.end());
            std::string res;
            for (int num : result) {
                res += std::to_string(num) + " ";
            }
            res.pop_back();
            return res;
        }
    }

    return "Impossible";
}

int main() {
    std::vector<int> sums1 = {1269, 1160, 1663};
    std::vector<int> sums2 = {1, 1, 1};
    std::vector<int> sums3 = {226, 223, 225, 224, 227, 229, 228, 226, 225, 227};
    std::vector<int> sums4 = {-1, 0, -1, -2, 1, 0, -1, 1, 0, -1};
    std::vector<int> sums5 = {79950, 79936, 79942, 79962, 79954,
                              79972, 79960, 79968, 79924, 79932};

    std::cout << (solution(3, sums1) == "383 777 886") << std::endl;
    std::cout << (solution(3, sums2) == "Impossible") << std::endl;
    std::cout << (solution(5, sums3) == "111 112 113 114 115") << std::endl;
    std::cout << (solution(5, sums4) == "-1 -1 0 0 1") << std::endl;
    std::cout << (solution(5, sums5) == "39953 39971 39979 39983 39989")
              << std::endl;

    return 0;
}
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> expenses(12);
    for (int i = 0; i < 12; ++i) {
        std::cin >> expenses[i];
    }

    int monthly_income = 2000;
    int total_savings = 0;
    int hand_money = 0;

    for (int i = 0; i < 12; i++) {
        hand_money += monthly_income;
        if (hand_money < expenses[i]) {
            std::string months[] = {"January", "February", "March",
                                    "April",   "May",      "June",
                                    "July",    "August",   "September",
                                    "October", "November", "December"};
            std::cout << "You need do some change in " << months[i]
                      << std::endl;
            return 0;
        }
        hand_money -= expenses[i];
        int savings = (hand_money / 100) * 100;
        total_savings += savings;
        hand_money -= savings;
    }

    total_savings = static_cast<int>(total_savings * 1.3);
    int final_money = hand_money + total_savings;

    std::cout << final_money << std::endl;

    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 998244353;

bool is_palindrome(const string &s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool is_valid_parentheses(const string &s, int start, int end) {
    int balance = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] == '(') {
            balance++;
        } else {
            balance--;
        }
        if (balance < 0) {
            return false;
        }
    }
    return balance == 0;
}

int count_valid_palindromic_substrings(const string &s) {
    int n = s.length();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (is_palindrome(s, i, j) && is_valid_parentheses(s, i, j)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        int result = count_valid_palindromic_substrings(S);
        cout << result % MOD << endl;
    }
    return 0;
}
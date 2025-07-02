#include <bits/stdc++.h>
using namespace std;
#define INT string
INT lst[10] = {{"0"},
               {"1"},
               {"2097152"},
               {"10460353203"},
               {"4398046511104"},
               {"476837158203125"},
               {"21936950640377856"},
               {"558545864083284007"},
               {"9223372036854775808"},
               {"109418989131512359209"}};
INT add(INT a, INT b) {
    if (a.size() < b.size()) {
        swap(a, b);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while (b.size() < a.size()) {
        b += '0';
    }
    int carry = 0;
    INT ans;
    for (int i = 0; i < a.size(); i++) {
        int sum = a[i] - '0' + b[i] - '0' + carry;
        ans += sum % 10 + '0';
        carry = sum / 10;
    }
    if (carry) {
        ans += carry + '0';
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
INT multiply(INT a, INT b) {
    if (a.size() < b.size())
        swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<INT> res;
    for (int i = 0; i < b.size(); i++) {
        INT ans;
        int carry = 0;
        for (int j = 0; j < a.size(); j++) {
            int sum = (a[j] - '0') * (b[i] - '0') + carry;
            ans += sum % 10 + '0';
            carry = sum / 10;
        }
        if (carry) {
            ans += carry + '0';
        }
        reverse(ans.begin(), ans.end());
        for (int j = 0; j < i; j++) {
            ans += '0';
        }
        res.push_back(ans);
    }
    INT sum = res[0];
    for (int i = 1; i < res.size(); i++) {
        sum = add(sum, res[i]);
    }
    if (a == "0" || b == "0") {
        return "0";
    }
    return sum;
}
/* void dfs(vector<int> cnt, int index, int sheng) {
    if (sheng == 0) {
        INT sum = "0";
        for (int i = 0; i < cnt.size(); i++) {
            sum = add(sum, lst[cnt[i]]);
        }
        if (sum.size() != 21)
            return;
    }
    if (index == cnt.size() - 1) {
        cnt[index] = sheng;
        dfs(cnt, index + 1, 0);
        return;
    }
    for (int i = 0; i < 21; i++) {
        cnt[index] = i;
        dfs(cnt, index + 1, sheng - i);
        cnt[index] = 0;
    }
} */
// vector<int> c;
// void f(int num, int a, int b) {
//     if (c.size() == a) {
//         int summing = 0;
//         for (int i = 0; i < c.size(); i++) {
//             summing += c[i];
//         }
//         if(summing>21) return;
//         else c.push_back(21 -summing);
//         INT sum = "";
//         for (int i = 0; i < c.size(); i++) {
//             for (int j = 0; j < c[i]; j++) {
//                 sum = add(sum, lst[i]);
//             }
//         }
        
//             for (int i = 0; i < 10; i++) {
//                 cout << c[i] << " ";
//             }
//             cout << endl << sum << endl;
        
//         c.pop_back();
//         return;
//     }
//     if (num > b)
//         return;
//     c.push_back(num);
//     f(num + 1, a, b);
//     c.pop_back();
//     f(num + 1, a, b);
// }

// int main() {
//     f(1, 9, 30);
//     return 0;
// }
vector<int> c;
void f(int num, int a, int b) {
    if (c.size() == a) {
        for (int i = 0; i < c.size(); i++) {
            cout << c[i] << " ";
        }
        cout << endl;
        return;
    }
    if (num >= b)
        return;
    c.push_back(num);
    f(num + 1, a, b);
    c.pop_back();
    f(num + 1, a, b);
}

int main() {
    f(0, 9, 30);
    return 0;
}
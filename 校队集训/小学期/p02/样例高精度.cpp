#include <bits/stdc++.h>
using namespace std;
struct Int {
    int arr[6];
    bool yc;
    Int(int n = 0) {
        memset(arr, 0, sizeof(int) * 6); 
        yc = 0;                         
        int i = 0;
        while (n) {
            arr[i++] = n % 10000;
            n /= 10000;
        }
    }
    Int(string s) {

        memset(arr, 0, sizeof(int) * 6);
        yc = 0;
        int i = 0;
        int len = s.size();
        len = len <= 21 ? len - 1 : 20;
        int tmp;
        for (; len >= 0; --len) {
            if (i % 4 == 0)
                tmp = 0;
            tmp += (s[len] - '0') * pow(10, i % 4);
            if (i % 4 == 3 || len == 0) {
                arr[i / 4] = tmp;
            }
            ++i;
        }
    }
    void display() const {
        int i;
        bool flag = 0;
        for (i = 5; i >= 1; i--) {
            if (flag || arr[i]) {
                if (flag == 0)
                    printf("%d", arr[i]);
                else
                    printf("%04d", arr[i]);
                flag = 1;
            }
        }
        if (flag)
            printf("%04d", arr[i]);
        else
            printf("%d", arr[i]);
    }
    bool operator<(const Int &b) const {
        int i;
        for (int i = 5; i >= 0; --i)
            if (this->arr[i] < b.arr[i])
                return 1;
            else if (b.arr[i] < this->arr[i])
                return 0;
        return 0;
    }
    bool operator>(const Int &b) const { return b < *this; }
    bool operator<=(const Int &b) const { return !(b < *this); }
    bool operator>=(const Int &b) const { return !(b > *this); }
    bool operator==(const Int &b) const { return !(*this < b) && !(b < *this); }
    Int &operator+=(const Int &b) {
        int i;
        int jin = 0;
        for (i = 0; i < 6; i++) {
            int tmp = arr[i] + b.arr[i] + jin;
            arr[i] = tmp % 10000;
            jin = tmp / 10000;
        }
        if (jin)
            yc = 1;
        return *this;
    }
    Int operator+(const Int &b) const {
        Int tmp = *this;
        return tmp += b;
    }
    Int &operator*=(int b) {
        int i;
        int jin = 0;
        for (int i = 0; i < 6; ++i) {
            int tmp = arr[i] * b + jin;
            arr[i] = tmp % 10000;
            jin = tmp / 10000;
        }
        if (jin)
            yc = 1;
        return *this;
    }
    Int operator*(int b) {
        Int tmp = *this;
        return tmp *= b;
    }
    string to_string() const {
        ostringstream oss;
        bool isLeading = true;
        for (int i = 5; i >= 0; --i) {
            if (arr[i] != 0 || !isLeading) {
                if (isLeading) {
                    oss << arr[i];
                    isLeading = false;
                } else {
                    oss << setw(4) << setfill('0') << arr[i];
                }
            }
        }
        string result = oss.str();
        if (result.empty())
            return "0";
        return result;
    }
};
Int lst[10] = {{"0"},
               {"1"},
               {"2097152"},
               {"10460353203"},
               {"4398046511104"},
               {"476837158203125"},
               {"21936950640377856"},
               {"558545864083284007"},
               {"9223372036854775808"},
               {"109418989131512359209"}};
vector<int> c;
vector<int> jishu(10);
bool check(string s){
    if(s.size()!=21)  return 0;
    vector<int> jishu2(10, 0);
    for (int i = 0; i < s.size(); i++) {
        jishu2[s[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if(jishu[i]!=jishu2[i])
            return 0;
    }
    return 1;
}
void f(int begin, int n, int m) {
    if (c.size() == n) {
        Int sum=0;
        vector<int> moni;
        moni.push_back(0);
        for (int i = 0; i < c.size(); i++) {
            moni.push_back(c[i]);
        }
        int j = 0,summing=0;
        for (int i = 1;i<moni.size();i++){
            int d = 1;
            if(i==1)d=0;
            jishu[j]=moni[i]-moni[i-1]-d;
            j++;
        }
        for (int i = 0; i < 9;i++){
            summing += jishu[i];
        }
            jishu[9] = 21 - summing;
        for (int i = 0;i<10;i++){
            sum+=lst[i]*jishu[i];
        }
        string s=sum.to_string();
        if(check(s)){
            cout << s << endl;
        }
        return;
    }
    for (int i = begin; i < m; i++) {
        c.push_back(i);
        f(i + 1, n, m);
        c.pop_back();
    }
}

int main() {
    f(0,9,30);
    return 0;
}
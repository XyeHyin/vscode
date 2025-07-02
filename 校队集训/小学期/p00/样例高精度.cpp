#include <bits/stdc++.h>
using namespace std;
struct Int {
    int arr[6];
    bool yc;
    Int(int n = 0) {
        memset(arr, 0, sizeof(int) * 6); // 初始化
        yc = 0;                          // 是否发生溢出
        int i = 0;
        while (n) {
            arr[i++] = n % 10000;
            n /= 10000;
        }
    }

    // 将数据进行数据结构的处理
    Int(string s) {

        memset(arr, 0, sizeof(int) * 6);
        yc = 0;
        int i = 0;
        int len = s.size();
        // 长度超出21算21个数,不超出算当前的数位
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
    // 格式化输出
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
    // 运算符重载小于号
    bool operator<(const Int &b) const {
        int i;
        for (int i = 5; i >= 0; --i)
            if (this->arr[i] < b.arr[i])
                return 1;
            else if (b.arr[i] < this->arr[i])
                return 0;
        return 0;
    }
    // 运算符重载大于号
    bool operator>(const Int &b) const { return b < *this; }
    // 运算符重载小于等于号
    bool operator<=(const Int &b) const { return !(b < *this); }
    // 运算符重载大于等于号
    bool operator>=(const Int &b) const { return !(b > *this); }
    // 运算符重载等于号
    bool operator==(const Int &b) const { return !(*this < b) && !(b < *this); }
    // 运算符重载加等于号
    Int &operator+=(const Int &b) {
        int i;
        int jin = 0;
        for (i = 0; i < 6; i++) {
            int tmp = arr[i] + b.arr[i] + jin;
            arr[i] = tmp % 10000;
            jin = tmp / 10000;
        }
        // 因为是21位数,而数据结构开到了24位,所以理论上不会发生溢出的情况,只会有进位不满的情况
        if (jin)
            yc = 1;
        return *this;
    }
    // 运算符重载加号
    Int operator+(const Int &b) const {
        Int tmp = *this;
        return tmp += b;
    }
    // 运算符重载乘等于号
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
    // 运算符重载乘号
    Int operator*(int b) {
        Int tmp = *this;
        return tmp *= b;
    }
    string to_string() const {
        ostringstream oss;
        bool isLeading = true;         
        for (int i = 5; i >= 0; --i) { 
            if (arr[i] != 0 ||
                !isLeading) { 
                if (isLeading) {
                    oss << arr[i];  
                    isLeading = false; 
                } else {
                    oss << setw(4) << setfill('0')
                        << arr[i];
                }
            }
        }
        string result = oss.str();
        if (result.empty())
            return "0"; // 如果结果为空，表示数字为0
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
void f(int num, int a, int b) {
    if (c.size() == a) {
        int summing = 0;
        for (int i = 0; i < c.size(); i++) {
            summing += c[i];
        }
        if(summing>21) return;
        else c.push_back(21-c[0]-c[1]-c[2]-c[3]-c[4]-c[5]-c[6]-c[7]-c[8]);
        Int sum = 0;
        for (int i = 0; i < c.size(); i++) {
            sum += lst[c[i]];
        }
        string s = sum.to_string();
        vector<int> ar(10, 0);
        for (int i = 0; i < s.size(); i++) {
            ar[s[i] - '0']++;
        }
        // for(int i = 0; i < 10; i++){
        //     cout<<ar[i]<<" ";
        // }
        // cout<<endl;
        if(s.size()==21){
            cout<<s<<endl;
        }
        c.pop_back();
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
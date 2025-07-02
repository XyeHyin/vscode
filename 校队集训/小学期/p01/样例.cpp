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
};
Int lst[10];
vector<int> c;
void f(int num, int a, int b) {
   
}

int main() {
     f(1, 9, 30);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct Int {
    int arr[6];
    bool yc;
    Int(int n = 0) {
        memset(arr, 0, sizeof(int) * 6); // ��ʼ??
        yc = 0;                          // �Ƿ������
        int i = 0;
        while (n) {
            arr[i++] = n % 10000;
            n /= 10000;
        }
    }

    // �����ݽ������ݽṹ�Ĵ���
    Int(string s) {

        memset(arr, 0, sizeof(int) * 6);
        yc = 0;
        int i = 0;
        int len = s.size();
        // ���ȳ���21??21����,�������㵱ǰ����??
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
    // ��ʽ�����
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
    // ���������С�ں�
    bool operator<(const Int &b) const {
        int i;
        for (int i = 5; i >= 0; --i)
            if (this->arr[i] < b.arr[i])
                return 1;
            else if (b.arr[i] < this->arr[i])
                return 0;
        return 0;
    }
    // ��������ش��ں�
    bool operator>(const Int &b) const { return b < *this; }
    // ���������С�ڵ��ں�
    bool operator<=(const Int &b) const { return !(b < *this); }
    // ��������ش��ڵ��ں�
    bool operator>=(const Int &b) const { return !(b > *this); }
    // ��������ص��ں�
    bool operator==(const Int &b) const { return !(*this < b) && !(b < *this); }
    // ��������ؼӵ���??
    Int &operator+=(const Int &b) {
        int i;
        int jin = 0;
        for (i = 0; i < 6; i++) {
            int tmp = arr[i] + b.arr[i] + jin;
            arr[i] = tmp % 10000;
            jin = tmp / 10000;
        }
        // ��Ϊ??21λ��,�����ݽṹ������24??,���������ϲ��ᷢ���������??,ֻ���н�λ���������
        if (jin)
            yc = 1;
        return *this;
    }
    // ��������ؼ�??
    Int operator+(const Int &b) const {
        Int tmp = *this;
        return tmp += b;
    }
    // ��������س˵���??
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
    // ��������س�??
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
            return "0"; // ������Ϊ�գ���ʾ����Ϊ0
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
bool check(string s) {
    if (s.size() != 21)
        return 0;
    // vector<int> jishu2(10, 0);
    // for (int i = 0; i < s.size(); i++) {
    //     jishu2[s[i] - '0']++;
    // }
    // for (int i = 0; i < 10; i++) {
    //     if(jishu[i]!=jishu2[i])
    //         return 0;
    // }
    Int sum1 = 0;
    for (int i = 0; i < s.size(); i++) {
        sum1 += lst[s[i] - '0'];
    }
    if (sum1 == Int(s))
        return 1;
    return 0;
}
int main(){
    string s = "128468643043731391252";
    if(check(s))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
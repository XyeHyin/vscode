#include <cmath>
#include <iostream>
using namespace std;

// 计算模意义下的逆元素
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1; // 如果找不到，则返回1，但在这个场景下应该总能找到逆元素
}

int main() {
    unsigned char cipher[] = {198, 44, 113, 215, 43,  231, 181, 44,  147,
                              95,  61, 181, 79,  180, 95,  79,  180, 232,
                              181, 79, 46,  95,  231, 147, 95,  164, 181,
                              146, 79, 65,  63,  82,  116, 77,  0};

    int inv17 = modInverse(17, 256); // 计算17的模256逆元素

    for (int i = 0; i < 35; i++) {
        unsigned char decryptedChar = (cipher[i] * inv17) % 256;
        cout << static_cast<char>(decryptedChar);
    }

    cout << endl;
    return 0;
}
#include <bitset>
#include <iostream>
using namespace std;

int main() {
    int T;  
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int x;
        cin >> x;
        cout << bitset<64>(x * x * x * x)
                    .to_string()
                    .substr(bitset<64>(x * x * x * x).to_string().find('1'))
             << endl;
    }
    return 0;
}
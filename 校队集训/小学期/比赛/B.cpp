#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n < 10)
        cout << "厚外套" << endl;
    else if (n >= 10 && n <= 20)
        cout << "穿夹克" << endl;
    else
        cout << "穿T恤";
    return 0;
}
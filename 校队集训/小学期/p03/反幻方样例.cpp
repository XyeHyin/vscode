#include <bits/stdc++.h>
using namespace std;
int main() {
    int count = 0;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    do{
        vector<int> b(8);
        b[0] = a[0] + a[1] + a[2];
        b[1] = a[3] + a[4] + a[5];
        b[2] = a[6] + a[7] + a[8];
        b[3] = a[0] + a[3] + a[6];
        b[4] = a[1] + a[4] + a[7];
        b[5] = a[2] + a[5] + a[8];
        b[6] = a[0] + a[4] + a[8];
        b[7] = a[2] + a[4] + a[6];
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        if(b.size() == 8){
            count++;
        }
    }while(next_permutation(a, a + 9));
    cout << count/8 << endl;
    return 0;
}
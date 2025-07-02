    #include <bits/stdc++.h>
    using namespace std;
    const int op = 5e8;
    int main() {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b = a;
        vector<int> s = a;
        if (a[0] == -999999999) {
            b[0] = op;
            s[0] = -op;
        }
        for (int i = 1; i < n; i++) {
            if (b[i] == -999999999) {
                if (b[i - 1] - x >= -op) {
                    b[i] = b[i - 1] - x;
                }else{
                    b[i] = op;
                }
            }
            if (s[i] == -999999999) {
                if(s[i-1]-x+1>=-op){
                    s[i] = s[i-1]-x+1;
                }else{
                    s[i] = -op;
                }
            }
        }
        int cnta = 0, cntb = 0;
        for (int i = 1; i < n; i++) {
        if(b[i-1]-b[i]>=x){
            cntb++;
        }
            if(s[i-1]-s[i]>=x){
                cnta++;
            }
        }
        cout << cntb << " " << cnta << endl;
        return 0;
    }
    #include <bits/stdc++.h>
    using namespace std;
    int main(){
        int n;
        cin >> n;
        vector<int> a(n+1);
        for(int i = 1; i <= n; i++){
        a[i]=i;
        }
        do{
            for(int i = 1; i <= n; i++){
                cout <<setw(5)<< a[i];
            }
            cout << endl;
        }while(next_permutation(a.begin()+1,a.end()));
        return 0;
    }
#include<bits/stdc++.h>
using namespace std;
int main(){
    int M;
    cin >> M;
    for (int i = 0; i < M;i++){
        int K;
        cin >> K;
        int N = 0;
        bool flag = false;
        while (N<=10){
            N++;
            int Wei=(to_string(K)).size();
            int pos=0;
            int num=K*K*N;
            string str=to_string(num);
            while(pos<str.size()){
                if(str.substr(pos, str.size() - pos)==to_string(K)){
                    cout << N << " " << num << endl;
                    flag = true;
                    break;
                }
                pos++;
            }
            if(flag)
                break;
        }
        if(flag){
            continue;
        }
        cout << "No" << endl;

    }
}
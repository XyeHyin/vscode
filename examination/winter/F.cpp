#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    char c[n][m];
    char c2[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
        {
            cin >> c2[i][j];
        }
    } 
    for (int i = 0; i < n;i++){
        bool y = true;
        for (int j = 0; j < m;j++){
            if (c2[i][j] == '*'){
                y = false;
            }  
        }
        if (y == true){
            for (int j = 0; j < m;j++){
                c[i][j] = '0';
            }
        }
    }
    for (int i = 0; i < m;i++){
        bool y = true;
        for (int j = 0; j < n;j++){
            if (c2[j][i]=='*'){
                y = false;
            }   
        }
        if (y == true){
            for (int j = 0; j < n;j++){
                c[j][i] = '0';
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (c[i][j] == '0'){
                c2[i][j] = c[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (c2[i][j] != '0'){
                cout << c2[i][j];
            }
        }
        cout << endl;
    }
    
}

    
        
        
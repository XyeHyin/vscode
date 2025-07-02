#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<double> score;
    cin >> n;
    for(int i=0;i<n;i++){
        double a,b;
        cin >> a>>b;
        score.push_back(a*0.6+b*0.4);
    }
    sort(score.begin(), score.end(), greater<double>());
    for(int i=0;i<3;i++){
        printf("%.2f\n", score[i]);
    }
    return 0;
}
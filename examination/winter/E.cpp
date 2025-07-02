#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;	    cin >> n;
	string s;	cin >> s;
	int cnta = 0, cntb = 0, ans = 0;
	for(int i = 0; i<n; i++){
		if(s[i] == 'a') cnta++;
		else cntb++;
		if((i%2==1) && cnta != cntb){
			ans++;
			cnta = 0;
			cntb = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
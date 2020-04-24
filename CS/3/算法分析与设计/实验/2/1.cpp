#include <bits/stdc++.h>
using namespace std;
int res, sta, n;
int r[2005], s[2005];
void recall(int m){
    
	if(m == n + 1){
		for(int i = 1; i <= res; i++){
			cout << r[i] << ' ';
		}
		for(int i = sta; i > 0; i--){
			cout << s[i] << ' ';
		}
		cout << endl;
		return;
	}
	if(sta > 0){
		r[++res] = s[sta];
		sta--;
		recall(m);
		s[++sta] = r[res];
		res--;
	}
	s[++sta] = m;
	recall(m + 1);
	sta--;
}
int main(){
	cin >> n;
	res = 0;sta = 0;
	recall(1);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll MOD = 1e9 + 7 ; 
int main() {
	ll n , x ;
	cin >> n >> x; 
	vector<ll> a(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	vector<ll> ans(x + 1, 0);
	ans[0] = 1 ;
	for(int i = 1 ; i <= x ; i++) {
	    for(ll num : a) {
	        if(i >= num) {
	            ans[i] = (ans[i] + ans[i - num]) % MOD ;
	        }
	    }
	}
	cout << ans[x] % MOD << endl;
}

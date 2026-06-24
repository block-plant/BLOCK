#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll N = 1e5 + 7 ;
ll dp[N];
const ll MOD = 1e9 + 7 ;
ll k;

void precompute() {
    dp[0] = 1 ;
    for(int i = 1 ; i < N ; i++) {
        dp[i] = dp[i-1] % MOD ;
        if(i >= k) dp[i] = ((dp[i] % MOD) + (dp[i-k] % MOD)) % MOD;
    }
    for(int i = 1 ; i < N ; i++) {
        dp[i] = ((dp[i] % MOD) + (dp[i-1] % MOD)) % MOD;
    }
}

void solve() {
    int a , b ;
    cin >> a >> b;
    ll ans = dp[b] % MOD ;
    if(a > 0) {
        ans = (ans - dp[a - 1] + MOD) % MOD ; 
    }
    cout << ans << endl;
}

int main() {
	int t ;
	cin >> t >> k ; 
	precompute();
	while(t--) {
	    solve();
	}
}

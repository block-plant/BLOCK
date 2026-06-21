#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll MOD = 1e9 + 7 ; 
int main() {
	ll n , m ;
	cin >> n >> m ; 
	vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
	
	vector<vector<ll>> dp(n + 1, vector<ll>(m + 2 , 0));
	for(int i = 1 ; i <= n ; i++) {
	    for(int j = 1 ; j <= m ; j++) {
	        if(i == 1) {
                if(a[i] == 0 || a[i] == j) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
                continue ;
            }
            if(a[i] == 0) {
                dp[i][j] = ((((dp[i-1][j] % MOD) + (dp[i-1][j+1] % MOD)) % MOD) + (dp[i-1][j-1] % MOD)) % MOD;
            }
            else {
                if(j == a[i]) {
                    dp[i][j] = ((((dp[i-1][j] % MOD) + (dp[i-1][j+1] % MOD)) % MOD) + (dp[i-1][j-1] % MOD)) % MOD;
                }
                else {
                    dp[i][j] = 0;
                }
            }
            
	    }
	}
	ll Ans = 0 ;
	for(int i = 1 ; i <= m ; i++) {
	    Ans = ((Ans % MOD) + (dp[n][i] % MOD)) % MOD ;
	}
	cout << Ans << endl;
}
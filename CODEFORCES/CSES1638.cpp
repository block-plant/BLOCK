#include <bits/stdc++.h>
using namespace std;

using ll = long long ;
const ll MOD = 1e9 + 7 ;
int main() {
	ll n ;
	cin >> n ;
	vector<string> b(n) ;
	for(auto &s : b) cin >> s ;
	vector<vector<ll>> dp(n , vector<ll>(n , 0));
	for(int i = 0 ; i < n ; i++) {
	    if(b[i][0] == '*') break;
	    dp[i][0] = 1 ;
	}
	for(int i = 0 ; i < n ; i++) {
	    if(b[0][i] == '*') break;
	    dp[0][i] = 1 ;
	}
	for(int i = 1 ; i < n ; i++) {
	    for(int j = 1 ; j < n ; j++) {
	        if(b[i][j] == '*') dp[i][j] = 0 ;
	        else if(b[i][j-1] == '*' && b[i-1][j] == '*') {
	            dp[i][j] = 0 ; 
	        }
	        else if(b[i][j-1] == '*') dp[i][j] = dp[i-1][j] ;
	        else if(b[i-1][j] == '*') dp[i][j] = dp[i][j-1];
	        else dp[i][j] = ((dp[i-1][j] % MOD) + (dp[i][j-1] % MOD)) % MOD;
	    }
	}
	cout << dp[n-1][n-1] << endl;
}

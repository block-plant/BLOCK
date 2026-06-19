#include <bits/stdc++.h>
using namespace std;

using ll = long long ;
const ll MOD = 1e9 + 7 ; 
int main() {
	ll n , k ;
	cin >> n >> k ; 
	
	// auto getFact = [&](ll n)->vector<ll> {
	//     vector<ll> ans;
    //     for(int i = 1; i * i <= n; i++) {
    //         if(n % i == 0) {
    //             ans.push_back(i);
    //             if(i != n / i)
    //                 ans.push_back(n / i);
    //         }
    //     }
    //     sort(ans.begin(), ans.end());
    //     return ans ;
	// };
	vector<vector<ll>> div(n + 1); 
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            div[j].push_back(i); 
        }
    }
	vector<vector<ll>> dp(k + 1 , vector<ll>(n + 1 , -1));
	for(int i = 1 ; i <= k ; i++) {
	    for(int j = 1 ; j <= n ; j++) {
	        if(i == 1 || j == 1) {
	            dp[i][j] = 1 ;
	            continue ;
	        }
	        ll temp = 0;
	        for(auto x : div[j]) {
	            temp = ((temp % MOD) + (dp[i-1][x] % MOD) % MOD) ;
	        }
	        dp[i][j] = temp % MOD ; 
	    }
	}
	
	ll Ans = 0 ;
	for(int i = 1 ; i <= n ; i++) Ans = ((Ans % MOD) + (dp[k][i] % MOD)) % MOD;
	cout << Ans << endl;
}

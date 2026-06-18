#include <bits/stdc++.h>
using namespace std;

using ll = long long ;
const ll MOD = 1e9 + 7 ;

int main() {
    ll n ;
    cin >> n ; 
    vector<ll> a(n);
    for(auto &x : a) cin >> x;
    vector<ll> dp(n+1 , 0);
    dp[0] = 1 ;
    ll sum = 1 ; 
    for(int i = 1 ; i <= n ; i++) {
        dp[i] = sum ; 
        sum = (sum + dp[i]) % MOD ;
        if(i >= 6) {
            sum = (sum - dp[i-6] + MOD) % MOD ;
        }
    }
    cout << dp[n] << endl;
}

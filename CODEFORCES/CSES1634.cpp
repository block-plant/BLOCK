#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
int main() {
    ll n , x; 
    cin >> n >> x ; 
    vector<ll>a(n) ;
    for(auto &p :a) cin >> p; 
    vector<ll> dp(x+1 , 1e9);
    dp[0] = 0 ;
    for(ll i = 1 ; i <= x ; i++) {
        for(ll num : a) {
            if(i - num >= 0) {
                dp[i] = min(dp[i] , dp[i - num] + 1) ;
            }
        }
    }
    if(dp[x] == 1e9) cout << -1 << endl;
    else cout << dp[x] << endl;
}

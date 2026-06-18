#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
int main() {
    ll n ;
    cin >> n ;
    vector<ll> a(n) ;
    for(auto &x : a) cin >> x;
    
    vector<vector<ll>> dp(n , vector<ll>(n , 0));
    // for(int i = 0 ; i < n ; i++) dp[i][i] = a[i];
   
    for(int i = n-1 ; i >= 0 ; i--) {
        for(int j = i ; j < n ; j++) {
            ll l = (i + 1 <= j) ? dp[i+1][j] : 0;
            ll r = (i <= j - 1) ? dp[i][j-1] : 0;
            if(i <= j) {
                if((n - (j - i + 1)) % 2 == 0) {
                    dp[i][j] = max(a[i] + l , a[j] + r);
                }
                else {
                    dp[i][j] = 0 + min(r , l);
                }
            }
        }
    }
    cout << dp[0][n-1] << endl;
}

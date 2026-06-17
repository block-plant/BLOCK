/**
 * Author: KUNWAR
 * Date:   2026-06-17
 * Time:   23:20:30
**/

#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
int main() {
    int t ;
    cin >> t ;
    while(t--) {
        int n, m; 
        cin >> n >> m;
        
        if(n == 1) { 
            cout << 0 << endl;
            continue;
        }
        
        long long ans = 0;
        if(n == 2) {
            for(int i = 2 ; i <= m ; i++) 
                for(int j = 2; j <= m; j++) 
                    if(gcd(i, j) == 1) ans++;
            cout << ans % MOD << endl; 
            continue;
        }
    
        vector<long long> dp(m + 1);
        for(int L = m ; L >= 1 ; L--) {
            dp[L] = power(m / L, n - 2);
            for(int i = 2 * L; i <= m; i += L) 
                dp[L] = (dp[L] - dp[i] + MOD) % MOD;
        }
    
        for(int L = 1; L <= m; L++) {
            if(!dp[L]) continue;
            for(int i = 1 ; i <= m ; i++) {
                if(gcd(i, L) == 1) continue;
                for(int j = 1 ; j <= m ; j++) {
                    if(gcd(j, L) > 1 && gcd(gcd(i, L), j) == 1) {
                        ans = (ans + dp[L]) % MOD;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
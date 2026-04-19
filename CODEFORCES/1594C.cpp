/**
 * Author: KUNWAR
 * Date:   2026-04-20
 * Time:   02:03:00
**/

#include <bits/stdc++.h>
using namespace std;

// --- Type Definitions ---
using ll = long long;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int n = 1e6 + 8;
vector<bool> isPrime(n , true);
vector<ll> spf(n);

void spff() {
    for(int i = 0 ; i < n ; i++) spf[i] = i ; 
    isPrime[0] = false ;
    isPrime[1] = false ; 
    for(int i = 2 ; i * i <= n ; i++) {
        if(isPrime[i]) {
            spf[i] = i ; 
            for(int j = i * i ; j <= n ; j += i) {
                isPrime[j] = false ;
                spf[j] = min(spf[j] , (ll)i);
            }
        }
    }
}

void solve() {
    ll l ; 
    cin >> l ;
    char c ; 
    cin >> c ; 
    string s; 
    cin >> s ;

    bool tochange = true;
    
    for(int i = 0 ; i < l ; i++) {
        if(s[i] != c) {
            tochange = false;
            break;
        }
    }

    if(tochange) {
        cout << 0 << endl;
        return;
    }

    ll ans = 0 ; 
    
    for(int i = l/2+1 ; i <= l ; i++) {
        if(s[i - 1] == c) {
            ans = i ;
        }
    }
    
    if(ans == 0) ans = l;
    bool one = false ;
    bool two = false ;
    
    ll anstwo = 0 ; 
    
    if(s[ans - 1] == c) one = true; 
    
    if(s[ans - 1] != c) two = true;
    
    if(ans + 1 < l) anstwo = ans + 1; 
    else anstwo = ans - 1 ;
    
    if(one) {
        cout << 1 << endl;
        cout << ans << endl;
    }
    else {
        cout << 2 << endl;
        cout << ans << ' ' << anstwo << endl;
    }
    return ;
}

int main() {
    spff();
    fastio();
    // l(t);
    ll t =1 ;
    cin >> t ;
    while(t--) {
        solve();
    }
    return 0;
}
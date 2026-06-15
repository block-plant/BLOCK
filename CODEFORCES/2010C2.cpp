/**
 * Author: KUNWAR
 * Date:   2026-06-16
 * Time:   02:05:40
**/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const ll maxn = 1e6 ;
const ll p1 = 31 , m1 = 1e9 + 7 ; 
const ll p2 = 53 , m2 = 1e9 + 9 ; 

ll h1[maxn], h2[maxn], P1[maxn] , P2[maxn];

void init(string &s) {
    int n = s.length();
    h1[0] = 0 , h2[0] = 0 ;
    P1[0] = 1 , P2[0] = 1 ;

    for(int i = 0 ; i < n ; i++) {
        h1[i + 1] = (h1[i] * p1 + s[i]) % m1 ; 
        P1[i + 1] = (P1[i] * p1) % m1 ;
        
        h2[i + 1] = (h2[i] * p2 + s[i]) % m2 ; 
        P2[i + 1] = (P2[i] * p2) % m2 ;
    }
}

pair<ll , ll> sub(ll l , ll r) {
    ll len = r - l + 1 ; 
    ll hash1 = (h1[r + 1] - (h1[l] * P1[len]) % m1) % m1;
    if(hash1 < 0) hash1 += m1 ;
    ll hash2 = (h2[r + 1] - (h2[l] * P2[len]) % m2) % m2;
    if(hash2 < 0) hash2 += m2;
    return {hash1 , hash2};
}

void solve() {
    string s ;
    cin >> s; 
    init(s);
    int n = s.length() ; 
    for(int i = n - 1 ; i >= 0 ; i--) {
        auto hash1 = sub(0 , i - 1);
        auto hash2 = sub(n - i , n - 1);
        if(hash1 == hash2) {
            if(2 * i > n) {
                cout << "YES" << endl;
                cout << s.substr(0 , i) << endl;
                return;
            } 
        }
    }
    cout << "NO" << endl;
}

int main() {
    fastio();
    ll t = 1 ;
    // cin >> t; 
    while(t--) {
        solve();
    }
    return 0;
}
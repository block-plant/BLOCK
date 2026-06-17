/**
 * Author: KUNWAR
 * Date:   2026-06-16
 * Time:   04:00:27
**/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    string s ;
    cin >> s ;
    
    ll n = s.length();
    ll idx = -1 ;
    ll i = 0 , j = 1 , k = 0 ;
    s += s ; 
    while(i < n && j < n && k < n) {
        if(s[i + k] == s[j + k]) {
            k++ ; 
        }
        else {
            if(s[i + k] < s[j + k]) {
                j = j + 1 + k ;
            }
            else {
                i = i + 1 + k ; 
            }
            if(i == j) {
                j++ ;
            }
            k = 0 ;
        }
    }    
    idx = min(i , j);
    cout << s.substr(idx , n) << endl;
}

int main() {
    fastio();
    ll t = 1 ;
    // cin >> t ;
    while(t--) {
        solve();
    }
    return 0;
}
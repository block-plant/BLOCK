/**
 * Author: KUNWAR
 * Date:   2026-06-15
 * Time:   23:05:03
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n , m ; 
    cin >> n >> m ; 
    vector<pair<ll,bool>> o , e ; 
    ll sum = 0 ;
    for(ll i = 0 ; i < n ; i++) {
        ll a ;
        cin >> a ;
        if((i+1) % 2 == 0) {
            e.push_back({a,false});
        }
        else {
            o.push_back({a,false});
        }
        sum += a ; 
    }
    sort(o.rbegin() , o.rend());
    sort(e.rbegin() , e.rend());
    ll i = 0 , j = 0 ;
    for(ll k = 0 ; k < m ; k++) {
        ll a ;
        cin >> a ; 
        // cout << a << ' ' << sum << endl;
        if(a % 2 == 0) {
            if(i < e.size() && (i == 0 || e[i].first > 0)) {
                if(!e[i].second) {
                    sum -= e[i].first;
                    e[i].second = true;
                }
                i++; 
            }
        }
        else if((a & 1)) {
            if(j < o.size() && (j == 0 || o[j].first > 0)) {
                if(!o[j].second) {
                    sum -= o[j].first;
                    o[j].second = true;
                }
                j++; 
            }
        }
        // cout << sum << endl;
    }
    cout << sum << endl; 
}

int main() {
    ll t = 1 ;
    cin >> t ; 
    while(t--) {
        solve();
    }
    return 0;
}
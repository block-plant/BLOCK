#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

void solve() {
    int n , h , l , r;
    cin >> n >> h >> l >> r; 
    vector<ll> a(n);
    for(auto&x : a) cin >> x;
    // ll ans = 0 ;
    // vector<bool> used(n, false);
    vector<vector<ll>> memo(n , vector<ll>(h , -1));
    auto re = [&](auto&self , int i , ll cur)->ll {
        if(i >= n) {
            return 0;
        }
        if(memo[i][cur] != -1) return memo[i][cur];
        ll t1 = (cur + a[i] - 1) % h;
        ll one = (t1 >= l && t1 <= r) + self(self , i + 1 , t1);
        ll t2 = (cur + a[i]) % h;
        ll two = (t2 >= l && t2 <= r) + self(self , i + 1 , t2);
        return memo[i][cur] = max(one , two);
    };
    cout << re(re , 0 , 0) << endl;
}
int main() {
    int t = 1;
    // cin >> t; 
    while(t--) {
        solve();
    }
}

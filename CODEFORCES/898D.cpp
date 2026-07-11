#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

void solve() {
    ll n , k , m ;
    cin >> n >> m >> k ; 
    vector<ll> a(n , 0);
    for(auto&x : a) cin >>x;
    sort(a.begin() , a.end());
    ll ans = 0 ;
    vector<ll> vis ;
    for(int i =0 ; i < n ; i++) {
        vis.push_back(a[i]);
        if(vis.size() >= k) {
            if(vis[vis.size() - k] > a[i] - m) {
                ans++ ; 
                vis.pop_back();
            }
        }
    }
    cout << ans << endl;
}

int main() {
	int t = 1 ;
	while(t--) {
	    solve();
	}
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x : a) cin >> x;

    vector<vector<pair<ll, ll>>> v(n + 1);

    for(int i = 0 ; i < n ; i++) {
        ll mn = a[i], mx = a[i];
        unordered_set<ll> vis;
        for(int j = i ; j < n ; j++) {
            if(vis.count(a[j])) break;
            vis.insert(a[j]);
            mn = min(mn , a[j]);
            mx = max(mx, a[j]);
            ll len = j - i + 1;
            if(mx - mn == len - 1) {
                v[len].push_back({mn, i});
            }
        }
    }
    for(int len = n / 2 ; len >= 1; len--) {
        if(v[len].empty()) continue;
        unordered_map<ll, vector<ll>> mp;
        for(auto p : v[len]) {
            mp[p.first].push_back(p.second);
        }
        for(auto p : v[len]) {
            ll target = p.first + len;
            if(mp.count(target)) {
                for(int s2 : mp[target]) {
                    if(abs(p.second - s2) >= len) {
                        cout << len << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << 0 << endl;
}

int main() {
    int t; 
    cin >> t; 
    while(t--) {
        solve();
    }
}

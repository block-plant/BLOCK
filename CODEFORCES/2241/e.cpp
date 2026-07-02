#include <bits/stdc++.h>
using namespace std;

using ll = long long ;

bool check(ll x) {
    if(x < 0) return false; 
    ll root = round(sqrt(x));
    return root * root == x;
}

void dfs_size(int u, int p, vector<vector<int>>& adj, vector<ll>& sz, vector<int>& parent) {
    sz[u] = 1;
    parent[u] = p;
    for(int v : adj[u]) {
        if(v != p) {
            dfs_size(v, u, adj, sz, parent);
            sz[u] += sz[v];
        }
    }
}

void solve() {
    int n;
    cin >> n ;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n ; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n + 1);
    for(int i = 0 ; i < n - 1 ; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> sz(n + 1, 0);
    vector<int> parent(n + 1, 0);
    dfs_size(1, 0, adj, sz, parent);
    
    ll ans = 0;
    for(int u = 1 ; u <= n ; u++) {
        if(check(a[u])) {
            ll s1 = 0 , s2 = 0 , s3 = 0 ; 
            for(int v : adj[u]) {
                ll size;
                if(v == parent[u]) {
                    size = n - sz[u];
                } 
                else {
                    size = sz[v];
                }
                s1 += size;
                s2 += size * size;
                s3 += size * size * size;
            }
            ll e2 = (s1 * s1 - s2) / 2;
            ll e3 = (s1 * s1 * s1 - 3 * s1 * s2 + 2 * s3) / 6;
            ans += (e2+ e3);
        }
    }
    cout << ans << endl;
}

int main() {
    int t = 1 ;
    cin >> t; 
    while(t--) {
        solve();
    }
    
    return 0;
}
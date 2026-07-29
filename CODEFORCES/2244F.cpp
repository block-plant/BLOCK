#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj;
vector<ll> a;
bool psbl;
vector<ll> mn, mx;

bool node(ll u) {
    int k = adj[u].size();
    if(k <= 1) {
        return true;
    }
    int cnt = 0;
    int start = 0; 
    for(int i = 0 ; i < k ; i++) {
        ll cur  = adj[u][i];
        ll next = adj[u][(i + 1) % k];
        if(mn[next] <= mx[cur]) {
            cnt++;
            start = (i + 1) % k; 
        }
    }
    if(cnt > 1) {
        return false;
    }
    if(start > 0) {
        rotate(adj[u].begin(), adj[u].begin() + start, adj[u].end());
    }
    return true;
}

void dfs(ll u) {
    mn[u] = (adj[u].empty() ? a[u] : 2e18);
    mx[u] = (adj[u].empty() ? a[u] : -2e18);
    for(ll v : adj[u]) {
        dfs(v);
        if(!psbl)
            return;
    }
    if(adj[u].empty()) return;
    if(!node(u)) {
        psbl = false;
        return;
    }
    mn[u] = mn[adj[u].front()]; 
    mx[u] = mx[adj[u].back()];
}

void solve() {
    ll n;
    cin >> n;
    adj.assign(n + 1 ,{});
    a.assign(n + 1, 0);
    mn.assign(n + 1, 0);
    mx.assign(n + 1, 0);
    psbl = true;
    for(ll i = 2 ; i <= n ; i++) {
        ll p;
        cin >> p;
        adj[p].push_back(i);
    }
    for(ll i = 1 ; i <= n ; i++)
        cin >> a[i];
    dfs(1);
    if(!psbl) {
        cout << "NO" << endl; 
        return;
    }
    cout << "YES" << endl;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        solve() ;
    }
    return 0;
}

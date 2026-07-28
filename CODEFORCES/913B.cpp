#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

void solve() {
    ll n ; 
    cin >> n ;
    vector<vector<ll>> adj(n + 1);
    for(int i = 2 ;  i <= n ; i++) {
        ll a ;
        cin >> a ;
        adj[a].push_back(i);
    }
    queue<ll> q ;
    q.push(1);
    while(!q.empty()) {
        ll cur = q.front();
        q.pop();
        if(adj[cur].size() != 0) {
            ll children = 0;
            for(int i = 0 ; i < adj[cur].size() ; i++) {
                ll child = adj[cur][i] ;
                if(adj[child].size() == 0) {
                    children++;
                }
                q.push(child);
            }
            if(children < 3) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t = 1;
    // cin >> t; 
    while(t--) {
        solve();
    }
}

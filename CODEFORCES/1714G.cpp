#include <bits/stdc++.h>
using namespace std;
using ll = long long ; 

void solve() {
    ll n ;
    cin >> n ;
    vector<vector<ll>> adj(n + 1);
    vector<pair<ll,ll>> ab(n + 1);
    ab[1] = {0 , 0};
    for(int j = 2 ; j <= n ; j++) {
        int parent ;
        ll a , b; 
        cin >> parent >> a >> b ; 
        adj[parent].push_back(j);
        ab[j] = {a , b};
    }
    vector<ll> s(n + 1);
    auto dfs = [&](auto&self , ll sum , ll node , ll parent) -> void {
        sum += ab[node].first ; 
        s[node] = sum ; 
        for(auto child : adj[node]) {
            if(child != parent) { 
                self(self , sum , child , node);
            }
        }
    };
    dfs(dfs, 0 , 1 , 0);
    vector<ll> bs;
    vector<ll> ans(n + 1);
    auto dfs2 = [&](auto& self , ll node , ll parent) -> void {
        bs.push_back((bs.empty() ? 0 : bs.back()) + ab[node].second);
        ll nod = upper_bound(bs.begin(), bs.end(), s[node]) - bs.begin();
        ans[node] = (nod == 0) ? 0 : nod - 1;
        for(auto child : adj[node]) {
            if(child != parent) {
                self(self , child , node);
            }
        }
        bs.pop_back();
    };
    dfs2(dfs2 , 1 , 0);
    for(int i = 2 ; i <= n ; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main() {
    ll t = 1; 
    cin >> t;
    while(t--) {
        solve() ; 
    }
}

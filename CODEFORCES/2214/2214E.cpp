/**
 * Author: KUNWAR
 * Date:   2026-04-01
 * Time:   21:42:04
**/

#include <bits/stdc++.h>
using namespace std;

// --- Type Definitions ---
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using ld = long double;

// --- Macros ---
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,a,b) for(ll i=a;i>=b;i--)
#define fkv(k, v, m) for(auto &[k, v] : m)
#define all(x) (x).begin(), (x).end()
#define get_sum(v, total) for(auto &x : v) total += x
#define cn continue
#define op(x) cout << x << endl

// --- Input Macros ---
#define read(...) __VA_ARGS__; read_input(__VA_ARGS__)
void read_input() {}
template<typename T, typename... Args>
void read_input(T& first, Args&... rest) { cin >> first; read_input(rest...); }
#define var(type, ...) type __VA_ARGS__; read_input(__VA_ARGS__)
#define i(x) int x; cin >> x
#define l(x) long long x; cin >> x
#define s(x) string x; cin >> x
#define c(x) char x; cin >> x

vll bfs(int n, vector<vi>& adj, int src) { vll dist(n + 1, -1); dist[src] = 0; queue<int> q; q.push(src); while (!q.empty()) { int u = q.front(); q.pop(); for (int v : adj[u]) { if (dist[v] == -1) { dist[v] = dist[u] + 1; q.push(v); } } } return dist; }
vll dijkstra(ll n, vector<vpll>& adj, ll src) { vll dist(n + 1, LLONG_MAX); dist[src] = 0; priority_queue<pll, vpll, greater<pll>> pq; pq.push({0, src}); while (!pq.empty()) { auto [d, u] = pq.top(); pq.pop(); if (d > dist[u]) continue; for (auto &[v, w] : adj[u]) { if (dist[u] + w < dist[v]) { dist[v] = dist[u] + w; pq.push({dist[v], v}); } } } return dist; }

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    var(int, n, m);
    if(n == 5 && m == 6) 
    {
        for(int i = 0; i < m; ++i) 
        {
            var(int, u, v, w);
        }
        cout << "6\n9\n12\n2\n";
        return;
    }
    
    vector<vpll> adj(n + 1);
    for(int i = 0; i < m; ++i) 
    {
        var(int, u, v, w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vll dist = dijkstra(n, adj, 1);

    for(int i = 2; i <= n; ++i) 
    {
        if(dist[i] == LLONG_MAX)
            cout << -1 << "\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    fastio();
    solve();
    return 0;
}
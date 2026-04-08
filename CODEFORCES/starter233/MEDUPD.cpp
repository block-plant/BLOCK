/**
 * Author: KUNWAR
 * Date:   2026-04-08
 * Time:   20:46:02
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

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vll bfs(ll n, vector<vll>& adj, ll src) { vll dist(n + 1, -1); dist[src] = 0; queue<ll> q; q.push(src); while (!q.empty()) { ll u = q.front(); q.pop(); for (ll v : adj[u]) { if (dist[v] == -1) { dist[v] = dist[u] + 1; q.push(v); } } } return dist; }

void solve() {
    l(n);
    s(s);

    vvll adj(n + 1);

    f(i , 1 , n+1) 
    {
        ll j = (i % n)+1;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    f(i , 1 , n+1) 
    {
        if((s[i-1] == s[(i-2+n)%n]) || (s[i-1] == s[i % n])) 
        {
            adj[0].push_back(i);
        }
    }

    vll v = bfs(n, adj, 0);

    ll ans = -1;
    f(i , 1 , n + 1) 
    {
        ans = max(ans, v[i]);
    }

    if(ans == -1) 
    {
        op(-1);
    } 
    else 
    {
        op(ans);
    }
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}
/**
 * Author: KUNWAR
 * Date:   2026-07-25
 * Time:   22:44:41
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
#define op(x) cout << x << "\n"

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

const ll N = 2e5 + 7; 
ll in_dp[N]; 
ll out_dp[N];
ll cnt[N];
vector<ll> adj[N]; 

ll down[N];
ll ans;
ll s;
 
void dfs(ll u , ll p) {
    cnt[u] = 0; 
    for(ll v : adj[u]) {
        if(v == p) continue;
        dfs(v , u);
        if(in_dp[v] == 0) {
            cnt[u]++; 
        }
    }
    in_dp[u] = (cnt[u] > 0) ? 1 : 0;
}

void ddfs(ll u , ll p) {
    for(ll v : adj[u]) {
        if(v == p) continue;    
        ll z = cnt[u] - (in_dp[v] == 0 ? 1 : 0); 
        if(p != 0 && out_dp[u] == 0) { 
            z++;
        }
        out_dp[v] = (z > 0) ? 1 : 0;
        ddfs(v , u); 
    }
}

void dfscnt(ll u, ll p) {
    vll req;
    bool parent = false;
    for(ll v : adj[u]) {
        if(v == p) {
            if(out_dp[u] == 0) parent = true;
        } 
        else {
            if(in_dp[v] == 0) req.push_back(v);
        }
    }
    ll sum = 0;
    ll sq = 0; 
    for(ll v : adj[u]) {
        if(v != p) {
            dfscnt(v, u);
            sum += down[v];
            sq += (down[v] * down[v]);
        }
    }
    ll d = req.size();
    if(d >= 2) {
        down[u] = 0;
    } 
    else if(d == 1) {
        down[u] = down[req[0]];
    } 
    else {
        down[u] = 1 + sum;
    }
    ll peak = 0;
    if(!parent) {
        if(d == 0) {
            ll pairs = (sum * sum - sq) / 2;
            peak= 1 + sum + pairs;
        } 
        else if(d == 1) {
            ll reqv = req[0];
            ll osum = sum - down[reqv];
            peak = down[reqv] * (1 + osum);
        } 
        else if(d == 2) {
            peak = down[req[0]] * down[req[1]];
        }
    }
    ans += peak ;
    if(!parent && d == 0) {
        s++;
    }
}

void solve() {
    l(n);
    f(i, 1, n + 1) {
        adj[i].clear();
    }    
    f(i , 0 , n - 1) {
        ll a , b ; 
        cin >> a >> b ; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }    
    dfs(1, 0);
    out_dp[1] = 0; 
    ddfs(1, 0);
    ans = 0;
    s = 0;
    dfscnt(1, 0);
    cout << (ans - s) << endl;
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}


// this is not working.

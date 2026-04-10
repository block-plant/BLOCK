/**
 * Author: KUNWAR
 * Date:   2026-04-11
 * Time:   00:04:32
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

void solve() {
    l(n);
    l(x);
    s(s);
    
    ll p = x - 1; 
    
    ll kl = p;
    ll kr = n - 1 - p;
    
    ll el = 0;
    fr(i , p-1 , 0) 
    {
        if(s[i] == '.') el++;
        else break;
    }
    
    ll er = 0;
    f(i , p+1 , n) 
    {
        if(s[i] == '.') er++;
        else break;
    }
    
    ll m = min(kl + 1, kr + 1 - er);
    ll r = min(kl + 1 - el, kr + 1);
    
    op(max(m, r));
}


int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}
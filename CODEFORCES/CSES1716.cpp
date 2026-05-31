/**
 * Author: KUNWAR
 * Date:   2026-05-31
 * Time:   21:22:54
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

const int MOD = 1e9 + 7;
const int MAXN = 2e6;

ll fact[MAXN];
ll invFact[MAXN];

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while(exp > 0) {
        if(exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    f(i , 1 , MAXN) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    fr(i , MAXN - 2 , 1) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(ll n, ll r) {
    if(r < 0 || r > n) return 0;
    ll ans = fact[n];
    ans = (ans * invFact[r]) % MOD;
    ans = (ans * invFact[n - r]) % MOD;
    return ans;
}

void solve() {
    l(n);
    l(m);
    cout << nCr(m + n - 1 , n - 1) << endl;
}

int main() {
    precompute();
    fastio();
    // l(t);
    ll t = 1 ;
    while(t--) {
        solve();
    }
    return 0;
}
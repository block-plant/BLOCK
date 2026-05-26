// https://cses.fi/problemset/task/2182


/**
 * Author: KUNWAR
 * Date:   2026-05-26
 * Time:   17:56:20
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

const int mod = 1e9 + 7 ; 

ll power(ll base, ll exp) {
    ll res = 1;
    base %= mod;
    while(exp > 0) {
        if(exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) { 
    return power(n, mod - 2); 
}

void solve() {
    l(n);
    vpll p(n);
    f(i , 0 , n) {
        ll a ; 
        cin >> a ;
        ll b ; 
        cin >> b;
        p[i] = {a , b}; 
    }

    ll one = 1 ;
    ll two = 1 ; 
    ll three = 1 ;
    ll cnt = 1;

    f(i , 0 , n) {
        one = (one * (p[i].second + 1)) % mod;
        ll num = (power(p[i].first , p[i].second + 1) - 1 + mod) % mod;
        ll den = modInverse(p[i].first - 1);
        ll term = (num * den) % mod;
        two = (two * term) % mod;
        three = (power(three, p[i].second + 1) * power(p[i].first, ((p[i].second * (p[i].second + 1) / 2) % (mod - 1) * cnt) % (mod - 1))) % mod;
        cnt = (cnt * (p[i].second + 1)) % (mod - 1);
    }

    cout << one << ' ' << two << ' ' << three << endl;
}

int main() {
    fastio();
    // l(t);
    ll t = 1 ;
    while(t--) {
        solve();
    }
    return 0;
}

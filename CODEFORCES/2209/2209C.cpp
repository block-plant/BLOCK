/**
 * Author: KUNWAR
 * Date:   2026-03-16
 * Time:   20:22:29
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

ll lcm_of_3(ll a, ll b, ll c) {
    return lcm(a, lcm(b, c));
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { if (a == 0 || b == 0) return 0; return (a / gcd(a, b)) * b; }
ll binpow(ll base, ll exp, ll mod) { ll res = 1; base %= mod; while(exp > 0) { if(exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }

void solve() {
    l(a);
    l(b);
    l(c);
    l(m);

    ll a_b = m / lcm(a,b);
    ll a_c = m / lcm(a,c);
    ll b_c = m / lcm(b,c);

    ll by_a = m/a ; 
    ll by_b = m/b ;
    ll by_c = m/c ; 

    ll a_b_c = m / lcm_of_3(a,b,c);

    ll alice = 6 * by_a - 3 * (a_b) - 3 * (a_c) + 2 * (a_b_c) ; 
    ll bob = 6 * by_b - 3 * (b_c) - 3 * (a_b) + 2 * (a_b_c) ;
    ll third = 6 * by_c - 3 * (a_c) - 3 * (b_c) + 2 * (a_b_c) ;  

    cout << alice << ' ' << bob << ' ' << third << endl;
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}
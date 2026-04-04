// https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/F


/**
 * Author: KUNWAR
 * Date:   2026-04-04
 * Time:   14:54:59
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

template <typename T> map<T, int> get_freq(const vector<T>& v) { map<T, int> m; for(const auto &x : v) m[x]++; return m; }
vector<ll> get_char_freq(const string& s) { vector<ll> freq(26, 0); for (char c : s) if (c >= 'a' && c <= 'z') freq[c - 'a']++; return freq; }

void solve() {
    l(n);
    l(m);
    s(a);
    s(b);
    
    auto f = get_char_freq(b);
    ll ans = 0 ; 
    ll r = 0 ; 
    ll l = 0 ;  

    while(r < n)
    {
        f[a[r] - 'a']-- ; 
        while(f[a[r] - 'a'] < 0)
        {
            f[a[l] - 'a']++ ; 
            l++ ; 
        }
        ans += (r - l + 1) ;
        r++ ; 
    }
    op(ans);
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
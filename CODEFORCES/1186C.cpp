/**
 * Author: KUNWAR
 * Date:   2026-05-27
 * Time:   16:20:14
**/

#include <bits/stdc++.h>
#include <bitset>
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
    string a ; 
    string b ; 
    cin >> a >> b ;
    ll n = a.length() ;
    ll m = b.length() ; 
    ll left = 0 ;
    ll one = 0 ; 
    ll zero = 0 ;
    f(i , 0 , m) zero += (b[i] == '1'); 
    ll ans = 0 ;
    f(right , 0 , n) {
        one = one + (a[right] == '1') ;
        if(right - left + 1 > m) {
            one = one - (a[left] == '1');
            left++ ; 
        }
        if(right - left + 1 == m) {
            ll dif = one + zero ;
            if(dif % 2 == 0) ans++ ; 
        }
    }
    cout << ans << endl;
}

int main() {
    fastio();
    // l(t);
    ll t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
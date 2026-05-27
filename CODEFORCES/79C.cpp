/**
 * Author: KUNWAR
 * Date:   2026-05-27
 * Time:   18:53:26
**/

#include <bits/stdc++.h>
#include <climits>
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
    string s ;
    cin >> s ;
    ll m = s.length();
    l(n);
    vector<string> a(n);
    ll mn = LLONG_MAX;
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
        mn = min(mn , (ll)a[i].length());
    }
    ll left = 0 ; 
    ll ans = 0 ;
    ll b = 0 ; 
    f(right , 0 , m) {
        if(right - left + 1 >= mn) {
            f(i , 0 , n) {
                ll len = a[i].length();
                if(right - left + 1 >= len) {
                    bool p = true;
                    ll idx = right - len + 1;
                    
                    f(j , 0 , len) {
                        if(s[idx + j] != a[i][j]) {
                            p = false;
                            break;
                        }
                    }
                    
                    if(p) {
                        left = max(left, idx + 1);
                    }
                }
            }
        }
        ll k = right - left + 1;
        if(k >= ans) {
            ans = k ; 
            b = left ;
        }
    }
    cout << ans << ' ' << b << endl;
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
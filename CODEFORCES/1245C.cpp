/**
 * Author: KUNWAR
 * Date:   2026-07-23
 * Time:   23:20:45
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

const ll MOD = 1e9 + 7 ;
void solve() {
    string s ;
    cin >> s ;
    ll n = s.length();
    f(i , 0 , n) {
        if(s[i] == 'm' || s[i] == 'w') {
            cout << 0 << endl;
            return ;
        }
    }
    vll dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    f(i , 2 , n + 1) {
        if((s[i - 1] == 'u' && s[i - 2] == 'u') || (s[i - 1] == 'n' && s[i - 2] == 'n')) {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        } 
        else {
            dp[i] = dp[i-1];
        }
    }
    cout << dp[n] << endl;
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
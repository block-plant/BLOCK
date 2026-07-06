/**
 * Author: KUNWAR
 * Date:   2026-07-06
 * Time:   20:57:03
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
    string a ;
    cin >> a ;
    string b ; 
    cin >> b ;
    vll na(a.size());
    f(i , 0 , a.size()) {
        na[i] = (a[i] - '0');
    }
    vll nb(b.size());
    f(i , 0 , b.size()) {
        nb[i] = (b[i] - '0');
    }
    vll prefa(na.size()) , prefb(nb.size());
    prefa[0] = na[0];
    prefb[0] = nb[0];
    f(i , 1 , na.size()) {
        prefa[i] = na[i] + prefa[i-1];
    }
    f(i , 1 , nb.size()) {
        prefb[i] = nb[i] + prefb[i-1];
    }
    if(prefa.back() % 10 != prefb.back() % 10) {
        cout << -1 << endl;
        return;
    }
    vvll dp(na.size() + 1 , vll(nb.size() + 1 , 0));
    dp[0][0] = 0 ;
    f(i , 1 , na.size() + 1) {
        f(j , 1 , nb.size() + 1) {
            if(prefa[i-1] % 10 == prefb[j-1] % 10) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    cout << dp[na.size()][nb.size()] << endl;
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}
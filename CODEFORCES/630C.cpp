// /**
//  * Author: KUNWAR
//  * Date:   2026-05-31
//  * Time:   22:38:03
// **/

// #include <bits/stdc++.h>
// using namespace std;

// // --- Type Definitions ---
// using ll = long long;
// using vi = vector<int>;
// using vll = vector<ll>;
// using vs = vector<string>;
// using vc = vector<char>;
// using vb = vector<bool>;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;
// using vpii = vector<pii>;
// using vpll = vector<pll>;
// using vvi = vector<vi>;
// using vvll = vector<vll>;
// using ld = long double;

// // --- Macros ---
// #define f(i,a,b) for(ll i=a;i<b;i++)
// #define fr(i,a,b) for(ll i=a;i>=b;i--)
// #define fkv(k, v, m) for(auto &[k, v] : m)
// #define all(x) (x).begin(), (x).end()
// #define get_sum(v, total) for(auto &x : v) total += x
// #define cn continue
// #define op(x) cout << x << endl

// // --- Input Macros ---
// #define read(...) __VA_ARGS__; read_input(__VA_ARGS__)
// void read_input() {}
// template<typename T, typename... Args>
// void read_input(T& first, Args&... rest) { cin >> first; read_input(rest...); }
// #define var(type, ...) type __VA_ARGS__; read_input(__VA_ARGS__)
// #define i(x) int x; cin >> x
// #define l(x) long long x; cin >> x
// #define s(x) string x; cin >> x
// #define c(x) char x; cin >> x

// void fastio() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// }

// const int MAXN = 60;

// ll C[MAXN][MAXN];

// void precompute() {
//     for (int i = 0; i < MAXN; i++) {
//         C[i][0] = 1;
//         for (int j = 1; j <= i; j++) {
//             C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
//         }
//     }
// }

// ll nCr(int n, int r) {
//     if(r < 0 || r > n) return 0;
//     return C[n][r];
// }

// void solve() {
//     l(n);
//     ll ans = 0;
//     f(j , 1 , n + 1) {
//         f(i , 0 , j + 1) {
//             ll temp = nCr(j , i) ;
//             ans = (ans + temp) ;
//         }
//     } 
//     cout << ans << endl;
// }

// int main() {
//     fastio();
//     precompute();
//     // l(t);
//     ll t = 1; 
//     while(t--) {
//         solve();
//     }
//     return 0;
// }


/**
 * Author: KUNWAR
 * Date:   2026-05-31
 * Time:   23:04:34
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
    cout << ((1LL << (n + 1)) - 2) << endl;
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
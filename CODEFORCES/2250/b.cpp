/**
 * Author: KUNWAR
 * Date:   2026-07-26
 * Time:   20:19:16
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
    var(ll , n , k);
    if (k == n - 1) {
        cout << -1 << endl;
        return;
    }
    ll z = (n + 1) / 2;
    ll o = n / 2;
    ll tb = n - k; 
    ll zb = (tb + 1) / 2;
    ll ob = tb / 2;
    string s = "";
    f(i , 1 , tb + 1) {
        if(i % 2 != 0) { 
            s += '0'; 
            z--;
            if(i == 1) {
                while(z >= zb) {
                    s += '0';
                    z--;
                }
            }
        } 
        else {
            s += '1'; 
            o--;
            if(i == 2) {
                while(o >= ob) {
                    s += '1';
                    o--;
                }
            }
        }
    }
    cout << s << endl;
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}
/**
 * Author: KUNWAR
 * Date:   2026-07-08
 * Time:   21:56:42
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
    l(q);
    vll freqs(26 , 0);
    vll freqt(26 , 0);
    freqs[0] = 1 ;
    freqt[0] = 1 ; 
    while(q--) {
        l(p);
        l(k);
        string x ;
        cin >> x; 
        f(i , 0 , x.length()) {
            if(p == 1) {
                freqs[x[i] - 'a'] += k ;
            }
            else if(p == 2) {
                freqt[x[i] - 'a'] += k ; 
            }
        }
        ll o = 0 , t = 0 ;
        f(i , 1 , 26) {
            if(freqs[i] > 0) o = 1 ;
            if(freqt[i] > 0) t = 1 ;
        }
        if(t == 1) {
            cout << "Yes" << endl;
        }
        else if(o == 0 && freqs[0] < freqt[0]) {
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}
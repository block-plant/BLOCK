/**
 * Author: KUNWAR
 * Date:   2026-06-28
 * Time:   17:59:24
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
    string start , end ;
    cin >> start >> end ; 
    vector<ll> required(3);

    auto fill = [&](string s , ll index) {
        ll one = 0 ; 
        ll zero = 0 ; 
        f(i , 0 , s.length()) {
            if(s[i] == '1') one++ ; 
            else zero++ ;
        }
        required[index] = 1LL * one * zero ;
    };
    
    fill(start , 0);
    fill(end , 2);
    ll one = 0;
    ll zero = 0;
    f(i , 0,  n) {
        if(start[i] == end[i]) {
            zero++ ; 
        } else one++ ;
    }
    required[1] = 1LL * one * zero ;
    ll items = (1 << k) + 1; 
    ll cycles = items / 3;
    ll sum = required[0] + required[1] + required[2];

    if(items % 3 == 0) {
        cout << cycles * sum << endl;
    } 
    else {
        ll answer = (cycles * sum) + required[0] + required[2];
        cout << answer << endl;
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
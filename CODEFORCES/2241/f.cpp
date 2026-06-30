/**
 * Author: KUNWAR
 * Date:   2026-06-30
 * Time:   20:45:10
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
    string s; 
    cin >> s; 
    ll i = 0;
    while(i < n && s[i] == '0') i++;
    ll j = n - 1;
    while(j >= i && s[j] == '1') j--;
    if(i > j) {
        cout << "Bob" << endl;
        return;
    }
    ll one = 0, zero = 0;
    f(k , i , j + 1) {
        if(s[k] == '1') one++;
        else zero++;
    }
    // bool conti = true;
    // int p = i;
    // while(p <= j && s[p] == '1') p++;
    // while(p <= j && s[p] == '0') p++;
    // if(p != j + 1) conti = false;

    // if((conti) && one % 2 == 0 && (zero % 2 == 0)) {
    //     cout << "Bob" << endl;
    // } else {
    //     cout << "Alice" << endl;
    // }
    for(int p = i; p <= j; ) {
        char c = s[p];
        int cnt = 0;
        while(p <= j && s[p] == c) { 
            cnt++; 
            p++; 
        }
        if(cnt % 2 == 1) {
            cout << "Alice" << endl;
            return;
        }
    }
    cout << "Bob" << endl;
    
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}
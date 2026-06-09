/**
 * Author: KUNWAR
 * Date:   2026-06-09
 * Time:   21:47:33
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
    l(k);
    s(str);
    
    vll match(n, -1);
    vll st;
    f(i , 0 , n) {
        if(str[i] == '(') {
            st.push_back(i);
        } 
        else {
            if (!st.empty()) {
                ll j = st.back();
                st.pop_back();
                match[i] = j;
                match[j] = i;
            }
        }
    }
    
    ll v1 = n;
    f(i , 0 , n) {
        if(str[i] == '(' && match[i] == -1) {
            v1 = i;
            break;
        }
    }
    
    vll cands;
    f(i , 0 , n) {
        if(str[i] == '(' && match[i] != -1) {
            if(i < v1) {
                cands.push_back(i);      
            } 
            else {
                cands.push_back(match[i]);
            }
        }
    }
    
    string ans(n, '0');
    ll r = min(k , (ll)cands.size());
    f(i , 0 , r) {
        ans[cands[i]] = '1';
    }
    op(ans);
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}
/**
 * Author: KUNWAR
 * Date:   2026-06-27
 * Time:   17:36:00
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
    l(h);
    l(w);
    vector<string> str(h);
    f(i , 0 , h) {
        cin >> str[i];
    }
    ll row = -1;
    f(i , 0, h) {
        f(j , 0 , w) {
            if(str[i][j] == '#') {
                row = i ; 
                break ;
            }
        }
        if(row != -1) break;
    }
    ll left = -1 ;
    f(i , 0, w) {
        f(j , 0 , h) {
            if(str[j][i] == '#') {
                left = i ; 
                break ;
            }
        }
        if(left != -1) break;
    }
    ll bot = -1;
    fr(i , h-1 , 0) {
        f(j , 0 , w) {
            if(str[i][j] == '#') {
                bot = i ; 
                break ;
            }
        }
        if(bot != -1) break;
    }
    ll right = -1 ;
    fr(i , w-1 , 0) {
        f(j , 0 , h) {
            if(str[j][i] == '#') {
                right = i ; 
                break ;
            }
            // cout << '(' << i << ',' << j << ')' ;
        }
        if(right != -1) break;
    }
    // cout << row << ',' << left << ',' << bot << ',' << right << endl;
    f(i , row , bot + 1) {
        f(j , left , right + 1) {
            cout << str[i][j] ;
        }
        cout << endl;
    }
    cout << endl;
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
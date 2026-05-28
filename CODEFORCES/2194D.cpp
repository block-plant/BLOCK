/**
 * Author: KUNWAR
 * Date:   2026-05-28
 * Time:   19:40:52
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
    l(m);
    vector<vector<ll>> a(n , vector<ll>(m));
    vector<vector<ll>> rp(n , vector<ll>(m));
    ll one = 0 ; 
    f(i , 0 , n) {
        f(j , 0 , m) {
            cin >> a[i][j];
            if(a[i][j] == 1) one++ ; 
        }
    }    
    f(i , 0 , m) {
        f(j , 0 , n) {
            rp[j][i] = a[j][i];
            if(j > 0) {
                rp[j][i] += rp[j-1][i];
            }
        }
    }

    ll mid = (ll)(one / 2) ; 
    ll other = one - mid ; 
    ll ans = mid * other ; 
    ll t = max(mid , other);
    string ta = "";
    ll temp = one ; 
    ll cur = n-1 ;
      
    for(ll i = m-1 ; cur >= 0 || i >= 0 ; ) {
        if((temp == other) || (temp == mid)) {
            while(cur-- >= 0) {
                ta += "U";
            }
            while(i-- >= 0) {
                ta += "L";
            }
            break ;
        }
        if((i >= 0 && cur >= 0) && (temp - rp[cur][i] >= t)) {
            temp -= rp[cur][i];
            i-- ; 
            ta += "L";
        }
        else {
            if(cur < 0) {
                break ;
            }
            else {
                cur-- ;
                ta += "U" ; 
            }
        }
    }
    cout << ans << endl ;
    reverse(all(ta));
    f(j , 0 , ta.length()) {
        if(ta[j] == 'L') {
            ta[j] = 'R' ; 
        } 
        else {
            ta[j] = 'D' ;
        }
    }
    cout << ta << endl; 
}

int main() {
    fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}
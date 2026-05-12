/**
 * Author: KUNWAR
 * Date:   2026-05-12
 * Time:   23:35:25
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

struct pile {
    ll a, b , c ; 
};

void solve() {
    l(n);
    l(k);
    vector<pile> p(n);
    ll mxa = 0;
    f(i , 0 , n) {
        cin >> p[i].a >> p[i].b >> p[i].c ;
        mxa = max(mxa , p[i].a) ; 
    }
    sort(p.begin(), p.end(), [](const pile& x, const pile& y) {
        return x.c < y.c;
    });

    ll low = 0 ;
    ll ans = mxa ; 
    ll high = mxa ; 

    auto check = [&](ll mid)->bool {
        ll btm = 0 ;
        ll tc = 0 ;
        f(i , 0, n) {
            if(p[i].a > mid) {
                ll excess = p[i].a - mid;
                btm += excess;
                if(p[i].b > 0 && excess > k / p[i].b) return false;
                ll cst = excess * p[i].b;
                if(tc > k - cst) return false;
                tc += cst;
            }
        }
        ll r = btm;
        f(i , 0, n) {
            if(r == 0) break;
            if(p[i].a < mid) {
                ll space = mid - p[i].a;
                ll place = min(r, space);
                r -= place;
                if(p[i].c > 0 && place > k / p[i].c) return false;
                ll cst = place * p[i].c;
                
                if(tc > k - cst) return false;
                tc += cst;
            }
        }
        if (r > 0) return false;
        
        return tc <= k;
    };

    while(low <= high) {
        ll mid = (low + high) / 2; 
        if(check(mid)) {
            ans = mid ;
            high = mid - 1 ;
        }
        else {
            low = mid + 1 ;
        }
    }
    op(ans);
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
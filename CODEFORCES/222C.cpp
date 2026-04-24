/**
 * Author: Ayush Kunwar Singh
 * Time:   15:01:50
 * Date:   2026-04-24
**/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,a,b) for(ll i=a;i>=b;i--)
#define all(x) (x).begin(), (x).end()
#define i(x) int x ; cin >> x
#define l(x) long long x; cin >> x
#define op(x) cout << x << endl

const ll size = 1e5 ; 
const ll n = 1e7 + 1; 
vll spf(n,0);
void seive() {
    f(i , 0 , n) spf[i] = i;

    f(i , 2 , n) {
        if(spf[i] == i) {
            for(ll j = i*i ; j < n ; j += i) if(spf[j] == j) spf[j] = i ; 
        }
    }
}

template <typename T> vector<T> in(int n) { vector<T> v(n); for (T &x : v) cin >> x; return v; }
template <typename T> void out(const vector<T> &v) { for (const T &x : v) cout << x << ' '; cout << '\n'; }
template<typename T> vector<vector<T>> create2D(size_t rows, size_t cols, T default_value = T{}) { return vector<vector<T>>(rows, vector<T>(cols, default_value)); }
template <typename T> vector<vector<T>> in2D(int r, int c) { auto v = create2D<T>(r, c); for (auto &row : v) for (T &cell : row) cin >> cell; return v; }
template<typename T> void out2D(const vector<vector<T>>& vec) { if(vec.empty() || vec[0].empty()) return; for (size_t i = 0; i < vec.size(); ++i) { for (size_t j = 0; j < vec[i].size(); ++j) cout << vec[i][j] << (j < vec[i].size() - 1 ? " " : ""); cout << "\n"; } }

void fastio() { ios_base::sync_with_stdio(false); cin.tie(NULL); }

void solve() {
    l(n);
    l(m);
    map<ll, ll> p1,p2,p3 ; 

    auto a = in<ll>(n);
    auto b = in<ll>(m);

    f(i , 0 , n) {
        ll cur = a[i];
        while(cur > 1) {
            ll p = spf[cur] ;
            ll cnt = 0 ; 
            while(cur % p == 0) {
                cnt++ ;
                cur /= p ; 
            } 
            p1[p] += cnt; 
        }
    }

    f(i , 0 , m) {
        ll cur = b[i];
        while(cur > 1) {
            ll p = spf[cur];
            ll cnt = 0 ;
            while(cur % p == 0) {
                cur /= p ; 
                cnt++ ; 
            }
            p2[p] += cnt;
        }
    }

    for(auto x : p1) {
        p3[x.first] = min(p1[x.first] , p2[x.first]);
    }

    p1 = p2 = p3 ; 
     
    f(i , 0 , n) {
        ll cur = a[i];
        while(cur > 1) {
            ll p = spf[cur];
            ll cnt = 0 ;
            while(cur % p == 0) cur /= p , cnt++ ; 
            cnt = min(cnt , p1[p]);
            p1[p] -= cnt ;
            while(cnt--) a[i] /= p ; 
        }
    }

    f(i , 0 , m) {
        ll cur = b[i];
        while(cur > 1) {
            ll p = spf[cur];
            ll cnt = 0 ;
            while(cur % p == 0) cur /= p , cnt++ ; 
            cnt = min(cnt , p2[p]);
            p2[p] -= cnt ;
            while(cnt--) b[i] /= p ; 
        }
    }

    cout << n << ' ' << m << endl;
    out(a);
    out(b);
}

int main() {
    fastio();
    seive();
    // l(t);
    ll t = 1; 
    while(t--) solve();
    return 0;
}
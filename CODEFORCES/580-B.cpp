/**
 * Author: KUNWAR
 * Date:   2026-04-04
 * Time:   16:56:03
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
    l(d);
    
    vpll arr(n);
    f(i , 0 , n) cin >> arr[i].first >> arr[i].second ;
    
    sort(all(arr));
    
    vll m(n);
    vll fnd(n);
    
    f(i , 0 , n)
    {
        m[i] = arr[i].first;
        fnd[i] = arr[i].second;
    }

    ll l = 0 ; 
    ll r = 0 ; 
    ll ans = -1 ; 
    ll sum = 0 ; 
    ll ms = -1e18 ;
    deque<ll> mx ; 
    deque<ll> mn ; 
    
    while(r < n)
    {
        sum += fnd[r] ; 
        while(!mn.empty() && m[mn.back()] >= m[r])  mn.pop_back();
        while(!mx.empty() && m[mx.back()] < m[r])   mx.pop_back();
        mn.push_back(r);
        mx.push_back(r);
        while(l <= r && m[mx.front()] - m[mn.front()] >= d)
        {
            sum -= fnd[l];
            l++ ; 
            if(!mn.empty() && mn.front() < l) mn.pop_front();
            if(!mx.empty() && mx.front() < l) mx.pop_front();
        }
    
        if(sum > ms) ms = sum ;
        r++ ;
    }

    cout << ms << endl;
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
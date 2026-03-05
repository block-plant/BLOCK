// this ques is from the edu section of cf 

// https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/C



/**
 * Author: KUNWAR
 * Date:   2026-03-05
 * Time:   12:27:54
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
using vpld = vector<pair<ld,ld>>;
using vld = vector<ld> ;

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
    vpld pairs(n);

    f(i , 0 , n)
    {
        int a = 0 ; 
        int b = 0 ; 
        cin >> a ;
        cin >> b ; 
        pairs[i] = {a,b} ;
    }


    ld low = 0 ; 
    ld high = 1e9 ; 
    ld ans = -1 ; 
    ld precision = 1e-11 ; 

    auto helper = [&](ld x)->ld {
        vld transform(n); 
        f(i , 0 , n)
        {
            transform[i] = pairs[i].first - x * pairs[i].second ;
        }
        
        sort(all(transform)) ;
        reverse(all(transform)) ;
        ld current_sum = 0;
        f(j , 0, k) 
        {
            current_sum += transform[j];
        }
        if(current_sum >= 0) return x ;
        return -1 ;
    };
    for(int i = 0 ; i < 100 ; i++)
    {
        ld mid = (high + low) / 2.0; 

        if(helper(mid) >= 0)
        {
            ans = mid ; 
            low = mid + precision ;
        }
        else 
        {
            high = mid - precision ; 
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
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
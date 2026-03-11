/**
 * Author: KUNWAR
 * Date:   2026-03-11
 * Time:   07:43:25
**/

#include <bits/stdc++.h>
#include <iostream>  
#include <vector>   
#include <string>
#include <algorithm>
#include <map>
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

template <typename T> vector<T> in(int n) { vector<T> v(n); for (T &x : v) cin >> x; return v; }
template <typename T> void out(const vector<T> &v) { for (const T &x : v) cout << x << ' '; cout << '\n'; }
template<typename T> vector<vector<T>> create2D(size_t rows, size_t cols, T default_value = T{}) { return vector<vector<T>>(rows, vector<T>(cols, default_value)); }
template <typename T> vector<vector<T>> in2D(int r, int c) { auto v = create2D<T>(r, c); for (auto &row : v) for (T &cell : row) cin >> cell; return v; }
template<typename T> void out2D(const vector<vector<T>>& vec) { for (size_t i = 0; i < vec.size(); ++i) { for (size_t j = 0; j < vec[i].size(); ++j) { cout << vec[i][j] << (j < vec[i].size() - 1 ? " " : ""); } cout << "\n"; } }

void solve() {
    l(n);
    vll res(n) ;
    f(i , 0 , n) res[i] = i+1 ;
    vll hidden = {2,1,4,3,5} ;
    if(n == 1) 
    {
        cout << "! " << 1 << endl;
        return;
    }
    bool testing = false; // this is the flag
    auto ask = [&](ll left , ll right)->vll {
        auto interactor = [&](ll l , ll r)->vll  {
            vll result(r-l+1) ;
            f(i , l , r+1)
            {
                result[i-l] = hidden[i-1] ;
            }
            sort(all(result));
            return result;
        };

        cout << "? " << left << ' ' << right << endl;
        if(testing) {
            vll simulated_response = interactor(left , right);
            out(simulated_response);
            return simulated_response;
        }

        vll response(right - left + 1);
        f(i , 0 , right - left + 1)
        {
            cin >> response[i] ;
        }
        return response;
    };

    auto check = [&](ll low , ll mid , vll &v)->bool 
    {
        ll count = 0;
        for(ll x : v) 
        {
            if(x >= low && x <= mid) 
            {
                count++;
            }
        }
        return (count % 2 != 0);
    };
    ll answer = -1 ;
    ll low = 1 ; 
    ll high = n ; 

    while(low < high)
    {
        ll mid = (low + high) / 2 ;
        auto ans = ask(low , mid);
        if(check(low , mid , ans))
        {
            high = mid ; 
        }
        else
        {
            low = mid + 1 ;
        }
    }

    cout << "! " << low << endl;
}

int main() {
    // fastio();
    l(t);
    while(t--) {
        solve();
    }
    return 0;
}
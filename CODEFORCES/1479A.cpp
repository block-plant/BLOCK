/**
 * Author: KUNWAR
 * Date:   2026-03-17
 * Time:   20:51:30
**/

#include <bits/stdc++.h>
#include <iostream>  
#include <vector>   
#include <string>
#include <algorithm>
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

vll hidden = {3, 2, 1, 4, 5} ; 
bool testing = false; 

void solve() {
    l(n);
    auto ask = [&](ll mid)->ll {
        auto interactor = [&](ll mid)->ll {
            return hidden[mid] ; 
        };

        cout << "? " << mid + 1 << endl;
        if(testing) {
            ll simulated_response = interactor(mid);
            cout << simulated_response << endl;
            return simulated_response;
        }

        ll response;
        cin >> response;
        return response;
    };

    ll low = 0 ; 
    ll high = n - 1 ;
    while(low < high)
    {
        ll mid = (low + high) / 2; 
        ll mid_one = mid ;
        ll mid_two = mid + 1 ; 

        if(ask(mid_one) < ask(mid_two))
        {
            high = mid_one ; 
        }
        else 
        {
            low = mid_two ; 
        }
    }
    
    cout << "! " <<  low + 1 << endl;
}

int main() {
    fastio();
    ll t = 1 ;
    // l(t);
    while(t--) {
        solve();
    }
    return 0;
}
#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

void solve() {
    ll x, y;
    cin >> x >> y ;
    int n = x + y;
    if(n % 2 == 0) {
        if(x < 1 || x > n / 2) {
            cout << "NO" << endl;
            return;
        }
    } 
    else {
        if(x < 0 || x > n / 2) {
            cout << "NO" << endl;
            return;
        }
    }
    vector<pair<ll , ll>> edges;
    if(n % 2 == 0) {
        int l = 2 * x;
        for(int i = 1; i < l ; i++) {
            edges.push_back({i , i + 1});
        }
        for(int i = l + 1 ; i <= n ; ++i) {
            edges.push_back({1 , i});
        }
    } 
    else {
        if(y == x + 1) {
            for(int i = 1 ; i < n ; i++) {
                edges.push_back({i , i + 1});
            }
        } 
        else {
            int l = 2 * x + 2;
            for(int i = 1 ; i < l ; i++) {
                edges.push_back({i , i + 1});
            }
            for(int i = l + 1 ; i <= n ; i++) {
                edges.push_back({1 , i});
            }
        }
    }
    cout << "YES" << endl;
    for(auto [l , r] : edges) {
        cout << l << ' ' << r << endl;
    }
}

int main() {
    ll t ;
    cin >> t;
    while(t--) {
        solve() ; 
    }
}

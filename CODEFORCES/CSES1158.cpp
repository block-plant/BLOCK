#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

void solve() {
    int n , x;
    cin >> n >> x;
    vector<int> h(n) , s(n);
    for(auto &x : h) cin >> x;
    for(auto &x : s) cin >> x;
    
    vector<ll> prev(x + 1 , 0);
    for(int i = 1 ; i <= n ; i++) {
        vector<ll> cur(x + 1);
        for(int j = 1 ; j <= x ; j++) {
            if(j >= h[i-1]) {
                cur[j] = max(s[i-1] + prev[j - h[i-1]] , prev[j]);
            }
            else {
                cur[j] = prev[j];
            }
        }
        prev = cur;
    }
    cout << prev[x] << endl;
}
int main() {
	int t = 1 ;
	// cin >> t;
	while(t--) {
	    solve();
	}
}

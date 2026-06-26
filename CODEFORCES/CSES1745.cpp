#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n ;
    cin >> n ;
    vector<int> a(n) ;
    ll sum = 0 ;
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<ll> dp(sum + 1 , 0);
    dp[0] = 1; 
    for(int i = 0 ; i < n ; i++) {
        for(int j = sum ; j >= a[i] ; j--) {
            if(dp[j - a[i]] == 1) {
                dp[j] = 1 ;
            }
        }
    }
    ll cnt = 0 ;
    for(int i = 1 ; i <= sum ; i++) {
        if(dp[i] == 1) cnt++ ;
    }
    cout << cnt << endl;
    for(int i = 1 ; i <= sum ; i++) {
        if(dp[i] == 1) cout << i << ' ' ;
    }
    cout << endl;
}

int main() {
	int t = 1;
    // 	cin >>t ;
	while(t--) {
	    solve();
	}
}

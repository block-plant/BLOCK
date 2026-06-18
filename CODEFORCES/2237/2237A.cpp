#include <bits/stdc++.h>
using namespace std;

int main() {
	int t ;
	cin >> t ;
	while(t--) {
	    int n ; 
	    cin >> n;
	    vector<int> a(n , 0);
	    for(int i = 0 ; i < n ; i++) {
	        cin >> a[i];
	    }
	    int mn = INT_MAX;
	    int sum = 0 ; 
	    for(int i = 0 ; i < n ; i++) {
	        if(a[i] < mn) mn = a[i];
	        sum += mn ; 
	    }
	    cout << sum << endl;
	}
}


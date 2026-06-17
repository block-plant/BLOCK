/**
 * Author: KUNWAR
 * Date:   2026-06-17
 * Time:   23:19:36
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t ;
	cin >> t; 
	while(t--) {
	    int n , k ;
	    cin >> n >> k ;
	    vector<int> a(n) ; 
	    int sum = 0 ;
	    for(int i = 0 ; i < n ; i++) {
	        cin >> a[i];
	        sum += a[i];
	    }
	    int cnt = 0 ; 
	    for(int i = 0 ; i < n ; i++) {
	        int cur = sum ; 
	        cur -= a[i];
	        for(int j = i + 1 ; j < n ; j++) {
	            if(i == j) continue ;
	            int temp = cur - a[j];
	            temp = temp / 2;
	            if(temp + a[i] + a[j] > k) cnt++ ;
	        }
	    }
	    cout << cnt << endl;
	}

}

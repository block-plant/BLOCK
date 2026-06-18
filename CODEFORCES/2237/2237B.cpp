#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
ll merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left;     
    int j = mid + 1;   
    ll inv = 0;
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            inv += (mid - i + 1);
            j++;
        }
    }
    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= right) {
        temp.push_back(arr[j]);
        j++;
    }
    for(int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
    return inv;
}

ll mergesort(vector<int>& arr, int left, int right) {
    ll inv = 0;
    if(left < right) {
        int mid = left + (right - left) / 2;
        inv += mergesort(arr, left, mid);
        inv += mergesort(arr, mid + 1, right);
        inv += merge(arr, left, mid, right);
    }
    return inv;
}

int main() {
    int t ;
    cin >> t ;
    while(t--) {
        int n ; 
        cin >> n ;
        vector<int> a(n , 0);
        for(auto &x : a) cin >> x ; 
        vector<int> b(n , 0);
        for(auto &x : b) cin >> x ; 
        map<int , int> mp ;
        for(int i = 0 ; i < n ; i++) {
            mp[b[i]] = i+1;
        }
        vector<int> ans ; 
        
        bool psbl = true;
        for(int i = 0; i < n; i++) {
            auto it = mp.lower_bound(a[i]); 
            if(it == mp.end()) {
                psbl = false;
                break; 
            }
            else {
                ans.push_back(it->second); 
                mp.erase(it); 
            }
        }
        if(!psbl) {
            cout << -1 << endl;
            continue;
        }
        
        int Ans = mergesort(ans , 0 , n - 1);
        cout << Ans << endl;
    }
}


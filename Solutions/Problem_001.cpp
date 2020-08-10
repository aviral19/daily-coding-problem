#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define LOP(i,j,n) for(int i = j; i<n; i++)
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define FOREACH(it, l) for(auto it = l.begin(); it!= l.end(); it++)


bool check_sum(vector<int> a, int k){
    unordered_set<int> pt;
    for(int num : a){
        if(pt.find(num) != pt.end()) return true;
        pt.insert(k-num);
    }
    return false;
}


int main() {
    vector<int> v1 = {10, 15, 3, 7}, v2 = {}, v3 = {10,15,3,4};
    int k1 = 17, k2 = 10, k3 = 17;

    cout << check_sum(v1, k1) << endl; // True - returns 1
    cout << check_sum(v2, k2) << endl; // False - returns 0
    cout << check_sum(v3, k3) << endl; // False - return 0
    
}
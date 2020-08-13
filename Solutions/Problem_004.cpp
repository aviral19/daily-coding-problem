#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define ll long long int
#define LOP(i,j,n) for(int i = j; i<n; i++)
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define FOREACH(it, l) for(auto it = l.begin(); it!= l.end(); it++)



int main(){
    vector<int> given = {3, 4, -1 , 1};         
    int n = given.size();
    
    int j = 0, i;
    for(i = 0; i<n; i++){
        if(given[i] <= 0){
            swap(given[i], given[j]);
            j++;
        }
    }

    for(i = 0; i<n; i++){
        if(abs(given[i]) - 1 < n and given[abs(given[i]) - 1] > 0){
            given[abs(given[i]) - 1] = -given[abs(given[i]) - 1];
        }
    }
    
    for(i = 0; i<n; i++){
        if(given[i] > 0){
            cout << i+1 << endl;
            break;
        }
    }
    if(i == n) cout << n + 1 << endl;
    
}
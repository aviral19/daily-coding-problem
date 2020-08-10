#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define LOP(i,j,n) for(int i = j; i<n; i++)
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define FOREACH(it, l) for(auto it = l.begin(); it!= l.end(); it++)

// When Division is allowed
vector<int> productWithDivision(vector<int> a){
    int n = a.size();

    vector<int> res(n);
    
    int lastnum = 1;
    for(int i = 0; i<n-1; i++){
        lastnum *= a[i];                        // O(n) to get this
    }
    res[n-1] = lastnum;
    for(int i = n-2; i>=0; i--){                // O(n) to fill this
        res[i] = (res[i+1] * a[i+1])/a[i];      // Division is used here
    }
    return res;
}


// Follow up - When division is not allowed
vector<int> productWithoutDivision(vector<int> a){
    int n = a.size();
    vector<int> rightprod(n), leftprod(n);
    leftprod[0] = a[0];
    for(int i = 1; i<n;i++){
        leftprod[i] = a[i] * leftprod[i-1];     // O(n) to fill this
    }

    rightprod[n-1] = a[n-1];
    for(int i = n-2; i>=0; i--){
        rightprod[i] = a[i] * rightprod[i+1];   // O(n) to fill this
    }

    vector<int> res(n);
    for(int i = 1; i<n-1; i++){
        res[i] = leftprod[i-1]*rightprod[i+1];  // O(n) to fill this
    }
    res[0] = rightprod[1];
    res[n-1] = leftprod[n-2];
    

    return res;
}


int main() {
    
    vector<int> a1 = {1,2,3,4,5}, a2 = {3,2,1};
    vector<int> res1, res2;
    vector<int> res3, res4;


    // Using with Division method
    res1 = productWithDivision(a1);
    for(int num : res1) cout << num << " ";

    cout << endl;

    res2 = productWithDivision(a2);
    for(int num : res2) cout << num << " ";
    cout << endl;


    // Using without division method
    res3 = productWithoutDivision(a1);
    for(int num : res3) cout << num << " ";

    cout << endl;

    res4 = productWithoutDivision(a2);
    for(int num : res4) cout << num << " ";
    cout << endl;
}
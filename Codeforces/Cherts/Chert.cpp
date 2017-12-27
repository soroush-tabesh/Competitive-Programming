// In the Name of Allah
#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long int ll;

bool check(int a,int b){
    return a*a < b;
}

ll gsq(ll x){
    ll l=0,r=1;
    while(r*r <= x){
        r*=2;
    }
    r*=2;
    while(r-l>1){
        ll mid = (r+l)/2;
        if(mid*mid > x){
            r = mid+1;
        }else if(mid*mid == x){
            return mid;
        }else{
            l = mid+1;
        }
    }
    return l;
}

int32_t main() {
    int a;
    cin >> a;
    while(a){
        cout << gsq(a) << endl;
        cin >> a;
    }
    return 0;
}

#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define pb push_back
#define pf push_front
#define fr first
#define sc second

using namespace std;

typedef long long int ll;
typedef long double ld;

void solution();

int main(){
	Init;
	solution();
	return 0;
}

ll rec(ll p,ll q){
	if(q == 1)
		return p-1;
	return rec(q,p%q)+(p/q);
}

void solution(){
	int t;
	cin >> t;
	for(int k = 0;k < t;k++){
		ll p,q;
		cin >> p >> q;
		ll temp = __gcd(p,q);
		p /= temp;
		q /= temp;
		if(p < q)
			swap(p,q);
		cout << rec(p,q) << endl;
	}
}

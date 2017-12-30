//In The Name of Allah
//Fri 8/10/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int n;
ld r;
ld cordx[1100];
ld cordy[1100];

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> r;
	forar(i,n){
		cin >> cordx[i];
	}
	cout << setprecision(20);
	forar(i,n){
		ld py = r;
		forar(j,i){
			ld val = 4*r*r-(cordx[i]-cordx[j])*(cordx[i]-cordx[j]);
			if(val < 0)
				continue;
			val = sqrt(val);
			val += cordy[j];
			py = max(py,val);
		}
		cordy[i] = py;
		cout << py << " ";
	}
}

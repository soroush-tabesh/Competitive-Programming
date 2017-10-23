//In The Name of Allah
//Mon 1/8/96
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

const ll mod = 1e9+7,M = 3e5+5;

void Solution();

int n;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	if(n%2){
		if(n==1){
			cout << "2\n1 1" << endl;
			return;
		}else{
			cout << (3*n-1)/2 << endl;
		}
		cout << "2 1 ";
		forar(i,n/2-1){
			cout << 2*i+4 << " ";
			cout << 2*i+3 << " ";
			cout << 2*i+2 << " ";
		}
		cout << n << " ";
		cout << n-1 << " ";
	}else{
		n--;
		if(n==1){
			cout << "3\n2 1 2" << endl;
			return;
		}else{
			cout << (3*n-1)/2+2 << endl;
		}
		cout << "2 1 ";
		forar(i,n/2-1){
			cout << 2*i+4 << " ";
			cout << 2*i+3 << " ";
			cout << 2*i+2 << " ";
		}
		cout << n << " ";
		cout << n-1 << " ";
		cout << n+1 << " ";
		cout << n << " ";
	}

}

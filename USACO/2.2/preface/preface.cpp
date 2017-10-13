/*
ID: soroosh4
LANG: C++11
TASK: preface
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("preface.in","r",stdin),freopen("preface.out","w",stdout)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;
const int MAX = 100*1000+5;

void Solution();

enum{
	I,V,X,L,C,D,M
};
string symbs = "IVXLCDM";

int n;
int data[10];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void count(int k){
	int a[4];
	a[0] = k%10;
	a[1] = (k/10) % 10;
	a[2] = (k/100) % 10;
	a[3] = (k/1000) % 10;

	data[M] += a[3];

	if(a[2]){
		if(a[2] < 4){
			data[C] += a[2];
		}else if(a[2] < 6){
			data[C] += 5-a[2];
			data[D]++;
		}else if (a[2] < 9){
			data[D]++;
			data[C] += a[2]-5;
		}else{
			data[C]++;
			data[M]++;
		}
	}
	if(a[1]){
		if(a[1] < 4){
			data[X] += a[1];
		}else if(a[1] < 6){
			data[X] += 5-a[1];
			data[L]++;
		}else if (a[1] < 9){
			data[L]++;
			data[X] += a[1]-5;
		}else{
			data[C]++;
			data[X]++;
		}
	}
	if(a[0]){
		if(a[0] < 4){
			data[I] += a[0];
		}else if(a[0] < 6){
			data[I] += 5-a[0];
			data[V]++;
		}else if (a[0] < 9){
			data[V]++;
			data[I] += a[0]-5;
		}else{
			data[X]++;
			data[I]++;
		}
	}

}

void Solution(){
	cin >> n;
	fori(i,1,n+1){
		count(i);
	}
	forar(i,10){
		if(data[i]){
			cout << symbs[i] << ' ' << data[i] << endl;
		}
	}
}

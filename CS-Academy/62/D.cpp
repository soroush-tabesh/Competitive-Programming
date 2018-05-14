//In The Name of Allah
//Wed 29/9/96
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
int data[M];
bool ispar[M];
int damn[M];

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i];
	}
	if(n==1){
		cout << 0 << endl;
		return;
	}
	int cntispar = 1;
	ispar[0] = 1;
	pii mx1,mx2;
	mx1 = max(mp(data[0],0),mp(data[1],1));
	mx2 = min(mp(data[0],0),mp(data[1],1));
	if(data[1] <= data[0]){
		damn[0]++;
	}else{
		ispar[1] = 1;
		cntispar++;
	}
	fori(i,2,n){
		if(data[i] > mx1.F){
			mx2 = mx1;
			mx1 = mp(data[i],int(i));
			ispar[i]=1;
			cntispar++;
		}else if(data[i] > mx2.F){
			mx2 = mp(data[i],int(i));
			damn[mx1.S]++;
		}
	}
	int ans = cntispar-1;
	forar(i,n){
		ans = max(ans,cntispar-int(ispar[i])+damn[i]);
	}
	cout << ans << endl;
}

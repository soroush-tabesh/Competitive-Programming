//In The Name of Allah
//Sun 19/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e5+5;

void Solution();

int n,ans,tail;
pii data[M]; // val - pos
int newdata[M];
int val2pos[M];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

bool cmp(pii a,pii b){
	return a.F < b.F;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i].F;
		data[i].S = i;
	}
	stable_sort(data,data+n,cmp);
	forar(i,n){
		newdata[data[i].S] = i;
		val2pos[i] = data[i].S;
	}
	ans = 1;
	forar(i,n){
		if(i > tail){
			tail = i;
			ans++;
		}
		tail = max(tail,newdata[i]);
		tail = max(tail,val2pos[i]);
	}
	cout << ans << endl;
}

 
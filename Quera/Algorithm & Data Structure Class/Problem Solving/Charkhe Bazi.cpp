//In The Name of Allah
//Mon 30/5/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
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

void Solution();

int spos,epos;
int n;
bool forb[100*1000+5];
bool mark[100*1000+5];
int dist[100*1000+5];
vector<int> topro;int head,tail;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

int getvert(){
	int res = 0;
	forar(i,5){
		int a;
		cin >> a;
		res*=10;
		res+=a;
	}
	return res;
}

int ppow(int base,int exp){
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	int v = ppow(base,exp/2);
	v*=v;
	if(exp%2)
		v*=base;
	return v;
}

int numberTranslate(int k,int radix,int vect){
	int t = (k/ppow(10,radix))%10;
	t = ((t+vect+10)%10) - t;
	t *= ppow(10,radix);
	k += t;
	return k;
}

void bfs(){
	while(head < tail){
		int cur = topro[head];
		head++;
		forar(i,5){
			forar(vect,2){
				int neib = numberTranslate(cur,i,vect*2-1);
				if(!mark[neib] && !forb[neib]){
					mark[neib] = 1;
					dist[neib] = dist[cur]+1;
					topro.pb(neib);
					tail++;
				}
			}
		}
	}
}

void Solution(){
	spos = getvert();
	epos = getvert();
	cin >> n;
	forar(i,n){
		int a = getvert();
		forb[a] = 1;
	}
	forar(i,100*1000+5){
		dist[i] = -1;
	}
	dist[spos] = 0;
	mark[spos] = 1;
	topro.pb(spos);
	tail++;
	bfs();
	cout << dist[epos] << endl;
}


//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define frs first
#define scnd second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;

void Solution();

struct Cup{
	int id;
	int cap;
	int fill;
};
typedef struct Cup Cup;
int n,w,prd;
Cup cup[100];


int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

bool compa(Cup a,Cup b){
	return a.cap > b.cap;
}

bool compb(Cup a,Cup b){
	return a.id < b.id;
}

void Solution(){
	cin >> n >> w;
	forar(i,n){
		cin >> cup[i].cap;
		cup[i].id = i;
	}
	sort(cup,cup+n,compa);
	forar(i,n){
		prd += (cup[i].cap+1)/2;
		cup[i].fill += (cup[i].cap+1)/2;;
	}
	if(prd > w){
		cout << -1;
		return;
	}
	int i = 0;
	while(i < n && prd < w){
		prd += cup[i].cap - cup[i].fill;
		cup[i].fill = cup[i].cap;
		if(prd >= w){
			cup[i].fill += w-prd;
		}
		i++;
	}
	sort(cup,cup+n,compb);
	forar(i,n){
		cout << cup[i].fill << " ";
	}
}


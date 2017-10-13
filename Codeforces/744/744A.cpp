#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define ForI(i,a,b) for(long long int i = a; i < b;i++)
#define ForD(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9+7;

using namespace std;

void solution();

set<int> capitals;
set<int> adj[1000];
bool mark[1000];
vector<set<int> > comps_main;
vector<set<int> > comps_misc;
int n,k,cnt;
ll m;
set<int> tempset;
bool tempbool;

int main()
{
	Init;
    #ifndef ONLINE_JUDGE
    WFile;
	//int tc;
	//cin >> tc;
	//ForI(i,0,tc)
	#endif

	solution();

    return 0;
}

void DFS_findcomps(int v){
	tempset.insert(v);
	mark[v] = 1;
	cnt++;
	if(capitals.find(v) != capitals.end())
		tempbool = true;
	for(set<int>::iterator it = adj[v].begin();it != adj[v].end();it++ ){
		if(mark[(*it)] == 0){
			DFS_findcomps((*it));
		}
	}
}

void findcomps(){
	while(cnt < n){
		int i=0;
		for(;i<n;i++)
			if(mark[i]==0)
				break;
		tempset.clear();
		tempbool = false;
		DFS_findcomps(i);
		set<int> res(tempset);
		if(res.size()!=0){
			if(tempbool)
				comps_main.push_back(res);
			else
				comps_misc.push_back(res);
		}
	}
}

void solution(){
	cin >> n >> m >> k;
	ForI(i,0,k){
		int temp;
		cin >> temp;
		capitals.insert(temp-1);
	}
	ForI(i,0,m){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	findcomps();
	// fill edges in comps
	m*=(-1);
	int max_main=0;
	ForI(i,0,comps_main.size()){
		int s = comps_main[i].size();
		m += s*(s-1)/2;
		max_main = max(max_main,s);
	}
	ForI(i,0,comps_misc.size()){
		int s = comps_misc[i].size();
		m += s*(s-1)/2;
		m += s*max_main;
		max_main += s;
	}
	
	cout << m;
	
}


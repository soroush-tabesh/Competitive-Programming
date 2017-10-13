/*
ID: soroosh4
LANG: C++11
TASK: wormhole
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("wormhole.in","r",stdin),freopen("wormhole.out","w",stdout)
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
const int M = 100*1000+5;

void Solution();

int n,ans;
map<int,set<pii > > cords; //map<i,set<pair<j,id> > >
int wormadj[12];
int physadj[12];
bool mark[12][2]; //phys mark and worm mark
bool loop = false;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void dfs(int v,bool phys){
	if(!phys)
		mark[v][0] = true;
	else
		mark[v][1] = true;
	int neib;
	if(phys){
		neib = physadj[v];		
	}else{
		neib = wormadj[v];
	}
	if(neib==-1)
		return;
	if((phys && mark[neib][0]) || (!phys && mark[neib][1])){
		loop = true;
		return;
	}
	dfs(neib,!phys);
}

bool check(){
	loop = false;
	forar(v,n){
		memset(mark,0,sizeof mark);
		dfs(v,false);
		//cout << wormadj[v]+1 << ' ' << physadj[v]+1 << endl;
	}
	ans += int(loop);
	//cout << (loop ? "looped" : "normal") << endl << endl;
}

void wormadjrec(int dep){
	// check if we are on a leaf
	if(2*dep > n){
		check();
		return;
	}
	
	// find first processable node
	int curproc;
	forar(i,n){
		if(wormadj[i]==-1){
			curproc = i;
			break;
		}
	}
	int ahead = n-2*dep+1;
	fori(i,curproc+1,n){
		if(wormadj[i] == -1){
			//Log("Hi!!!!");
			wormadj[i] = curproc;
			wormadj[curproc] = i;
			wormadjrec(dep+1);
			wormadj[i] = -1;
			wormadj[curproc] = -1;
		}
	}
	
}

void Solution(){
	cin >> n;
	forar(id,n){
		int i,j;
		cin >> j >> i; // cartesian to matrix
		cords[i].insert({j,id});
	}
	memset(wormadj,-1,sizeof wormadj);
	memset(physadj,-1,sizeof physadj);
	//set phys adj
	for(pair<int,set<pii > > row : cords){
		int last = -1;
		for(pii e : row.S){
			if(last != -1)
				physadj[last] = e.S;
			last = e.S;
		}
	}
	wormadjrec(1);
	cout << ans << endl;
}

//In The Name of Allah
//Tue 31/5/96
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

struct Disk{
	int height;
	int baseIndex;
	int down = -1;
	int up = -1;
};
typedef struct Disk Disk;

struct Base{
	int topIndex = -1;
	int bottomIndex = -1;
	int size;
};
typedef struct Base Base;

int n = 30*1000,m;
Base bases[30*1000+5];
Disk disks[30*1000+5];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void doMerge(int baseA,int baseB){
	if(baseA == baseB)
		return;
	if(bases[baseA].size < bases[baseB].size){ // B stays under, A goes on it
		// Attach A and B, update topNode
		disks[bases[baseA].bottomIndex].down = bases[baseB].topIndex;
		disks[bases[baseB].topIndex].up = bases[baseA].bottomIndex;
		bases[baseB].topIndex = bases[baseA].topIndex;
		
		// Update size
		bases[baseB].size += bases[baseA].size;
		
		// Update height and baseIndex in A from bottom
		int indA = bases[baseA].bottomIndex;
		while(indA != -1){
			disks[indA].baseIndex = baseB;
			disks[indA].height = disks[disks[indA].down].height+1;
			indA = disks[indA].up;
		}
	}else{ // A stays top, B goes under it
		// Attach A and B, update bottomNode
		disks[bases[baseA].bottomIndex].down = bases[baseB].topIndex;
		disks[bases[baseB].topIndex].up = bases[baseA].bottomIndex;
		bases[baseA].bottomIndex = bases[baseB].bottomIndex;
		
		// Update size
		bases[baseA].size += bases[baseB].size;
		
		// Update height and baseIndex in B from top
		int indB = bases[baseB].topIndex;
		while(indB != -1){
			disks[indB].baseIndex = baseA;
			disks[indB].height = disks[disks[indB].up].height-1;
			indB = disks[indB].down;
		}
	}
}

inline int getHeight(int v){
	return disks[v].height - disks[bases[disks[v].baseIndex].bottomIndex].height + 1;
}

void Solution(){
	// init
	fori(i,1,n+1){
		disks[i].height = 1;
		disks[i].baseIndex = i;
		
		bases[i].topIndex = i;
		bases[i].bottomIndex = i;
		bases[i].size = 1;
	}
	cin >> m;
	forar(i,m){
		string str;
		cin >> str;
		if(str == "Height"){
			int v;
			cin >> v;
			cout << getHeight(v) << endl;
		}else{
			int a,b;
			cin >> a >> b;
			//cout << "dbg " << disks[a].baseIndex << " " << disks[b].baseIndex << endl;
			doMerge(disks[a].baseIndex,disks[b].baseIndex);
		}
	}
}


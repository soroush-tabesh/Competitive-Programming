// In The Name of Allah
// Sun 18/6/96
#include<bits/stdc++.h>

#define fori(i,a,b) for(int i = a;i < b;i++)
#define pb push_back
#define mp make_pair

using namespace std;

int n;
vector<int> adjout[100],adjin[100],cadjout[100],postord;
int comp[100],dp[100],compcnt;
bool mark[100],iscyc[100],dpmark[100];

class BigO{
	public:
	void dfsA(int v){
		if(mark[v])
			return;
		mark[v] = 1;
		for(int neib : adjout[v])
			dfsA(neib);
		postord.pb(v);
	}
	void dfsB(int v,int c){
		comp[v] = c;
		for(int neib : adjin[v])
			if(!comp[neib])
				dfsB(neib,c);
	}
	int getdp(int v){
		if(dpmark[v])
			return dp[v];
		dpmark[v] = 1;
		for(int neib : cadjout[v])
			dp[v] = max(dp[v],getdp(neib));
		if(iscyc[v])
			dp[v]++;
		return dp[v];
	}
	int minK(vector<string> graph){
		n = graph.size();
		fori(i,0,n){
			fori(j,0,n){
				if(graph[i][j] == 'Y'){
					adjout[i].pb(j);
					adjin[j].pb(i);
				}
			}
		}
		fori(i,0,n)
			dfsA(i);
		fori(i,0,n)
			if(!comp[postord[n-i-1]])
				dfsB(postord[n-i-1],++compcnt);
		fori(i,0,n){
			for(int neib : adjin[i])
				if(comp[neib] != comp[i])
					cadjout[comp[neib]].pb(comp[i]);
			int in = 0,out = 0;
			for(int neib : adjin[i])
				if(comp[neib] == comp[i])
					in++;
			for(int neib : adjout[i])
				if(comp[neib] == comp[i])
					out++;
			if(in != 0 || out != 0){
				if(in != 1 || out != 1)
					return -1;
				iscyc[comp[i]] = 1;
			}
		}
		int ans = 0;
		fori(i,1,compcnt+1)
			ans = max(ans,getdp(i));
		return max(0,ans-1);
	}
};

int main(){
	string s;
	cin >> s;
	vector<string> data;
	while(s!="0"){
		data.pb(s);
		cin >> s;
	}
	BigO bigo;
	cout << bigo.minK(data) << endl;
	fori(i,0,compcnt+1){
		for(int x : cadjout[i]){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
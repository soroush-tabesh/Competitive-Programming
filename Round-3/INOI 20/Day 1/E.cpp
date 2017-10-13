//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
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

const ll delta = 10861;

void Solution();

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
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

bool comp(pii a ,pii b){
	return (a.F > b.F || (a.F == b.F && a.S < b.S));
}

void Solution(){
	// Soalesh tedad halat haye kami dasht arzeshe bazgashti o ina ro nadare :)
	ld prob = 0;
	forar(mask,ppow(3,6)){ // 7 13 21 30
		ld curprob = double(delta)*double(delta);
		char g[6]; // 7-13 7-21 7-30 13-21 13-30 21-30
		int x = mask;
		int sc[4] = {0,0,0,0};
		forar(i,6){
			g[i] = x%3; // 0=tie 1=left 2=right
			x/=3;
		}
		switch(g[0]){ // 7-13
			case 0:
				sc[0]++;
				sc[1]++;
				curprob *= double(44)/double(100);
			break;
			case 1:
				sc[0]+=3;
				curprob *= double(13)*double(56)/double(20);
				curprob /= double(100);
			break;
			case 2:
				sc[1]+=3;
				curprob *= double(7)*double(56)/double(20);
				curprob /= double(100);
			break;
		}
		switch(g[1]){ // 7-21
			case 0:
				sc[0]++;
				sc[2]++;
				curprob *= double(36)/double(100);
			break;
			case 1:
				sc[0]+=3;
				curprob *= double(21)*double(64)/double(28);
				curprob /= double(100);
			break;
			case 2:
				sc[2]+=3;
				curprob *= double(7)*double(64)/double(28);
				curprob /= double(100);
			break;
		}
		switch(g[2]){ //7-30
			case 0:
				sc[0]++;
				sc[3]++;
				curprob *= double(27)/double(100);
			break;
			case 1:
				sc[0]+=3;
				curprob *= double(30)*double(73)/double(37);
				curprob /= double(100);
			break;
			case 2:
				sc[3]+=3;
				curprob *= double(7)*double(73)/double(37);
				curprob /= double(100);
			break;
		}
		switch(g[3]){ // 13-21
			case 0:
				sc[1]++;
				sc[2]++;
				curprob *= double(42)/double(100);
			break;
			case 1:
				sc[1]+=3;
				curprob *= double(21)*double(58)/double(34);
				curprob /= double(100);
			break;
			case 2:
				sc[2]+=3;
				curprob *= double(13)*double(58)/double(34);
				curprob /= double(100);
			break;
		}
		switch(g[4]){ // 13-30
			case 0:
				sc[1]++;
				sc[3]++;
				curprob *= double(33)/double(100);
			break;
			case 1:
				sc[1]+=3;
				curprob *= double(30)*double(67)/double(43);
				curprob /= double(100);
			break;
			case 2:
				sc[3]+=3;
				curprob *= double(13)*double(67)/double(43);
				curprob /= double(100);
			break;
		}
		switch(g[5]){ // 21-30
			case 0:
				sc[2]++;
				sc[3]++;
				curprob *= double(41)/double(100);
			break;
			case 1:
				sc[2]+=3;
				curprob *= double(30)*double(59)/double(51);
				curprob /= double(100);
			break;
			case 2:
				sc[3]+=3;
				curprob *= double(21)*double(59)/double(51);
				curprob /= double(100);
			break;
		}
		
		pii res[4];
		res[0] = {sc[0],7};
		res[1] = {sc[1],13};
		res[2] = {sc[2],21};
		res[3] = {sc[3],30};
		sort(res,res+4,comp);
		if(res[0].S == 21 || res[1].S == 21){
			prob += curprob;
		}
		
	}
	prob = floor(prob);
	cout << fixed;
	cout.precision(2);
	cout << prob;
}
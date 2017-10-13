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

int n;
int preSeq[10*1000+5];
int inSeq[10*1000+5];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void printPostorder(int* preBegin,int* preEnd,int* inBegin,int* inEnd){
	if(preBegin >= preEnd || inBegin >= inEnd || inEnd > (inSeq+n) || preEnd > (preEnd+n))
		return;
	int leftboundpos = find(inBegin,inEnd,*preBegin) - inBegin;
	printPostorder(preBegin+1, preBegin+leftboundpos+1, inBegin, inBegin+leftboundpos);
	printPostorder(preBegin+leftboundpos+1, preEnd, inBegin+leftboundpos+1, inEnd);
	cout << (*preBegin) << " ";
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> inSeq[i];
	}
	forar(i,n){
		cin >> preSeq[i];
	}
	printPostorder(preSeq,preSeq+n,inSeq,inSeq+n);
	cout << endl;
}


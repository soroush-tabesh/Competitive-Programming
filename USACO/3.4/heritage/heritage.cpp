//In The Name of Allah
//Mon 6/6/96
/*
ID: soroosh4
LANG: C++11
TASK: heritage
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("heritage.in","r",stdin),freopen("heritage.out","w",stdout)
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

int n;
string preSeq;
string inSeq;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void printPostorder(char* preBegin,char* preEnd,char* inBegin,char* inEnd){
	if(preBegin >= preEnd || inBegin >= inEnd || inEnd > (&inSeq[0]+n) || preEnd > (&preSeq[0]+n))
		return;
	int leftboundpos = find(inBegin,inEnd,*preBegin) - inBegin;
	printPostorder(preBegin+1, preBegin+leftboundpos+1, inBegin, inBegin+leftboundpos);
	printPostorder(preBegin+leftboundpos+1, preEnd, inBegin+leftboundpos+1, inEnd);
	cout << (*preBegin);
}

void Solution(){
	cin >> inSeq >> preSeq;
	n = preSeq.length();
	printPostorder(&preSeq[0],&preSeq[0]+n,&inSeq[0],&inSeq[0]+n);
	cout << endl;
}

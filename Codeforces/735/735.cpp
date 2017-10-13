#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define ForS(i,a,b) for(int i = a; i < b;i++)
#define ForB(i,a,b) for(int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
	
typedef long long int ll;
typedef long double ld;

ll mod = 1e9+7;

using namespace std;

void A();
void B();
void C();
void D();

int main()
{
	Init;
    C();
    return 0;
}

void A(){
	
}

void B(){
	
}

void C(){
	ll n,fib_a=1,fib_b=1,fib_c=2,i=1;
	cin >> n;
	
	if(n < 3){
		cout << n-1;
		return;
	}
	while(fib_c <= n){
		fib_a = fib_b;
		fib_b = fib_c;
		fib_c = fib_b+fib_a;
		i++;
	}
	
	cout << i-1;
}

void D(){
	
}


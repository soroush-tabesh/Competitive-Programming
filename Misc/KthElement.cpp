//In The Name of Allah
//Tue 21/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e5+5;

void Solution();

int n,m;
int data[M];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

int* m_partition(int* head,int* tail){
	int pivot = *head;
	head++;
	int* last = head;
	while(head < tail){
		if(*head <= pivot){
			swap(*last,*head);
			last++;
		}
		head++;
	}
	return last;
}

int kthElement(int* head,int* tail,int k){ // kth smallest
	if(k > tail - head || k <= 0 || tail - head <= 0)
		return -1;
	if(tail - head == k){
		int mx = *head;
		while(head < tail){
			mx = max(mx,*head);
			head++;
		}
		return mx;
	}
	swap(*head,*(head + (rand()%(tail-head))));
	int* bound = m_partition(head,tail);
	if(bound - head == k)
		return *head;
	if(bound - head < k)
		return kthElement(bound,tail,k-(bound-head));
	return kthElement(head+1,bound,k);
}

void Solution(){
	cin >> n >> m;
	forar(i,n){
		cin >> data[i];
	}
	cout << kthElement(data,data+n,m) << endl;
}

//In The Name of Allah
//Sun 15/11/96
#include <bits/stdc++.h>

// http://codeforces.com/blog/entry/11080
// http://codeforces.com/blog/entry/13279

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

// custom node update
template<class Node_CItr,
	 class Node_Itr,
	 class Cmp_Fn,
	 class _Alloc>
struct my_node_update
{
    typedef my_type metadata_type;
	 virtual Node_CItr
    node_begin() const = 0;
 
    virtual Node_CItr
    node_end() const = 0;

    void operator()(Node_Itr it, Node_CItr end_it)
    {
        auto l=it.get_l_child();
        auto r=it.get_r_child();
        int left=0,right=0;
        if(l!=end_it) left =l.get_metadata();
        if(r!=end_it) right=r.get_metadata();
        const_cast<int&>(it.get_metadata())=left+right+1;
    }
	int order_of_key(int x)
    {
        int ans=0;
        auto it=node_begin();
        while(it!=node_end())
        {
            auto l=it.get_l_child();
            auto r=it.get_r_child();
            if(Cmp_Fn()(x,**it))
            {
                it=l;
            }
            else
            {
                ans++;
                if(l!=node_end()) ans+=l.get_metadata();
                it=r;
            }
        }
        return ans;
    }
};

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename T> using ordered_set =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

inline void Solution(){
	// example code in the other file
}

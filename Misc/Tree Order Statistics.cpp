//In The Name of Allah

// http://codeforces.com/blog/entry/11080
// http://codeforces.com/blog/entry/13279

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
set_t;

template <typename T> using ordered_set =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// custom node update
template<class Node_CItr,
	 class Node_Itr,
	 class Cmp_Fn,
	 class _Alloc>
struct my_node_update
{
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

int main()
{
  // Insert some entries into s.
  set_t s;
  s.insert(12);
  s.insert(505);
  s.insert(30);
  s.insert(1000);
  s.insert(10000);
  s.insert(100);

  // The order of the keys should be: 12, 30, 100, 505, 1000, 10000.
  assert(*s.find_by_order(0) == 12);
  assert(*s.find_by_order(1) == 30);
  assert(*s.find_by_order(2) == 100);
  assert(*s.find_by_order(3) == 505);
  assert(*s.find_by_order(4) == 1000);
  assert(*s.find_by_order(5) == 10000);
  assert(s.find_by_order(6) == s.end());

  // The order of the keys should be: 12, 30, 100, 505, 1000, 10000.
  assert(s.order_of_key(10) == 0);
  assert(s.order_of_key(12) == 0);
  assert(s.order_of_key(15) == 1);
  assert(s.order_of_key(30) == 1);
  assert(s.order_of_key(99) == 2);
  assert(s.order_of_key(100) == 2);
  assert(s.order_of_key(505) == 3);
  assert(s.order_of_key(1000) == 4);
  assert(s.order_of_key(10000) == 5);
  assert(s.order_of_key(9999999) == 6);

  // Erase an entry.
  s.erase(30);

  // The order of the keys should be: 12, 100, 505, 1000, 10000.
  assert(*s.find_by_order(0) == 12);
  assert(*s.find_by_order(1) == 100);
  assert(*s.find_by_order(2) == 505);
  assert(*s.find_by_order(3) == 1000);
  assert(*s.find_by_order(4) == 10000);
  assert(s.find_by_order(5) == s.end());

  // The order of the keys should be: 12, 100, 505, 1000, 10000.
  assert(s.order_of_key(10) == 0);
  assert(s.order_of_key(12) == 0);
  assert(s.order_of_key(100) == 1);
  assert(s.order_of_key(505) == 2);
  assert(s.order_of_key(707) == 3);
  assert(s.order_of_key(1000) == 3);
  assert(s.order_of_key(1001) == 4);
  assert(s.order_of_key(10000) == 4);
  assert(s.order_of_key(100000) == 5);
  assert(s.order_of_key(9999999) == 5);

  return 0;
}


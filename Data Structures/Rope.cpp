//* Description: insert element at $i$-th position, cut a substring and 
// * re-insert somewhere else. At least 2 times slower than handwritten treap. 
//push_back() - O(log N).
//pop_back() - O(log N)
//insert(int x, crope r1): O(log N) and Worst O(N)
//substr(int x, int l): O(log N)
//replace(int x, int l, crope r1): O(log N).
#include <ext/rope>
using namespace __gnu_cxx;
void ropeExample() {
	rope<int> v(5,0); // initialize with 5 zeroes
	F0R(i,sz(v)) v.mutable_reference_at(i) = i+1; 
	F0R(i,5) v.pb(i+1); // constant time pb
	rope<int> cur = v.substr(1,2); 
	v.erase(1,3); // erase 3 elements starting from 1st element
	for (rope<int>::iterator it = v.mutable_begin(); 
		it != v.mutable_end(); ++it) pr((int)*it,' ');
	ps(); // 1 5 1 2 3 4 5
	v.insert(v.mutable_begin()+2,cur); // or just 2
	v += cur; F0R(i,sz(v)) pr(v[i],' ');
	ps(); // 1 5 2 3 1 2 3 4 5 2 3
}
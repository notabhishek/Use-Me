// Segment Tree 
// Queries handled
// 1. add a[i]+= v for  l<=i<=r     O(logN)
// 2. find value of a[i]            O(logN)

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

const int MAXN = 1e5 + 1; // max size
ll tree[4*MAXN]; // tree
ll a[MAXN]; // array
ll n , m;

void build(int v , int tl, int tr){ // build the tree
	if(tl == tr)
		tree[v] = a[tl];
	else {
		int tmid = (tl + tr)/2;
		build(2*v , tl , tmid);
		build(2*v + 1 , tmid + 1 , tr);
        // merge here
		// tree[v] = tree[2*v] + tree[2*v + 1]; 
	}
}

// 1. add a[i]+= v for  l<=i<=r     O(logN)
void add(int v , int tl, int tr , int l , int r, int val) { 
	if(tl > r || l > tr)
		return;
	if(tl >= l && tr<=r)
		tree[v] += val;
	else {
		int tmid = (tl + tr)/2;
		add(2*v , tl , tmid , l , r, val);
		add(2*v + 1, tmid + 1 ,tr ,  l , r , val);
	}
}

// 2. find value of a[i]            O(logN)
ll get(int v , int tl, int tr, int idx) {
	if(tl == tr)
		return tree[v];
	int tmid = (tl + tr)/2;
	if(idx > tmid) 
		return tree[v] + get(2*v + 1 , tmid + 1 , tr , idx);
	else
		return tree[v] + get(2*v , tl , tmid ,idx);
}

int main() {
	cin >> n >> m;

    // Uncomment to build tree from given array
	// for(int i = 0 ; i < n; ++i) {
		// cin >> a[i];
	// }
	// build(1 , 0 , n-1);
	while(m--) {
		int q;
		cin >> q;
		if(q == 1) {
			int l , r, v;
			cin >> l >> r >> v;
			--r;
			add(1 , 0 , n-1 , l , r , v);
		} else {
			int i;
			cin >> i;
			cout << get(1 , 0 , n-1 , i) << endl;
		}
	}
}
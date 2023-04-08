#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define itr iterator
#define ritr reverse_iterator
#define pint pair<int, int>
#define pll pair<ll, ll>
#define S second
#define F first
#define v(a) vector<a>
#define mk(a, b) make_pair(a, b)
#define psh(a) push_back(a)
#define mem(arr, a) memset(arr, a, sizeof(arr))
#define pr(n) printf("%d\n", n)
#define sc(n) scanf ("%d", &n)
#define scll(n) scanf ("%lld", &n)
#define prll(n) printf("%lld\n", n)
#define MOD 1000000007ll
#define inf 1000000000ll

typedef struct {
	int l, r, len;
}ans;

ans LPS (string s) {
	int n;
	n = s.size();

	ans a;
	a.l = 0;
	a.r = 0;
	a.len = 1;

	int i, j, k;
	int ctr = 0;
	for (i = 0; i < n; i++) {
		ctr = 1;
		j = i-1;
		k = i+1;
		for (; k < n && j >= 0; k++, j--) {
			if (s[j] != s[k]) {
				break;
			}
			ctr+=2;
		}
		if (a.len < ctr) {
			a.len = ctr;
			a.l = j+1;
			a.r = k-1;
		}
	}

	for (i = 0; i < n; i++) {
		ctr = 0;
		j = i;
		k = i+1;
		for (; j>=0 && k < n; k++, j--) {
			if (s[j] != s[k]) {
				break;
			}
			ctr+=2;
		}
		if (a.len < ctr) {
			a.len = ctr;
			a.l = j+1;
			a.r = k-1;
		}
	}
	return a;
}

int main (void) {
	string s;
	cin>>s;
	ans Ans;
	Ans = LPS (s);
	cout<<Ans.l<<" "<<Ans.r<<" "<<Ans.len<<endl;
	int i;
	for (i = Ans.l; i <= Ans.r; i++) {
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}

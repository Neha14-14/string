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

void getZarr (string mixStr, int * Z) {
	int n = mixStr.size();
	int L, R, k;
	L = R = 0;
	Z[0] = 0;
	for (int i = 1; i < n; i++) {
		if (i > R) {
			L = R = i;
			while (R < n && mixStr[R-L] == mixStr[R]) {
				R++;
			}
			Z[i] = R-L;
			R--;
		}else {
			k = i - L;
			if (Z[k] < R-i+1) {
				Z[i] = Z[k];
			}else {
				L = i;
				while (R < n && mixStr[R-L] == mixStr[R]) {
					R++;
				}
				Z[i] = R-L;
				R--;
			}
		}
	}
}

void Z_search (string str, string pat) {
	string mixStr = pat + "$" + str;
	int l = mixStr.size();
	int Z[l];
	getZarr(mixStr, Z);
	int i;
	int m = pat.size();
	for (i = 0; i < l; i++) {
		if (Z[i] == m) {
			cout<<i-(m+1)<<endl;
		}
	}
	return ;
}

int main (void) {
	freopen ("input.in", "r", stdin);
	string str, pat;
	cin>>str>>pat;
	Z_search (str, pat);
	return 0;
}

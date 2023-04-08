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

ans LPS(string s) {
	int n;
	n = s.size();
	bool dp[n][n];
	memset (dp,false, sizeof (dp));
	int i, j, k;
	ans Ans;
	Ans.l = 0;
	Ans.r = 0;
	Ans.len = 0;
	for (i = 1; i <= n; i++) {
		k = i-1;
		for (j = 0; k < n; j++, k++) {
			if (i == 1) {
				dp[j][k] = true;
			}else if (i == 2){
				if (s[j] == s[k]) {
					dp[j][k] = true;
				}
			}else {
				if (s[j] == s[k] && dp[j+1][k-1]) {
					dp[j][k] = true;
				}
			}
			if (dp[j][k]) {
				if (Ans.len < i) {
					Ans.l = j;
					Ans.r = k;
					Ans.len = i;
				}
			}
		}
	}
	return Ans;
}

int main (void) {

	string s;
	cin>>s;

	ans Ans = LPS(s);
	cout<<Ans.l<<" "<<Ans.r<<" "<<Ans.len<<endl;
	int i;
	for (i = Ans.l; i <= Ans.r; i++) {
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}

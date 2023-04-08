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

string txt, pat;
int d = 33, q = 101;
void rabinkarp (string txt, string pat) {

	int N = txt.size();
	int M = pat.size();

	if (M > N) {
		return ;
	}

	int i, j, p = 0, t = 0, h = 1;
	for (i = 0; i < M-1; i++) {
		h  = (h*d)%q;
	}

	for (i = 0; i < M; i++) {
		p = (p*d + txt[i])%q;
		t = (t*d + pat[i])%q;
	}
	for (i = 0; i <= N-M; i++) {/**/
		if (p == t) {
			for (j = 0; j < M; j++) {
				if (pat[j] != txt[j+i]) {/**/
					break;
				}
			}
			if (j == M) {
				cout<<i<<endl;
			}
		}

		if (i < N-M) {/**/
			t = (d*(t-txt[i]*h) + txt[i+M])%q; /**/
			if (t < 0) {
				t = t + q;
			}
		}
	}
	return ;
}

int main (void) {
	cin>>txt>>pat;
	rabinkarp (txt, pat);
	return 0;
}

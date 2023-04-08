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


vector<int> computePrefix(string pat){
    int m = pat.size();
    vector<int> longestPrefix(m);
    for(int i = 1, k = 0; i < m; i++){
        while(k > 0 && pat[k] != pat[i]){
            k = longestPrefix[k - 1];
        }
        if(pat[i] == pat[k]){
            longestPrefix[i] = ++k;
        }
        else{
            longestPrefix[i] = k;
        }
    }
    return longestPrefix;
}

void KMP(string str,string pat){
    int n = str.size();
    int m = pat.size();
    vector<int> longestPrefix = computePrefix(pat);
    for (int i = 0; i < m; i++) {
      cout<<longestPrefix[i]<<" ";
    }
    cout<<endl;
    for(int i = 0, k = 0; i < n; i++){
        while(k > 0 && pat[k] != str[i]){
            k = longestPrefix[k - 1];
        }
        if(str[i] == pat[k]){
            k++;
        }
        if(k == m){
            cout << i - m + 1 << "\n";
            k = longestPrefix[k - 1];
        }
    }
}

int main (void) {
  freopen ("input.in", "r", stdin);
	string txt, pat;
	cin>>txt>>pat;
	KMP(txt, pat);
	return 0;
}

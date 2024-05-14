#include <bits/stdc++.h>

#define forr(i, a, b) for(int i = (int) a; i < (int) b; i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define fst find
#define snd second

typedef long long ll;
typedef long double ld;

using namespace std;

ll dp[100500];
ll piedras[100500];

ll resolversaltos (ll x, ll k) {
    if (dp[x] != -1) return dp[x];
    dp[x]=1e18;
    for (ll i = 1; i <= k; i++) {
        if (x-i >= 0) {
            dp[x] = min(dp[x], resolversaltos(x-i, k) + abs(piedras[x]-piedras[x-i]));
        }
    }
    return dp[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    ll n,k;
    cin >> n >> k;
    forn(i, n) {
        cin >> piedras[i];
    }
    dp[0]=0;
    cout << resolversaltos(n-1, k) << '\n';
}
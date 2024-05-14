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

ll resolversaltos (int x) {
    if (dp[x] != -1) return dp[x];
    dp[x]=1e18;
    if (x-2 >= 0) dp[x] = min(dp[x], min(resolversaltos(x-2)+abs(piedras[x]-piedras[x-2]),resolversaltos(x-1)+abs(piedras[x]-piedras[x-1])) );
    else if (x-1 == 0) dp[x] = min(dp[x],  abs(piedras[x]-piedras[x-1]) );
    return dp[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    ll n;
    cin >> n;
    forn(i, n) {
        cin >> piedras[i];
    }
    dp[0]=0;
    cout << resolversaltos(n-1) << '\n';
}
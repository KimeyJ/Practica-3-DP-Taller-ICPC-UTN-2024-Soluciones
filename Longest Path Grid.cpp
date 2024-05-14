#include <bits/stdc++.h>

#define forr(i, a, b) for(ll i = (ll) a; i < (ll) b; i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef long double ld;

using namespace std;

vector<int> adj[100500];
int dp[100500];

int dfs(int s) {
    if (dp[s] != -1) return dp[s];
    dp[s] = 0;
    for (auto u : adj[s]) {
        dp[s] = max(dp[s],dfs(u) + 1);
    }
    return dp[s];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    forn(i, m) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    int maxi = 0;
    forn(i, n+1) {
        maxi = max(maxi,dfs(i));
    }
    cout << maxi << '\n';
}
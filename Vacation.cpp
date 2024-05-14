#include <bits/stdc++.h>

#define forr(i, a, b) for(ll i = (ll) a; i < (ll) b; i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define fst find
#define snd second

typedef long long ll;
typedef long double ld;
const ll INF = 1e10;

using namespace std;

ll dp[100500][4];
ll dias[100500][3];

ll resolverfeliz (ll x, ll ult) {
    if (x < 0) return 0;
    if (dp[x][ult] != -1) return dp[x][ult];
    ll ans = -1;
    if (ult == 0) {
        ans = max(ans, max(resolverfeliz(x-1, 1)+dias[x][1], resolverfeliz(x-1, 2)+dias[x][2]));
    }
    else if (ult == 1) {
        ans = max(ans, max(resolverfeliz(x-1, 0)+dias[x][0], resolverfeliz(x-1, 2)+dias[x][2]));
    }
    else if (ult == 2) {
        ans = max(ans, max(resolverfeliz(x-1, 0)+dias[x][0], resolverfeliz(x-1, 1)+dias[x][1]));
    }
    else {
        ans = max(ans, resolverfeliz(x-1, 0)+dias[x][0]);
        ans = max(ans, resolverfeliz(x-1, 1)+dias[x][1]);
        ans = max(ans, resolverfeliz(x-1, 2)+dias[x][2]);
    }
    dp[x][ult] = ans;
    return dp[x][ult];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    forn(i,n) {
        cin >> dias[i][0] >> dias[i][1] >> dias[i][2];
    }
    ll ult = 3;
    cout << resolverfeliz(n-1, ult);
}
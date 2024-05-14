#include <bits/stdc++.h>

#define forr(i, a, b) for(ll i = (ll) a; i < (ll) b; i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef long double ld;
const ll MOD = 1e9 + 7;


using namespace std;

char grid[1050][1050];
ll dp[1050][1050];

ll contarcaminos(ll h, ll w) {
    if (dp[h][w] != -1) return (dp[h][w] % MOD);
    if (h == 0 && w == 0) return 1;
    dp[h][w] = 0;
    if ((grid[h-1][w] == '#' && w == 0) || (grid[h][w-1] == '#' && h == 0) || (grid[h-1][w] == '#' && grid[h][w-1] == '#') ) return 0;
    if (grid[h-1][w] == '.' && grid[h][w-1] == '.' && h != 0 && w != 0) {
        dp[h][w] = (contarcaminos(h-1, w) + contarcaminos(h,w-1)) % MOD;
    }
    else if (grid[h-1][w] == '#' || h == 0) {
        dp[h][w] = contarcaminos(h,w-1) % MOD;
    }
    else if (grid[h][w-1] == '#' || w == 0) {
        dp[h][w] = contarcaminos(h-1, w) % MOD;
    }
    return (dp[h][w] % MOD);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll h, w;
    memset(dp, -1, sizeof(dp));
    cin >> h >> w;
    forn(i, h) {
        forn(j, w) {
            cin >> grid[i][j];
        }
    }
    cout << contarcaminos(h-1,w-1) << '\n';
}
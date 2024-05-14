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

ld prob[3020];
ld dp[3020][3020];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    memset(dp, 0.0, sizeof(dp));
    dp[0][0] = 1.0;
    cin >> n;
    forn(i, n) {
        cin >> prob[i+1];
    }
    for (int coins = 1; coins <= n; coins++) {
        for (int heads = 0; heads <= coins; heads++) {
            if (heads == 0) {
                dp [coins][heads] = dp[coins-1][heads] * (1-prob[coins]);
            }
            else {
                dp[coins][heads] = (dp[coins-1][heads-1] * prob[coins]) + (dp[coins-1][heads] * (1-prob[coins]));
            }
        }
    }
    ld ans = 0;
    for (int i = (n+1)/2; i <= n; i++) {
        ans += dp[n][i];
    }
    cout << setprecision(10) << ans << '\n';
} 
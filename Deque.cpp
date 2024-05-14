#include <bits/stdc++.h>

#define forr(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef long double ld;
const ll MAX = 4e18;

using namespace std;

vector<ll> values;
ll dp[3100][3100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0;
    cin >> n;
    forn(i, n)
    {
        ll x;
        cin >> x;
        values.pb(x);
    }
    for(int i = n-1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                dp[i][j] = values[i];
            else
            {
                dp[i][j] = max(values[i] - dp[i+1][j], values[j] - dp[i][j - 1]);
            }
        }
    }
    cout << dp[0][n-1] << "\n";
}
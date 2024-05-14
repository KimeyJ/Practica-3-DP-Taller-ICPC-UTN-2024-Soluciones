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
ll dp[410][410];

ll resolverslime(ll l, ll r, ll n)
{
    if (l == r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    dp[l][r] = MAX;
    ll suma = 0;
    for (int i = l; i <= r; i++)
    {
        suma = suma + values[i];
    }
    for (int i = l; i < r; i++)
    {
        dp[l][r] = min(dp[l][r], resolverslime(l, i, n) + resolverslime(i+1, r, n) + suma);
    }
    return dp[l][r];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    forn(i, n)
    {
        ll x;
        cin >> x;
        values.pb(x);
    }
    cout << resolverslime(0, n - 1, n) << '\n';
}
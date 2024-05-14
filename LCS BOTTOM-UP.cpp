#include <bits/stdc++.h>

#define forr(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef long double ld;

using namespace std;

ll dp[3500][3500];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s;
    cin >> t;
    memset(dp, 0, sizeof(dp));
    ll ls = s.length();
    ll lt = t.length();
    for (ll i = 1; i <= ls; i++)
    {
        for (ll j = 1; j <= lt; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] += dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string ans = "";
    while (ls > 0 && lt > 0)
    {
        if (s[ls - 1] == t[lt - 1])
        {
            ans += s[ls - 1];
            ls--;
            lt--;
        }
        else if (dp[ls - 1][lt] >= dp[ls][lt - 1])
        {
            ls--;
        }
        else
        {
            lt--;
        }
    }
    ll tam = ans.length() - 1;
    while (tam >= 0)
    {
        cout << ans[tam];
        tam--;
    }
}
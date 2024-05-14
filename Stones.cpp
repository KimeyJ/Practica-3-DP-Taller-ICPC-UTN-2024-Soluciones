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

int values[110];
ll dp[100500];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    memset(dp, 0, sizeof(dp));
    cin >> n >> k;
    forn(i, n) {
        cin >> values[i];
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i - values[j] >= 0 && dp[i - values[j]] == 0) {
                dp[i] = 1;
                break;
            }
            else dp[i] = 0;
        }
    }
    if (dp[k] == 1) {
        cout << "First" << '\n';
    }
    else {
        cout << "Second" << '\n';
    }
} 
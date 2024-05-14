#include <bits/stdc++.h>

#define forr(i, a, b) for(ll i = (ll) a; i < (ll) b; i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef long double ld;
//const ll INF = 1e10;
//const ll INTMAX = 1e5 + 500;
//const ll MOD = 1e9 + 7; 

using namespace std;

ll dp[150][100500];

ll resolverobj (ll x, vector<pair<ll, ll>> &obj, ll nObj) {
    if (nObj < 0) return 0;
    if (dp[nObj][x] != -1) return dp[nObj][x];
    if (obj[nObj].fst <= x){
        dp[nObj][x] = max(resolverobj(x, obj, nObj - 1), resolverobj(x - obj[nObj].fst, obj, nObj - 1) + obj[nObj].snd);
    }
    else {
        dp[nObj][x] = max(dp[nObj][x],resolverobj(x, obj, nObj - 1));
    }
    return dp[nObj][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,w;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    vector<pair<ll, ll>> obj;
    cin >> n >> w;
    forn(i,n) {
        pair<ll,ll> x;
        cin >> x.fst >> x.snd;
        obj.pb(x);
    }
    cout << resolverobj(w, obj, n-1) << '\n';
}
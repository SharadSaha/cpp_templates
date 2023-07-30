#include <bits/stdc++.h>
using namespace std;

// Faster input/output
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

// common operations
#define pb push_back
#define mp make_pair
#define fi first
#define se second

void dfs(ll s,ll par,vector<vector<ll>> &g){
    // code before entering current node subtree
    cout << s << " ";
    for(auto child:g[s]){
        if(child==par) continue;

        // code before entering child subtree
        dfs(child,s,g);
        // code after computing child subtree
    }
    // code after exiting current node subtree
}

int main() {
    fastio;

    // demo
    ll n,e,u,v;
    cin >> n >> e;
    vector<vector<ll>> g(n,vector<ll>());

    for(int i=0;i<e;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,-1,g);
    // demo

    return 0;
}

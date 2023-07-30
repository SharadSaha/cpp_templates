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


// get height of each node
void get_height(ll s,ll par,vector<vector<ll>> &g,vector<ll> &height){
    // code before entering current node subtree
    for(auto child:g[s]){
        if(child==par) continue;

        // code before entering child subtree
        get_height(child,s,g,height);
        // code after computing child subtree
        height[s]=max(height[s],1+height[child]);
    }
    // code after exiting current node subtree
}


// get depth of each node
void get_depth(ll s,ll par,vector<vector<ll>> &g,vector<ll> &depth){
    // code before entering current node subtree
    for(auto child:g[s]){
        if(child==par) continue;

        // code before entering child subtree
        depth[child]=depth[s]+1;
        get_depth(child,s,g,depth);
        // code after computing child subtree
    }
    // code after exiting current node subtree
}


// get the number of even nodes in the subtree of each node
void get_even_cnt(ll s,ll par,vector<vector<ll>> &g,vector<ll> &even_cnt){
    // code before entering current node subtree
    if(!(s&1)) even_cnt[s]++;
    for(auto child:g[s]){
        if(child==par) continue;

        // code before entering child subtree
        get_even_cnt(child,s,g,even_cnt);
        // code after computing child subtree
        even_cnt[s]+=even_cnt[child];
    }
    // code after exiting current node subtree
}


// get the sum for each node's subtree
void get_subtree_sum(ll s,ll par,vector<vector<ll>> &g,vector<ll> &subtree_sum){
    // code before entering current node subtree
    subtree_sum[s]+=s;
    for(auto child:g[s]){
        if(child==par) continue;

        // code before entering child subtree
        get_subtree_sum(child,s,g,subtree_sum);
        // code after computing child subtree
        subtree_sum[s]+=subtree_sum[child];
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
    vector<ll> subtree_sum(n,0), even_cnt(n,0), height(n,0), depth(n,0);
    get_subtree_sum(0,-1,g,subtree_sum);
    get_even_cnt(0,-1,g,even_cnt);
    get_height(0,-1,g,height);
    get_depth(0,-1,g,depth);

    for(auto s:subtree_sum) 
        cout << s << " ";
    cout << endl;
    for(auto s:even_cnt) 
        cout << s << " ";
    cout << endl;
    for(auto s:height) 
        cout << s << " ";
    cout << endl;
    for(auto s:depth) 
        cout << s << " ";
    cout << endl;
    // demo

    return 0;
}

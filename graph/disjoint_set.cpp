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

class DS{
public:
    vector<ll> parent,size;
    DS(ll n){
        for(ll i=0;i<n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }

    ll find(ll v){
        if(v==parent[v]) return v;
        else return parent[v]=find(parent[v]);
    }

    void _union(ll a, ll b){
        a=find(a);
        b=find(b);
        if(a==b) return;
        if(size[a]<size[b]) swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
};

int main() {
    fastio;

    // demo
    DS ds(5);
    ds._union(2,4);
    ds._union(3,2);
    for(auto a:ds.parent) cout << a << " ";
    cout << endl;
    for(auto a:ds.size) cout << a << " ";
    cout << endl;
    // demo
}

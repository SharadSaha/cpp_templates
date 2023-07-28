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

// custom comparator function for sorting
/* The argument a (first argument) comes earlier in the 
sorted array as compared to the argument b (second argument).*/

bool comp(pll &a, pll &b)
{
    return (a.first < b.first);
}

int main() {
    fastio;

    // code
    vector<pll> v={{1,2},{3,4},{-1,0},{9,10},{5,4}};

    // custom sort 
    sort(v.begin(),v.end(),comp);

    // descending order
    sort(v.begin(),v.end(),greater<pll>());
    
    return 0;
}

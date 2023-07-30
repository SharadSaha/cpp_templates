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



int main() {
    fastio;

    // demo
    string s, pattern;
    cin >> s >> pattern;

    unordered_map<char,ll> mp;
    for(auto ch:pattern) 
        mp[ch]++;
    
    ll k=pattern.size(), n=s.size();
    // demo

    // sliding window

    ll i=0,j=0,count=mp.size(),ans=0;

    while(j<n){
        // do calculations for each j on start of loop
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0) count--;
        }

        // if window size not yet reached, j++
        if(j-i+1<k) j++;
        else if(j-i+1==k){
            // if window size reached, remove calculations for i, then i++ and j++
            if(count==0) ans++;
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]++;
                if(mp[s[i]]==1) count++;
            }

            i++;
            j++;
        }
    }

    cout << ans << endl;

    // sliding window

    return 0;
}

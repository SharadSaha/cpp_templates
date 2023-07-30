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

    // demo : minimum window substring : min size of window in s which contains all characters of t
    string s,t;
    cin >> s >> t;
    unordered_map<char,int> mp,ref;
    for(auto a:t)
        mp[a]++;
    int i=0,j=0,n = s.size(),count = mp.size(),ans = INT_MAX,index1=0,index2=0;
    
    while(j<n){

        // keep performing calculations for j
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0) count--;
        }

        // if condition satisfied, update ans and slide the window from the back (i++)
        if(count==0){
            if(ans>j-i+1){
                ans=j-i+1;
                index1 = i;
                index2 = j;
            }
            while(count==0){
                if(ans>j-i+1){
                    ans=j-i+1;
                    index1 = i;
                    index2 = j;
                }
                // remove calculation for each i as we slide the window
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]>0) count++;
                }
                i++;
            }
        }

        // always slide the window from the front
        j++;
    }

    if(ans==INT_MAX) cout << "" << endl;
    else cout << s.substr(index1,index2-index1+1) << endl;
    // demo

    return 0;
}

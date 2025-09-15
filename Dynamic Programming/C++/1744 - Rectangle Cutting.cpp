#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define FIO                     ios::sync_with_stdio(false); cin.tie(nullptr)
#define TC(t)                   int t; cin >> t; for(int i = 1; i <= t; i++)
#define deb(x)                  cerr << #x << " = " << x << endl
#define deb2(x, y)              cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define f0(i, a, n)             for(i = a; i < n; i++)
#define f1(i, a, n)             for(i = a; i <= n; i++)
#define ini(x, y)               memset(x, y, sizeof(x))
#define all(x)                  x.begin(), x.end()
#define sz(x)                   x.size()
#define ll                      long long int
#define pb                      push_back
#define ppb                     pop_back
#define mp                      make_pair
#define ff                      first
#define ss                      second
#define M                       1000000007
#define endl                    '\n'
#define bits(x)                 __builtin_popcountll(x)
#define zrbits(x)               __builtin_ctzll(x)
#define vi                      vector<int>
#define pii                     pair<int,int>
#define vpii                    vector<pii>
#define ordered_set             tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set       tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
 
const int N = 1e5 + 1;
const int MX = 1e9;
const ll INF = 1e18;
 
using namespace std;
using namespace __gnu_pbds;
 
inline ll ceil(ll a,ll b) {return (a % b ? a / b + 1 : a / b);}
inline ll mod(ll x) {return ( (x % M + M) % M );}
 
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for(auto& x : v) os << x << " "; return os << '\n';}
template<typename... T> void in(T&... args) {((cin >> args), ...);}
template<typename... T> void out(T&&... args) {((cout << args << endl), ...);}
template<typename... T> void out2(T&&... args) {((cout << args << " "), ...);}
 
void solve() {
        ll n, m, i, j, x;
        cin >> n >> m;
        
 
        vector<vector<ll>> dp(n+1, vector<ll>(m+1, INF));
        f1(i, 1, n) {
                f1(j, 1, m) {
                        if(i == j) dp[i][j] = 0;
                        else {
                                f1(x, 1, i-1) dp[i][j] = min(dp[i][j], 1 + dp[i-x][j] + dp[x][j]);
                                f1(x, 1, j-1) dp[i][j] = min(dp[i][j], 1 + dp[i][j-x] + dp[i][x]);
                        }
                }
        }
 
        cout << dp[n][m] << endl;
}
 
int main () {
        FIO;
        // TC(t)
        solve();
        return 0;
}

// #pragma GCC target("avx2")
// #pragma GCC target("popcnt")
// #pragma GCC target("lzcnt")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define FIO                     ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll                      long long
#define ull                     unsigned long long
#define lll                     __int128
#define lld                     long double
#define loop(i, a, b)           for(ll i = a; i <= b; i++)
#define loop2(i, b, a)          for(ll i = b; i >= a; i--)
#define ini(x, y)               memset(x, y, sizeof(x))
#define all(x)                  x.begin(), x.end()
#define all2(x)                 x.rbegin(), x.rend()
#define sz(x)                   (ll)x.size()
#define pb                      push_back
#define ppb                     pop_back
#define mp                      make_pair
#define ff                      first
#define ss                      second
#define M                       1000000007
#define endl                    '\n'
#define bits(x)                 __builtin_popcountll(x)
#define zrbits(x)               __builtin_ctzll(x)
#define vl                      vector<ll>
#define pll                     pair<ll,ll>
#define vpll                    vector<pll>
#define uni(x)                  x.erase(unique(all(x)), x.end())
#define ordered_set             tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set       tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define mxheap                  priority_queue<ll>
#define mnheap                  priority_queue<ll, vector<ll>, greater<ll>>
#define mxheap2                 priority_queue<pair<ll,ll>>
#define mnheap2                 priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>
 
using namespace std;
using namespace __gnu_pbds;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)
 
const int N = 2e5 + 5;
const int L = 20;
const int MX = 1e9 + 10;
const ll INF = 1e18;
 
const int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
 
inline ll uceil(ll a,ll b) {return (a % b ? a / b + 1 : a / b);}
inline ll mod(ll x) {return ( (x % M + M) % M );}
ll ulog(ll val, ll base) {ll cnt = 0; val /= base; while(val) {cnt++; val /= base;} return cnt;}
ll power(ll a, ll b) {ll res = 1; while (b) {if (b & 1) res = res * a; a = a * a; b >>= 1;} return res;}
ll modpow(ll a, ll b) {ll res = 1; while (b) {if (b & 1) res = res * a % M; a = a * a % M; b >>= 1;} return res;}
 
#ifdef FARHAN
#define deb(x)                  cerr << #x << " = " << x << endl;
#define deb2(x, y)              cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define deb3(x, y, z)           cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define deb4()                  cerr << endl;
#define done                    cerr << "Line " << __LINE__ << " is done" << endl;
#else
#define deb(x)
#define deb2(x, y)
#define deb3(x, y, z)
#define deb4()
#define done
#endif
 
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for(auto& x : v) os << x << " "; return os;}
template<typename T> ostream& operator<<(ostream& os, const set<T>& v) {for(auto& x : v) os << x << " "; return os;}
template<typename T, typename S> ostream& operator<<(ostream& os, const pair<T, S>& p) {os << p.first << ' ' << p.second; return os;}
template<typename... T> void in(T&... args) {((cin >> args), ...);}
template<typename... T> void out(T&&... args) {((cout << args << endl), ...);}
template<typename... T> void out2(T&&... args) {((cout << args << " "), ...);}
template<typename... T> void out3(T&&... args) {((cout << args << " "), ...); cout << endl;}
 
bool is_valid(ll i, ll j, ll n) {
        return (i >= 0 && i < n && j >= 0 && j < n);
}
 
void gabbarIsBack() {
        ll n;
        cin >> n;
 
        vector<ll> a(n);
        for(ll i = 0; i < n; i++) {
                cin >> a[i];
        }
 
        vector<vector<ll>> dp(n, vector<ll>(n));
        for(ll i = n - 1; i >= 0; i--) {
                for(ll j = i; j < n; j++) {
                        ll mn1 = a[i] + min(is_valid(i + 2, j, n) ? dp[i + 2][j] : 0, is_valid(i + 1, j - 1, n) ? dp[i + 1][j - 1] : 0);
                        ll mn2 = a[j] + min(is_valid(i + 1, j - 1, n) ? dp[i + 1][j - 1] : 0, is_valid(i, j - 2, n) ? dp[i][j - 2] : 0);
                        dp[i][j] = max(mn1, mn2);
                }
        }
        cout << dp[0][n - 1] << endl;
}
 
signed main () {
        #ifdef FARHAN
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        FIO;
        int tc = 1;
        // cin >> tc;
        for(int i = 1; i <= tc; i++) {
                gabbarIsBack();
        }
        return 0;
}

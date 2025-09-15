// increasing subsequence
#include <bits/stdc++.h>
using namespace std;
 
int main () {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<int> v;
        v.push_back(a[0]);
        for(int i = 1; i < n; i++) {
                if(a[i] > v.back()) v.push_back(a[i]);
                else {
                        int it = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
                        v[it] = a[i];
                }
        }
        cout << v.size() << endl;
 
        return 0;
}

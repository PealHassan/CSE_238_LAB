#include<bits/stdc++.h>  
#define ll long long int
#define pb push_back
#define mod 1000000007
#define vi vector<ll>
#define vpi vector< pair<ll,ll> > 
using namespace std;  
ll fun(vi& a, ll x) {
    if(x == 0) return 0;
    ll m = x, cnt = 0;
    for(ll i = a.size()-1; i>=0; i--) {
        cnt += (m/a[i]);
        m = m%a[i];  
        if(m == 0) break;
    }
    return cnt;
}
void solve() {
   ll n, x;  
   cin >> n >> x; 
   vi a(n);
   for(ll i = 0; i<n; i++) cin >> a[i];
   ll ans = fun(a,x);
   ll flag = 0;
   for(ll i = 1; i<n; i++) {
       ll u = ceil(x/(a[i]*1.0));
       u*=a[i];  
       ans = min(ans,fun(a,u)+fun(a,u-x));
   }
   cout << ans << endl;
}
int main() {
    ll t = 1;  
   // cin >> t;  
    while(t--) solve();
    return 0;
}
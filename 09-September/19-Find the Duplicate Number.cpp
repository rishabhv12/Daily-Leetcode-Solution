#include<bits/stdc++.h>

#define mod      1000000007
#define ll       long long int
#define endl     "\n"
#define vi       vector<int>
#define vl       vector<long long int>
#define pb(n)    push_back(n);
#define all(v)   (v).begin(),(v).end()

using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
ll power(ll a,ll n);

    int findDuplicate(vector<int>& nums) {
        int len = nums.size();

        for (int num : nums) {
            int idx = abs(num);
            if (nums[idx] < 0) {
                return idx;
            }
            nums[idx] = -nums[idx];
        }
        for(int num: nums) cout<<num<<" ";
        cout<<endl;
        return len;
    }

void solve(){
    int n; cin>>n;
    vi v;
    for(int i=0;i<n;i++) {
        int x; cin>>x;
        v.pb(x);
    }

    int ans = findDuplicate(v);
}

int main(){
    fast();
    int t=1;
  //  cin>>t;
    
    while(t--){
        solve();
    }
    return 0;
}





ll power(ll a,ll n)
{
  ll res=1;
  while(n)
  {
    if(n&1) {res*=a;--n;}
    else {a*=a;n/=2;}
  }
  return res;
}
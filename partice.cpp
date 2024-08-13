#include<bits/stdc++.h>
#define ll long long
#define pn cout<<"NO"<<endl
#define py cout<<"YES"<<endl
#define vl vector<long long>
#define vb vector<bool>
#define u_map unordered_map
#define pll pair<long long,long long>
#define inf INT_MAX
#define pb push_back
#define mod 998244353
#define MOD 1000000007
#define ld long double
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
using namespace std;

class SGTree{
    public:
    vector<ll>seg;

    SGTree(ll n){
        seg.resize(4*n+1);
    }

    void build(ll ind , ll low , ll high , vector<ll>&arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        ll mid = (low+high)>>1;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);

        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }

    void update(ll ind,ll low , ll high , vector<ll>&arr , ll i , ll value){
        if(low==high){
            seg[ind] = value;
            arr[i] = value;
            return;
        }

        ll mid = (low+high)>>1;
        if(i<=mid)update(2*ind+1,low,mid,arr,i,value);
        else update(2*ind+2,mid+1,high,arr,i,value);

        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }

    ll query(ll ind,ll low , ll high , ll l , ll r){
        // no overlap
        if(high<l || low>r)return INT_MAX;
        // complete overlap
        if(low>=l && high<=r)return seg[ind];

        ll mid = (low+high)>>1;
        ll left = query(2*ind+1,low,mid,l,r);
        ll right = query(2*ind+2,mid+1,high,l,r);

        return min(left,right);
    }
};




void input(vector<ll>&arr,ll n){
  for(ll i =0;i<n;i++)cin>>arr[i];
}

void printArr(vector<ll>&arr, ll i,ll j){
   for(ll k = i;k<=j;k++)cout<<arr[k]<<" ";
   cout<<endl; 
}

void find(){
    ll n;
    cin>>n;
    vl arr(n);
    input(arr,n);
    SGTree seg1(n);
    seg1.build(0,0,n-1,arr);
    // seg1.printSeg();
    ll q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<seg1.query(0,0,n-1,l,r)<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll test;
    cin>>test;
    while(test--){
    find();
}
 return 0;
}
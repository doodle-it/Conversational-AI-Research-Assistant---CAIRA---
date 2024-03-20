#include "bits/stdc++.h"
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template<class T> using oset = tree<T,null_type,less_equal// for indexed_multiset */
// <T> ,rb_tree_tag,tree_order_statistics_node_update> ;    // order_of_key (k) -> # of elem strictly < k .
//                                                      // *(s.find_by_order(k)) -> element at index K .
#define int              long long
using   ll=              long long;
#define ld               long double
#define endl             '\n'
#define dbg(x)           cout<<#x<<" is -> "<<x<<endl
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define pb               push_back
#define po               pop_back
#define mp               make_pair
#define sab(x)           x.begin(),x.end()
#define rsab(x)          x.rbegin(),x.rend()
#define ff               first
#define ss               second
#define sz(x)            (int)x.size()
#define sp(x)            fixed<<setprecision(x)
#define uni(edge)        edge.erase(unique(edge.begin(),edge.end()),edge.end());
#define to_up(x)         transform(sab(x),x.begin(),::toupper)
#define to_low(x)        transform(x.begin(),x.end(),x.begin(),::tolower)
#define yes              cout << "YES\n"
#define no              cout << "NO\n"

const int M = 1000000007;
const int MM = 998244353;
const ld Pi= acos(-1);
const int N=1e6+5;
const int inf=1e18;

void simp(){
    //happy coding!!
    ll a,b,c;cin>>a>>b>>c;
    if((c+(b%3))<3 && b%3){cout<<-1<<endl;return;}
    ll sum=0;
    if((c+b%3)%3)sum+=1;
    sum+=(a+b/3+(c+b%3)/3);
    cout<<sum<<endl;
}


signed main(){

    speed_;

    // freopen("input06.txt", "r", stdin);
    // freopen("ouput06.txt", "w", stdout);
    
    int t;
    t=1;
    cin>>t;
    while(t--){  
        
        // cout<<"Case #"<<curr++<<": "; 
        simp();
        
    }
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.1415926535897932384626 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
#define debug(x,y) cout<<x<<"  "<<y<< endl
#define debugc(x) cout <<"[ "<< x <<" ]"<<endl
#define max 1e6
bitset<1000001>b;
void sieve ()
{    
     b.set();
     b[0] = 0;               //  n(log(log(n)))
     b[1] = 0;

    for(int i = 2 ; i <= max ; i++) 
    { 
            if(b[i]) 
             {
                   for(int j = i*i ; j <= max ; j += i) 
                   b[j] = 0;
             }
    }
}

int gcd(int a,int b)
{
    if(b == 0)
    return a;
    return gcd( b , a%b );
}

void find_prime_divisor (int n)
{
    for(int i = 2 ; i*i<= n ;i++)
    {
        if(n%i == 0) 
        {    
            int cnt = 0 ;
            while(n%i == 0)
            {
                n/=i ;
                cnt ++;

            }
            // store value while using
        }
    }
} 

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    return 0;
}
    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    #define PI 3.1415926535897932384626 
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    typedef vector<pii> vpii;
    typedef vector<vi> vvi;
    #define debugxy(x,y) cout<<"[ "<<x<<"  "<<y<<" ]"<< endl
    #define debugx(x) cout <<"[ "<< x <<" ]"<<endl
    vector<vector<pii>> adj;
    vi vis;
    int water ;
    int tap ;
    void dfs(int room)
    {
        vis[room] = 1 ;
        for(auto x : adj[room]) 
        {
            water = min( water , x.second) ;
            if(!vis[x.first])
            { 
                if(adj[x.first].size() == 1)
                tap = x.first ;
                dfs(x.first);
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
        int n , p ; 
        cin >> n >> p ;
        adj.resize(n + 1) ;
        vis.resize(n + 1 , 0 );
        unordered_set<int>check ;
        for(int i = 0 ; i < p ; i ++)
        {
            int a , b , diameter ; 
            cin >> a >> b >> diameter ;
            check.insert(a);
            adj[a].push_back({b , diameter});
            adj[b].push_back({a , diameter}) ;
        }
        vector<pair<int , pii>>ans ;
        for(int i = 1 ; i <= n ; i ++) 
        {    
            
            if(!vis[i] && (adj[i].size() == 1) ) 
            {
                water  = adj[i][0].second ;
                tap = - 1;
                dfs(i);
                if(check.find(i) != check.end()) 
                {
                      ans.push_back({i , { tap , water}});
                }
                else
                {
                      ans.push_back({ tap , {i , water}}) ;    
                }
                
            }
        }
        
        if(ans.size())
        {
            sort(ans.begin() , ans.end() ) ;
            cout << ans.size() << endl;  
            for(auto x : ans )
            cout << x.first <<" " << x.second.first <<" "<<x.second.second <<endl;
        }
        else 
        cout <<"0\n";
        adj.clear();
        vis.clear();
    return 0;
    // THINGS TO KEEP IN MIND
    //   * int overflow, time and memory limits
    //   * Special case (n = 1?)
    //   * Do something instead of nothing and stay organized
    //   * Don't get stuck in one focus
    //   * int l=s.length()-x (s.length()<x) garbage value
    // TIME AND MEMORY LIMITS
    //   * 1 second is approximately 10^8 operations (c++)
    //   * 10^6 Elements of 32 Bit (4 bytes) is equal to 4 MB
    //   * 62x10^6 Elements of 32 Bit (4 bytes) is equal to 250 MB
    //   * 10^6 Elements of 64 Bits (8 bytes) is equal to 8 MB
    //   * 31x10^6 Elements of 64 Bit (8 bytes) is equal to 250 MB
    }
/*
Week of code 34
Fibonacci sum over all subarrays in the tree 
*/

typedef long long ull;

vector<int> ed[2000001];
int vis[200001]={0};
int fib[100000001];
vector<int> val;
ull res = 0;
int mod = 1000000007;

void bfs(int node_id, ull pre){
    
    //cout << node_id << " id " << endl;
    
    vis[node_id]=1;
    
    int node = val[node_id-1];
    
    pre += node;
    res += fib[pre] % mod;
    
    //cout << "pre " << pre << " f " << fib[pre] << endl;
    
    //cout << "res " << res << endl;

    for(auto a: ed[node_id]){
        if(!vis[a])
            bfs(a, pre);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int x,y;
        cin >> x >> y;
        
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    val.resize(n);
    for(int i=0; i<n; i++){
        cin >> val[i];
    }
    
    // fill fibo
    fib[0]=1;
    fib[1]=1;
    for(int i=2; i<100000001; i++){
        fib[i] = fib[i-1] % mod + fib[i-2] % mod;
        fib[i] %= mod;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++) vis[j]=0;
        bfs(i, 0);
    }
    
    cout << res % mod << endl;

    return 0;
}

/*
Week of code 34
Count number of subarrays with equal count of both numbers from query
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int q;
    cin >> n >> q;
    
    map< pair<int, int> , int> Mapa;
    
    map<int,int> mp;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
        mp.insert(make_pair(arr[arr_i],1));
    }
    for(int a0 = 0; a0 < q; a0++){
        int x;
        int y;
        cin >> x >> y;
        
        pair<int, int> p(x,y);
        
        if(Mapa.find(p)!=Mapa.end()){
            map< pair<int, int> , int>::iterator it = Mapa.find(p);
            cout << it->second << endl;
            continue;
        }
        
        if(x==y || (mp.find(x)==mp.end() && mp.find(y)==mp.end())){
            cout << n * (n+1) / 2 << endl;
            continue;
        }
        
        // Write Your Code Here
        int DP[16002]={0};
        
        int kx=0,ky=0;
        for(int i=0; i<n; i++){
            if(arr[i]==x) kx++;
            if(arr[i]==y) ky++;
            
            int diff = kx - ky + 8001;
            DP[diff]++;
        }
        
        int cnt=DP[8001];
        
        //cout << "C " <<  cnt << endl;
        
        int offset=0;
        for(int i=1; i<n; i++){
            if(arr[i-1]==x){
                offset++;
            }else if(arr[i-1]==y){
                offset--;
            }
           if(DP[8001+offset]>0) DP[8001+offset]--; 
           cnt += DP[8001+offset]; 
           //cout << "C " <<  cnt << endl;
        }
        
        cout << cnt << endl;
        
        Mapa.insert(make_pair(p,cnt));        
    }
    return 0;
}

bool mA[1000005] = {0};
bool mB[1000005] = {0};


int maximumGcdAndSum(vector <int> A, vector <int> B) {
    // Complete this function
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int gcd_sofar=1;
    
    for(int i=1; i<=1000005; i++){
        
        int i2 = i*i;
        
        for(int j=A.size()-1; A[j]>=i2; j--){
            
            int d = A[j]/i;
            if( d<gcd_sofar ) break;
            
            if(i*d==A[j]){
                mA[i]=1; mA[d]=1;
            }
        }
        for(int j=B.size()-1; B[j]>=i2; j--){
            
            int d = B[j]/i;
            if( d<gcd_sofar ) break;
            
            if(i*d==B[j]){
                mB[i]=1; mB[d]=1;
                if(mA[d] && d>gcd_sofar) gcd_sofar = d;
            }
        }        
        
    }
    
    int gcd = 1;
    for(int i=1000005; i>=2; i--){
        if(mA[i] && mB[i]) { gcd = i; break; }
    }
    
    if(gcd==1){
        return A[A.size()-1]+B[B.size()-1];
    }
    
    int N,M;
    for(int k=A.size()-1; k>=0; k--){
        if(A[k]%gcd == 0) N = A[k];
    }
    for(int k=B.size()-1; k>=0; k--){
        if(B[k]%gcd == 0) M = B[k];
    }    
    
    return N+M;
}

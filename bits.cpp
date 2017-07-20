/*
Week of code 34
Lucky number: look for the next number such that sum of first 3 digits = sum of last 3 digits
*/
bool lucky(int y){
    vector<int> d;
    for(int i=0; i<6; i++){
        d.push_back(y % 10);
        y /= 10;
    }
    
    return (d[0]+d[1]+d[2]) == (d[3]+d[4]+d[5]);
}
int onceInATram(int& x) {
    // Complete this function  
    x++;
    while( !lucky(x) ) x++;
    
    return x;
}

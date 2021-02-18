int mcd(int a, int b){
    if(a==b){ // 1
        return a;
    }
    else
        if(a>b) // 2a
            return mcd(a-b,b);
        else //2b
            return mcd(a,b-a);    
}
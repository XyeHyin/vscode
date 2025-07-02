int main(){
    int a[2][7], b[7];
    bool c = false;
    for(int i=0;i<2;i++){
        for(int j=0;j<7;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<7;i++){
       if(a[0][i]+a[1][i]>8){
           b[i]=a[0][i]+a[1][i];
              c=true;
       }
       }
       int max_val = 0;
       int count = 0;
       if (c == false)
       {
           cout << "0" << endl;
    }else{
       for(int i=0;i<7;i++){
           if(b[i]>max_val){
               max_val=b[i];
                count=i+1;
           }
       }
    }
    cout << count << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
//Minimu flips required to make aORb equal to c
int flipsrequired(int a,int b,int c){
    int flips=0;
    while(a>0||b>0||c>0){
        int ai=a&1;
        int bi=b&1;
        int ci=c&1;
        if(ci==1){
            if(ai==0&&bi==0){
              flips+=1;
            }
        }
        else{
            flips+=ai+bi;
        }
        a>>=1;
        b>>=1;
        c>>=1;
        
    }
    return flips;
    
}
int main(){
    int a,b,c;
    cout<<"ENTER THE VALUE OF a,b,c respectively ";
    cin>>a >>b >> c;
    cout<<"minimu nu,ber of flips required :"<<flipsrequired(a,b,c)<<endl;
    return 0;

}
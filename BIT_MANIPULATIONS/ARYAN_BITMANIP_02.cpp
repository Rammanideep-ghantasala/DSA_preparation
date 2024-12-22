#include<bits/stdc++.h>
using namespace std;
 /* find all subsequence of a string
 suppose abc is the string then 
 no of subsequnces are 8=2*2*2=2power3
 { } empty is also a subsequence
 ab is a subsequnce but ba is not 110
 ac is subsequnce but ca is not  101
 bc  is subsequnce but bc is not 011
 c is subsequnce 001
 b is subsequnce 010
 a is subsequnce 100
 abc is subsequnce 111
 we can represent like this in binary bits
 */
vector<string>generatesequences(string str){
    int n=str.size();
    int totalsubsequences=1<<n;
    vector<string>subsequences;
    for(int mask=0;mask<totalsubsequences;++mask){
    string subsequence ;
    for(int i=0;i<n;++i){
        if(mask&(1<<i)){
            subsequence+=str[i];
        }
    }
    subsequences.push_back(subsequence);
}
return subsequences;
}
int main(){
    string s;
    cout<<"enter a string";
    cin>>s;
    vector<string>subsequences=generatesequences(s);
    for(auto subsequence :subsequences){
        cout<<(subsequence.empty() ?"\"\"": subsequence)<<endl;
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
/* LUCKY NUMBERS PROBLEM CODE FORCES96B
Petya loves lucky numbers. Everybody knows that positive integers are lucky if their decimal representation doesn't contain digits other than 4 and 7. 
For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Lucky number is super lucky if it's decimal representation contains equal amount of digits 4 and 7. 
For example, numbers 47, 7744, 474477 are super lucky and 4, 744, 467 are not.

One day Petya came across a positive integer n. Help him to find the least super lucky number which is not less than n.
*/
int findluckynumberposition(string luckynumber){
    int length=luckynumber.size();
    int position=0;
    for(int i=0;i<length;++i){
        position+=(1<<i);
    }
    int rank=0;
    for(char digit:luckynumber){
        rank<<=1;
        if(digit=='7'){
            rank |=1;
        }
    }
        position+=rank+1;
        return position;
    }
int main(){
    string luckynumber;
    cout<<"enter a lucky number";
    cin>>luckynumber;
    for(char c:luckynumber){
        if(c!='4'&&c!='7'){
            cout<<"Invalid input .it is not a magical number";
            return 1;
        }
    }
    int position=findluckynumberposition(luckynumber);
    cout<<"the position of a lucky number "<<luckynumber<<" is "<<position<<endl;
    return 0;
}
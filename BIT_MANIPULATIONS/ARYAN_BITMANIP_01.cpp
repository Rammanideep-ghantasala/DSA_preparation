#include<bits/stdc++.h>
using namespace std;
/*
right shift =division by 2
left shift=multiply by 2

AND-BOTH ARE SAME THEN IT IS 1 ELSE 0
XOR-IF BOTH ARE DIFFERNET THEN IT IS 1 ELSE IT IS 0
OR-IF ANUTHING IS TRUE THEN RESULT WILL BE TRUE
if they how many bits should we change to make number a to number then wes hould do like this
step-1:First find XOR of a,b then no of set in the result is the no :of bits we should change in a to make b
*/
/*Method 1:
   How to count no:of number of set bits
   step1: first do the right shift
   step2:and perform &operator with the set 
   step3: if you get set bit then increase count by +1
   caution :initially keep the count as 1
   step3:last you will get only the set bits in the number
   by the above method you will get Time complexcity O(no:of set bits)
Method 2-
step 1:try to exctract any random set bit in the number
How to extract:
1.)find n-1 and perform and operator of n&n-1
then you will lost one set bit.
you iterate this one
*/
/*int countsetbits(int n){
    int count=0;
    while(n>0){
        count+=(n&1);
        n>>=1;
    }
    return count;
}
int main(){
    int number ;
cout<<"enter a non-negative number"<<;
cin>>number;
    cout<<"the number of set bits "<<number<<" is "<<countsetbits(number)<<endl;
    return 0;
}*/
/* for method 2 code is written below*/
bool isbitset(int n,int i){
    return (n&(1<<i))!=0;
}
int countsetbits(int n){
    int count=0;
    for(int i=0;i<32;++i){
        if(isbitset(n,i)){
            ++count;
        }
    }
    return count;
}
int main(){
    int number;
    cout<<"enter a positive number";
    cin>>number;
    cout<<"the no:of set bits in the number  "<<number<<" is "<<countsetbits(number)<<endl;
  return 0;
}
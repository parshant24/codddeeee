#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include<unordered_map>
using namespace std;

int main(){
    long long n;
    cin>> n;
    while(n!=1){
        cout <<n<<" ";
        if(n%2==1){
            n=3*n+1;
        }else{
            n/=2;
        }
    }
    cout<<n;

    return 0;
}
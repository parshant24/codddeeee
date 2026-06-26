#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include<unordered_map>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int t;
    cin >> t;

    while(t--){
        long long n;
        cin>>n;
        vector<vector<int>> grid(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> grid[i][j];
            }
        }
        int ans =0;
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-i;j++){
                int count1=0;
                int count0=0;
                if(grid[i][j]==0){
                    count0++;
                }else{
                    count1++;
                }
                if(grid[n-1-i][j]==0){
                    count0++;
                }else{
                    count1++;
                }
                if(grid[i][n-1-j]==0){
                    count0++;
                }else{
                    count1++;
                }
                if(grid[n-1-i][n-1-j]==0){
                    count0++;
                }else{
                    count1++;
                }
                ans+=min(count0,count1);
            }
        }        
        cout <<ans<<endl;        
    }     
}


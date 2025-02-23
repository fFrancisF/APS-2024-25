#include <bits/stdc++.h>
using namespace std;

int countSetBits(int num){
    int count = 0;
    while(num){
        num = num & (num - 1);
        count++;
    }
    return count;
}

int assignJobs(vector<vector<int>>& c){
    int n = c.size();

    vector<int> dp(1<<n, INT_MAX);
    dp[0] = 0;

    int x, j, mask;

    for(mask = 0; mask < 1<<n; mask++){
        x = countSetBits(mask);
        for(j = 0; j < n; j++){
            if((mask | 1 << j) != mask)
                dp[mask|1 << j] = min(dp[mask|1 << j], dp[mask] + c[x][j]);
        }
    }
    return dp[(1 << n) - 1];
}

int main(){
    int n;
    cout<<"Enter the number of jobs/people: ";
    cin>>n;
    vector<vector<int>> c(n, vector<int>(n));

    cout<<"Enter the cost matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin>>c[i][j];
    }
    cout<<"Minimum cost required after assigning all jobs to distinct people is: "<<assignJobs(c);
}

//---------------------------------------------------RECURSION O(2^n)--------------------------------------------------------
int solve(vector<vector<int>> &p,int n,int c,int i){
    if(i==n-1){
        return max({p[i][(c+1)%3],p[i][(c+2)%3]});
    }

    return max(solve(p,n,(c+1)%3,i+1)+p[i][(c+1)%3] , solve(p,n,(c+2)%3,i+1)+p[i][(c+2)%3]);
}

int ninjaTraining(int n, vector<vector<int>> &p){
    return max({solve(p,n,0,0),solve(p,n,1,0),solve(p,n,2,0)});
}//Top-Down approch 0->n-1

//-------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------DP O(3*n)----------------------------------------------------------------

int ninjaTraining(int n, vector<vector<int>> &p){
    if(n == 1)return max({p[0][0], p[0][1], p[0][2]});
    
    vector<vector<int>> dp(n, vector<int>(3, 0));

    for(int c = 0; c < 3; c++){
        dp[n-1][c] = max(p[n-1][(c+1)%3], p[n-1][(c+2)%3]);
    }

    // dp[i][c] represents: Maximum points from day i to day n−1 -----> given that activity c was done on day i−1.
    for(int i = n-2; i >= 1; i--){
        for(int c = 0; c < 3; c++){
            dp[i][c] = max(
                p[i][(c+1)%3] + dp[i+1][(c+1)%3],
                p[i][(c+2)%3] + dp[i+1][(c+2)%3]
            );
        }
    }

    int ans = 0;
    for(int c = 0; c < 3; c++){
        ans = max(ans, p[0][c] + dp[1][c]);
    }
    // as there was no previous day for day 0 so we calc using dp[1] and p[0] to finally give our answer

    return ans;
}//Botom-Up approch n-1 -> 0

//------------------------------------------------------------------------------------------------------------------------------------

//now DP moving forward i.e from 0 to n-1 th day---------------------- Simplest DP soln 

#include <algorithm>
int ninjaTraining(int n, vector<vector<int>> &p)
{
    vector<vector<int>> dp(n,vector<int> (3,0));
    //BASE CASE day 0 --->0th day par past day ki koi restriction nahi hai 

    for(int day=0;day<n;day++){
        for(int ac=0;ac<3;ac++){
            if(day==0){dp[0][ac]= p[0][ac];continue;}//base case
            
            dp[day][ac]=p[day][ac] + max(dp[day-1][(ac+1)%3] , dp[day-1][(ac+2)%3]);
        }
    }
    return max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}

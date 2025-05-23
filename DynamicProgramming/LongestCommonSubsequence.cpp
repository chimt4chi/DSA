//Reference Code(Aman) : https://www.programiz.com/online-compiler/2dsMbkU6ehDXa

#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

//This is the Memoized version of LCS
int lcsUsingDP(string &s1,string &s2,int i,int j,vector<vector<int>> &dp)
{
    //cout<<i<<" "<<j<<endl;

    //Base case : 
    if(i==0 || j==0)
        return 0;

    //Check and return DP value
    if(dp[i-1][j-1]!=-1)
    {
        //cout<<"DP: "<<i-1<<" "<<j-1<<endl;
        return dp[i-1][j-1];
    }    
    //cout<<i<<" "<<j<<endl;
    //General case
    if(s1[i-1]==s2[j-1])
    {
        dp[i-1][j-1] = 1 + lcsUsingDP(s1,s2,i-1,j-1,dp); //As this char is matched
        return dp[i-1][j-1];
    }
    
    dp[i-1][j-1] = max(lcsUsingDP(s1,s2,i,j-1,dp),lcsUsingDP(s1,s2,i-1,j,dp)); 
    return dp[i-1][j-1];
}

//Basic recursive version of LCS
int lcs(string &s1,string &s2,int i,int j)
{
    //cout<<i<<" "<<j<<endl;

    //Base case : 
    if(i==0 || j==0)
        return 0;

    //General case
    if(s1[i-1]==s2[j-1])
        return 1 + lcs(s1,s2,i-1,j-1);//As this char is matched
    
    return max(lcs(s1,s2,i,j-1),lcs(s1,s2,i-1,j)); 
}

int main()
{
    string s1="nocommon";
    string s2="coyemmosn"; //yes written inside common to test the algo
    //string s2="comnomon"; 

    int result = lcs(s1,s2,s1.size(),s2.size());
    cout<<"Result(Non DP) : "<<result<<endl;

    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m,vector<int>(n,-1));//Creating a dp matrix with size m x n. These are the maximum values that can be attained by i and j.

    result = lcsUsingDP(s1,s2,s1.size(),s2.size(),dp);
    cout<<"Result(Memoization) : "<<result<<endl;

    return 0;
}


#include<bits/stdc++.h>
using namespace std;
void transfom(string s,string t)
{
    int dp[1000][1000]={0},i,j;
    for(i=t.size()-1;i>=0;i--)
    {
        for(j=s.size()-1;j>=0;j--)
        {
        if(i ==t.size()-1)
            dp[i][j]=1;
        else if(j==s.size()-1)
            dp[i][j]=0;
        else
            {
                char a=t[i];
                char b=s[j];
            if(a!=b)
            dp[i][j]=dp[i][j+1];
            else
            dp[i][j]=dp[i][j+1]+dp[i+1][j+1];
            }
        }
    }
for(int i=0;i<t.size();i++)
{
    for(int j=0;j<s.size();j++)
    cout<<dp[i][j]<< " ";
    cout<<endl;
}

}
 int main( )
{
//number of ways to convet source to targer
    transfom("abcccdf","abccdf");

    return 0;
}

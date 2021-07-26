#include<bits/stdc++.h>
using namespace std;
void longestpalindromicsubstring(string s)
{
int dp[100][100]={0};

    int c=0;
    for(int g=0;g<s.size();g++)
    {
        for(int i=0,j=g;j<s.size();i++,j++)
        {
            if(g==0)
            dp[i][j]=1;
            else if(g==1)
            {
                if(s[i]==s[j])
                dp[i][j]=1;
                else
                dp[i][j]=0;
            }
            else
            {
                if(s[i]==s[j] &&dp[i+1][j-1])
                dp[i][j]=1;
                else
                dp[i][j]=0;
            }
            if(dp[i][j])
            c=g+1;

        }
    }


    cout<<c;

}

int main()
{
    longestpalindromicsubstring(" aba");
}

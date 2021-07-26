#include<bits/stdc++.h>
using namespace std;
void palindromicsubstring(string s)
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

        }
    }

    for(int i=1;i<s.size();i++)
    {
        for(int j=1;j<s.size();j++)
        {
            if(dp[i][j])c++;
        }

    }
    cout<<c;

}

int main()
{
    palindromicsubstring(" geek");
}

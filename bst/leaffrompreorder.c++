#include<bits/stdc++.h>
using namespace std;
void leafNode(int preorder[], int n)
{
    stack<int> s;
    //890 325 290 530 965                       890 325
    for (int i = 0, j = 1; j < n; i++, j++)
    {
        bool found = false;

        if (preorder[i] > preorder[j])
            s.push(preorder[i]);

        else
        {
            while (!s.empty())
            {
                if (preorder[j] > s.top())
                {
                    s.pop();
                    found = true;
                }
                else
                    break;
            }
        }

        if (found)
            cout << preorder[i] << " ";
    }

    // Since rightmost element is always leaf node.
    cout << preorder[n - 1];
}


int main()
{
    int preorder[] = { 890, 325, 290, 530, 965 };
    int n = sizeof(preorder)/sizeof(preorder[0]);

    leafNode(preorder, n);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void findMajority(int arr[], int n)
{
    int count1 = 0, count2 = 0;
    
    int first=INT_MAX, second=INT_MAX;

    int flag=0;
    for (int i = 0; i < n; i++)
    {

        if (first == arr[i])
            count1++;

        else if (second == arr[i])
            count2++;

        else if (count1 == 0)
        {
            count1++;
            first = arr[i];
        }

        else if (count2 == 0)
         {
            count2++;
            second = arr[i];
        }

        else
        {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;
  .
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == first)
            count1++;

        else if (arr[i] == second)
            count2++;
    }

    if (count1 > n / 3)
    {
        cout << first << " ";
          flag=1;
    }
    if (count2 > n / 3)
    {
        cout << second << " ";
          flag=1;
    }
      if(flag==0)
          cout << "No Majority Element" << endl;

}

int main() {

    int a[] = { 2, 2, 3, 1, 3, 2, 1, 1 };

    findMajority(a, 8);

    return 0;
}

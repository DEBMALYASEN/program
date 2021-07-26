#include<bits/stdc++.h>
using namespace std;
int findNextGreater(vector<int>& nums, int curr)
{
   int len = nums.size(), lo = 0, hi = len - 1;

   while (lo <= hi)
   {
      int mid = lo + (hi - lo) / 2;
      if (nums[mid] <= curr)
      lo = mid + 1;
      else
      hi = mid - 1;
   }
   return lo >= len? -1 : lo;
}

bool isValid(int pos, int digit,  string& time)
{
   if (pos == 0)
   return digit <= 2;
   else if (pos == 1)
   return time[0] == '2'? digit <= 3: digit <= 9;
   else if (pos == 3)
   return digit <= 5;
   else if (pos == 4)
   return digit <= 9;
   else
   return false;
}
   string nextClosestTime(string time)
   {
      vector<int> digits;
      for (auto c : time)
      {
         if (isdigit(c))
            digits.push_back(c - '0');
      }
      sort(digits.begin(), digits.end());



      for (int i = 4; i >= 0; --i)
      {
         if (i == 2)
         continue;
         int digit = time[i] - '0', idx = findNextGreater(digits, digit);
         if (idx == -1 || !isValid(i, digits[idx], time))
            time[i] = '0' + digits[0];
         else
         {
            time[i] = '0' + digits[idx];
            break;
         }
      }
      return time;
   }


int main()
{
    string s="22.58";
    cout<<nextClosestTime(s);
}

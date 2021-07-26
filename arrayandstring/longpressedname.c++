
#include<bits/stdc++.h>
using  namespace std;


bool isLongPressedName(string name, string typed)
 {
       int i = 0;
       for (int j = 0; j < typed.size(); ++j)
       {
           if (i < name.size() && name[i] == typed[j])
           ++i;
           else if (i == 0 || name[i-1] != typed[j])
           return false;
       }
       return i == name.size();
   }
   int main()
   {
       string name="Alex";
       string typed="Alleeex";
       cout<< isLongPressedName(name, typed);
   }

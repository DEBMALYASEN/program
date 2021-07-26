#include<bits/stdc++.h>
using namespace std;
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		unordered_map<string, vector<string>> hash_table;
		vector<vector<string>> result;

		for (auto elem : strs)
         {
			string hash = elem;
			sort(hash.begin(), hash.end());
			hash_table[hash].push_back(elem);
		}

		for (auto item : hash_table) {
			result.push_back(item.second);
		}

		return result;
	}
int main()
{
    vector<string>s={"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>>t=groupAnagrams(s);
    int c=1;
    for(auto i:t)
    {   cout<<c<<" ";
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
        c++;
    }
}

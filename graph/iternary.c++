#include <bits/stdc++.h>
using namespace std;

void printItinerary(map<string, string> dataSet)
{
    map<string, string> reversemap;


    for (auto i:dataSet)
        reversemap[i.second] = i.first;


    string start;

    for (auto i:dataSet)
    {
        if (reversemap.find(i.first) == reversemap.end())
        {
            start = i.first;
            break;
        }
    }

     if (start.empty())
     {
        cout << "Invalid Input" << endl;
        return;
     }

    auto i = dataSet.find(start);

    while (i != dataSet.end())
    {
        cout << i->first << "->" << i->second << endl;

        i = dataSet.find(i->second);
    }

}

int main()
{
    map<string, string> dataSet;
    dataSet["Chennai"] = "Banglore";
    dataSet["Bombay"] = "Delhi";
    dataSet["Goa"] = "Chennai";
    dataSet["Delhi"] = "Goa";

    printItinerary(dataSet);

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string LCP(string X, string Y)
{
    int i = 0, j = 0;
    while (i < X.length() && j < Y.length())
    {
        if (X[i] != Y[j]) {
            break;
        }

        i++, j++;
    }

    return X.substr(0, i);
}

string findLCP(vector<string> const &words, int low, int high)
{
    if (low > high)
        return string("");

    if (low == high)
        return words[low];


    int mid = (low + high) / 2;


    string X = findLCP(words, low, mid);
    string Y = findLCP(words, mid + 1, high);

    return LCP(X, Y);
}

int main()
{
    vector<string> words { "techie delight", "tech", "techie","technology", "technical" };

    cout << "The longest common prefix is "<< findLCP(words, 0, words.size() - 1);

    return 0;
}

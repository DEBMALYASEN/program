#include <bits/stdc++.h>
using namespace std;


void sort012(int a[], int n)
{
    int l = 0;
    int h =n- 1;
    int k = 0;

    while (k <= h)
    {
        switch (a[k])
        {

        case 0:
            swap(a[l++], a[k++]);
            break;

        case 1:
            k++;
            break;

        case 2:
            swap(a[k], a[h--]);
            break;
        }
    }
}




int main()
{
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };

    sort012(arr, 12);

    for (int i = 0; i < 12; i++)
        cout << arr[i] << " ";

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
void findKClosestElements(int arr[], int x, int k, int n)
{
    int left = 0;
    int right = n;

    while (right - left >= k)
    {
        if (abs(arr[left] - x) > abs(arr[right] - x)) {
            left++;
        }
        else {
            right--;
        }
    }



    while (left <= right)
    {
        printf("%d ", arr[left]);
        left++;
    }
}

int main(void)
{
    int arr[] = { 10, 12, 15, 17, 18, 20, 25 };


    int x = 17, k = 4;//x search k closest

    findKClosestElements(arr, x, k, 7);

    return 0;
}

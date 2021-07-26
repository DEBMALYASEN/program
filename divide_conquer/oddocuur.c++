#include <stdio.h>
//identical elements appear in pairs
int findOddOccuring(int arr[], int low, int high)
{

    if (low == high) {
        return low;
    }

    int mid = (low + high) / 2;

    if (mid & 1)
    {
        if (arr[mid] == arr[mid - 1])
            return findOddOccuring(arr, mid + 1, high);

        else
            return findOddOccuring(arr, low, mid - 1);

    }

    else
    {
        if (arr[mid] == arr[mid + 1])
            return findOddOccuring(arr, mid + 2, high);

        else
            return findOddOccuring(arr, low, mid);

    }
}

int main(void)
{
    int arr[] = { 2, 2, 1, 1, 3, 3, 2, 2, 4, 4, 3, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int index = findOddOccuring(arr, 0, n - 1);
    printf("The odd occurring element is %d ", arr[index]);

    return 0;
}

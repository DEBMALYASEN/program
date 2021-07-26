#include<bits/stdc++.h>
using namespace std;

// Function to find the ceiling of `x` in a sorted array `arr[low…high]`.
// i.e., the smallest integer greater than or equal to `x`
int findCeiling(int arr[], int low, int high, int x)
{
    // search space is `A[low…high]`

    // if `x` is less than equal to the lowest element in search
    // space, the lowest element is the ceiling
    if (x <= arr[low]) {
        return arr[low];
    }

    // if `x` is more than the highest element in the search space,
    // its ceiling doesn't exist
    if (x > arr[high]) {
        return -1;
    }

    // find the middle index
    int mid = (low + high) / 2;

    // if `x` is equal to the middle element, it is the ceiling
    if (arr[mid] == x) {
        return arr[mid];
    }

    // if `x` is more than the middle element, the ceiling exists in the right
    // subarray `A[mid+1…high]`
    else if (arr[mid] < x) {
        return findCeiling(arr, mid + 1, high, x);
    }

    // if `x` is less than the middle element, the ceiling exists in the left
    // subarray `A[low…mid]`(Note – middle element can also be ceiling)
    else {
        return findCeiling(arr, low, mid, x);
    }
}

// Function to find the floor of `x` in a sorted array `arr[low…high]`.
// i.e., the largest integer less than or equal to `x`
int findFloor(int arr[], int low, int high, int x)
{
    // search space is `A[low…high]`

    // if `x` is less than the lowest element in search
    // space, its floor doesn't exist
    if (x < arr[low]) {
        return -1;
    }

    // if `x` is more than equal to the highest element in
    // the search space, it is the floor
    if (x >= arr[high]) {
        return arr[high];
    }

    // find the middle index
    int mid = (low + high) / 2;

    // this check is placed to handle infinite loop for
    // a call to `findFloor(arr, mid, right, x)`
    if (mid == low) {
        return arr[low];
    }

    // if `x` is equal to the middle element, it is the floor
    if (arr[mid] == x) {
        return arr[mid];
    }

    // if `x` is more than the middle element, the floor exists in the right
    // subarray `A[mid…high]`(Note – middle element can also be the floor)
    else if (arr[mid] < x) {
        return findFloor(arr, mid, high, x);
    }

    // if `x` is less than the middle element, the floor exists in the left
    // subarray `A[low…mid-1]`
    else {
        return findFloor(arr, low, mid - 1, x);
    }
}

int main(void)
{
    int arr[] = { 1, 4, 6, 8, 9 };


    for (int i = 0; i <= 10; i++)
    {
        printf("Number %2d —> ceiling is %2d, floor is %2d\n", i,
                    findCeiling(arr, 0, 5, i),
                    findFloor(arr, 0, 5, i));

    }

    return 0;
}

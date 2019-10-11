#include "sort.h"
static void merge(int *nums, int *l, int lSize, int *r, int rSize)
{
    int i = 0, j = 0, itr = 0;
    while (i < lSize && j < rSize)
    {
        if (l[i] < r[j])
        {
            nums[itr++] = l[i++];
        }
        else
        {
            nums[itr++] = r[j++];
        }
    }
    while (i < lSize)
    {
        nums[itr++] = l[i++];
    }
    while (j < rSize)
    {
        nums[itr++] = r[j++];
    }
}
void mergeSort(int *nums, int length)
{
    if (length < 2)
    {
        return;
    }
    int mid = length / 2;
    int *l = new int[mid];
    int *r = new int[length - mid];
    for (int i = 0; i < mid; i++)
    {
        l[i] = nums[i];
    }
    for (int i = mid; i < length; i++)
    {
        r[i - mid] = nums[i];
    }
    mergeSort(l, mid);
    mergeSort(r, length - mid);
    merge(nums, l, mid, r, length - mid);
    delete[] l;
    delete[] r;
}
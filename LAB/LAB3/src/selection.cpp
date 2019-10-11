//
// Created by 吴佳遥 on 2019-10-10.
//

#include "sort.h"

int rSelect(int *nums, int left, int right, int k)
{
    if (left == right)
    {
        return nums[left];
    }
    int index = rand() % (right - left + 1) + left;
    swap(index, left, nums);
    int pivot = nums[left];
    int i = left + 1, j = i;
    for (; i <= right; i++)
    {
        if (nums[i] < pivot)
        {
            swap(j, i, nums);
            j++;
        }
    }
    swap(j - 1, left, nums);
    int relative = (j - 1) - left;
    if (relative == k)
    {
        return nums[j - 1];
    }
    else if (relative > k)
    {
        return rSelect(nums, left, j - 2, k);
    }
    else
    {
        return rSelect(nums, j, right, k - relative - 1);
    }
}

static int choosePivot(int *nums, int left, int right)
{
    if (left == right)
    {
        return nums[left];
    }
    int length = right - left + 1;
    int divLength = length % 5 == 0 ? length / 5 : length / 5 + 1;
    int *res = new int[divLength];
    int itr = 0;
    for (int i = 0; i < length; i = i + 5)
    {
        int tmpRight = (i + 4 >= length) ? length - 1 : i + 4;
        int tmpLength = tmpRight - i + 1;
        int *div = new int[tmpLength];
        for (int j = i; j <= tmpRight; j++)
        {
            div[j - i] = nums[j];
        }
        quickSort(div, 0, tmpLength - 1);
        if (tmpLength % 2 == 1)
        {
            res[itr++] = div[tmpLength / 2];
        }
        else
        {
            res[itr++] = (div[tmpLength / 2] + div[tmpLength / 2 - 1]) / 2;
        }
        delete[] div;
    }
    int x = choosePivot(res, 0, divLength - 1);
    delete[] res;
    return x;
}

int dSelect(int *nums, int left, int right, int k)
{
    if (left == right)
    {
        return nums[left];
    }
    int pivot = choosePivot(nums, left, right);
    int pivotat = 0;
    for (int i = left; i < right; i++)
    {
        if (nums[i] == pivot)
        {
            pivotat = i;
        }
    }
    swap(pivotat, left, nums);
    //int pivot = nums[left];
    int i = left + 1, j = i;
    for (; i <= right; i++)
    {
        if (nums[i] < pivot)
        {
            swap(j, i, nums);
            j++;
        }
    }
    swap(j - 1, left, nums);
    if (j - 1 == k)
    {
        return nums[k];
    }
    else if (j - 1 > k)
    {
        return rSelect(nums, left, j - 2, k);
    }
    else
    {
        return rSelect(nums, j, right, k - j + 1);
    }
}
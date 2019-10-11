//
// Created by 吴佳遥 on 2019-10-10.
//
#include "sort.h"
void bubbleSort(int *nums, int length)
{
    for(int i = 0 ; i<length-1;i++)
    {
        for (int j = 0; j < length-1-i; j++)
        {
            if(nums[j] > nums[j+1])
            {
                swap(j,j+1,nums);
            }
        }
    }
}



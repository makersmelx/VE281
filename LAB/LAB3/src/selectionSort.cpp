//
// Created by 吴佳遥 on 2019-10-10.
//

#include "sort.h"

void selectionSort(int*nums,int length)
{
    for(int i = 0 ;i < length - 1;i++)
    {
        int min = INT32_MAX;
        int minAt = i;
        for(int j = i ; j< length;j++)
        {
            if(nums[j]<min)
            {
                min = nums[j];
                minAt = j;
            }
        }
        swap(i,minAt,nums);
    }
}


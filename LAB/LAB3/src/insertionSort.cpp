//
// Created by 吴佳遥 on 2019-10-10.
//
#include "sort.h"
void insertSort(int* nums, int length){
    for(int i = 1 ; i<length;i++)
    {
        int tmp = nums[i],j = i-1;
        while(j>=0 && tmp < nums[j])
        {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = tmp;
    }

}
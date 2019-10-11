#include "sort.h"
using namespace std;
void quickSort(int* nums,int left,int right)
{
    if(left >= right)
    {
       return ;
    }
    int pivotIndex = rand() % (right - left + 1) + left;
    swap(left,pivotIndex,nums);
    int pivotat = left;
    int i = left + 1, j = i;
    for (; j <= right; j++)
    {
        if (nums[j] < nums[pivotat])
        {
            swap(i,j,nums);
            i++;
        }
    }
    swap(i-1,pivotat,nums);
    quickSort(nums,left, i - 2);
    quickSort(nums,i, right);
}
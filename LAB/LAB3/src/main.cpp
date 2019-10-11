#include "sort.h"
#ifdef TIMING
#include <time.h>
#endif
using namespace std;
int main()
{
    int mode = 0;
    cin >> mode;
    int length = 0;
    cin >> length;
    int select = 0;

    int *nums = new int[length];
    if (mode == 5 || mode == 6)
    {
        cin >> select;
    }
    for (int i = 0; i < length; i++)
    {
        int tmp = 0;
        cin >> tmp;
        nums[i] = tmp;
    }
#ifdef TIMING
    clock_t start = clock();
#endif
    switch (mode)
    {
    case 0:
    {
        bubbleSort(nums, length);
#ifndef TIMING
        printArray(nums, length);
#endif
        break;
    }
    case 1:
    {
        insertSort(nums, length);
#ifndef TIMING
        printArray(nums, length);
#endif
        break;
    }
    case 2:
    {
        selectionSort(nums, length);
#ifndef TIMING
        printArray(nums, length);
#endif
        break;
    }
    case 3:
    {
        mergeSort(nums, length);
#ifndef TIMING
        printArray(nums, length);
#endif
        break;
    }
    case 4:
    {
        quickSort(nums, 0, length - 1);
#ifndef TIMING
        printArray(nums, length);
#endif
        break;
    }
    case 5:
    {
        int res = rSelect(nums, 0, length - 1, select);
#ifndef TIMING
        printSearch(select, res);
#endif
        break;
    }
    case 6:
    {
        int res = dSelect(nums, 0, length - 1, select);
#ifndef TIMING
        printSearch(select, res);
#endif
        break;

        break;
    }

    default:
        break;
    }
#ifdef TIMING
    clock_t finish = clock();
    int t = (int)(finish - start);
    float x = ((float)t) / CLOCKS_PER_SEC;
    cout << length << ",";
    cout << t << endl;
#endif
    free(nums);
}
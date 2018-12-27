#ifndef SQLISTSORT_H
#define SQLISTSORT_H
    
#include "../myhead.h"
#include "../03list/01sequece-list/sequence.h"
const int KEYNUM = 3;
const int RADIX = 10;
template <typename elemtype>
class SqListSort:public SqList<elemtype>
{
public:
    void binaryInsertSort();

    void bubbleSort();

    int getIndex(int i);

    void heapSort();

    void insertSort();

    void mergeSort();

    void quickSort();

    void radixSort();

    void ShellSort();

    void selectSort();

    void staticLinkListSort();

private:
    void heapSortAdjust_aux(int low, int high);

    void mergeSort_aux(int s, int high);

    void mergeSortOne_aux(int i, int m, int n);

    void quickSort_aux(int low, int hign);

    int quickSortPartition_aux(int low, int high);

    void radixSortCollect_aux(int front[], int end[], int time);

    void radixSortDistribute_aux(int i, int front[], int end[]);

    void ShellSort_aux(int dk);

public:
    SqListSort();

    ~SqListSort();

    SqListSort(const SqListSort& s);

protected:
    int *index;

};

template <typename elemtype>
void SqListSort<elemtype>::binaryInsertSort()
{
    int low;
    int mid;
    int high;
    int k = -1;
    elemtype key;

    for(int i = 1; i < n; i++)
    {
        key = elem[i];
        low = 0;
        high = i - 1;

        while(low <= high)
        {
            mid = (low + high) / 2;
            
            if(key < elem[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        for(int j = i - 1; j >= high + 1; --j)
        {
            elem[j + 1] = elem[j];
        }
        elem[high + 1] = key;
    }
}

template <typename elemtype>
void SqListSort<elemtype>::bubbleSort()
{
   bool flag = true; 
   elemtype t;

   for(int i = 1; i < n && flag; ++i)
   {
       flag = false;
       for(int j = 0; j < n - 1; ++j)
       {
           if(elem[j + 1] < elem[j])
           {
               flag = true;
               t = elem[j + 1];
               elem[j + 1] = elem[j];
               elem[j] = t;
           }
       }
       if(flag == false)
           break;
   }
}

template <typename elemtype>
int SqListSort<elemtype>::getIndex(int i)
{
    if(i < 1 || i > n)
        return -1;
    else
        return index[i - 1];
}

template <typename elemtype>
void SqListSort<elemtype>::heapSort()
{
    int i, j = 1;
    elemtype t;

    for(i = n / 2; i > -1; --i)
        heapSortAdjust_aux(i, n - 1);

    for(i = n - 1; i >= 1; --i)
    {
        t = elem[i];
        elem[i] = elem[0];
        elem[0] = t;

        heapSortAdjust_aux(0, i - 1);
    }
}

template <typename elemtype>
void SqListSort<elemtype>::insertSort()
{
    elemtype key;
    int temp_index;

    for(int i = 0; i < n; i++)
        index[i] = i;

    for(i = 1; i < n; i++)
    {
        key = elem[i];
        temp_index = index[i];

        for(int j = i - 1; j >= 0 && key < elem[j]; --j)
        {
            elem[j + 1] = elem[j];
            index[j + 1] = index[j];
        }

        elem[j + 1] = key;
        index[j + 1] = temp_index;
    }
}

template <typename elemtype>
void SqListSort<elemtype>::mergeSort()
{
    mergeSort_aux(0, n - 1);
}

template <typename elemtype>
void SqListSort<elemtype>::quickSort()
{
    quickSort_aux(0, n - 1);
}

template <typename elemtype>
void SqListSort<elemtype>::radixSort()
{
    int front[RADIX], end[RADIX];

    int i;

    for(i = 0; i < n; ++i)
        elem[i].next = i + 1;

    elem[n - 1].next = 0;

    for(i = 1; i <= KEYNUM; ++i)
    {
        radixSortDistribute_aux(i, front, end);
        
        radixSortCollect_aux(front, end, i);
    }
}

template <typename elemtype>
void SqListSort<elemtype>::ShellSort()
{
    int dlta[FRISTSIZE];

    for(int d = n / 2; k = 0; d >= 1; d = d / 2)
        dlta[k++] = d;

    for(int i = 0; i < k; ++i)
        ShellSort_aux(dlta[i]);
}

template <typename elemtype>
void SqListSort<elemtype>::selectSort()
{
    int min;
    elemtype t;

    for(int i = 1; i < n; i++)
    {
        min = i - 1;

        for(int j = i; j < n; j++)
        {
            if(elem[j] < elem[min])
                min = j;
        }

        if(min != i - 1)
        {
            t = elem[min];
            elem[min] = elem[i - 1];
            elem[i - 1] = t;
        }
    }
}

template <typename elemtype>
void SqListSort<elemtype>::staticLinkListSort()
{
    int q;
    int p;

    elem[0].next = 1;

    for(int i = 2; i < n; ++i)
    {
        q = 0; 
        p = elem[0].next;

        while(p && elem[p].data <= elem[i].data)
        {
            q = p;
            p = elem[p].next;
        }

        elem[i].next = p;
        elem[q].next = i;
    }
}

template <typename elemtype>
void SqListSort<elemtype>::heapSortAdjust_aux(int low, int high)
{
    elemtype t = elem[low];

    for(int max = 2 * low + 1; max <= high;)
    {
        if(max + 1 <= high && elem[max] < elem[max + 1])
            ++max;

        if(t >= elem[max])
            break;
        
        elem[low] = elem[max];

        low = max;

        max = 2 * low + 1;
    }
    elem[low] = t;
}

template <typename elemtype>
void SqListSort<elemtype>::mergeSort_aux(int low, int high)
{
    int mid;

    if(low != high)
    {
        mid = (low + high) / 2;

        mergeSort_aux(low, mid);

        mergeSort_aux(mid + 1, high);

        mergeSort_aux(low, mid, high);
    }
}

template <typename elemtype>
void SqListSort<elemtype>::mergeSortOne_aux(int i, int m, int n)
{
    elemtype temp[FIRSTSIZE];

    int i, j, k;
    
    static int time = 1;

    for(i = k = low, j = mid + 1; i <= mid && j <= high;)
    {
        if(elem[i] <= elem[j])
            temp[k++] = elem[i++];
        else
            temp[k++] = elem[j++];
    }

    if(i <= mid)
    {
        for(; i <= mid;)
            temp[k++] = elem[i++];
    }

    if(j <= high)
    {
        for(; j <= high;)
            temp[k++] = elem[j++];
    }

    for(k = low; k <= high; ++k)
        elem[k] = temp[k];
}

template <typename elemtype>
void SqListSort<elemtype>::quickSort_aux(int low, int hign)
{
   int keyLoc;

   if(low < high)
   {
       keyLoc = quickSortPartition_aux(low, high);
       quickSort_aux(low, keyLoc - 1);
       quickSort_aux(keyLoc + 1, high);
   }
}

template <typename elemtype>
int SqListSort<elemtype>::quickSortPartition_aux(int low, int high)
{
    int i = low, j = high;
    elemtype t;
    
    t = elem[i];

    while(i < j)
    {
        while(i < j && elem[j] >= t)
            --j;

        elem[i] = elem[j];
        while(i < j && elem[i] <= t)
            ++i;

        elem[j] = elem[i];
    }
    
    elem[i] = t;
    return i;
}

template <typename elemtype>
void SqListSort<elemtype>::radixSortCollect_aux(int front[], int end[], int time)
{
    int rear;

    int j;
    for(j = 0; !front[j]; ++j);
    
    elem[0].next = front[j];
    read = end[j];

    while(j < RADIX)
    {
        ++j;
        for(; j < RADIX - 1 && !front[j]; ++j);

        if(j < RADIX && front[j])
        {
            elem[rear].next = front[j];
            rear = end[j];
        }
    }
    elem[rear].next = 0;
}

template <typename elemtype>
void SqListSort<elemtype>::radixSortDistribute_aux(int i, int front[], int end[])
{
    int p;
    int pos;
    int t;

    for(int j = 0; j < RADIX; ++j)
        front[j] = 0;

    for(p = elem[0].next; p; p = elem[p].next)
    {
        t = elem[p].data;
        pos = i;
        while(pos > 1)
        {
            t /= 10;
            --pos;
        }

        j = t % 10;

        if(!front[j])
            front[j] = p;
        else
            elem[end[j]].next = p;
        end[j] = p;
    }
}

template <typename elemtype>
void SqListSort<elemtype>::ShellSort_aux(int dk)
{
    int j;
    static int time = 1;
    elemtype key;

    for(int i = dk; i < n; ++i)
    {
        j = i - dk;
        if(elem[i] < elem[j])
        {
            key = elem[i];

            for(; j >= 0 && key < elem[j]; j -= dk)
                elem[j + dk] = elem[j];
            elem[j + dk] = key;
        }
    }
}

template <typename elemtype>
SqListSort<elemtype>::SqListSort()
{
    index = new int[FIRSTSIZE];
    assert(index != 0);
}

template <typename elemtype>
SqListSort<elemtype>::~SqListSort()
{
    clear();
    delete[] index;
}

template <typename elemtype>
SqListSort<elemtype>::SqListSort(const SqListSort& s)
{
    listSize = otherS.listSize;
    
    index = new int[listSize];
    assert(index != 0);

    elem = new elemtype[listSize];
    assert(index != 0);

    n = otherS.n;

    for(int i = 0; i < n; ++i)
    {
        elem[i] = otherS.elem[i];
        index[i] = otherS.index[i];
    }
}
#endif

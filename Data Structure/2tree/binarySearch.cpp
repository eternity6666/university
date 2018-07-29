/*
 * 这是二分查找(Binary Search)的运用
 */
const int maxSize=100005;
typedef int elementType;
typedef struct
{
    elementType data[maxSize];
    int length;
} *List;
int BinarySearch(List tbl,elementType k)
{
    int left,right,mid,NotFound=-1;

    left=1;
    right = tbl->length;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(k<tbl->data[mid])right=mid-1;
        else if(k>tbl->data[mid])left=mid+1;
        else return mid;
    }
    return NotFound;
}
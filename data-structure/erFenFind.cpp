#include <bits/stdc++.h>

using namespace std;
int main()
{
    int array[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    int a=12;
    int left,right,mid;
    int i=0;
    left=1;
    right=13;
    while(left<=right)
    {
        i++;
        mid=(left+right)/2;
        if(array[mid]>a) right=mid-1;
        else if(array[mid]<a) left=mid+1;
        else
        {
            cout<<i<<endl;
            cout<<"find it"<<endl;
            break;
        }
    }
    return 0;
}
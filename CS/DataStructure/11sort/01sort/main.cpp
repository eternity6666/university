#include <iostream>
#include "../../myhead.h"
#include "SqList.h"
#include <iomanip>

const int KEYNUM = 3;
const int RADIX = 10;
using namespace std;


int quickelemtypeime=1;
int quickelemtypeemp[100]={0};
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
    void heapSortAdjust_aux(int s,int m);
    void mergeSort_aux(int s,int t);
    void mergeSortOne_aux(int i,int m,int n);
    void quickSort_aux(int low,int high);
    int quickSortPartion_aux(int low,int high);
    void radixSortCollect_aux(int front[],int end[],int time);
    void radixSortDistribute_aux(int i,int front[],int end[]);
    void ShellSort_aux(int dk);
public:
    SqListSort();
    ~SqListSort();
    SqListSort(const SqListSort& s);
protected:
    int *index;
public:
    class sNode
    {
    public:
        int data;
        int next;
    };
    typedef sNode *SNodePointer;
protected:
    SNodePointer LinkE;
    int linkN;
};
template <typename elemtype>
void SqListSort<elemtype>::binaryInsertSort()
{
    int low;
    int mid;
    int high;
    int k;
    int i,j;
    
    
    int *mt=new int[this->n];  
    assert(mt!=0);
    int temp;
    elemtype key;
    for(i=1;i<this->n;++i)
    {
    
        for(k=0;k<this->n;k++)
            mt[k]=0;
        temp=0;
        
        key=this->elem[i];
        low=0;
        high=i-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            mt[mid]=++temp;
            if(key<this->elem[mid])
                high=mid-1;
            else
                low=mid+1;
            
        }
        
        for(j=i-1;j>=high+1;--j)
            this->elem[j+1]=this->elem[j];
        this->elem[high+1]=key;
       
        {
            if(i-1==0)
                cout<<"初始："<<endl;
            else
                cout<<"第"<<i-1<<"趟折半插入排序的结果如下："<<endl;
          
            cout<<"("<<'\t';
            for(k=0;k<this->n;)
            {
                cout<<this->elem[k];
                k++;
                if(k==i)
                    cout<<")";
                cout<<'\t';
            }
            cout<<endl;
            
            
            cout<<"\t";
            for(k=0;k<this->n;k++)
            {
                if(mt[k]>0)
                    cout<<"↑"<<'\t';
                else 
                    cout<<"\t";
                
            }
            cout<<endl;
            cout<<'\t';
            for(k=0;k<this->n;k++)
            {
                if(mt[k]>0)
                    cout<<mt[k]<<"\t";
                else 
                    cout<<'\t';
                
            }
            cout<<endl;
        }
    }
    delete[] mt;
}

template <typename elemtype>
void SqListSort<elemtype>::bubbleSort()
{
    bool flag=true;
    elemtype t;
    int i,j,k;
    for(i=1;i<this->n&&flag;++i)
    {
        flag=false;
        cout<<"("<<i<<")"<<endl;
        cout<<"第"<<i<<"趟排序经过如下"<<endl;
        for(j=0;j<this->n-i;++j)
        {
            
            if(this->elem[j+1]<this->elem[j])
            {
                {
                    for(k=0;k<=j+1;k++)
                        cout<<this->elem[k]<<'\t';
                    cout<<endl;
                    for(k=0;k<j+1;k++)
                    {
                        if(k==j)
                            
                            cout<<"|_______|";
                        else
                            cout<<'\t';
                    }
                    cout<<endl<<endl;
                }
                flag=true;
                t=this->elem[j+1];
               this-> elem[j+1]=this->elem[j];
                this->elem[j]=t;
            }
        }
       
        {
            cout<<"第"<<i<<"趟排序结果如下"<<endl;
            for(k=0;k<this->n;k++)
            {
                if(k==this->n-i)
                    cout<<"(";
                cout<<this->elem[k];
                if(k==this->n-1)
                    cout<<")";
                else
                    cout<<'\t';
            }
            cout<<endl<<endl;
        }
    }
}

template <typename elemtype>
int SqListSort<elemtype>::getIndex(int i)
{
    if(i<1||i>this->n)
        return -1;
    return index[i-1];
}

template <typename elemtype>
void SqListSort<elemtype>::heapSort()
{
    int i,k,l;
    elemtype t;
    int m=this->n;
    int deep;
    int time=1;
    int *tp=new int[this->n*2];
    assert(tp!=0);
    for(k=0;k<2*this->n;k++)
        tp[k]=k+1;
    int r;
    int p,q;
    int *temp=new int[this->n];
    assert(temp!=0);
    for(i=0;i<this->n;i++)
        temp[i]=0; 
    for(i=0;i<this->n;i++)
    {
        
        if(i==0)
        {
            temp[i]=1;
            m=m-temp[i];
        }
        else
        {
            temp[i]=2*temp[i-1];
            m=m-temp[i];
        }
        if(m<=temp[i]*2)
        {
            temp[i+1]=m;
            break;
        }
    }
    deep=i+2;
    
    int *flo=new int[deep];
    assert(flo!=0);
    flo[0]=2;
    for(i=1;i<deep;i++)
        flo[i]=2+flo[i-1];
 
    {
        
        cout<<"排序经过："<<endl<<endl;
        cout<<"初态："<<endl;
        m=0;q=0;
        r=2*this->n;
        for(i=0;i<deep;i++)
        {
            if(i!=0)
            {
                if(temp[i]!=0)
                {
                    for(k=0;k<deep-i;k++)
                    {
                        cout<<setw(2*tp[--r])<<" ";
                        for(p=0;p<temp[i];p++)
                        {
                            if(p%2==0)
                                cout<<setw(2)<<"_/";
                            else
                                cout<<setw((2*k+1)*2)<<" "<<setw(2)<<"\\_"<<setw((2*(2*q+1-k*2)))<<" ";
                        }
                        cout<<endl;
                    }
                    q=deep-i-1;
                }
            }
            
            cout<<setw(2*tp[--r])<<" ";
            for(k=m;k<m+temp[i];)
            {
                cout<<setw(2)<<this->elem[k]<<setw(2*flo[deep-i-1]+2)<<" ";
                if(m!=0&&this->n-k-1!=0)
                    cout<<setw(2)<<this->elem[++k]<<setw(2)<<" ";
                k++;
            }
            cout<<endl;
            m+=temp[i];
        }
        cout<<endl;
    }
    for(l=this->n/2-1;l>-1;--l)
        heapSortAdjust_aux(l,this->n-1);
    
    
    cout<<"创建初始堆："<<endl;
    {
        m=0;
        p=0;
        r=2*this->n;
        for(i=0;i<deep;i++)
        {
            if(i!=0)
            {
                if(temp[i]!=0)
                {
                    for(k=0;k<deep-i;k++)
                    {
                        cout<<setw(2*tp[--r])<<" ";
                        for(p=0;p<temp[i];p++)
                        {
                            if(p%2==0)
                                cout<<setw(2)<<"_/";
                            else
                                cout<<setw((2*k+1)*2)<<" "<<setw(2)<<"\\_"<<setw((2*(2*q+1-k*2)))<<" ";
                        }
                        cout<<endl;
                    }
                    q=deep-i-1;
                }
            }
            
            cout<<setw(2*tp[--r])<<" ";
            for(k=m;k<m+temp[i];)
            {
                cout<<setw(2)<<this->elem[k]<<setw(2*flo[deep-i-1]+2)<<" ";
                if(m!=0&&this->n-k-1!=0)
                    cout<<setw(2)<<this->elem[++k]<<setw(2)<<" ";
                k++;
            }
            cout<<endl;
            m+=temp[i];
        }
        cout<<endl;
    }
    
    for(l=this->n-1;l>=1;--l)
    {
        t=this->elem[l];
        this->elem[l]=this->elem[0];
        this->elem[0]=t;
        heapSortAdjust_aux(0,l-1);
        
        cout<<"第"<<time<<"次大根堆的调整:"<<endl;
        {
            m=0;
            p=0;
            r=2*this->n;
            for(i=0;i<deep;i++)
            {
                if(i!=0)
                {
                    if(temp[i]!=0)
                    {
                        for(k=0;k<deep-i;k++)
                        {
                            cout<<setw(2*tp[--r])<<" ";
                            for(p=0;p<temp[i];p++)
                            {
                                if(p%2==0)
                                    cout<<setw(2)<<"_/";
                                else
                                    cout<<setw((2*k+1)*2)<<" "<<setw(2)<<"\\_"<<setw((2*(2*q+1-k*2)))<<" ";
                            }
                            cout<<endl;
                        }
                        q=deep-i-1;
                    }
                }
                cout<<setw(2*tp[--r])<<" ";
                for(k=m;k<m+temp[i];)
                {
                    cout<<setw(2)<<this->elem[k]<<setw(2*flo[deep-i-1]+2)<<" ";
                    if(m!=0&&this->n-k-1!=0)
                        cout<<setw(2)<<this->elem[++k]<<setw(2)<<" ";
                    k++;
                }
                cout<<endl;
                m+=temp[i];
            }
            cout<<endl;
            time++;
        }
        
    }
    
    delete[] temp;
    delete[] tp;
    delete[] flo;
}

template <typename elemtype>
void SqListSort<elemtype>::heapSortAdjust_aux(int low,int high)
{
    elemtype t=this->elem[low];
    for(int max=2*low+1;max<=high;)
    {
        if(max+1<high&&this->elem[max]<this->elem[max+1])
            ++max;
        if(t>=this->elem[max])
            break;
        this->elem[low]=this->elem[max];
        low=max;
        max=2*low+1;
    }
    this->elem[low]=t;
}
//直接插入排序
template <typename elemtype>
void SqListSort<elemtype>::insertSort()
{
    elemtype key;
    int temp_index;
    int i,j,k,m;
    for(i=0;i<this->n;++i)
        index[i]=i;
    for(i=1;i<this->n;++i)
    {
        key=this->elem[i];
        temp_index=index[i];
        for(j=i-1;j>=0&&key<this->elem[j];--j)
        {
           this-> elem[j+1]=this->elem[j];
            index[j+1]=index[j];
        }
        this->elem[j+1]=key;
        index[j+1]=temp_index;
       
        {
            if(i==0)
                cout<<"初始："<<endl;
            else
                cout<<"第"<<i<<"趟折半插入排序的结果如下："<<endl;
          
            cout<<"("<<'\t';
            for(k=0;k<this->n;)
            {
                cout<<this->elem[k];
                k++;
                if(k==i+1)
                {
                    cout<<")";
                    m=k;
                }
                cout<<'\t';
            }
            cout<<endl;
            for(k=0;k<this->n;k++)
            {
                if(m==k)
                    cout<<"↑";
                cout<<'\t';
            }
            cout<<endl;
            
        }
    }
}

template <typename elemtype>
void SqListSort<elemtype>::mergeSort()
{
    mergeSort_aux(0,this->n-1);
}

template <typename elemtype>
void SqListSort<elemtype>::mergeSort_aux(int low,int high)
{
    int mid;
    if(low!=high)
    {
        mid=(low+high)/2;
        mergeSort_aux(low,mid);
        mergeSort_aux(mid+1,high);
        mergeSortOne_aux(low,mid,high);
    }
}

template <typename elemtype>
void SqListSort<elemtype>::mergeSortOne_aux(int low,int mid,int high)
{
    elemtype temp[FIRSTSIZE];
    int k,i,j;
    static int time=1;

    {
        cout<<"("<<time++<<")\t";
        cout<<"("<<'\t';
        for(k=low;k<=mid;k++)
            cout<<this->elem[k]<<'\t';
        cout<<")";
        cout<<"(\t";
        for(k=mid+1;k<=high;k++)
            cout<<this->elem[k]<<'\t';
        cout<<")";
        cout<<endl;
        cout<<"\t"<<"\t"<<"\t";
        for(k=low;k<=high;k++)
            if(k==mid)
                cout<<"\\/";
            else
                cout<<'\t';
        cout<<endl;
    }
    
    
    
    
    for(i=k=low,j=mid+1;i<=mid&&j<=high;)
    {
        if(this->elem[i]<=this->elem[j])
            temp[k++]=this->elem[i++];
        else
            temp[k++]=this->elem[j++];
    }
    if(i<=mid)
    {
        for(;i<=mid;)
            temp[k++]=this->elem[i++];
    }
    if(j<=high)
    {
        for(;j<=high;)
            temp[k++]=this->elem[j++];
    }
    if(j<=high)
    {
        for(;j<=high;)
            temp[k++]=this->elem[j++];
    }
    for(k=low;k<=high;++k)
        this->elem[k]=temp[k];
    cout<<"\t(\t";
    for(k=low;k<=high;k++)
    {
        cout<<this->elem[k]<<'\t';
    }
    cout<<")"<<endl<<endl;
    
}

template <typename elemtype>
void SqListSort<elemtype>::quickSort()
{
    cout<<"排序经过："<<endl;
    quickSort_aux(0,this->n-1);
    quickelemtypeime=1;
    for(int i=0;i<100;i++)
        quickelemtypeemp[i]=0;
}
template <typename elemtype>
void SqListSort<elemtype>::quickSort_aux(int low,int high)
{
    int keyLoc;
    int k;
    if(low<high)
    {
        keyLoc=quickSortPartion_aux(low,high);
        cout<<"\t第"<<quickelemtypeime<<"趟快速排序结果如下："<<endl;
        cout<<'\t';
        for(k=0;k<this->n;k++)
        {
            if(quickelemtypeemp[k]==0)
                if(quickelemtypeemp[k-1]==1)
                    cout<<"(";
            cout<<this->elem[k];
            if(quickelemtypeemp[k]==0&&quickelemtypeemp[k+1]==1)
                cout<<")";
            if(quickelemtypeemp[k]==0&&(k+1)==this->n)
                cout<<")";
            cout<<'\t';
        }
        quickelemtypeime++;
        cout<<endl<<endl;
        quickSort_aux(low,keyLoc-1);
        quickSort_aux(keyLoc+1,high);
    }
}

template <typename elemtype>
int SqListSort<elemtype>::quickSortPartion_aux(int low,int high)
{
    int i=low,j=high;
    elemtype t;
    t=this->elem[i];
    while(i<j)
    {
        while(i<j&&this->elem[j]>=t)
            --j;
        this->elem[i]=this->elem[j];
        while(i<j&&this->elem[i]<=t)
            ++i;
        this->elem[j]=this->elem[i];
    }
    this->elem[i]=t;
    quickelemtypeemp[i]=1;
    return i;
}

template <typename elemtype>
void SqListSort<elemtype>::radixSort()
{
    int front[RADIX],end[RADIX];
    int i,j,k;
    if (!LinkE)
        return;
    for(i=0;i<linkN;++i)
        LinkE[i].next=i+1;
    LinkE[linkN-1].next=0;
    cout<<"\t初始化如下："<<endl;
    cout<<"\t        ";
    for(j=0;j<linkN;j++)
        cout<<"["<<setw(2)<<j<<"] ";
    cout<<endl<<"\t  data: ";
    for(j=0;j<linkN;j++)
    {
        if (j==0)
            cout<<"     ";
        else
            cout<<setw(4)<<LinkE[j].data<<" ";
    }
    cout<<endl<<"\t  next: ";
    for(j=0;j<linkN;j++)
        cout<<setw(3)<<LinkE[j].next<<"  ";
    cout<<endl;
    
    
    for(i=1;i<=KEYNUM;++i)
    {
        radixSortDistribute_aux(i,front,end);
        radixSortCollect_aux(front,end,i);
        cout<<"\t("<<i<<")第"<<i<<"趟基数排序的经过如下："<<endl;
        for(j=0;j<RADIX;j++)
        {
            if(front[j])
            {
                cout<<"\t   front["<<j<<"]="<<front[j]<<" →";
                for(k=front[j];;k=LinkE[k].next)
                {
                    cout<<"["<<setw(2)<<k<<"] ";
                    if(k==end[j])
                        break;
                }
                cout<<"← end["<<j<<"]="<<end[j]<<endl;
                
                cout<<"\t                ";
                for(k=front[j];;k=LinkE[k].next)
                {
                    cout<<" "<<setw(3)<<LinkE[k].data<<" ";
                    if(k==end[j])
                        break;
                }
                cout<<endl;
                
                cout<<"\t                ";
                for(k=front[j];;k=LinkE[k].next)
                {
                    cout<<" "<<setw(3)<<LinkE[k].next<<" ";
                    if(k==end[j])
                        break;
                }
                cout<<endl;
            }
        }
        cout<<"\t   第"<<i<<"趟基数排序的结果如下："<<endl;
        cout<<"\t        ";
        for(j=0;j<linkN;j++)
            cout<<"["<<setw(2)<<j<<"] ";
        cout<<endl<<"\t  data: ";
        for(j=0;j<linkN;j++)
        {
            if (j==0)
                cout<<"     ";
            else
                cout<<setw(4)<<LinkE[j].data<<" ";
        }
        cout<<endl<<"\t  next: ";
        for(j=0;j<linkN;j++)
            cout<<setw(3)<<LinkE[j].next<<"  ";
        cout<<endl;
    }
}
template <typename elemtype>
void SqListSort<elemtype>::radixSortCollect_aux(int front[],int end[],int time)
{
    int rear;
    int j;
    for(j=0;!front[j];++j);
    LinkE[0].next=front[j];
    rear=end[j];
    while(j<RADIX)
    {
        ++j;
        for(;j<RADIX-1&&!front[j];++j);
        if(j<RADIX&&front[j])
        {
            LinkE[rear].next=front[j];
            rear=end[j];
        }
    }
    LinkE[rear].next=0;
}

//基数排序的分配函数
template <typename elemtype>
void SqListSort<elemtype>::radixSortDistribute_aux(int i,int front[],int end[])
{
    int p;
    int pos;
    int t;
    int j;
    for(j=0;j<RADIX;++j)
        front[j]=0;
    for(p=LinkE[0].next;p;p=LinkE[p].next)
    {
        t=LinkE[p].data;
        pos=i;
        while(pos>1)
        {
            t/=10;
            --pos;
        }
        j=t%10;
        if(!front[j])
            front[j]=p;
        else
            LinkE[end[j]].next=p;
        end[j]=p;
    }
}


template <typename elemtype>
void SqListSort<elemtype>::ShellSort()
{
    int dlta[FIRSTSIZE];
    int d,k,i;
    for(d=this->n/2,k=0;d>=1;d=d/2)
        dlta[k++]=d;
    for(i=0;i<k;++i)
    {
        cout<<"("<<i+1<<")第"<<i+1<<"趟Shell排序(d="<<dlta[i]<<")的经过如下："<<endl;
        ShellSort_aux(dlta[i]);
        cout<<"  第"<<i+1<<"趟Shell排序(d="<<dlta[i]<<")的结果如下："<<endl;
        for(int j=0;j<this->n;j++)
            cout<<this->elem[j]<<"\t";
        cout<<endl<<endl;
        
    }
}

template <typename elemtype>
void SqListSort<elemtype>::ShellSort_aux(int dk)
{
    int j,i,k;
    elemtype key;
    for(i=dk;i<this->n;++i)
    {
        for(j=0;j<this->n;j++)
            cout<<this->elem[j]<<"\t";
        cout<<endl;
        
        j=i-dk;
        if(this->elem[i]<this->elem[j])
        {
            key=this->elem[i];
            for(;j>=0&&key<this->elem[j];j-=dk)
                this->elem[j+dk]=this->elem[j];
            this->elem[j+dk]=key;
        }
        for(k=0;k<=i;k++)
        {
            if(k==j+dk)
                cout<<"↑"<<"\t";
            else if(k%dk==i%dk)
                cout<<" _ "<<"\t";
            else 
                cout<<"\t";
        }
        cout<<endl<<endl;
        
    }
}

template <typename elemtype>
void SqListSort<elemtype>::selectSort()
{
    int min,i,j,k;
    elemtype t;
    for(i=1;i<this->n;i++)
    {
        min=i-1;
        for(j=i;j<this->n;++j)
            if(this->elem[j]<this->elem[min])
                min=j;
        if(min!=i-1)
        {
            t=this->elem[min];
            this->elem[min]=this->elem[i-1];
            this->elem[i-1]=t;
        }
        
       
        {
            cout<<"第"<<i<<"趟直接选择排序的结果如下："<<endl;
           
            cout<<"("<<'\t';
            for(k=0;k<this->n;)
            {
                cout<<this->elem[k];
                k++;
                if(k==i)
                    cout<<"\t"<<")"<<"\t";
                else
                    cout<<'\t';
            }
            cout<<endl;
        }
    }
}
template <typename elemtype>
void SqListSort<elemtype>::staticLinkListSort()
{
    int q;
    int p;
    int i;
    if (!LinkE)
        return;
    LinkE[0].next=1;
    for(i=2;i<linkN;++i)
    {
        if(i==2)
            cout<<"\t初始："<<endl;
        else
            cout<<"\t第"<<(i-2)<<"趟静态链表排序的结果如下："<<endl;
        
        int j;
        cout<<"\t        ";
        for(j=0;j<linkN;j++)
            cout<<"["<<setw(2)<<j<<"] ";
        cout<<endl<<"\t  data: ";
        for(j=0;j<linkN;j++)
        {
            if (j==0)
                cout<<"     ";
            else
                cout<<setw(4)<<LinkE[j].data<<" ";
        }
        cout<<endl<<"\t  next: ";
        for(j=0;j<linkN;j++)
            cout<<setw(3)<<LinkE[j].next<<"  ";
        cout<<endl;
        
        if(i>=linkN)
            break;
        q=0;
        p=LinkE[0].next;
        while(p&&LinkE[p].data<=LinkE[i].data)
        {
            q=p;
            p=LinkE[p].next;
        }
        LinkE[i].next=p;
        LinkE[q].next=i;
    }
}


template <typename elemtype>
SqListSort<elemtype>::SqListSort()
{
    index=new int[FIRSTSIZE];
    assert(index!=0);
    LinkE=new sNode[1000];
    linkN=0;
}

template <typename elemtype>
SqListSort<elemtype>::~SqListSort()
{
    this->clear();
    delete []index;
    delete[] LinkE;
}

template <typename elemtype>
SqListSort<elemtype>::SqListSort(const SqListSort& otherS)
{
    index=new int[this->listSize];
    assert(index!=0);
    this->listSize=otherS.listSize;
    this->n=this->other.n;
    for(int i=0;i<this->n;i++)
    {
        this->elem[i]=otherS.elem[i];
        index[i]=otherS.index[i];
    }
    linkN=otherS.linkN;
    LinkE=new SNodePointer[linkN];
    assert(LinkE!=0);
    
    for(int i=0;i<linkN;i++)
    {
        LinkE[i].data=otherS.LinkE[i].data;
        LinkE[i].next=otherS.LinkE[i].next;
    }
}

#ifndef SQLISelemtypeSORelemtype_H
#define SQLISelemtypeSORelemtype_H
#endif

template <typename elemtype>
class MySqListSort:public SqListSort<elemtype>
{
public:
   
    void read(istream& in);
    
    void displaySq(ostream& out);
   
    void displaySS(ostream& out);
  
    bool randSql(int n,MySqListSort<elemtype>& otherS);
 
    void randStaSql();
};
template <typename elemtype>
void MySqListSort<elemtype>::read(istream& in)
{
    cout<<"请输入要建立的顺序表的元素个数：";
    cin>>this->n;
    
    for(int i=0;i<this->n;i++)
    {
        cout<<"请输入顺序表的第"<<i+1<<"个元素：";
        in>>this->elem[i];
    }
    cout<<endl;
}
template <typename elemtype>
istream& operator >>(istream& in,MySqListSort<elemtype>& iL)
{ 
    iL.read(in);
    return in;
}
//输出
template <typename elemtype>
void MySqListSort<elemtype>::displaySq(ostream& out) 
{
    if(this->n==0)
        return;
    for(int i=0;i<this->n;i++)
        cout<<"["<<i+1<<"]"<<"\t";
    cout<<endl;
    for(int i=0;i<this->n;i++)
        cout<<this->elem[i]<<"\t";
    cout<<endl<<endl;
}
template <typename elemtype>
ostream& operator <<(ostream& out,MySqListSort<elemtype>& oL)
{
    oL.displaySq(out);
    oL.displaySS(out);
    return out;
}
//生成随机数顺序表
template <typename elemtype>
bool MySqListSort<elemtype>::randSql(int n,MySqListSort<elemtype>& otherS)
{
    srand((unsigned int)time(NULL));
    
    if(n<1||n>otherS.listSize) return false;
    else 
    {
        for(int i=0;i<n;i++)
        {
            otherS.elem[i]=(rand()%100+1);         
        }
        otherS.n=n;
    }
    return true;
}
template <typename elemtype>
void MySqListSort<elemtype>::randStaSql()
{
    srand((unsigned int)time(NULL));
    this->linkN=rand()%6+1;
    elemtype e;
    cout<<"\t用以下随机数作为当前静态链表的元素："<<endl<<"\t";
    delete[] this->LinkE;
    
    for(int i=0;i<this->linkN;i++)
    {
        if(i==0)
        {
            this->LinkE[i].data=0;
            this->LinkE[i].next=0;
            continue;
        }
        e=rand()%100;
        cout<<setw(5)<<e;
        this->LinkE[i].data=e;
        this->LinkE[i].next=0;
    }
    cout<<endl<<endl<<"\t随机生成的静态链表表为："<<endl;
    displaySS(cout);
}

template <typename elemtype>
void MySqListSort<elemtype>::displaySS(ostream& out)
{
    if(this->linkN==0)
        return;
    int i;
    cout<<"\t        ";
    for(i=0;i<this->linkN;i++)
        cout<<"["<<setw(2)<<i<<"] ";
    cout<<endl<<"\t  data: ";
    for(i=0;i<this->linkN;i++)
    {
        if (i==0)
            cout<<"     ";
        else
            cout<<setw(4)<<this->LinkE[i].data<<" ";
    }
    cout<<endl<<"\t  next: ";
    for(i=0;i<this->linkN;i++)
        cout<<setw(3)<<this->LinkE[i].next<<"  ";
    cout<<endl;
}

int main(){
    while(1)
    {
    MySqListSort<int> sor;
    cout <<"1.直接插入排序" << endl;
    cout <<"2.折半插入排序" << endl;
    cout <<"3.静态链表插入排序" << endl;
    cout <<"4.希尔排序" << endl;
    cout <<"5.冒泡排序" << endl;
    cout <<"6.快速排序" << endl;
    cout <<"7.直接选择排序" << endl;
    cout <<"8.堆排序" << endl;
    cout <<"9.归并排序" << endl;
    cout <<"10.基数排序" << endl;
    // freopen("/Users/user/Desktop/1.txt", "r", stdin);
    cin >> sor;
    }
   // sor.insertSort();
   // sor.binaryInsertSort();
   // sor.staticLinkListSort();
    //sor.ShellSort();
   // sor.bubbleSort();
   // sor.quickSort();
   // sor.selectSort();
  //  sor.heapSort();
   // sor.mergeSort();
   // sor.radixSort();
    return 0;
}


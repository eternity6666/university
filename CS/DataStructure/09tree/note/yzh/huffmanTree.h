#ifndef HUFFMANTREE_H

#define HUFFMANTREE_H

#include "SqTree.h"
#include "mySqTree.h"

/*哈夫曼树数据结构*/
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
struct node{
    char data;
    int weight,parent,lchild,rchild;
    string code;
    node(){
        data=(char)NULL;
        weight=0;
        parent=lchild=rchild=-1;
        code="";
    }
};

template<typename T>
class HuffmanTree
{
    /*template<typename T>
    friend std::istream& operator >> (std::istream& in, HuffmanTree<T>& item);
    template<typename T>
    friend std::ostream& operator << (std::ostream& out, HuffmanTree<T>& item);*/

public:
    /*显示哈夫曼树所有信息*///OK
    void display();

    /*显示哈夫曼树节点顺序表*///OK
    void displayList();

    /*以树状形式显示哈夫曼树*///OK
    void displayTree();

    /*由叶子结点生成哈夫曼树内部结点*///OK
    void createHuffmanInsideNode();

    /*把哈夫曼树节点顺序表转换成能以树状形式显示的顺序存储树*///OK
    void createHuffmanSeqTree();

    /*生成叶子结点的哈夫曼编码*///OK
    void huffmanCoding();

    /*判断哈夫曼树节点顺序表的状况*///OK
    int HuffmanSqListStatus();

    /*输入哈夫曼树叶子结点（信息和权值）*///OK
    void inputHuffmanLeafList();

    /*判断是否形成哈夫曼树对应的顺序存储树*///OK
    bool isHuffanSqTreeEmpty();

private:
    vector<node> huffSqList;		//哈夫曼树节点顺序表
    myseqtree<T> huffSqTree;	//哈夫曼树对应的顺序存储树
};

/*显示哈夫曼树所有信息*/
template<typename T>
void HuffmanTree<T>::display()
{
    /*显示哈夫曼树信息*/
    if (HuffmanSqListStatus() == 0)
    {
        cout << "\t哈夫曼树为空" << endl;
        return;
    }

    if (HuffmanSqListStatus() == 1)
    {
        cout << "\t哈夫曼树叶子结点如下（还没生成内部结点）：" << endl;
        displayList();
        return;
    }

    cout << "\t哈夫曼树所有结点如下：" << endl;
    displayList();

    if (!isHuffanSqTreeEmpty())
    {
        /*以树状形式显示哈夫曼树*/
        cout << endl << "\t 以以树状形式显示哈夫曼树如下：" << endl;
        cout << huffSqTree << endl;
        return;
    }

}

/*显示哈夫曼树节点顺序表*/
template<typename T>
void HuffmanTree<T>::displayList()
{
    /*显示哈夫曼树结点顺序表信息*/
    if (HuffmanSqListStatus() == 0)
    {
        cout << "\t没有输入哈夫曼树叶子结点，所以列表结点为空！" << endl;
        return;
    }

    if (HuffmanSqListStatus() == 1)
        cout << "\t哈夫曼树叶子结点如下（还没生成内部结点）：" << endl;
    else
        cout << "\t哈夫曼树所有结点如下：" << endl;


    //输出顺序表
    cout<<"       ";
    for(int i=0;i<huffSqList.size();i++){
        cout<<"["<<i<<"]"<<" ";
    }
    cout<<"\n  data"<<" ";
    for(int i=0;i<huffSqList.size();i++){
        cout<<setw(3)<<huffSqList[i].data<<" ";
    }
    cout<<"\nweight"<<" ";
    for(int i=0;i<(int)huffSqList.size();i++){
        cout<<setw(3)<<huffSqList[i].weight<<" ";
    }
    cout<<"\nparent"<<" ";
    for(int i=0;i<huffSqList.size();i++){
        cout<<setw(3)<<huffSqList[i].parent<<" ";
    }
    cout<<"\nlchild"<<" ";

    for(int i=0;i<huffSqList.size();i++){
        cout<<setw(3)<<huffSqList[i].lchild<<" ";
    }
    cout<<"\nrchild"<<" ";
    for(int i=0;i<huffSqList.size();i++){
        cout<<setw(3)<<huffSqList[i].rchild<<" ";
    }
    cout<<"\n  code"<<" ";
    for(int i=0;i<huffSqList.size();i++){
        cout<<setw(3)<<huffSqList[i].code<<" ";
    }
}

/*以树状形式显示哈夫曼树,并提示要能以树状形式显示哈夫曼树，还需完成的操作*/
template<typename T>
void HuffmanTree<T>::displayTree()
{
    if (!isHuffanSqTreeEmpty())
    {
        /*以树状形式显示哈夫曼树*/
        cout << endl << "\t 以以树状形式显示哈夫曼树如下：" << endl;
        cout << huffSqTree << endl;
        return;
    }

    /*显示哈夫曼树信息*/
    if (HuffmanSqListStatus() == 0)
    {
        cout << "\t没有输入哈夫曼树叶子结点！" << endl << endl;
        cout << "\t以树状形式显示哈夫曼树，你需要完成以下操作: "<< endl;
        cout << "\t(1)输入哈夫曼树的叶子节点（信息和权值）。" << endl;
        cout << "\t(2)由叶子节点生成哈夫曼树的内部结点。" << endl;
        cout << "\t(3)把哈夫曼树节点顺序表转换成能以树状形式显示的顺序存储树。" << endl;

        return;
    }

    if (HuffmanSqListStatus() == 1)
    {
        cout << "\t已经输入哈夫曼树叶子结点" << endl << endl;
        cout << "\t以树状形式显示哈夫曼树，你需要完成以下操作: " << endl;
        cout << "\t(1)由叶子节点生成哈夫曼树的内部结点。" << endl;
        cout << "\t(2)把哈夫曼树节点顺序表转换成能以树状形式显示的顺序存储树。" << endl;

        return;
    }


    if (HuffmanSqListStatus() == 2)
    {
        cout << "\t已经生成了哈夫曼树的所有结点！" << endl << endl;
        cout << "\t以树状形式显示哈夫曼树，你需要完成以下操作: " << endl;
        cout << "\t(1)把哈夫曼树节点顺序表转换成能以树状形式显示的顺序存储树。" << endl;
        return;
    }
}

/*由叶子结点生成哈夫曼树内部结点*/
template<typename T>
void HuffmanTree<T>::createHuffmanInsideNode() {
    int leafNum = (int) huffSqList.size();            //哈夫曼树叶子结点数
    int totalNum = 2 * leafNum - 1;                //哈夫曼树的结点总数
    int min1 = -1, min2 = -1;                    //存放两个未选择过的权值最小的结点的下标
    int weight1, weight2;            //存放两个未选择过的权值最小的结点的权值

    node e;                    //预存放哈夫曼树的内部结点

    if (HuffmanSqListStatus() == 0) {
        cout << "\t没有输入哈夫曼树的叶子结点，所以无法生成其内部结点！" << endl;
        return;
    }

    if (HuffmanSqListStatus() == 2) {
        cout << "\t已经生成了哈夫曼树的内部结点！" << endl;
        return;
    }

    /*注意生成哈夫曼树的内部结点*/
    for (int i = leafNum; i < totalNum; ++i) {
        weight1 = weight2 = 0x7f7f7f7f;            //weight1<weight2

        /*从现有的哈夫曼树界定的顺序表中，选出两个未选择过的权值最小的结点*/
        for (int j = 0; j < i; j++) {
            //huffSqList.getElem(j + 1, e);
            e = huffSqList[j];
            if (e.parent == -1) {
                /*如果该结点未被选择过*/
                if (e.weight < weight1)//比最小的小
                {
                    min2 = min1;
                    min1 = j;
                    weight2 = weight1;
                    weight1 = e.weight;
                } else if (e.weight < weight2) {
                    min2 = j;
                    weight2 = e.weight;
                }
            }
        }

        e.data = '@';
        e.weight = weight1 + weight2;
        e.lchild = min1;
        e.rchild = min2;
        e.parent = -1;
        e.code = "";

        /*将新生成的内部结点插入的顺序表最后*/
        huffSqList.push_back(e);

        /*设置两个最小权值结点的双亲下标*/
        huffSqList[min1].parent = i;
        huffSqList[min2].parent = i;
    }
}

/*把哈夫曼树节点顺序表转换成能以树状形式显示的顺序存储树*/
template <typename T>
void HuffmanTree<T>::createHuffmanSeqTree()
{
    				//预用作节点计数器及存储空间的下标值
   						//预存放哈夫曼树节点的信息值
    int num = (int)huffSqList.size();		//总结点数

//    node eP, eL, eR;				//预存放哈夫曼树的父节点，左孩子，及右孩子
    queue<node> que;			//预存放哈夫曼树节点队列
    queue<char> resultQ;			//预存放结点信息

    /*显示哈夫曼树信息*/
    if (HuffmanSqListStatus() == 0)
    {
        cout << "\t没有输入哈夫曼树叶子结点！" << endl << endl;
        cout << "\t把哈夫曼树节点顺序表转换成能以树状形式显示的顺序存储树，你需要完成以下操作: " << endl;
        cout << "\t(1)输入哈夫曼树的叶子节点（信息和权值）。" << endl;
        cout << "\t(2)由叶子节点生成哈夫曼树的内部结点。" << endl;

        return;
    }

    if (HuffmanSqListStatus() == 1)
    {
        cout << "\t已经输入哈夫曼树叶子结点" << endl << endl;
        cout << "\t把哈夫曼树节点顺序表转换成能以树状形式显示的顺序存储树，你需要完成以下操作: " << endl;
        cout << "\t(1)由叶子节点生成哈夫曼树的内部结点。" << endl;

        return;
    }

    if (!isHuffanSqTreeEmpty())
    {
        /*以树状形式显示哈夫曼树*/
        cout << endl << "\t已经把哈夫曼树节点顺序表转换成能以树状形式显示的顺序存储树!" << endl;
        return;
    }

    /*把哈夫曼树节点顺序表转换成能以树状形式显示的顺序存储树*/

    que.push(huffSqList[num-1]);				//根节点进队列,num为总结点数
    //char c=''
    int i=0;
    node tmp;tmp.data=' ';
    tmp.lchild=tmp.rchild=-1;
    while(i<num){
        node fro=que.front();que.pop();
        if(fro.data!=' ')i++;
        resultQ.push(fro.data);
        if(fro.lchild!=-1)
            que.push(huffSqList[fro.lchild]);
        else
            que.push(tmp);
            //resultQ.push(' ');
        if(fro.rchild!=-1)
            que.push(huffSqList[fro.rchild]);
        else
            que.push(tmp);
    }

    /*把resultQ中的元素都复制到哈夫曼树中*/
    huffSqTree.setSizeEmptyTree((int)resultQ.size());
    i = 0;
    char c;
    while(!resultQ.empty())
    {
        c=resultQ.front();resultQ.pop();
        huffSqTree.setnode(i++, c);
    }

    /*以顺序方式显示哈夫曼树对应的顺序存储树*/
    huffSqTree.display();
    cout << endl << endl;

    cout << huffSqTree << endl;//输出树状树

}

/*生成叶子结点的哈夫曼编码*/
template<typename T>
void HuffmanTree<T>::huffmanCoding()
{

    int leafNum = ((int)huffSqList.size() + 1 ) / 2;

    //int index ;			//预存放哈夫曼编码的下标
    //char * code;			//预临时存放哈夫曼编码
    			//预存放哈夫曼树节点顺序表中孩子结点和双亲结点

    /*显示哈夫曼树信息*/
    if (HuffmanSqListStatus() == 0)
    {
        cout << "\t没有输入哈夫曼树叶子结点！" << endl << endl;
        cout << "\t生成叶子结点的哈夫曼编码，你需要完成以下操作: " << endl;
        cout << "\t(1)输入哈夫曼树的叶子节点（信息和权值）。" << endl;
        cout << "\t(2)由叶子节点生成哈夫曼树的内部结点。" << endl;

        return;
    }

    if (HuffmanSqListStatus() == 1)
    {
        cout << "\t已经输入哈夫曼树叶子结点" << endl << endl;
        cout << "\t生成叶子结点的哈夫曼编码，你需要完成以下操作: " << endl;
        cout << "\t(1)由叶子节点生成哈夫曼树的内部结点。" << endl;

        return;
    }

    /*取哈夫曼树第一个结点，判断是否已经生成了哈夫曼编码*/
    node eC, eP;
    eC=huffSqList[0];
    if (!eC.code.empty())
    {
        cout << "\t已经生成了哈夫曼编码！" << endl;
        return;
    }
    /*逐一生成每个叶子结点的哈夫曼编码*/
    //int child_now,parent_now;
    int child, parent;			//预存放当前结点的孩子即双亲的下标
    for (int i = 0; i < leafNum; ++i)
    {
        parent=huffSqList[i].parent;
        child=i;
        while(parent!=-1){
            eP=huffSqList[parent];
            if(eP.lchild==child)huffSqList[i].code+='0';
            else huffSqList[i].code+='1';
            child=parent;
            parent=eP.parent;
        }
        reverse(huffSqList[i].code.begin(),huffSqList[i].code.end());
    }
    displayList();
}

/*判断哈夫曼树节点顺序表的状况*/
template<typename T>
int HuffmanTree<T>::HuffmanSqListStatus()
{
    int n;		//预存放哈夫曼树最后一个结点的下标
    node e;		//预存放哈夫曼树的内部结点

    if (huffSqList.empty())
        return 0;				//说明还没有输入叶子结点

    n = (int)huffSqList.size();

    e=huffSqList[n-1];			//查看最后那个结点是否有左右字树，如果有的话，就已经生成了内部结点，否则没有

    if (n != 1 && e.lchild == -1 && e.rchild == -1)
        return 1;

    else
        return 2;			//如果只有一个结点，那么就不用生称内部结点
}

/*输入哈夫曼树叶子结点（信息和权值）*/
template<typename T>
void HuffmanTree<T>::inputHuffmanLeafList()
{
    huffSqList.clear();	//把哈夫曼顺序表置空

    huffSqTree.clear();	//把哈夫曼顺序树置空

    int n=0;
    cout<<"请输入哈夫曼树叶子结点数：";cin>>n;
    cout<<"请输入哈夫曼树叶子结点（英文字母信息值和数字的权值\n";
    node tmp;
    for(int i=0;i<n;i++){
        cout<<"第"<<i+1<<"个叶子结点的信息值和权值（以空格隔开）：";
        //cin>>huffSqList[i].data;
        cin>>tmp.data;
        getchar();
        cin>>tmp.weight;
        huffSqList.push_back(tmp);
        //cin>>huffSqList[i].weight;
    }
}

/*判断是否形成哈夫曼树对应的顺序存储树*/
template<typename T>
bool HuffmanTree<T>::isHuffanSqTreeEmpty() {
    return (huffSqTree.getfinalindex() == -1);
}
#endif


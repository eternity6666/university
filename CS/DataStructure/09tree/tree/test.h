#ifndef TEST_H
#define TEST_H
#include"BiTree.h"
#include "ThreadTree.h"
#include "HuffmanTree.h"
using namespace std;

template<typename T>
void e1(BiTree<T>& t)
{
    system("clear");
    if(t.isempty())
        cout << " 该树为空" << endl;
    else
    {
        cout << t;
        cout << " 该树有" << t.countnode() << " 个结点。" << endl;
    }
    cout << endl;
}

template<typename T>
void e2(BiTree<T>& t)
{
    if(t.isempty())
        cout << " 该树为空" << endl;
    else
    {
        cout << t;
        cout << " 该树有" << t.countleaf() << " 个叶子。" << endl;
    }
    cout << endl;

}

template<typename T>
void e3(BiTree<T>& t)
{
    if(t.isempty())
        cout << " 该树为空" << endl;
    else
    {
        cout << t;
        cout << " 该树深度为" << t.depth() << endl;
    }
    cout << endl;
}

template<typename T>
void e4(BiTree<T>& t)
{
    if(t.isempty())
        cout << " 该树为空" << endl;
    else
    {
        cout << t;
        cout << " 交换所有子树" << endl;
        t.exchangelrchild();
        cout << t;
    }
    cout << endl;
}

template<typename T>
void e5(BiTree<T>& t)
{
    if(t.isempty())
        cout << " 该树为空" << endl;
    else
    {
        cout << t;
        cout << " 前序递归遍历该树：";
        t.preordertraverse();
        cout << endl;
    }
    cout << endl;
}

template<typename T>
void e6(BiTree<T>& t)
{
    if(t.isempty())
        cout << " 该树为空" << endl;
    else
    {
        cout << t;
        cout << " 中序递归遍历该树:";
        t.inordertraverse();
        cout << endl;
    }
    cout << endl;
}

template<typename T>
void e7(BiTree<T>& t)
{
    if(t.isempty())
        cout << " 该树为空" << endl;
    else
    {
        cout << t;
        cout << " 后序递归遍历该树：";
        t.postordertraverse();
        cout << endl;
    }
    cout << endl;
}

template<typename T>
void e8(BiTree<T>& t)
{
    if(t.isempty())
        cout << " 该树为空" << endl;
    else
    {
        cout << t;
        cout << " 非递归中序遍历该树：";
        t.norecursioninordertraverse();
        cout << endl;
    }
    cout << endl;
}

template<typename T>
void e9(BiTree<T>& t)
{
    if(t.isempty())
        cout << " 该树为空" << endl;
    else
    {
        cout << t;
        cout << " 按层次顺序遍历该树：";
        t.layordertraverse();
        cout << endl;
    }
    cout << endl;
}

template<typename T>
void e10(BiTree<T>& t)
{
    if(t.isempty())
        cout << " 该树为空" << endl;
    else
    {
        t.displayseqtree();
        cout << endl;
    }
    cout << endl;
}

template<typename T>
void e11(BiTree<T>& t)
{
    t.linktosequential();
    cout << " 操作结束" << endl;
    cout << endl;
}

template<typename T>
void e12(BiTree<T>& t)
{
    cout << " 操作结束" << endl;
    cout << endl;
}

template<typename T>
void e13(BiTree<T>& t)
{
    t.randomcreate();
    cout << endl;
}

template<typename T>
void e14(BiTree<T>& t)
{
    cin >> t;
    cout << endl;
}

template<typename T>
void e15(ThreadTree<T>& tt){
    cout << " 中序遍历上述中序穿线二叉树为：";
    tt.inOrderTraverse_ThreadTree();
}

template<typename T>
void e16(ThreadTree<T>& tt){
    //tt.sequetialToThreadTree()
    cin>>tt;
    cout << tt;
}

template<typename T>
void e17(ThreadTree<T>& tt){
    char ch,prior,next;
    cout << " 输入指定节点的数据域：";cin>>ch;
    tt.searchPriorNode(ch,prior);
    tt.searchNextNode(ch,next);
    cout << " 在上述中序穿线二叉树中" << ch << " 中序的前驱为：" << prior << " 后继为：" << next << '\n';
}

template<typename T>
void e18(ThreadTree<T>& tt){
    tt.randomCreate(-1);
    cout << " 随机生成中序穿线二叉树操作成功\n";
    cout << tt;
}

template<typename T>
void e19(ThreadTree<T>& tt){
    cin>>tt;
    cout << tt;
}

template <typename T>
void e20(HuffmanTree<T>& ht){
    cout << " \n*********哈夫曼树（二叉树的应用）*********\n";
    int choose=0;
    while(1)
    {
        cout << " \t20.1输入哈夫曼树叶子结点（信息和权值）\n";
        cout << " \t20.2有叶子结点生成哈夫曼树内部结点\n";
        cout << " \t20.3生成叶子结点的哈弗曼编码\n";
        cout << " \t20.4显示哈夫曼树结点顺序表\n";
        cout << " \t20.5把哈夫曼树节点顺序表转化为能以树状形式显示的顺序存储树\n";
        cout << " \t20.6以树状形式显示哈夫曼树\n";
        cout << " \t其他 结束\n";
        cout << " \n";

        cout << " \n//////////////////////////////////////\n";
        ht.displayList();
        cout << " \n//////////////////////////////////////\n";

        cout << " 请输入你要操作的代码<1-6>";
        cin >> choose;
        switch(choose)
        {
            case 1:
                e20_1(ht);
                cout << '\n';
                break;
            case 2:
                e20_2(ht);
                cout << '\n';
                break;
            case 3:
                e20_3(ht);
                cout << '\n';
                break;
            case 4:
                e20_4(ht);
                cout << '\n';
                break;
            case 5:
                e20_5(ht);
                cout << '\n';
                break;
            case 6:
                e20_6(ht);
                cout << '\n';
                break;
            default: 
                cout << " \n结束" << endl;
        }
        cout << " 还继续吗<Y.继续\tN.结束>? ";
        char c;
        cin >> c;
        if(c == 'Y' || c == 'y')
            continue;
        else
            break;
    }
}

template <typename T>
void e20_1(HuffmanTree<T>& ht){
    cout << " ********# 输入哈夫曼树叶子节点（信息和权值）#********\n";
    ht.inputHuffmanLeafList();
    ht.displayList();
}

template <typename T>
void e20_2(HuffmanTree<T>& ht){
    cout << " ********# 由叶子结点生成哈夫曼树内部结点 #********\n";
    //ht.displayList();
    ht.createHuffmanInsideNode();
    cout << " 操作成功！\n";
    ht.displayList();
}

template <typename T>
void e20_3(HuffmanTree<T>& ht){
    //ht.displayList();
    cout << " ********# 生成叶子结点的哈夫曼编码 #********\n";
    ht.huffmanCoding();
    ht.displayList();
}

template <typename T>
void e20_4(HuffmanTree<T>& ht){
    cout << " ********# 显示哈夫曼树顺序表 #********\n";
    ht.displayList();
}

template <typename T>
void e20_5(HuffmanTree<T>& ht){
    cout << " ********# 把哈夫曼树结点顺序表转化为顺序存储树 #********\n";
    ht.createHuffmanSeqTree();//自带输出功能；
}

template <typename T>
void e20_6(HuffmanTree<T>& ht){
    cout << " ********# 以树状形式显示哈夫曼树 #********\n";
    ht.displayTree();
}
#endif


#include <iostream>
#include <string>
#include "test.h"
#include "ThreadTree.h"
#include "HuffmanTree.h"

using namespace std;

int main()
{
    // using cout;

    BiTree<char> q, p;
    ThreadTree<char> tt;
    HuffmanTree<char> ht;

    int choose = 0;
    cout<<"\n ********# 随机生成测试树——二叉树 #********\n";
    q.randomcreate(7);//生成普通二叉树,修改默认参数
    cout << endl;
    bool isCreat_threadTree=false; 
    while(1)
    {
        system("clear");
        cout << q << endl;
        cout << " *********测试顺序表的操作*********" << endl;
        cout << "    1. 求二叉树的结点数"<< endl;
        cout << "    2. 求二叉树的叶子数"<< endl;
        cout << "    3. 递归求二叉树的深度"<< endl;
        cout << "    4. 交换二叉树中所有结点的左右子树"<< endl;
        cout << "    5. 前序递归遍历二叉树"<< endl;
        cout << "    6. 中序递归遍历二叉树"<< endl;
        cout << "    7. 后序递归求二叉树"<< endl;
        cout << "    8. 非递归中序遍历二叉树"<< endl;
        cout << "    9. 按层次顺序遍历二叉树"<< endl;
        cout << "   10. 以顺序存储的方式显示二叉树"<< endl;
        cout << "   11. 二叉树的二叉链表储存转化为顺序存储结构"<< endl;
        cout << "   12. 二叉树的顺序存储转换为二叉链表存储结构"<< endl;
        cout << "   13. 随机生成二叉树"<< endl;
        cout << "   14. 输入二叉树"<< endl;
        cout << "   15. 中序遍历中序穿线二叉树"<<'\n';
        cout << "   16. 中序穿线二叉树顺序存储转链式存储"<<'\n';
        cout << "   17. 中序穿线二叉树中找指定结点中序的前驱和后继"<<'\n';
        cout << "   18. 随机生成中序穿线二叉树"<<'\n';
        cout << "   19. 输入中序穿线二叉树"<<'\n';
        cout << "   20. 哈夫曼树（二叉树的应用）"<<'\n';
        cout << " 其他. 结束 "<< endl;
        cout << " 请选择你要操作的代码<1-20>: ";
        cin >> choose;
        if(choose>14 &&choose<18 && !isCreat_threadTree){
            isCreat_threadTree= true;
            cout<<"\n ********# 随机生成测试树——穿线中序二叉树 #********\n";
            tt.randomCreate(7);
            cout<<"\n 当前穿线中序二叉树为：\n";
            cout<<tt;
        }
        switch (choose)
        {
            case 1:
                e1(q);
                cout << endl;
                break;
            case 2:
                e2(q);
                cout << endl;
                break;
            case 3:
                e3(q);
                cout << endl;
                break;
            case 4:
                e4(q);
                cout << endl;
                break;
            case 5:
                e5(q);
                cout << endl;
                break;
            case 6:
                e6(q);
                cout << endl;
                break;
            case 7:
                e7(q);
                cout << endl;
                break;
            case 8:
                e8(q);
                cout << endl;
                break;
            case 9:
                e9(q);
                cout << endl;
                break;
            case 10:
                e10(q);
                cout << endl;
                break;
            case 11:
                e11(q);
                cout << endl;
                break;
            case 12:
                e12(q);
                cout << endl;
                break;
            case 13:
                e13(q);
                cout << endl;
                break;
            case 14:
                e14(q);
                cout << endl;
                break;
            case 15:
                e15(tt);
                cout << '\n';
                break;
            case 16:
                e16(tt);
                cout << '\n';
                break;
            case 17:
                e17(tt);
                cout << '\n';
                break;
            case 18:
                e18(tt);
                cout << '\n';
                break;
            case 19:
                e19(tt);
                cout << '\n';
                break;
            case 20:
                e20(ht);
                cout<<'\n';break;
            default: cout << "\n 结束" << endl;
        }
        cout << " 还继续吗<Y.继续\tN.结束>? ";
        char c;
        cin >> c;
        if(c == 'Y' || c == 'y')
            continue;
        else
            break;
    } 
    return 0;
}


#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
template <typename T>
class Bitree{
public:
    class Node{
    public:
        Node():lchild(NULL), rchild(NULL){};
        T data;
        class Node *lchild, *rchild;
    };
    typedef Node* NodePointer;
public:
    void clear();
    
    int countLeaf();
    
    int countNode();
    
    int depth();
    
    void displaySeqTree();
    
    void exchangeLRchild();
    
    NodePointer getRoot();
    
    void inOrderTraverse();
    
    bool isEmpty();
    
    void layOrderTraverse();
    
    void linkToSequential();
    
    void noRecursionInOrderTraverse(); // 非递归中序遍历
    
    void postOrderTraverse();
    
    void preOrderTraverse();
    
    void randomCreate();
    
    void sequentialToLink(int num);
    

    void BiTree_aux(NodePointer& p, NodePointer otherP);
    
    int countLeaf_aux(NodePointer p);
    
    int countNode_aux(NodePointer p);
    
    void deleteNode_aux(NodePointer p);
    
    int depth_aux(NodePointer p);
    
    void exchangeLRchild_aux(NodePointer& p);
    
    void inOrderTraverse_aux(NodePointer p);
    
    void postOrderTraverse_aux(NodePointer p);
    bool judge(char ch){
        if(ch != '\0' && ch != ' ')
            return true;
        return false;
    }
    void preOrderTraverse_aux(NodePointer p);
    void sequentialToLink_aux(int i,int num,NodePointer& p);
    void linkToSequential_aux(T *tmpT,NodePointer p, int i);
public:
    Bitree();
    ~Bitree();
    Bitree(const Bitree<T>& otherT);
    void read();
    void display();
    void display_aux(int h);
protected:
    NodePointer root;
    T* sqT;
};
template <typename T>
void Bitree<T> :: clear(){
    deleteNode_aux(root);
    root = NULL;
}
template <typename T>
void Bitree<T> :: deleteNode_aux(NodePointer p){
    if(p->lchild)
        deleteNode_aux(p->lchild);
    if(p->rchild)
        deleteNode_aux(p->rchild);
    delete p;
}
template <typename T>
int Bitree<T> :: countLeaf(){
    return countLeaf_aux(root);
}
template <typename T>
int Bitree<T> :: countLeaf_aux(NodePointer p){
    if(!p->lchild && !p->rchild)
        return 1;
    int res = 0;
    if(p->lchild)
        res += countLeaf_aux(p->lchild);
    if(p->rchild)
        res += countLeaf_aux(p->rchild);
    return res;
}
template <typename T>
int Bitree<T> :: countNode(){
    return countNode_aux(root);
}
template <typename T>
int Bitree<T> :: countNode_aux(NodePointer p){
    if(!p->lchild && !p->rchild)
        return 1;
    int res = 1;
    if(p->lchild)
        res += countNode_aux(p->lchild);
    if(p->rchild)
        res += countNode_aux(p->rchild);
    return res;
}
template <typename T>
int Bitree<T> :: depth(){
    return depth_aux(root);
}
template <typename T>
int Bitree<T> :: depth_aux(NodePointer p){
    if(!p->lchild && !p->rchild)
        return 1;
    int ldep = 0, rdep = 0;
    if(p->lchild) ldep = depth_aux(p->lchild);
    if(p->rchild) rdep = depth_aux(p->rchild);
    return (ldep > rdep ? ldep : rdep) + 1;
}
template <typename T>
void Bitree<T> :: exchangeLRchild(){
    exchangeLRchild_aux(root);
    linkToSequential();
}
template <typename T>
void Bitree<T> :: exchangeLRchild_aux(NodePointer &p){
    if(p->lchild)
        exchangeLRchild_aux(p->lchild);
    if(p->rchild)
        exchangeLRchild_aux(p->rchild);
    NodePointer tmp = p->lchild;
    p->lchild = p->rchild;
    p->rchild = tmp;
}
template <typename T>
typename Bitree<T> :: NodePointer Bitree<T> :: getRoot(){
    return root;
}

template <typename T>
void Bitree<T> :: inOrderTraverse(){
    inOrderTraverse_aux(root);
}
template <typename T>
void Bitree<T> :: inOrderTraverse_aux(NodePointer p){
    if(p->lchild)
        inOrderTraverse_aux(p->lchild);
    cout << p->data ;
    if(p->rchild)
        inOrderTraverse_aux(p->rchild);
}
template <typename T>
bool Bitree<T> :: isEmpty(){
    return root;
}
template <typename T>
void Bitree<T> :: layOrderTraverse(){
    NodePointer p;
    queue <NodePointer> q;
    if(root)
        q.push(root);
    while(!q.empty()){
        p = q.front();
        cout << p->data;
        q.pop();
        if(p->lchild) q.push(p->lchild);
        if(p->rchild) q.push(p->rchild);
    }
}
template <typename T>
void Bitree<T> :: noRecursionInOrderTraverse(){
    NodePointer p = root;
    stack<NodePointer> s;
    while(p || !s.empty()){
        if(p) {
            s.push(p);
            p = p->lchild;
        }
        else {
            p = s.top(); s.pop();
            cout << p->data;
            p = p->rchild;
        }
    }
}

template <typename T>
void Bitree<T> :: postOrderTraverse(){
    postOrderTraverse_aux(root);
}

template <typename T>
void Bitree<T> :: postOrderTraverse_aux(NodePointer p){
    if(p->lchild)
        postOrderTraverse_aux(p->lchild);
    if(p->rchild)
        postOrderTraverse_aux(p->rchild);
    cout << p->data;
}
template <typename T>
void Bitree<T> :: preOrderTraverse(){
    preOrderTraverse_aux(root);
}
template <typename T>
void Bitree<T> :: preOrderTraverse_aux(NodePointer p){
    cout << p->data;
    if(p->lchild) preOrderTraverse_aux(p->lchild);
    if(p->rchild) preOrderTraverse_aux(p->rchild);
}

template <typename T>
void Bitree<T>::randomCreate(){
    srand((unsigned)time(NULL));
    int n = rand()%30+1;
    cout <<"随机生成结点数为:";
    cout << n << endl;
    int s;
    sqT = new T[300];
    for(int i = 0; i < 300; ++i)
        sqT[i] = ' ';
    for(int i = 0; i < n; ++i){
        s = rand()%10;
        char ch = s+'A';
        sqT[i] = ch;
    }
    
    sequentialToLink(n);
}
template <typename T>
void Bitree<T> :: sequentialToLink(int num){
    sequentialToLink_aux(0,num,root);
}

template <typename T>
void Bitree<T>:: sequentialToLink_aux(int i,int num, NodePointer& p){
    if(num == 0){
        p = NULL;
        return;
    }
    p = new Node;
    p->data = sqT[i];
    if(2*i+1 > num || !judge(sqT[2*i+1]) )
        p->lchild = NULL;
    else
        sequentialToLink_aux(i*2+1, num, p->lchild);
    if(2*i+2 > num || !judge(sqT[2*i+2]))
        p->rchild = NULL;
    else 
        sequentialToLink_aux(i*2+2, num, p->rchild);
}
template <typename T>
void Bitree<T>:: linkToSequential(){
 
    int h = 1 << (depth()+1);
    T* tmpT = new T[h ];
    if(!root){
        delete []sqT; return;
    }
    delete []sqT;
    sqT = new T[h];
    for(int i = 0; i < h-1; ++i)
        sqT[i] = tmpT[i] = ' ';
    linkToSequential_aux(tmpT, root, 0);
    for(int i = 0; i < h-1; ++i){
        sqT[i] = tmpT[i];
    }
}
template<typename T>
void Bitree<T>:: linkToSequential_aux(T *tmpT,  NodePointer p,int i){
    tmpT[i] = p->data;
    if(p->lchild != NULL)
        linkToSequential_aux(tmpT, p->lchild, 2*i+1);
    if(p->rchild != NULL)
        linkToSequential_aux(tmpT, p->rchild, 2*i+2);
}
template <typename T>
Bitree<T> :: Bitree(){
    root = NULL;
}
template <typename T>
Bitree<T>:: Bitree(const Bitree<T>& otherT){
    if(!otherT.root){
        root = NULL;
        
    }
    else{
        BiTree_aux(root, otherT.root);
        sqT = new T[1<<(depth()+1)];
        linkToSequential();
    }
}
template <typename T>
void Bitree<T> :: BiTree_aux(NodePointer& p, NodePointer otherP){
    if(!otherP){
        p = NULL;
        return;
    }
    p = new Node;
    assert(p!=0);
    p->data = otherP->data;
    if(!otherP->lchild)
        p->lchild = NULL;
    else
        BiTree_aux(p->lchild, otherP->lchild);
    if(!otherP->rchild)
        p->rchild = NULL;
    else
        BiTree_aux(p->rchild, otherP->rchild);
}
template <typename T>
Bitree<T> ::~Bitree<T>(){
    clear();
}

template <typename T>
void Bitree<T> :: read(){
    cout <<"   采用顺序存储方式创建一颗二叉树" << endl;
    string s;
    getline(cin,s);
    sqT = new T[300];
    for(int i = 0; i < 200; ++i)
        sqT[i] = ' ';
    for(int i = 0; i < s.length(); ++i)
        sqT[i] = s[i];
    sequentialToLink_aux(0, s.length(),root);
}
template <typename T>
void Bitree<T> :: display(){
    display_aux(depth());
}
template <typename T>
void Bitree<T> :: display_aux(int h){
   
    char chh = '_';
    char chzx = '/';
    char chyx = '\\';
    int space = 0;
    int rgan = 0;
    int cnt = 2;
    int th = h;
    while(th >= 4){
        rgan += cnt; cnt *= 2;
        th--;
    }
    int sum = cnt/2;
    int ptr = 0;
    for(int i = 0; i < h; ++i){
        space = (1<<(h-i-1))-1; 
        for(int j = 0; j < space; ++j){
            printf(" ");
        }        
        for(int k = 0; k < (1<<i) ; ++k,ptr++){
            if(judge(sqT[ptr]))
                cout << sqT[ptr];
            else printf(" ");
            for(int l = 0; l < (1<<(h-i))-1; ++l)
                printf(" ");
        }
        //  cout << ptr << endl;
        printf("\n"); // 打印结点
        int len2 = (1<<(h-i-1))-1;
        if(i == h-1) continue;
        if(i != h-2){
            for(int l = 0; l < len2-1-rgan; ++l)
                printf(" ");
        }
        for(int k = 0; k < (1<<i); ++k){
            if(i == h-2){
                //          cout <<(ptr-((1<<i)-k)-1)*2+1 << endl;
                if(judge(sqT[(ptr-((1<<i)-k))*2+1]) )
                    printf("%c",chzx);
                else printf(" ");
                printf(" ");
                if(judge(sqT[(ptr-((1<<i)-k))*2+2]))
                    printf("%c",chyx);
                else printf(" ");
                printf(" ");
            }
            else{
                //  cout <<(ptr-((1<<i)-k))*2+1 << endl;
                for(int l = 0; l < rgan; ++l){
                    if(judge(sqT[(ptr-((1<<i)-k))*2+1]))
                        printf("%c",chh);
                    else
                        printf(" ");
                }
                if(judge(sqT[(ptr-((1<<i)-k))*2+1]))
                    printf("%c",chzx);
                else printf(" ");
                printf(" ");
                if(judge(sqT[(ptr-((1<<i)-k))*2+2]))
                    printf("%c",chyx);
                else printf(" ");
                for(int l = 0; l < rgan; ++l)
                    if(judge(sqT[(ptr-((1<<i)-k))*2+2]))
                        printf("%c",chh);
                    else
                        printf(" ");
                if(i == h-1)
                    printf(" ");
                else
                    for(int l = 0; l < (1<<(h-i))-rgan*2-2-1; ++l)
                        printf(" ");
            }
        }
        printf("\n");
        rgan -= sum;
        sum /= 2;
    }
}


//
//  main.cpp
//  二叉树
//
//  Created by KR on 2017/12/8.
//  Copyright © 2017年 Link. All rights reserved.
//


int main(int argc, const char * argv[]) {
   
    cout <<"1.求二叉树的结点数"<<endl;
    cout <<"2.求二叉树的叶子数"<<endl;
    cout <<"3.递归求二叉树深度"<<endl;
    cout <<"4.交换二叉树中所有结点的左右子树"<<endl;
    cout <<"5.前序递归遍历二叉树"<<endl;
    cout <<"6.中序递归遍历"<<endl;
    cout <<"7.后序递归遍历"<<endl;
    cout <<"8.非递归中序遍历二叉树"<<endl;
    cout <<"9.按层次顺序遍历二叉树"<<endl;
    cout <<"10.以顺序存储的方式显示二叉树"<<endl;
    cout <<"11.二叉树的顺序存储转换为链式存储"<<endl;
    cout <<"12.随机生成二叉树"<<endl;
    cout <<"13.输入二叉树"<<endl;
    
    Bitree<char> tree;
    cout << "随机生成二叉树:" << endl;
    tree.randomCreate();
    cout << "二叉树高度为:"<<tree.depth() << endl;
    tree.display();
    cout <<"交换左右子树:" << endl;
    tree.exchangeLRchild();
    cout << "二叉树高度为:"<<tree.depth() << endl;
    tree.display();
    cout <<"前序遍历为:";
    tree.preOrderTraverse();
    cout << endl;
    cout <<"中序遍历为:";
    tree.inOrderTraverse();
    cout << endl;
    cout <<"非递归中序遍历为:";
    tree.noRecursionInOrderTraverse();
    cout << endl;
    cout <<"层次遍历为:";
    tree.layOrderTraverse();
    cout << endl;
    cout <<"后序遍历为:";
    tree.postOrderTraverse();
    cout << endl;
    cout <<"叶子结点数:";
    cout << tree.countLeaf() << endl;
    cout <<"结点个数:";
    cout << tree.countNode() << endl;
    cout <<"请输入一个二叉树" << endl;
    tree.read();
    tree.display();
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
map<char,int> m1;
map<int,char> m2;

int ep,xp;

struct Edge 			//有向网
{
    int ed,weight;
    Edge *ne;
} edge[105];

struct Node 			//有向网
{
    int no;
    Edge *np;
} node[20];

int ver[20];
int Ze = 1;

void show()
{
    //邻接表输出函数
    for(int i = 0; i<xp; i++)
    {
        map<int,char>::iterator it;
        it = m2.find(i);
        cout << "[" << i << "]" << "　" << (*it).second << ":";
        cout << node[i].no;
        Edge *p = node[i].np;
        while(p)
        {
            cout << "->" << p->ed;// << "(" << p->weight << ")";
            p = p->ne;
            if(p == NULL)
                break;
        }
        cout << endl;
    }
    return;
}

void wshow()
{
    //有向网输出函数
    if(xp == 0)
        cout << "当前有向网为空\n";
    else
        cout << "当前有向网如下：" << endl;
    for(int i = 0; i<xp; i++)
    {
        map<int,char>::iterator it;
        it = m2.find(i);
        cout << "[" << i << "]" << "　" << (*it).second << ":";
        cout << node[i].no;
        Edge *p = node[i].np;
        while(p)
        {
            cout << "->" << p->ed << "(" << p->weight << ")";
            p = p->ne;
            if(p == NULL)
                break;
        }
        cout << endl;
    }
    return;
}

void e1()
{
    int cnt = 2;//标记当前点是第几个遍历到的
    for(int i = 0; i<xp; i++)
        ver[i] = 0;//初始化所有点为未遍历到
    cout << "******从某顶点开始对图做深度优先遍历******" << endl;
    cout << "请输入起始顶点的数据值：";
    char a;
    cin >> a;
    cout << "从顶点" << a << "开始，当前图的深度优先遍历顺序为：" << endl;
    map<char,int>::iterator it1;
    it1 = m1.find(a);
    int x = (*it1).second;
    ver[x] = 1;
    stack<Edge*> s;
    s.push(node[x].np);
    while(!s.empty())
    {
        Edge* ep = s.top();
        s.pop();
        if(ver[ep->ed] == 0)
        {
            if(ep->ne != NULL)
            {
                s.push(ep->ne);
            }
            ver[ep->ed] = cnt;
            cnt++;
            int tmp = ep->ed;
            if(node[tmp].np != NULL)
            {
                Edge* tm1 = node[tmp].np;
                if(ver[tm1->ed] != 0)
                {
                    while(tm1->ne != NULL)
                    {
                        if(ver[tm1->ed] != 0)
                            tm1 = tm1->ne;
                        else
                        {
                            s.push(tm1);
                            break;
                        }
                    }
                    if(ver[tm1->ed] != 0)
                        tm1 = tm1->ne;
                    else
                    {
                        s.push(tm1);
                    }
                }
                else
                {
                    s.push(tm1);
                }
            }
        }
        else
        {
            while(ep->ne != NULL)
            {
                if(ver[ep->ed] == 0)
                    s.push(ep);
                else
                    ep = ep->ne;
            }
        }
    }
    int CNT = 1;
    for(int i = 0; i<xp; i++)
        for(int j = 0; j<xp; j++)
        {
            if(ver[j] == CNT)
            {
                map<int,char>::iterator it2;
                it2 = m2.find(j);
                cout << " " << (*it2).second;
                CNT++;
            }
        }
    cout << endl;

}

void e2()
{
    int cnt = 2;//标记当前点是第几个遍历到的
    for(int i = 0; i<xp; i++)
        ver[i] = 0;//初始化所有点为未遍历到
    cout << "******从某顶点开始对图做广度优先遍历******" << endl;
    cout << "请输入起始顶点的数据值：";
    char a;
    cin >> a;
    cout << "从顶点" << a << "开始，当前图的广度优先遍历顺序为：" << endl;
    map<char,int>::iterator it1;
    it1 = m1.find(a);
    int x = (*it1).second;
    ver[x] = 1;
    queue<Edge*> q;
    q.push(node[x].np);
    while(!q.empty())
    {
        Edge* ep = q.front();
        q.pop();
        if(ver[ep->ed] == 0)
        {
            ver[ep->ed] = cnt;
            cnt++;
            Edge* nep = ep->ne;
            while(nep != NULL)
            {
                if(ver[nep->ed] == 0)
                {
                    q.push(nep);
                    break;
                }
                else
                    nep = nep->ne;
            }
            int nex = ep->ed;
            Edge* cur = node[nex].np;
            while(cur != NULL)
            {
                if(ver[cur->ed] == 0)
                {
                    q.push(cur);
                    break;
                }
                else
                    cur = cur->ne;
            }
        }
    }
    int CNT = 1;
    for(int i = 0; i<xp; i++)
        for(int j = 0; j<xp; j++)
        {
            if(ver[j] == CNT)
            {
                map<int,char>::iterator it2;
                it2 = m2.find(j);
                cout << " " << (*it2).second;
                CNT++;
            }
        }
    cout << endl;

}

void e3()
{
    wshow();
    cout << endl << "**********判断并输出图的一个拓扑序列*************" << endl;
    int cnt[xp];
    memset(cnt,0,sizeof(cnt));
    Edge *cur;
    for(int i = 0; i<xp; i++)
    {
        cur = node[i].np;
        while(cur != NULL)
        {
            cnt[cur->ed]++;
            cur = cur->ne;
        }
    }
    queue<int> v;
    for(int i = 0; i<xp; i++)
    {
        if(cnt[i] == 0)
        {
            v.push(i);
        }
    }
    while(!v.empty())
    {
        int ds = v.front();
        v.pop();
        map<int,char>::iterator it;
        it = m2.find(ds);
        cout << (*it).second << " ";
        Edge *dsp = node[ds].np;
        while(dsp != NULL)
        {
            cnt[dsp->ed]--;
            if(cnt[dsp->ed] == 0)
                v.push(dsp->ed);
            dsp = dsp->ne;
        }
    }
    cout << endl << "***************************************" << endl;
    return;
}

void e4()
{
    wshow();
    cout << endl << "************输出图的关键活动*************" << endl;
    cout << "图的关键活动如下：" << endl;
    int cnt[xp],cost[xp],mcost[xp][xp];//cost记录最早发生时间，mcost[i][j]记录i-j这个时间的最晚发生时间
    memset(cnt,0,sizeof(cnt));
    memset(cost,0,sizeof(cost));
    for(int i = 0; i<xp; i++)
    {
        for(int j = 0; j<xp; j++)
            mcost[i][j] = 10000;
    }
    Edge *cur;
    for(int i = 0; i<xp; i++)
    {
        cur = node[i].np;
        while(cur != NULL)
        {
            cnt[cur->ed]++;
            cur = cur->ne;
        }
    }
    queue<int> v;
    for(int i = 0; i<xp; i++)
    {
        if(cnt[i] == 0)
            v.push(i);
    }
    while(!v.empty())
    {
        int ds = v.front();
        v.pop();
        Edge *dsp = node[ds].np;
        while(dsp != NULL)
        {
            cnt[dsp->ed]--;
            cost[dsp->ed] = max(cost[ds]+dsp->weight,cost[dsp->ed]);
            if(cnt[dsp->ed] == 0)
            {
                v.push(dsp->ed);
            }
            dsp = dsp->ne;
        }
    }

    for(int i = 0; i<xp; i++)
    {
        Edge *cr = node[i].np;
        while(cr != NULL)
        {
            mcost[i][cr->ed] = min(cost[cr->ed]-cr->weight,mcost[i][cr->ed]);
            cr = cr->ne;
        }
    }
    cout << setw(5) << "起点" << setw(5) << "终点" << setw(5) << "权值" << setw(5) << "最早" << setw(5) << "最晚" << " " << "关键路径" << endl;
    for(int i = 0; i<xp; i++)
    {
        Edge *se = node[i].np;
        while(se != NULL)
        {
            cout << setw(5) << i << setw(5) << se->ed << setw(5) << se->weight << setw(5) << cost[i] << setw(5) << mcost[i][se->ed];
            if(cost[i] == mcost[i][se->ed])
                cout << setw(5) << "*";
            cout << endl;
            se = se->ne;
        }

    }
}

void e5()
{
    //随机生成邻接表 ，邻接表与有向网用的结构体是一样的，在输出时没有输出邻接表的权值
    if(Ze == 1)
    {
        Ze++;
        xp = 6;
        for(int i = 0; i<xp; i++)
        {
            char a = 'A'+i;
            m1[a] = i;
            m2[i] = a;
        }
        for(int i = 0; i<xp; i++)
        {
            node[i].no = i;
            node[i].np = NULL;
        }
        ep = 8;
        edge[0].ed = 1;
        edge[0].weight = rand()%10;
        edge[0].ne = NULL;
        edge[0].ne = node[0].np;
        node[0].np = &edge[0];

        edge[1].ed = 3;
        edge[1].weight = rand()%10;
        edge[1].ne = NULL;
        edge[1].ne = node[0].np;
        node[0].np = &edge[1];

        edge[2].ed = 2;
        edge[2].weight = rand()%10;
        edge[2].ne = NULL;
        edge[2].ne = node[1].np;
        node[1].np = &edge[2];

        edge[3].ed = 2;
        edge[3].weight = rand()%10;
        edge[3].ne = NULL;
        edge[3].ne = node[3].np;
        node[3].np = &edge[3];

        edge[4].ed = 5;
        edge[4].weight = rand()%10;
        edge[4].ne = NULL;
        edge[4].ne = node[3].np;
        node[3].np = &edge[4];

        edge[5].ed = 5;
        edge[5].weight = rand()%10;
        edge[5].ne = NULL;
        edge[5].ne = node[2].np;
        node[2].np = &edge[5];

        edge[6].ed = 5;
        edge[6].weight = rand()%10;
        edge[6].ne = NULL;
        edge[6].ne = node[4].np;
        node[4].np = &edge[6];

        edge[7].ed = 4;
        edge[7].weight = rand()%10;
        edge[7].ne = NULL;
        edge[7].ne = node[2].np;
        node[2].np = &edge[7];
    }
    else
    {
        srand((unsigned)time(0));
        xp = rand()%7;  //点数
        if(xp <= 3)
        {
            xp = 5;
        }
        for(int i = 0; i<xp; i++)
        {
            char a = 'A'+i;
            m1[a] = i;
            m2[i] = a;
        }
        for(int i = 0; i<xp; i++)
        {
            node[i].no = i;
            node[i].np = NULL;
        }
        ep = rand()%10;  //边数目
        if(ep <= 4)
        {
            ep = 6;
        }
        for(int i = 0; i<ep; i++)
        {
            int x,y;
            x = rand()%6;
            y = rand()%6;
            while(1)
            {
                if(y == x)
                    y = rand()%6;
                else
                    break;
            }
            edge[i].ed = y;
            edge[i].weight = rand()%10;
            edge[i].ne = NULL;
            if(node[x].np == NULL)
                node[x].np = &edge[i];
            else
            {
                edge[i].ne = node[x].np;
                node[x].np = &edge[i];
            }
        }
    }
    cout << "**********随机生成图的邻接表*********" << endl;
    show();
    return;
}

void e6()
{
    //只能输入有向网0，2，3懒得写了 ,输入的顶点无限制，可以是任意字母

    cout << "**********输入图的邻接表*********" << endl;
    cout << "图的种类(0-有向图；1-有向网；2-无向图；3-无向网)" << endl;
    cout << "请输入图的种类：";
    int type;
    //int nv,ne;//nv点数目     ne边数目
    cin >> type;
    cout << "顶点数：";
    cin >> xp;
    cout << "顶点值：";
    for(int i = 0; i<xp; i++)
    {
        char a;
        cin >> a;
        m1[a] = i;
        m2[i] = a;
    }
    cout << "弧数：";
    cin >> ep;

    for(int i = 0; i<xp; i++)
    {
        node[i].no = i;
        node[i].np = NULL;
    }

    cout << "输入各弧邻接的顶点" << endl;
    for(int i = 0; i<ep; i++)
    {
        char a,b;
        int w;
        cout << "第" << i+1 << "条弧起点:";
        cin >> a;
        cout << "第" << i+1 << "条弧终点:";
        cin >> b;
        cout << "第" << i+1 << "条弧权值:";
        cin >> w;
        map<char,int>::iterator it1,it2;
        it1 = m1.find(a);
        it2 = m1.find(b);
        int x = (*it1).second;
        int y = (*it2).second;
        edge[i].ed = y;
        edge[i].weight = w;
        edge[i].ne = NULL;
        if(node[x].np == NULL)
            node[x].np = &edge[i];
        else
        {
            edge[i].ne = node[x].np;
            node[x].np = &edge[i];
        }
    }
    wshow();
}

int Num;
map<char,int> me1;
map<int,char> me2;
struct Ex 			//课程表 数据
{
    int edm;
    Ex *em;
} exe[105];
struct Nx 			//课程表数据
{
    int nom;
    Ex *nm;
} nxe[20];
vector<int> v[1000];
void ex2()
{
    cout << "****************课程信息*******************" << endl;
    cout << setw(8) << "课程号" << setw(8) << "课程名" << setw(8) << "先修课" << endl;
    for(int i = 0; i<Num; i++)
    {
        map<int,char>::iterator it;
        it = me2.find(i);
        cout << setw(8) << i+1 << setw(8) << (*it).second;
        int c1 = 1;
        for(int j = 0; j<v[i+1].size(); j++)
        {
            if(c1 == 1)
            {
                cout << setw(8) << v[i+1][j];
                c1++;
            }
            else
            {
                cout << "," << v[i+1][j];
            }
        }
        cout << endl;
    }
}

void ex1()
{
    cout << "请输入课程数：";
    cin >> Num;
    cout << "请输入每门课程的信息：" << endl;
    for(int i = 0; i<Num; i++)
    {
        int a,c;
        char b;
        cout << "第" << i+1 << "门课程号：";
        cin >> a;
        cout << "第" << i+1 << "门课程名：";
        cin >> b;
        me1[b] = a-1;
        me2[a-1] = b;
        cout << "先修课数目：";
        cin >> c;
        if(c != 0)
        {
            while(c--)
            {
                int x;
                cout << "先修课序号：";
                cin >> x;
                v[a].push_back(x);
            }
        }
    }
    ex2();
}

void ex4()
{
    cout << "课程表对应图的邻接表如下：" << endl;
    for(int i = 0; i<Num; i++)
    {
        map<int,char>::iterator it;
        it = me2.find(i);
        cout << "[" << i << "]" << "　" << (*it).second << ":";
        cout << nxe[i].nom;
        Ex *p = nxe[i].nm;
        while(p != NULL)
        {
            cout << "->" << p->edm;
            p = p->em;
            if(p == NULL)
                break;
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void ex3()
{
    for(int i = 0; i<Num; i++)
    {
        nxe[i].nom = i;
        nxe[i].nm = NULL;
    }
    int cat = 0;
    for(int i = 0; i<Num; i++)
    {
        for(int j = 0; j<v[i+1].size(); j++)
        {
            exe[cat].edm = i;
            exe[cat].em = nxe[v[i+1][j]-1].nm;
            nxe[v[i+1][j]-1].nm = &exe[cat];
            cat++;
        }
    }
    ex4();
}

void ex5()
{
    ex2();
    ex4();
    cout << "******************课表排课*********************" << endl;

    int cnt[Num];
    memset(cnt,0,sizeof(cnt));
    Ex *cur;
    for(int i = 0; i<Num; i++)
    {
        cur = nxe[i].nm;
        while(cur != NULL)
        {
            cnt[cur->edm]++;
            cur = cur->em;
        }
    }

    queue<int> v;
    for(int i = 0; i<Num; i++)
    {
        if(cnt[i] == 0)
        {
            v.push(i);
        }
    }

    while(!v.empty())
    {
        int ds = v.front();
        v.pop();
        map<int,char>::iterator it;
        it = me2.find(ds);
        cout << (*it).second << " ";
        Ex *dsp = nxe[ds].nm;
        while(dsp != NULL)
        {
            cnt[dsp->edm]--;
            if(cnt[dsp->edm] == 0)
                v.push(dsp->edm);
            dsp = dsp->em;
        }
    }
    cout << endl << "以上是课程表的一种排课情况。" << endl;
    cout << "********************************************" << endl;
    return;
}

void e7()
{
    while(1)
    {
        system("clear");
        cout << "**************课程表的排课******************" << endl;
        cout << "1.输入课程表的信息" << endl;
        cout << "2.显示课程表的信息" << endl;
        cout << "3.由课程表信息生成对应图的临接表" << endl;
        cout << "4.显示课程表对应的临接图" << endl;
        cout << "5.排课" << endl;
        cout << "其他.结束" << endl;
        cout << "/////////////////////////////////" << endl;
        //随机生成图的邻接表
        cout << "/////////////////////////////////" << endl;
        cout << "选择操作代码(1-5)" << endl;
        int choo;
        cin >> choo;
        while(1)
        {
            if(choo == 1)
                ex1();
            else if(choo == 2)
                ex2();
            else if(choo == 3)
                ex3();
            else if(choo == 4)
                ex4();
            else if(choo == 5)
                ex5();
            break;
            cout << endl << endl;
        }
        cout << "是否继续?(Y.继续\tN.结束)";
        char YesorNO;
        cin >> YesorNO;
        if(YesorNO == 'N' || YesorNO == 'n')
            break;
        else continue;
    }
}
int main()
{
    ep = xp = 0;
    while(1)
    {
        system("clear");
        cout << "1.从某顶点开始对图做深度优先遍历" << endl;
        cout << "2.从某顶点开始对图做广度优先遍历" << endl;
        cout << "3.判断并输出图的一个拓扑序列" << endl;
        cout << "4.输出图的关键活动" << endl;
        cout << "5.随机生成图的邻接表" << endl;
        cout << "6.输入图的邻接表" << endl;
        cout << "7.课程表的排课" << endl;
        cout << "其他.结束" << endl;
        cout << "/////////////////////////////////" << endl;
        //随机生成图的邻接表
        wshow();
        cout << "/////////////////////////////////" << endl;
        cout << "选择操作代码(1-7)" << endl;
        int choose;
        cin >> choose;
        while(1)
        {
            if(choose == 1)
                e1();
            else if(choose == 2)
                e2();
            else if(choose == 3)
                e3();
            else if(choose == 4)
                e4();
            else if(choose == 5)
                e5();
            else if(choose == 6)
                e6();
            else if(choose == 7)
                e7();
            break;
            cout << endl << endl;
        }
        cout << "是否继续?(Y.继续\tN.结束)";
        char YesNO;
        cin >> YesNO;
        if(YesNO == 'N' || YesNO == 'n')
            break;
        else continue;
    }
}


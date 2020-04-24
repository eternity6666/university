#include <queue>
#include <iostream>
using namespace std;

struct st
{
    int x = 0;
    string s;
};
int n;
string s;
void bfs()
{
    queue<st> q;
    st st1;
    st1.s = "";
    st1.x = 0;
    q.push(st1);
    while (!q.empty())
    {
        st1 = q.front();
        q.pop();
        if (st1.x == n)
            cout << "(" << st1.s << ")";
        else
        {
            st st2;
            st2.x = st1.x + 1;
            st2.s = st1.s + s[st1.x];
            q.push(st2);
            st2.s = st1.s;
            q.push(st2);
        }
    }
    cout << endl;
}

int main()
{
    cin >> n;
    cin >> s;
    bfs();
    return 0;
}
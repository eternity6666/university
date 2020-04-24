#include <iostream>
#include <vector>
using namespace std;
struct str
{
    string a, b, c;
};

vector<str> ve;
int main()
{
    int ma = 0;
    while (true)
    {
        string x;
        str st;
        cin >> x;
        if (x == "O")
            break;
        cin >> st.c >> x >> st.a >> x >> st.b >> x;
        int len = st.a.length() + st.b.length() + st.c.length();
        if (ma < len)
            ma = len;
        ve.push_back(st);
    }
    cout << 1 << endl;
    ma += 4;
    vector<str>::iterator vit;
    for (vit = ve.begin(); vit != ve.end(); vit++)
    {
        if(vit->c.length()==1)
            cout << " ";
        cout << vit->c;
        int len = ma - vit->a.length() - vit->b.length();
        cout << ": OPEN=" << vit->a;
        for(int i = 0; i < len; ++i)
            cout << " ";
        cout << "CLOSED=" << vit->b << endl;
    }
    return 0;
}
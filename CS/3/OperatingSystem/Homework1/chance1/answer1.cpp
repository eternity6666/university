#include <iostream>
#include <cstdlib>
#include <vector>
#include "main.h"
using namespace std;

class PigInProblemA : public Same
{
public:
    PigInProblemA(int id, Destination dest):Same(id, dest){}
};

vector<PigInProblemA> ve;

void crossRavine(int id, Destination dest)
{
    ve[id - 1].crossRavine();
}

void doneWithCrossing(int id, Destination dest)
{
    ve[id - 1].doneWithCrossing();
}

void pig(int id, Destination dest)
{
    crossRavine(id, dest);
    doneWithCrossing(id, dest);
}

int main()
{
    int num = int(rand() * 100) % 5 + 1;
    for (int i = 0; i < num; ++i)
        ve.push_back(PigInProblemA(i + 1, EAST));
    for (int i = 0; i < num; ++i)
        pig(i + 1, (ve[i].getDest() == WEST ? EAST : WEST));
    return 0;
}

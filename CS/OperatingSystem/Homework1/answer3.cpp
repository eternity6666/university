semaphore maxE = M, maxW = N;
semaphore max_total = K;

void WaitUntilSafeToCross(Destination dest)
{
    p(max_oneway[dest]);
    P(max_total);
}

void DoneWithCrossing(Destination dest)
{
    V(max_total);
    V(max_oneway[dest])
}
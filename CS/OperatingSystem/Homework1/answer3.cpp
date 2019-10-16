semaphore maxE = M, maxW = N;
semaphore maxTotal = K;

void WaitUntilSafeToCross(Destination dest)
{
    if(dest==EAST)
    {
        wait(maxE);
        wait(maxTotal);
    }
    else
    {
        wait(maxW);
        wait(maxTotal); 
    }
}

void DoneWithCrossing(Destination dest)
{
    if(dest==EAST)
    {
        signal(maxE);
        signal(maxTotal);
    }
    else
    {
        signal(maxW);
        signal(maxTotal);
    }
}
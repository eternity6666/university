int pigE = 0, pigW = 0;           //分别表示EAST方向、WEST方向pig的数量
semaphore mutexE = 1, mutexW = 1; //每个方向的互斥
semaphore max_on_rope = 5;        //确保rope上最多5只pig
semaphore rope = 1;               //确保rope上pig的朝向

void WaitUntilSafeToCross(Destination dest)
{
    if (dest == EAST)
    {
        wait(mutexE);
        pigE++;
        if (pigE == 1)
            wait(rope); //第一头排队的pig, 正等着rope
        signal(mutexE);
        wait(max_on_rope);
    }
    else
    {
        wait(mutexW);
        pigW++;
        if (pigW == 1)
            wait(rope); //第一头排队的pig, 正等着rope
        signal(mutexW);
        wait(max_on_rope);
    }
}

void DoneWithCrossing(Destination dest)
{
    if (dest == EAST)
    {
        wait(mutexE);
        signal(max_on_rope);
        pigE--;
        if (pigE == 0)
            signal(rope); //最后一头pig, 释放rope
        signal(mutexE);
    }
    else
    {
        wait(mutexW);
        signal(max_on_rope);
        pigW--;
        if (pigW == 0)
            signal(rope); // 最后一头pig, 释放rope
        signal(mutexW);
    }
}

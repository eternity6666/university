# HomeWork 1

## Personal Message

姓名|学号|班级
---|---|---
阳作华|6109117050|计算机科学与技术(软件技术)174班

## The Answer of Problem(a)

```C++
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
```

## The Answer of Problem(b)

```C++
int pigE = 0, pigW = 0;           //分别表示EAST方向、WEST方向pig的数量
semaphore mutexE = 1, mutexW = 1; //每个方向的互斥
semaphore max_on_rope = 5;        //确保rope上最多5只pig
semaphore rope = 1;               //确保rope上pig的朝向
semaphore order = 1;              //用于避免出现starvation现象

void WaitUntilSafeToCross(Destination dest)
{
    wait(order);
    if (dest == EAST)
    {
        wait(mutexE);
        pigE++;
        if (pigE == 1)
            wait(rope); //第一头排队的pig, 正等着rope
        signal(mutexE);
        signal(order);
        wait(max_on_rope);
    }
    else
    {
        wait(mutexE);
        pigE++;
        if (pigE == 1)
            wait(rope); //第一头排队的pig, 正等着rope
        signal(mutexE);
        signal(order);
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
```

## The Answer of Problem(c)

```C++
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
```

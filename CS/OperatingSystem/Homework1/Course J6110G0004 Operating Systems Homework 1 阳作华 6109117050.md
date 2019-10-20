# HomeWork 1

## Personal Message

| 姓名   | 学号       | 班级                            |
| :------: | :----------: | :-------------------------------: |
| 阳作华 | 6109117050 | 计算机科学与技术(软件技术)174班 |

## The Answer of Problem(a)

```C++
int pigE = 0, pigW = 0;           // 分别表示EAST方向、WEST方向pig的数量
semaphore mutexE = 1, mutexW = 1; // 每个方向的互斥
semaphore maxOnRope = 5;          // 确保rope上最多5头pig
semaphore rope = 1;               // 确保rope上pig的朝向

void WaitUntilSafeToCross(Destination dest)
{
    if (dest == EAST)
    {
        wait(mutexE);
        pigE++;
        if (pigE == 1)
            wait(rope); // 第一头排队的pig, 正等着使用rope
        signal(mutexE);
        wait(maxOnRope);
    }
    else
    {
        wait(mutexW);
        pigW++;
        if (pigW == 1)
            wait(rope); // 第一头排队的pig, 正等着使用rope
        signal(mutexW);
        wait(maxOnRope);
    }
}

void DoneWithCrossing(Destination dest)
{
    if (dest == EAST)
    {
        wait(mutexE);
        signal(maxOnRope);
        pigE--;
        if (pigE == 0)
            signal(rope); // 最后一头pig, 释放rope
        signal(mutexE);
    }
    else
    {
        wait(mutexW);
        signal(maxOnRope);
        pigW--;
        if (pigW == 0)
            signal(rope); // 最后一头pig, 释放rope
        signal(mutexW);
    }
}
```

## The Answer of Problem(b)

```C++
int pigE = 0, pigW = 0;           // 分别表示EAST方向、WEST方向pig的数量
semaphore mutexE = 1, mutexW = 1; // 每个方向的互斥
semaphore maxOnRope = 5;          // 确保rope上最多5头pig
semaphore rope = 1;               // 确保rope上pig的朝向
semaphore order = 1;              // 用于避免出现starvation现象

void WaitUntilSafeToCross(Destination dest)
{
    wait(order);
    if (dest == EAST)
    {
        wait(mutexE);
        pigE++;
        if (pigE == 1)
            wait(rope); // 第一头排队的pig, 正等着使用rope
        signal(mutexE);
        signal(order);
        wait(maxOnRope);
    }
    else
    {
        wait(mutexE);
        pigE++;
        if (pigE == 1)
            wait(rope); // 第一头排队的pig, 正等着使用rope
        signal(mutexE);
        signal(order);
        wait(maxOnRope);
    }
}

void DoneWithCrossing(Destination dest)
{
    if (dest == EAST)
    {
        wait(mutexE);
        signal(maxOnRope);
        pigE--;
        if (pigE == 0)
            signal(rope); // 最后一头pig, 释放rope
        signal(mutexE);
    }
    else
    {
        wait(mutexW);
        signal(maxOnRope);
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
```

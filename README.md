# Philosophers
 In this project, you will learn the basics of threading a process. You will learn how to make threads. You will discover the mutex.

## Threads:

[Multithreading in C](https://softpixel.com/~cwright/programming/threads/threads.c.php)

A thread is a lightweight process that can be managed independently by a scheduler. It improves the application performance using parallelism. A thread shares information like data segment, code segment, files etc. with its peer threads while it contains its own registers, stack, counter etc.

Thread is the segment of a process means a process can have multiple threads and these multiple threads are contained within a process. A thread have 3 states: running, ready, and blocked.

Thread takes less time to terminate as compared to process and like process threads do not isolate.

[https://www.youtube.com/watch?v=uA8X5zNOGw8&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM](https://www.youtube.com/watch?v=uA8X5zNOGw8&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM)

## Mutex :

[Mutex lock for Linux Thread Synchronization - GeeksforGeeks](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/)

[Mutual Exclusion in Synchronization - GeeksforGeeks](https://www.geeksforgeeks.org/mutual-exclusion-in-synchronization/)

## Semaphores:

[Semaphores in C](https://greenteapress.com/thinkos/html/thinkos013.html)

[Semaphores in Process Synchronization - GeeksforGeeks](https://www.geeksforgeeks.org/semaphores-in-process-synchronization/)

[What is a semaphore? How do they work? (Example in C)](https://www.youtube.com/watch?v=ukM_zzrIeXs)

## Sem VS Mutex:

[Mutex vs Semaphore - GeeksforGeeks](https://www.geeksforgeeks.org/mutex-vs-semaphore/)
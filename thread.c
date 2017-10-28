//$ cat main.c

// linux系统支持POSIX多线程接口，称为pthread。编写linux下的多线程程序，
// 需要包含头文件pthread.h，链接时需要使用库libpthread.a。 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int * thread(void *arg)
{
        printf("thread id is %d.\n",pthread_self());
        return NULL;
}

int main()
{
pthread_t id;
printf("Main thread id is %d \n",pthread_self());
if(!pthread_create(&id,NULL,(void *)thread,NULL))
{
printf("succeed!\n");
return 0;
}
else
{printf("Fail to Create Thread");
return -1;
}
}

// $ ./main
// Main thread id is 1
// succeed!
// thread id is 2.
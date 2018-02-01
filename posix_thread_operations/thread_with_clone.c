#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define _SCHED_H 1
#define __USE_GNU 1
#include <bits/sched.h>

#define STACK_SIZE 4096

int func(void *arg) {
    printf("Inside func.\n");
    printf("Clone thread  pid: %u\n", getpid());
    printf("Clone parent  pid: %u\n", getppid());
    sleep(1);
    printf("Terminating func...\n");

    return 0;
}

int main() {
    printf("This process pid: %u\n", getpid());
    char status_file[] = "/proc/self/status";
    void *child_stack = malloc(STACK_SIZE);
    int thread_pid;
    char statm_file[]="/proc/self/statm";

    printf("Creating new thread...\n");
    thread_pid = clone(&func, child_stack+STACK_SIZE, CLONE_SIGHAND|CLONE_FS|CLONE_VM|CLONE_FILES|CLONE_THREAD, NULL);
    printf("Done! Thread pid: %d with stack size 0%x(%d KB)\n", thread_pid,STACK_SIZE,(STACK_SIZE/1024));

    FILE *fp = fopen(status_file, "rb");

    printf("Looking into %s...\n", status_file);

    while(1) {
        char ch = fgetc(fp);
        if(feof(fp)) break;
        printf("%c", ch);
    }

    fclose(fp);

    fp = fopen(statm_file, "rb");

    printf("Looking into %s...\n", statm_file);

    while(1) {
        char ch = fgetc(fp);
        if(feof(fp)) break;
        printf("%c", ch);
    }

    fclose(fp);

    getchar();

    return 0;
}

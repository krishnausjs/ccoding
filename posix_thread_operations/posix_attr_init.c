#define _GNU_SOURCE     /* To get pthread_getattr_np() declaration */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <syscall.h>
#include <sys/prctl.h>

#define THREAD_1 "THREAD1"
#define THREAD_1_LEN (sizeof(THREAD_1)+1)
#define THREAD_2 "THREAD2"
#define THREAD_2_LEN (sizeof(THREAD_2)+1)

#define handle_error_en(en, msg) \
       do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

static void
display_pthread_attr(pthread_attr_t *attr, char *prefix)
{
   int s, i;
   size_t v;
   void *stkaddr;
   struct sched_param sp;

   s = pthread_attr_getdetachstate(attr, &i);
   if (s != 0)
       handle_error_en(s, "pthread_attr_getdetachstate");
   printf("%sDetach state        = %s\n", prefix,
	   (i == PTHREAD_CREATE_DETACHED) ? "PTHREAD_CREATE_DETACHED" :
	   (i == PTHREAD_CREATE_JOINABLE) ? "PTHREAD_CREATE_JOINABLE" :
	   "???");

   s = pthread_attr_getscope(attr, &i);
   if (s != 0)
       handle_error_en(s, "pthread_attr_getscope");
   printf("%sScope               = %s\n", prefix,
	   (i == PTHREAD_SCOPE_SYSTEM)  ? "PTHREAD_SCOPE_SYSTEM" :
	   (i == PTHREAD_SCOPE_PROCESS) ? "PTHREAD_SCOPE_PROCESS" :
	   "???");

   s = pthread_attr_getinheritsched(attr, &i);
   if (s != 0)
       handle_error_en(s, "pthread_attr_getinheritsched");
   printf("%sInherit scheduler   = %s\n", prefix,
	   (i == PTHREAD_INHERIT_SCHED)  ? "PTHREAD_INHERIT_SCHED" :
	   (i == PTHREAD_EXPLICIT_SCHED) ? "PTHREAD_EXPLICIT_SCHED" :
	   "???");

   s = pthread_attr_getschedpolicy(attr, &i);
   if (s != 0)
       handle_error_en(s, "pthread_attr_getschedpolicy");
   printf("%sScheduling policy   = %s\n", prefix,
	   (i == SCHED_OTHER) ? "SCHED_OTHER" :
	   (i == SCHED_FIFO)  ? "SCHED_FIFO" :
	   (i == SCHED_RR)    ? "SCHED_RR" :
	   "???");

   s = pthread_attr_getschedparam(attr, &sp);
   if (s != 0)
       handle_error_en(s, "pthread_attr_getschedparam");
   printf("%sScheduling priority = %d\n", prefix, sp.sched_priority);

   s = pthread_attr_getguardsize(attr, &v);
   if (s != 0)
       handle_error_en(s, "pthread_attr_getguardsize");
   printf("%sGuard size          = %d bytes\n", prefix, v);

   s = pthread_attr_getstack(attr, &stkaddr, &v);
   if (s != 0)
       handle_error_en(s, "pthread_attr_getstack");
   printf("%sStack address       = %p\n", prefix, stkaddr);
   printf("%sStack size          = 0x%x bytes\n", prefix, v);
}

static void *
sec_thread_start(void *arg)
{
   int s;
   pthread_attr_t gattr;

   char thread_2[THREAD_2_LEN] = THREAD_2;
   prctl(PR_SET_NAME, (unsigned long) thread_2,0,0,0);

   printf("\n Entered thread 2 \n");
   /* pthread_getattr_np() is a non-standard GNU extension that
      retrieves the attributes of the thread specified in its
      first argument */

   s = pthread_getattr_np(pthread_self(), &gattr);
   if (s != 0)
       handle_error_en(s, "pthread_getattr_np");

   printf("Thread attributes:\n");
   display_pthread_attr(&gattr, "\t");
}

static void *
thread_start(void *arg)
{
   int s;
   pthread_attr_t gattr;

   pthread_t sec_thr;
   pthread_attr_t sec_attr;
   pthread_attr_t *sec_attrp;      /* NULL or &attr */
   struct sched_param param;
   int var_size;
   void *stkaddr;
   printf("\n Entered thread 1 \n");
   char thread_1[THREAD_1_LEN] = THREAD_1;
   prctl(PR_SET_NAME, (unsigned long) thread_1,0,0,0);
   /* pthread_getattr_np() is a non-standard GNU extension that
      retrieves the attributes of the thread specified in its
      first argument */

   s = pthread_getattr_np(pthread_self(), &gattr);
   if (s != 0)
       handle_error_en(s, "pthread_getattr_np");

   printf("Thread attributes:\n");
   display_pthread_attr(&gattr, "\t");

    //sec_attrp=&sec_attr;

    /* Init thread attributes */
    if(0 != pthread_attr_init(&sec_attr))
    {	
	printf("\n %s:%d : Failed in pthread_attr_init\n",__FUNCTION__,__LINE__);
        goto e_exit;
    }

    /* Set scheduling policy */
    if (0 != (s = pthread_attr_setschedpolicy(&sec_attr, SCHED_RR)))
    {
        printf("\n %s:%d : Failed in pthread_attr_setschedpolicy\n",__FUNCTION__,__LINE__);
	goto e_exit;
    }

    /* Set scheduling priority */
    param.sched_priority = 96; //SYSTEMUTIL_THR_P_compute_thread_priority(thread->prio);

    if (0 != (s = pthread_attr_setschedparam(&sec_attr, &param)))
    {
	printf("\n %s:%d : Failed in pthread_attr_setschedparam\n",__FUNCTION__,__LINE__);
	goto e_exit;
    }

   printf("\n Creating Second thread  \n");
   s = pthread_create(&sec_thr, &sec_attr, &sec_thread_start, NULL);
   if (s != 0)
       handle_error_en(s, "Second pthread_create");

   printf("\n Sleeping after creating thread 2 ....\n");
#if 1
   sleep(100);
   if (sec_attrp != NULL) {
       s = pthread_attr_destroy(sec_attrp);
       if (s != 0)
	   handle_error_en(s, "Second pthread_attr_destroy");
   }
#endif
e_exit:
   exit(EXIT_SUCCESS);         /* Terminate all threads */
}

int
main(int argc, char *argv[])
{
   pthread_t thr;
   pthread_attr_t attr;
   pthread_attr_t *attrp;      /* NULL or &attr */
   int s;

   attrp = NULL;

   /* If a command-line argument was supplied, use it to set the
      stack-size attribute and set a few other thread attributes,
      and set attrp pointing to thread attributes object */

   if (argc > 1) {
       int stack_size;
       void *sp;

       attrp = &attr;

       s = pthread_attr_init(&attr);
       if (s != 0)
	   handle_error_en(s, "pthread_attr_init");

       s = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
       if (s != 0)
	   handle_error_en(s, "pthread_attr_setdetachstate");

       s = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
       if (s != 0)
	   handle_error_en(s, "pthread_attr_setinheritsched");

       stack_size = strtoul(argv[1], NULL, 0);

       s = posix_memalign(&sp, sysconf(_SC_PAGESIZE), stack_size);
       if (s != 0)
	   handle_error_en(s, "posix_memalign");

       printf("posix_memalign() allocated at %p\n", sp);

       s = pthread_attr_setstack(&attr, sp, stack_size);
       if (s != 0)
	   handle_error_en(s, "pthread_attr_setstack");
   }

   s = pthread_create(&thr, attrp, &thread_start, NULL);
   if (s != 0)
       handle_error_en(s, "pthread_create");

   printf("\n Sleeping after creating thread 1 ....\n");
#if 1
   sleep(150);
   if (attrp != NULL) {
       s = pthread_attr_destroy(attrp);
       if (s != 0)
	   handle_error_en(s, "pthread_attr_destroy");
   }
#endif
   pause();    /* Terminates when other thread calls exit() */
}

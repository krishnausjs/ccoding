#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define OVERWRITE_SIZE 0

#define MY_PRINTF(debug_level, ...)\
	({\
		if(debug_level) \
			printf(__VA_ARGS__); \
	})

#define RBUF_SIZE 256

typedef struct  {
	unsigned int *buf;
	int head;
	int tail;
	int size;
}circular_buf_t;

int circular_buf_reset(circular_buf_t *cbuf);
bool circular_buf_empty(circular_buf_t *cbuf);
int circular_buf_get(circular_buf_t *cbuf, unsigned int *data);
int circular_buf_put(circular_buf_t *cbuf, unsigned int data);
bool circular_buf_full(circular_buf_t *cbuf);

int circular_buf_reset(circular_buf_t *cbuf)
{
	int ret=-1;
	if(cbuf) 
	{
		cbuf->head=0;
		cbuf->tail=0;
		ret=0;
	}
	return ret;
}

bool circular_buf_empty(circular_buf_t *cbuf) 
{
	return (cbuf->head == cbuf->tail);
}

bool circular_buf_full(circular_buf_t *cbuf) 
{
	return (((cbuf->head+1)%cbuf->size) == cbuf->tail);
}

int circular_buf_put(circular_buf_t *cbuf, unsigned int data)
{
	int ret=-1;
	MY_PRINTF(0, "Entered %s:%d\n", __FUNCTION__,__LINE__);
	if(cbuf != NULL)
	{
		cbuf->buf[cbuf->head]=data;
		MY_PRINTF(1,"Inserted %d at index [%d]\n",data,cbuf->head);
		cbuf->head = (cbuf->head+1) % cbuf->size;
		MY_PRINTF(1,"Value of head is %d and tail is %d\n",cbuf->head,cbuf->tail);	  	   ret = 0;
	}
	MY_PRINTF(0, "Exiting %s:%d\n", __FUNCTION__,__LINE__);
	return ret;
}

int circular_buf_get(circular_buf_t *cbuf, unsigned int *data)
{
	int ret=-1;
	if(cbuf) 
	{
		*data=cbuf->buf[cbuf->tail];
		MY_PRINTF(1,"Fetching %d at index [%d]\n",*data,cbuf->tail);
		cbuf->tail = ((cbuf->tail+1) % cbuf->size);
		ret=0;
	}
	return ret;
}

int main() 
{
	int i=0;
	unsigned data;
	circular_buf_t cbuf;
	cbuf.size = 10;
	cbuf.buf = (unsigned int*)malloc(cbuf.size);
	memset(cbuf.buf,0x00,cbuf.size);
	circular_buf_reset(&cbuf);

	for(i=0; i < (cbuf.size + OVERWRITE_SIZE); i++)
	{
		circular_buf_put(&cbuf,i);
	}
	printf("\n");
	MY_PRINTF(1,"Value of head is %d and tail is %d\n",cbuf.head,cbuf.tail);	

	for(i=0; i<cbuf.size; i++)
	{
		circular_buf_get(&cbuf, &data);
	}
	printf("\n");
	MY_PRINTF(1,"Value of head is %d and tail is %d\n",cbuf.head,cbuf.tail);	
	return 0;
}



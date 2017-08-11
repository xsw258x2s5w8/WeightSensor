/*
 * Queue.c
 *
 *  Created on: Sep 2, 2016
 *      Author: software school
 */

#include "queue.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

/*构造一个空队列*/
Queue *InitQueue()
{
	Queue *pqueue = (Queue *)malloc(sizeof(Queue));
	if(pqueue!=NULL)
	{
		pqueue->front = NULL;
		pqueue->rear = NULL;
		pqueue->size = 0;
	}
	return pqueue;
}
/*销毁一个队列*/
void DestroyQueue(Queue *pqueue)
{
		if(IsEmptyQueue(pqueue)!=1)
				ClearQueue(pqueue);
		free(pqueue);
}
/*清空一个队列*/
void ClearQueue(Queue *pqueue)
{
	while(IsEmptyQueue(pqueue)!=1)
	{
		DeQueue(pqueue);
	}
}
/*判断队列是否为空*/
int IsEmptyQueue(Queue *pqueue)
{
//printf("%d %d %d\n",pqueue->front,pqueue->rear,pqueue->size);
		if(pqueue->front==NULL&&pqueue->rear==NULL&&pqueue->size==0)
				return 1;
		else
				return 0;
}

/*返回队列大小*/
int GetSizeQueue(Queue *pqueue)
{
		return pqueue->size;
}

/*返回队头元素*/
QNode GetFrontQueue(Queue *pqueue,Itemt *pitem)
{
		if(IsEmptyQueue(pqueue)!=1&&pitem!=NULL)
		{
				*pitem = pqueue->front->data;
		}
		return pqueue->front;
}
/*返回队尾元素*/
QNode GetRearQueue(Queue *pqueue,Itemt *pitem)
{
		if(IsEmptyQueue(pqueue)!=1&&pitem!=NULL)
		{
				*pitem = pqueue->rear->data;
		}
		return pqueue->rear;
}
/*QNode EnQueue(Queue *pqueue,Itemt item)
{
		QNode pnode = (QNode)malloc(sizeof(QNode));
		int length = item->head[8];
		int i = 0;

		if(pnode != NULL)
		{
				pnode->data=(struct senddstr *)malloc(sizeof(struct senddstr));     //新开辟一块地址，存储入队数据

				pnode->data->head[0] = item->head[0];
				pnode->data->head[1] = item->head[1];
				pnode->data->head[2] = item->head[2];
				pnode->data->head[3] = item->head[3];
				pnode->data->head[4] = item->head[4];
				pnode->data->head[5] = item->head[5];
				pnode->data->head[6] = item->head[6];
				pnode->data->head[7] = item->head[7];
				pnode->data->head[8] = item->head[8];

				while(length-12-i > 0)
				{
						pnode->data->data[i]=item->data[i];
						i++;
				}

				pnode->data->tail[0]=item->tail[0];
				pnode->data->tail[1]=item->tail[1];
				pnode->data->tail[2]=item->tail[2];
				pnode->data->tail[3]=item->tail[3];
				pnode->data->tail[4]=item->tail[4];
				pnode->next = NULL;

				if(IsEmptyQueue(pqueue))
				{
						pqueue->front = pnode;
				}
				else
				{
						pqueue->rear->next = pnode;
				}
				pqueue->rear = pnode;
				pqueue->size++;
		}
		return pnode;
}*/
/*将新元素入队      将array字符串封装成ConveyData 进入队列*/
QNode EnQueuebyArray(Queue *pqueue,unsigned char  *array)
{
	QNode pnode = (QNode)malloc(sizeof(QNode));
	int HEAD_LEN = 7;
	int j = 0;
	int i = 0;
	unsigned char ch;
	if(pnode != NULL)
	{
		pnode->data=(struct Convey_Data *)malloc(sizeof(struct Convey_Data));     //新开辟一块地址，存储入队数据

			pnode->data->head = array[0];
			pnode->data->id = array[1];
			pnode->data->from = array[2];
			pnode->data->to = array[3];
			memcpy(&(pnode->data->len),array+4,2);
			pnode->data->type = array[6];
			while(pnode->data->len > i)
			{
				pnode->data->data[i] = array[ HEAD_LEN + i ];
				i++;
			}
			/* CRC */
			memcpy(&(pnode->data->CRC),array+HEAD_LEN+i,4);
			i = i + 4;
			pnode->data->tail = array[HEAD_LEN + i];
			pnode->next = NULL;
			if(IsEmptyQueue(pqueue))
			{
				pqueue->front = pnode;
			}
			else
			{
				pqueue->rear->next = pnode;
			}
			pqueue->rear = pnode;
			pqueue->size++;
			//printf("Queue OK!\n");
		}
		return pnode;
}


/*队头元素出队*/
QNode DeQueue(Queue *pqueue)
{
	QNode pnode = pqueue->front;
	if(IsEmptyQueue(pqueue)!=1&&pnode!=NULL)
	{
		pqueue->size--;
		pqueue->front = pnode->next;
		//free(pnode->data);
		//free(pnode);
		if(pqueue->size==0)
			pqueue->rear = NULL;
	}
	return pnode;
}
/*
 * 查找value  并删除查找到的节点
 * pqueue	存的返回消息队列
 * pitem commandid根据commandid查找对应的消息
 * length就是value的所占的字节长度
 */
/*unsigned int FindQueueValue(Queue *pqueue,Itemt pitem,int length)
{
	Qnode  * 	node,*tempNode;
	node 		= pqueue->front;
	unsigned int 	i = 2,value = -1;
	int 		queueCommandId,commandId,rearCommandId ;

	if(pqueue != NULL)
	{// queue head
		queueCommandId = node->data->head[1]*256 + node->data->head[2];
	}

	if(pitem != NULL)
	{
		//source item
		commandId = pitem->head[1] * 256 + pitem->head[2];
		//printf("qCommandId = %d commandId = %d \n",queueCommandId,commandId);
		//printf( "Recive command ID \n" );          //modify by xhw

		if(queueCommandId == commandId)
		{
			if(length == 4)
			{
				value= node->data->data[2]*256*256*256 + node->data->data[3]*256*256 +node->data->data[4]*256 +node->data->data[5];
			}
			else if(length==2)
			{
				value =  node->data->data[2]*256 + node->data->data[3];
			}
			else if(length == 1)
			{
				value =  node->data->data[2];
			}
			pqueue->size--;
			pqueue->front = node->next;
			free(node->data);
			free(node);
			if(pqueue->size == 0)
				pqueue->rear = NULL;
			return value;
		}

		while(node->next)       //删除节点后的队列数据处理
		{
			queueCommandId = node->next->data->head[1]*256 + node->next->data->head[2];
			if(queueCommandId == commandId)
			{
				if(length == 4)
				{
					value =  node->next->data->data[2]*256*256*256 + node->next->data->data[3]*256*256 +node->next->data->data[4]*256 +node->next->data->data[5];
				}
				else if(length==2)
				{
					value =  node->next->data->data[2]*256 + node->next->data->data[3];
				}
				else if(length == 1)
				{
					value =  node->next->data->data[2];
				}
				rearCommandId = node->next->data->head[1]*256 + node->next->data->head[2];
				if( commandId == rearCommandId && i == pqueue->size)
				{
					pqueue->rear = node;
				}
				tempNode = node->next;
				node->next = node->next->next;
				free(tempNode->data);
				free(tempNode);
				pqueue->size--;
				return value;
			}
			node = node->next;
			i++;
		}
	}
	//如果队列的长度大于10 则删除第一个头
	if(pqueue->size>10)
	{
		DeQueue(pqueue);
	}
	return value;
}*/

//查找队列节点
/*QNode FindQueueNode(Queue *pqueue,Itemt pitem)
{
	Qnode  * node,*tempNode;
	node = pqueue->front;
	int i = 2, queueCommandId,commandId,rearCommandId ;
    if(pqueue != NULL)
    {
    	queueCommandId = node->data->head[1]*256 + node->data->head[2];
    	printf("head[1] =  %x head[2] = %x",node->data->head[1], node->data->head[2]);
    }
	if(pitem != NULL)
	{
		commandId = pitem->head[1] * 256 + pitem->head[2];
		printf("qCommandId = %d commandId = %d \n",queueCommandId,commandId);
		if(queueCommandId == commandId)
		{
			pqueue->size--;
			pqueue->front = node->next;
			if(pqueue->size == 0)
				pqueue->rear = NULL;
			return node;
		}
		while(node->next)
		{
			queueCommandId = node->next->data->head[1]*256 + node->next->data->head[2];
			if(queueCommandId == commandId)
			{
				rearCommandId = node->next->data->head[1]*256 + node->next->data->head[2];
				if( commandId == rearCommandId && i == pqueue->size)
				{
					pqueue->rear = node;
				}
				tempNode = node->next;
				node->next = node->next->next;
				pqueue->size--;
				return tempNode;
			}
			node = node->next;
			i++;
		}
	}
	return 0;
}

//根据commandid删除队列节点
int DeleteQueueNode(Queue *pqueue,Itemt pitem)     //	(List *pList,Item pitem)
{
	Qnode  * node,*tempNode;
	node = pqueue->front;
	int i = 2;
    int queueCommandId,commandId,rearCommandId ;
    if(pqueue != NULL)
    {
    	queueCommandId = node->data->head[1]*256 + node->data->head[2];
    }
	if(pitem != NULL)
	{
		commandId = pitem->head[1] * 256 + pitem->head[2];
		printf("qCommandId = %d commandId = %d \n",queueCommandId,commandId);
		if(queueCommandId == commandId)
		{
			pqueue->size--;
			pqueue->front = node->next;
			free(node->data);
			free(node);
			if(pqueue->size == 0)
				pqueue->rear = NULL;
			return 1;
		}
		while(node->next)
		{
			queueCommandId = node->next->data->head[1]*256 + node->next->data->head[2];

			if(queueCommandId == commandId)
			{
				rearCommandId = node->next->data->head[1]*256 + node->next->data->head[2];
				if( commandId == rearCommandId && i == pqueue->size)
				{
					pqueue->rear = node;
				}
				tempNode = node->next;
				node->next = node->next->next;
				free(tempNode->data);
				free(tempNode);
				pqueue->size--;
				return 1;
			}
			node = node->next;
			i++;
		}
	}
	return 0;
}*/

/*遍历队列并对各数据项调用visit函数*/
/*void QueueTraverse(Queue *pqueue)
{
		QNode pnode = pqueue->front;
		int i = pqueue->size;
		printf("i = %d",i);
		while(i--)
		{
//				printf(" %d %d %d %d",pnode->data->data[0],pnode->data->data[1],pnode->data->data[2],pnode->data->data[3]);
				pnode = pnode->next;
		}
}*/

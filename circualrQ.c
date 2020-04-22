

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

typedef char element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


QueueType *createQueue();
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);
int freeQueue(QueueType *cQ);

element getElement();

int freeQueue(QueueType *cQ){
	if(cQ == NULL){
       return 1;
}
	free(cQ);
	return 1;
}

int main(void)
{
	printf("   2017038042      yu seong hyun  ");
	QueueType *cQ = createQueue();
	element data;

	char command;

	do{
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Dubug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			data = getElement();
			enQueue(cQ, data);
			break;
		case 'd': case 'D':
			deQueue(cQ,&data);
			break;
		case 'p': case 'P':
			printQ(cQ);
			break;
		case 'b': case 'B':
			debugQ(cQ);
			break;
		case 'q': case 'Q':
            free(cQ);
			freeQueue(cQ);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');


	return 1;
}


QueueType *createQueue() // cQ를 동적으로 할당하는 함수
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));
	cQ->front = 0; //front 초기값 0
	cQ->rear = 0;  // rear 초기값 0
	return cQ;
}

element getElement() //원소 입력함수
{
	element item;
	printf("Input element = ");
	scanf(" %c", &item);
	return item;
}


/* complete the function */
int isEmpty(QueueType *cQ){//cQ의 맨처음이 cQ의 맨뒤와같아지게되면 queue는빈상태.
	if(cQ->front==cQ->rear){
		printf("큐에 원소가 없습니다.\n");
		return 1;

	}
	else{
    return 0;
	}
}

/* complete the function */
int isFull(QueueType *cQ)//cQ의마지막+1을 매크로로 나눈나머지가 cQ의맨앞과같아지면queue는 꽉찬상태.
{
   if(((cQ->rear+1)%MAX_QUEUE_SIZE)==cQ->front){
	   printf("큐에 원소가 꽉찼습니다.\n");
	   return 1;
   }
   else{
   return 0;
   }
}


/* complete the function */
void enQueue(QueueType *cQ, element item)
{   if(isFull(cQ)){//cQ가 꽉찼으면 바로 리턴.
	return;
}

else{

    	cQ->rear = (cQ->rear+1)%MAX_QUEUE_SIZE;//cQ의 맨뒤에 cQ의마지막+1을 매크로로 나눈나머지를대입
      cQ->queue[cQ->rear] = item; // cQ의 queue[cQ.rear]변수에 item을 대입.
    }
}
/* complete the function */
void deQueue(QueueType *cQ, element *item){
	if(isEmpty(cQ)){//cQ가비어있다면 바로 리턴.
		return;
	}
	else{
		cQ->front = (cQ->front+1)%MAX_QUEUE_SIZE; //cQ의앞에 cQ의맨앞+1을 매크로로나눈나머지를 대입.
}}


void printQ(QueueType *cQ)
{
	int i, first, last;

	first = (cQ->front + 1)%MAX_QUEUE_SIZE;
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE;

	printf("Circular Queue : [");

	i = first;
	while(i != last){
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE;

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if(i == cQ->front) {
			printf("  [%d] = front\n", i);
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);
}
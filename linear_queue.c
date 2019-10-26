#include<stdio.h>
#include<stdlib.h>

#define Q_SIZE 10

struct queue
{
	int items[Q_SIZE], rear, front;
	struct queue *ptr;
};

void enqueue(struct queue *, int);
int dequeue(struct queue *);
void display(struct queue *);

int main()
{
	int choice = 0, temp = 0;
	struct queue q;
	q.front = 0;
	q.rear = -1;

	do
	{
		printf("\nOperations:\n1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n\nEnter your choice: ");
        scanf("%d", &choice);

		switch(choice)
		{
			case 1: //enqueue
			printf("Enter elmnt to be enqueued: ");
			scanf("%d", &temp);
			printf("\n");
			enqueue(&q, temp);
			continue;

			case 2: //dequeue
			temp = dequeue(&q);
			printf("The dequeued elmnt is %d", temp);
			continue;

			case 3: //display
			display(&q);
			continue;

			case 4: //exit
			printf("Bye!\n\n");
			exit(1);

			default:
			printf("Wrong choice.\n\n");
			continue;
		}
	}while(choice != 4);

	return(0);
} //main fn ends

void enqueue(struct queue *ptr, int temp)
{
	if(ptr->rear == Q_SIZE-1)
	{
		printf("Queue full.\n\n");
	}
	else
	{
		ptr->items[++(ptr->rear)] = temp;
	}
}

int dequeue(struct queue *ptr)
{
	if(ptr->rear < ptr->front)
	{
		printf("Queue empty.\n\n");
		exit(1);
		//return (-1);
	}
	else
	{
		return(ptr->items[(ptr->front)++]);
	}
}

void display(struct queue *ptr)
{
	int i = 0;

	if(ptr->rear < ptr->front)
	{
		printf("Queue empty.\n\n");
	}
	else
	{
		for(i = ptr->front; i <= ptr->rear; i++)
		{
			printf("%d ", ptr->items[i]);
		}
		printf("\n\n");
	}
}

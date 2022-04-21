typedef struct node* Nodeptr;

typedef struct
{
	Nodeptr front;
	int count;
	Nodeptr rear;
}QUEUE_HEAD;

typedef QUEUE_HEAD* Queue;

typedef struct node
{
	int data;
	Nodeptr next;
}QUEUE_NODE;

Queue create();
void enqueue(Queue q, int item);
void display(Queue q);
int head(Queue q);
int tail(Queue q);
int dequeue(Queue q);
int isEmpty(Queue q);
int isFull(Queue q);
int clear(Queue q);

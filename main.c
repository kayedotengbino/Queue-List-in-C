#include <stdio.h>
#include "queuelist.h"

int main() 
{
	int repeat, choice, element, multElement;
	Queue q = create();
	
	do
	{
		printf("QUEUE MENU\n[1] Enqueue\n[2] Dequeue\n[3] Empty\n[4] Full\n[5] Clear\n[6] Head\n[7] Tail\n[8] Display\nChoice: ");
		scanf("%d", &choice);
		
		system("cls");
		
		switch(choice)
		{
			case 1:
				system("cls");
	
				do
				{	
                    if(!isFull(q))
                    {
                        printf("Enqueue (element): ");
	                	scanf("%d", &element);
						enqueue(q, element);
						
						printf("Add again? (1 = YES | 0 = NO): ");
						scanf("%d", &multElement);
                    }
                    else
                   	{
                   		printf("Sorry, stack is already full");
                    	multElement = 0;
				   	}
				}
				while(multElement == 1);
				break;
			case 2:
				system("cls");
				
				do
				{
                    if(isEmpty(q))
                        printf("Queue is empty.\n");
                    else
					{
                        dequeue(q);

                        printf("Element dequeued.\nDequeue again? (1 = YES | 0 = NO): ");
					    scanf("%d", &multElement);
                    }
				}
				while(multElement == 1);	
				
				break;
			case 3:
                system("cls");
				printf("Is queue empty? %s", isEmpty(q) ? "Yes" : "No");
				break;
			case 4:
                system("cls");
				printf("Is queue full? %s", isFull(q) ? "Yes" : "No (there are 10 elements that can be accomodated)");
				break;
			case 5:
				clear(q);
				printf("Queue is cleared.");
				break;
			case 6:
                printf("Head: %d", head(q));
				break;
			case 7:
                printf("Tail: %d", tail(q));
				break;
			case 8:
                system("cls");
                display(q);
				break;        
			default:
				printf("Invalid choice.\n");
				break;
		}
		
		printf("\nDo you wish to go back to menu? (1 = YES | 0 = NO): ");
		scanf("%d", &repeat);
		
		system("cls");
	}
	while(repeat == 1);
	
	return 0;
}

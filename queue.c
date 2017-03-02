#include<stdio.h>
#define size 5

typedef struct{
	int element[size];
	int front;
	int rear;
}queue;

queue q; // Making a queue instance. //

queue init(){
	// Initialise front and rear both with -1 //
	q.front = -1;
	q.rear = -1;
	return q;
}

void insert( int item ){
	//Checking overflow condition first. //
	
	if( q.rear == size-1  ){
		printf("Cannot add more items, since queue is full.\n");
	}
	else{
		if( q.front == -1 && q.rear == -1 ){
			/* Since if front and rear both 
			are at -1 position we can't only 
			update rear, we have to update 
			both front and rear to 0. */
			q.front = 0;
			q.rear = 0;
			printf("Both front and rear updated to 0.\n");
		}
		else{
			/* else it doesn't matter where is our front variable.
			Just update the rear variable to accomodate new element. */
			q.rear += 1;
		}
		// Now assign the new element at the updated rear. //
		q.element[q.rear] = item;
	}
} // End of insert() function. //

void delete(){
	// First check for underflow condition. //
	
	if( q.front == -1 ){
		/* checking front == -1 is sufficient because,
		if front == -1, then rear must also be at -1. */
		printf("Cannot delete items, since queue is empty.\n");
	}
	else{
		// Since we are deleting an element, we must also print the popped out element. //
		int elem = q.element[q.front];
		
		if( q.front == q.rear ){
			/* This implies only a single element in the queue,
			and so we have to bring front and rear both back
			to -1. */
			
			q.front = -1;
			q.rear = -1;
		}
		else{
			/* Since there are more than one element in the queue,
			we just need to update front from front to front + 1,
			and rear will not touched at all. */
			
			q.front += 1;
		}
		
		printf("The item from front of the queue has been deleted. Item is %d.\n", elem);
	}
} // End of delete() function. //

void display(){
	/* The display function must print the elements of the queue from front end
	to rear end and nothing else. */
	
	int i = q.front;
	
	for( i; i<=q.rear; i+=1 ){
		printf("%d\n", q.element[i]);
	}
	
	printf("Done!!\n");
	
} // End of display() function. //

void main(){
	// The very first step is to initialise the queue, since only then front and rear will be -1. //
	init();
	
	// For menu driven program, initialising a character ch = 1 //
	
	int ch = 1;
	
	while( ch == 1 ){
		printf("1. Insert in queue.\n");
		printf("2. Delete from queue.\n");
		printf("3. Display queue.\n");
		printf("4. Exit\n");
		
		// To take users choice, initialising x. //
		
		int x;
		printf("Enter choice: ");
		scanf("%d", &x);
		
		if( x == 1 ){
			// Ask for element. //
			int element;
			printf("Enter the element: ");
			scanf("%d", &element);
			
			// Make a call to insert() function. //
			insert( element );
			printf("Element inserted.\n");
		}
		else if( x == 2 ){
			// Make call to delete() function to pop out the element from queue. //
			delete();
		}
		else if( x == 3 ){
			// Make a call to display() function to display the queue. //
			display();
		}
		else if( x == 4 ){
			// Make ch = 0, so that while loop terminates. //
			ch = 0;
		}
		else{
			// If user enters something else, print invalid. //
			printf("Invalid choice!!\n");
		}
	}
} // End of main() //


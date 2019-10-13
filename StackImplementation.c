 #include <stdio.h>
 #include<stdlib.h>
# define n 5
 int top=-1;
 int stack[n]; 
 
void push(int);
int pop();
void display();

int main() {
    while(1)
    {
        int choice,e;
        
        while(1)
        {
		    printf("\nEnter\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
		    scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                if(top == n-1)
                {
                    printf("Stack overflow.");
                    break;
                }
                printf("Enter element:");
                scanf("%d",&e);
                push(e);
                break;
                case 2:
                if(top == -1)
                {
                    printf("Stack underflow.");
                    break;
                }
                e = pop();
                printf("Popped: %d", e);
                break;
                case 3:
                if(top == -1)
                {
                    printf("Stack empty.");
                    break;
                }
                display();
                break;
                case 4:
                exit(0);
            }
        }
    }
	return 0;
}

void push(int e)
{
    stack[++top]=e;
}

int pop()
{
    return stack[top--];
}

void display()
{
    int i;
    for(i = top; i > -1; i--)
        printf("\n%d",stack[i]);
}
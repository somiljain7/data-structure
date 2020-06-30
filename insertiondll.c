#include<stdlib.h>
#include<Stdio.h>
typedef struct  node{
int data;
struct node*next,*prev;
}node;
void main()
{ node*head,*p,*q,*r;
 int i,n,ch,x,loc;
}
do{
    printf("\nEnter 1:FOR FRONT, 2: END, 3: MIDDLE, 4:PRINT FOR INSERTION\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1: //FRONT
        if(head==NULL)
        { head=(node*)malloc(sizeof(node));
        p=head;
        printf("Enter data for the node");
        scanf("%d",&p->data);
        p->next=p->prev=NULL;
        }
        else
        {  p=head;
        p=(node*)malloc(sizeof(node));
        printf("Enter data for the node\n");
        scanf("%d",&p->data);
        p->next=head;
        head->prev=p;
        p->prev=NULL;
        head=p;  }
        break;
    case 2: // END
         p=(node*)malloc(sizeof(node));
         printf("Enter data for the node\n");
         scanf("%d",&p->data);
         q=head;
         while(q->next!=NULL)
         {   q=q->next;
         }
         q->next=p;
         p->prev=q;
         p->next=NULL;
         break;
    case 3: //MIDDLE
         p=(node*)malloc(sizeof(node));
         printf("Enter data for the node\n");
         scanf("%d",&p->data);
         q=head;
         printf("enter location of insertion\n");
         scanf("%d",&loc);
         for(i=0;i<loc-2;i++)
         {  q=q->next;
         }
         r=q->next;
         q->next=p;
         p->prev=q;
         r->prev=p;
         p->next=r;
         break;
    case 4: //PRINTING
        p=head;
        while(p!=NULL)
        { printf("%d\t",p->data);
          p=p->next;
        }
        break;
    default: printf("Error\n");
    }
    printf("Press 1 to repeat\n");
    scanf("%d",&x);
}while(x==1);
}


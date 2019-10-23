#include<iostream>
using namespace std;
struct node
{
    int data;
   struct node *next;
}*f,*s,*t;
void create1(int a[],int n)
{
    struct node *last,*t;
    f=new node;
    f->data=a[0];
    f->next=NULL;
    last=f;
    for(int i=1;i<10;i++)
    {
        t=new node;
        t->data=a[i];
        t->next=0;
        last->next=t;
        last=t;
    }
}
void create2(int a[],int n)
{
    struct node *last,*t;
    s=new node;
    s->data=a[0];
    s->next=NULL;
    last=s;
    for(int i=1;i<10;i++)
    {
        t=new node;
        t->data=a[i];
        t->next=0;
        last->next=t;
        last=t;
    }
}
void display(struct node *p)
{
    while(p!=NULL)
    {
       cout<<p->data<<" ";
       p=p->next;
    }
}
void rdisplay(struct node *p)
{
    if(p!=0)
    {
        //rdisplay(p->next); //fpr reverse print
        cout<<p->data<<" ";
        rdisplay(p->next);
    }
}
int sum(struct node *p)
{
    int sum=0;
    while(p!=0)
    {
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}
int rsum(struct node *p)
{
    int sum=0;
    if(p==0)
        return 0;
        return rsum(p->next)+p->data;
}
int count(struct node *p)
{
    int c=0;
    while(p!=0)
    {
        c++;
        p=p->next;
    }
    return c;
}
int rcount(struct node *p)
{
    int c=0;
    if(p==0)
        return 0;
    return rcount(p->next)+1;
}
int rcountx(struct node *p)
{
    int c=0;
    if(p==0)
        return 0;
    int x=rcountx(p->next);
    return x+1;
}
int max(struct node *p)
{
    int m=INT_MIN;
    while(p!=0)
    {
        if(p->data>m)
            m=p->data;
            p=p->next;
    }
    return m;
}
int rmax(struct node *p)
{
    int x=0;
    int m=INT_MIN;
    if(p==0)
       return m;
    x=rmax(p->next);
    if(x>p->data)
       return x;
    else
       return p->data;
}
struct node* lsearch(struct node *p,int key)
{
    struct node *q;
    while(p!=0){
    if(key==p->data)
    {
        q->next=p->next;
        p->next=f;
        f=p;
        return p;
    }
    q=p;
    p=p->next;
    }
}
struct node * rsearch(struct node *p,int key)
{
    if(p==0)
        return 0;
    if(p->data==key)
        return p;
    rsearch(p->next,key);
}
void insert(struct node *p,int index,int x)
{
    struct node *t;
    t=new node;
    t->data=x;
    if(index<0&&index>count(f))
        return ;
    if(index==0)
    {
        t->next=f;
        f=t;
    }
    else
        for(int i=1;i<index-1;i++)
        {
            p=p->next;}
            t->next=p->next;
                p->next=t;
}
void sortedinsert(struct node *p,int index,int x)
{
    struct node *q=0,*t;
    t=new node;
    t->data=x;
    if(f==0)
        f=t;
    else{
    while(p!=0&&p->data<x)
    {
        q=p;
        p=p->next;
    }
    if(p==f)
    {
        t->next=f;
        f=t;
    }
    else
    {
        t->next=q->next;
        q->next=t;
    }
    }
}
 int delet(struct node *p,int index)
{
    struct node *q=0;
    int x=-1,i;
    if(index<0||index>count(f))
        return x;
    else
    {
        if(index==1)
        {
            q=f;
            x=f->data;
            f=f->next;
            delete(q);
        }
        else{
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete(p);}
        return x;
    }
}
int issorted(struct node *p)
{
    int x=INT_MIN;
    while(p!=0)
    {
        if(p->data>=x)
        {
            x=p->data;
            p=p->next;
        }
        else
            return 0;
    }
    return 1;
}
void removedup(struct node *p)
{
    struct node *q;
    q=p->next;
    while(q!=0)
    {
        if(q->data!=p->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete(q);
            q=p->next;
        }
    }
}
/*void reverse(struct node *p)
{
    int *a,i=0;
    struct node *q=p;
    a=new int[count(p)];

    while(q!=0)
    {
        a[i]=q->data;
        q=q->data;
        i++;
    }
    q=p;
    i--;
    while(q!=0)
    {
        q->data=a[i];
        q=q->next;
        i--;
    }
}*/
void reverse2(struct node *p)
{
    struct node *q=0,*r=0;
    while(p!=0)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    f=q;
}
void rec_reverse(struct node *q,struct node *p)
{
    if(p!=0){
        rec_reverse(p,p->next);
        p->next=q;
    }
    else
    f=q;
}
void concat(struct node *p,struct node *q)
{
    while(p->next!=0)
    {
        p=p->next;
    }
    p->next=q;
}
void merge(struct node *p,struct node *q)
{
    struct node *last;
    if(p->data<q->data)
    {
        t=last=p;
        p=p->next;
        last->next=0;
    }
    else
    {
        t=last=q;
        q=q->next;
        last->next=0;
    }
    while(p &&q)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=0;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=0;
        }
    }
    if(p)
        last->next=p;
    if(q)
        last->next=q;
}
int main()
{
    int a[10];
    cout<<"enter elements of 1st array";
   for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
     int b[10];
    cout<<"enter elements of 2nd array";
   for(int i=0;i<10;i++)
    {
        cin>>b[i];
    }

   create1(a,10);
   display(f);
   /*cout<<endl;
   rdisplay(f);
    cout<<endl;
   cout<<count(f);
    cout<<endl;
   cout<<rcount(f);
    cout<<endl;
   cout<<rcountx(f);
    cout<<endl;
   cout<<sum(f);
    cout<<endl;
   cout<<rsum(f);
    cout<<endl;
   cout<<max(f);
    cout<<endl;
   cout<<rmax(f);
    cout<<endl;
  // cout<<lsearch(f,55);
   // cout<<endl;
   cout<<rsearch(f,55);
   insert(f,4,34);
   cout<<endl;
   display(f);
   sortedinsert(f,3,23);
   cout<<endl;
   display(f);
   cout<<endl;
   cout<<"deleted item="<<delet(f,3);
   cout<<endl;
   display(f);
   cout<<endl;
   cout<<issorted(f);
   removedup(f);
   cout<<endl;
   display(f);
  /* reverse(f);
   cout<<endl;
   display(f);*/
 /*  reverse2(f);
   cout<<endl;
   display(f);
   rec_reverse(0,f);
   cout<<endl;
   display(f);*/
   create2(b,10);
   cout<<endl;
   display(s);
  // concat(f,s);
   cout<<endl;
  // display(f);
  merge(f,s);
  display(t);


}

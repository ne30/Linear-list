#include<stdio.h>
#include<conio.h>
void create(int,int);
int delete(int);
void find(int,int);
void search(int);
void traverse();
void isempty();
void isfull();
void insert(int,int);
int destroy();


int *ll,max_size,len=0;

int main()
{
  int ch,*ll = NULL,i,x,ele,pos,n;
  char c='y';
  printf("Enter the max size of the linear list."); /*The max limit.*/
  scanf("%d",&max_size);
  while (c=='y'|| c=='Y')
{
  printf("Enter:\n1 to create a list\n2 to delete an element from the linear list\n3 to find the presence of the element at entered position\n4 to search for an element in linear list\n5 to print the output the list\n6 to merge another list in the first list\n7 to check whether the list is empty or not\n8 to check whether the list is full or not\n9 to insert an element at a given position\n0 to destroy the list.\n");
  scanf("%d",&i );
  switch(i)
  {
    case 1:
    printf("Enter the length of the list\n");
    scanf("%d",&len);
    create(len,0);
    break;

    case 2:
    printf("Enter the position of the element to deleted\n"); /*It will delete element from that position.*/
    scanf("%d",&pos);
    len = delete(pos);
    break;

    case 3:
    printf("Enter the element and position to know whether the element is present there or not\n");
    scanf("%d %d",&ele,&pos);
    find(ele,pos);
    break;

    case 4:
    printf("Enter the element to search in list\n");
    scanf("%d",&ele);
    search(ele);
    break;

    case 5:
    printf("The list:\n");
    traverse();
    break;

    case 6:
    printf("Enter the size of new list to be merged with first list\n");
    scanf("%d",&n);
    create(n,len);
    break;

    case 7:
    isempty();
    break;

    case 8:
    isfull();
    break;

    case 9:
    printf("Enter the element and position at which you want to place that element in the list\n");
    scanf("%d %d",&ele,&pos);
    insert(ele,pos);
    break;

    case 0:
    len = destroy();
    break;
  }
  printf("Do you want to operation again (y/n)?\n");
  scanf(" %c",&c);
  }
}

void create(int a,int b)
{
  ll = (int*)malloc(sizeof(int)*max_size);
  if((a+b) > max_size)
  printf("Wrong input as it crosses the max_size limit\n");
  else
  {
  printf("Enter the element.\n");
  for(int i=b;i<a;i++)
  scanf("%d",&ll[i]);
  printf("Element successfully entered\n");
  len = a+b;
  }
}

int delete(int a)
{
  int k = ll[a-1];
  if (a>len)
  {
    printf("Wrong input\ni.e. the enered position is greater than the length of list\n");
    return len;
  }
  else
  {
    for(int i=(a-1);i<len-1;i++)
    ll[i] = ll[i+1];
    printf("%d is deleted from %dth position\n",k,a);
    return (len-1);
  }
}

void find(int a,int b)
{
  if (b>len)
  printf("Wrong input\ni.e. the enered position is greater than the length of list\n");
  else
  {
    if (ll[b-1] == a)
    printf("The element is present in the list at the given position.\n");
    else
    printf("The element is not present in the list at the given position.\n");
  }
}

void search(int a)
{
  int r=0,i;
  for(i=0;i<len;i++)
  {
    if(ll[i]==a)
    {
      r=1;
      break;
    }
  }
  if(r)
  printf("%d is present in the list at %d position.\n",a,(i+1));
  else
  printf("The element is not present in  the list.\n");
}

void traverse()
{
  for(int i=0;i<len;i++)
  printf("\n %d \n",ll[i]);
}

void isempty()
{
  if (len == 0)
  printf("The list is empty\n");
  else
  printf("The list is not empty\n");
}

void isfull()
{
  if(len == max_size)
  printf("The list is full.\n");
  else
  printf("The list is not full.\n");
}

void insert(int x,int k)
{
   if(k<0 || k>len)
   printf("Wrong indexing.\n");
   else
   {
       if(len == max_size)
       printf("Linear list is full.\n");
       else
       {
           for(int i=len-1;i>=k;i--)
           ll[i+1] = ll[i];

           ll[k] = x;
           len++;
           printf("The element inserted successfully.\n");
       }
   }
}

int destroy()
{
  return 0;
}

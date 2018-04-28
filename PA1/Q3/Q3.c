#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node *next;
}NODE;

NODE* enqueue(NODE* head, int x)
{
  NODE* k;
  k = (NODE*) malloc(sizeof(NODE));
  k->value = x;
  k->next = head;
  head = k;
  printf("%d\n",k->value);
  return head;
}

NODE* dequeue(NODE* head)
{
  NODE* current;
  current = (NODE*) malloc(sizeof(NODE));
  current = head;
  if(head == NULL)
  {
    printf("Empty\n");
  }
  else
  {
    if(current->next == NULL)
    {
      printf("%d\n",current->value);
      current = NULL;
      return current;
    }
    else
    {
      while(current->next->next != NULL)
      {
        current = current->next;
      }
      printf("%d\n",current->next->value);
      current->next = NULL;
    }
  }
  return head;
}

void Is_Empty(NODE* head)
{
  if(head==NULL)
  {
    printf("True\n");
  }
  else
  {
    printf("False\n");
  }
}

int main(int argc, char const *argv[]) {

  int t;
  int i;

  scanf(" %d",&t);

  for(i=0;i<t;i++)
  {
    int n,q;
    scanf(" %d %d",&n,&q);
    NODE* head[n];
    for(int j=0;j<n;j++)
    {
      head[j] = (NODE*) malloc(sizeof(NODE));
      head[j] = NULL;
    }
    for(int k=0;k<q;k++)
    {
      int o,index;
      scanf(" %d",&o);
      if(o==1)
      {
        int a;
        scanf(" %d %d",&a,&index);
        index--;
        head[index] = enqueue(head[index],a);
      }
      else if(o==2)
      {
        scanf(" %d",&index);
        index--;
        head[index] = dequeue(head[index]);
      }
      else if(o==3)
      {
        scanf(" %d",&index);
        index--;
        Is_Empty(head[index]);
      }
    }
  }
  return 0;
}

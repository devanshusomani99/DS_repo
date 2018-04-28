#include <stdio.h>


typedef struct node{
  int value;
  struct node *next;
}NODE;

NODE* enqueue(NODE* head, int x)
{
  NODE* k;
  //k = (NODE*) malloc(sizeof(NODE));
  k->value = x;
  k->next = head;
  head = k;
  printf("%d\n",k->value);
  return head;
}

NODE* dequeue(NODE* head)
{
  NODE* current;
  //current = (NODE*) malloc(sizeof(NODE));
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
      head = NULL;
      return head;
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

  freopen("input.txt","r",stdin);

  int t,i;
  scanf("%d\n",&t);

  for(i=0;i<t;i++)
  {
    NODE* head;
    //head = (NODE*) malloc(sizeof(NODE));
    head = NULL;
    int q,j;
    scanf("%d\n",&q);
    for(j=0;j<q;j++)
    {
      int o;
      scanf("%d",&o);
      if(o==1)
      {
        int x;
        scanf(" %d\n",&x);
        head = enqueue(head,x);
      }
      else if(o==2)
      {
        scanf("\n");
        head = dequeue(head);
      }
      else if(o==3)
      {
        scanf("\n");
        Is_Empty(head);
      }
    }
  }

  return 0;
}

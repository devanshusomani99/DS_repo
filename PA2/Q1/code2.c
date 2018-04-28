#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int pop1;
char pop2;

typedef struct node{
  long long int value;
  struct node* next;
}int_ll;

typedef struct nodec{
  char value;
  struct nodec* next;
}char_ll;

int_ll* int_push(int_ll* head, int x)
{
  int_ll* k;
  k = (int_ll*) malloc(sizeof(int_ll));
  k->value = x;
  k->next = head;
  head = k;
  return head;
}

int_ll* int_pop(int_ll* head)
{
  pop1 = head->value;
  head = head->next;
  return head;
}

char_ll* char_push(char_ll* head, char x)
{
  char_ll* k;
  k = (char_ll*) malloc(sizeof(char_ll));
  k->value = x;
  k->next = head;
  head = k;
  return head;
}

char_ll* char_pop(char_ll* head)
{
  pop2 = head->value;
  head=head->next;
  return head;
}

int main(int argc, char const *argv[]) {

    freopen("input.txt","r",stdin);

    int t,i;
    scanf("%d\n", &t);
    for(i=0; i<t; i++) {

        int_ll* num;
        num = (int_ll*) malloc(sizeof(int_ll));
        num = NULL;

        char_ll* op;
        op = (char_ll*) malloc(sizeof(char_ll));
        op = NULL;

        long long int x,y;
        char poly[1000001];

        /*int cj, p=0;
        cj = getchar();
        while (cj != '\n') {
             printf("%c\n", cj);
  	         poly[p] = cj;
	         cj = getchar();
	         p++;
        }
        printf("%c", cj);
        poly[p] = '\0';*/
        scanf("%c",&poly[0]);
        //printf("%c\n", poly[0]);
        long long int jj;
        for(jj=1; jj<1000000;jj++){
            scanf("%c",&poly[jj]);
            //printf("%c       %lld\n",poly[jj],jj );
            if(poly[jj]=='\n') {
                poly[jj]=' ';
                poly[jj+1]='\0';
                break;
            }
        }

        //printf("%lld\n", jj);
        //scanf("%[^\n]s",poly);
        scanf("%lld %lld\n",&x ,&y);
        //printf("%lld %lld\n",x,y );
        /*int l = strlen(poly);
        printf("%lld\n", l);*/
        long long int j;
        long long int a,b;
        int flag1=0,flag2=0;
        /*poly[l]=' ';
        poly[l+1]='\0';*/
        for(j=0; j<jj; j++) {
            if(poly[j]==' ') {
                continue;
            }
            else if(poly[j]=='x') {
                if(poly[j+1]=='y') {
                    if(poly[j-1]>='0' && poly[j-1]<='9') {
                        num = int_pop(num);
                        num = int_push(num, pop1*x*y);
                        //printf("         %lld\n", pop1*x*y);
                    }
                    else if(j==0 || poly[j-1]==' ') {
                        num = int_push(num, x*y);
                        //printf("         %lld\n", x*y);
                    }
                    j++;
                }
                else if(j==jj-1 || poly[j+1]==' '){
                    if(poly[j-1]>='0' && poly[j-1]<='9') {
                        num = int_pop(num);
                        num = int_push(num, pop1*x);
                        //printf("         %lld\n", pop1*x);
                    }
                    else if(j==0 || poly[j-1]==' ') {
                        num = int_push(num, x);
                        //printf("         %lld\n", x);
                    }
                }
                if(flag1==1 || flag2==1) {
                    num = int_pop(num);
                    a = pop1;
                    num = int_pop(num);
                    b = pop1;
                    if(flag1==1) {
                        num = int_push(num,(int)(b/a));
                        flag1=0;
                    }
                    else if(flag2==1) {
                        num = int_push(num,b*a);
                        flag2=0;
                    }
                    op = char_pop(op);
                    continue;
                }
            }
            else if(poly[j]=='y') {
                if(poly[j+1]=='x') {
                    if(poly[j-1]>='0' && poly[j-1]<='9') {
                        num = int_pop(num);
                        num = int_push(num, pop1*x*y);
                        //printf("         %lld\n", pop1*x*y);
                    }
                    else if(j==0 || poly[j-1]==' ') {
                        num = int_push(num, x*y);
                        //printf("         %lld\n", x*y);
                    }
                    j++;
                }
                else if(j==jj-1 || poly[j+1]==' '){
                    if(poly[j-1]>='0' && poly[j-1]<='9') {
                        num = int_pop(num);
                        num = int_push(num, pop1*y);
                        //printf("         %lld\n", pop1*y);
                    }
                    else if(j==0 || poly[j-1]==' ') {
                        num = int_push(num, y);
                        //printf("         %lld\n", y);
                    }
                }
                if(flag1==1 || flag2==1) {
                    num = int_pop(num);
                    a = pop1;
                    num = int_pop(num);
                    b = pop1;
                    if(flag1==1) {
                        num = int_push(num,(int)(b/a));
                        flag1=0;
                    }
                    else if(flag2==1){
                        num = int_push(num,b*a);
                        flag2=0;
                    }
                    op = char_pop(op);
                    continue;
                }
            }
            else if(poly[j]>='0' && poly[j]<='9') {
                /*if(poly[j+1]=='x') {
                    num = int_push(num, (((int) (poly[j]-'0'))*x));
                    flagx=1;
                }
                else if(poly[j+1]=='y') {
                    num = int_push(num, (((int) (poly[j]-'0'))*y));
                    flagy=1;
                }*/
                long long int h = (int) (poly[j]-'0');

                while(poly[j+1]<='9' && poly[j+1]>='0') {
                    long long int hh = (int) (poly[j+1]-'0');
                    h = (h*10)+hh;
                    j++;
                }
                num = int_push(num, h);
                //printf("   %lld\n",h);
                if(j==(jj-1) || poly[j+1]==' ') {
                    if(flag1==1 || flag2==1) {
                        num = int_pop(num);
                        a = pop1;
                        num = int_pop(num);
                        b = pop1;
                        if(flag1==1) {
                            num = int_push(num,(int)(b/a));
                            flag1=0;
                        }
                        else if(flag2==1) {
                            num = int_push(num,b*a);
                            flag2=0;
                        }
                        op = char_pop(op);
                        continue;
                    }
                }
            }
            else if(poly[j]=='/') {
                flag1 = 1;
                op = char_push(op, poly[j]);
            }
            else if(poly[j]=='*') {
                flag2 = 1;
                op = char_push(op, poly[j]);
            }
            else if(poly[j]=='+') {
                op = char_push(op, poly[j]);
            }
            else if(poly[j]=='-') {
                op = char_push(op, poly[j]);
            }
        }

        while (op!=NULL) {
            op = char_pop(op);
            if (pop2=='-') {
                num = int_pop(num);
                a = pop1;
                num = int_pop(num);
                b = pop1;
                num = int_push(num, b-a);
            }
            else if (pop2=='+') {
                num = int_pop(num);
                a = pop1;
                num = int_pop(num);
                b = pop1;
                num = int_push(num, b+a);
            }
        }

        num = int_pop(num);

        printf("%lld\n",pop1);

    }
    free(num);
    free(op);
    return 0;
}

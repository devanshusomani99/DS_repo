#include<stdio.h>
#include<stdlib.h>

int print_result(int res[], int N)
{
  int flag=0,i;

  for(i=0;i<N;i++)
  {
    if(res[N-i-1]==0 && flag==0)
    {
      continue;
    }
    printf("%d",res[N-1-i]);
    flag=1;
  }

  printf("\n");
}

int max(int a, int b)
{
  if(a>b)
  {
    return a;
  }
  else
  {
    return b;
  }
}

int* add_strings(int a[], int b[], int n1, int n2)
{
  int i;
  int carry=0;
  int N=max(n1+1,n2+1);
  int* sum;
  sum = malloc(N*sizeof(int));
  for(i=0;i<N;i++)
  {
    if(i<=(n1-1) && i<=(n2-1))
    {
      sum[i]=((a[i]+b[i]+carry)%10);
      carry = ((a[i]+b[i]+carry)/10);
    }
    else if(i>(n1-1) && i<=(n2-1))
    {
      sum[i]=((b[i]+carry)%10);
      carry = ((b[i]+carry)/10);
    }
    else if(i<=(n1-1) && i>(n2-1))
    {
      sum[i]=((a[i]+carry)%10);
      carry = ((a[i]+carry)/10);
    }
    else if(i>(n1-1) && i>(n2-1))
    {
      sum[i]=carry;
      carry = 0;
    }
  }
  return sum;
}

int* subtract_strings(int a[], int b[], int n1, int n2)
{
  int i;
  int* diff;
  diff = malloc(n1*sizeof(int));
  for(i=0;i<n1;i++)
  {
    if(i<n2)
    {
      diff[i]=a[i]-b[i];
      if(diff[i]<0)
      {
        diff[i] = diff[i] + 10;
        a[i+1] = a[i+1] - 1;
      }
    }
    else
    {
      diff[i]=a[i];
    }
  }
  return diff;
}

int* multiply_strings(int a[], int b[], int n1, int n2)
{
  int i,j;
  int carry=0;
  int N=n1+n2;
  int* pro;
  pro = (int*) calloc(N,sizeof(int));
  if(n2>n1)
  {
    for(i=0;i<n1;i++)
    {
      int p[n2+1+i];
      int k=0;
      while (k<i)
      {
        p[k]=0;
        k++;
      }
      for(j=0;j<n2;j++)
      {
        p[j+i] = ((a[i]*b[j])+carry)%10;
        carry = ((a[i]*b[j])+carry)/10;
      }
      p[n2+i]=carry;
      carry=0;
      pro = add_strings(pro,p,n1+n2,n2+1+i);
    }
  }

  else
  {
    for(i=0;i<n2;i++)
    {
      int p[n1+1+i];
      int k=0;
      while (k<i)
      {
        p[k]=0;
        k++;
      }
      for(j=0;j<n1;j++)
      {
        p[j+i] = (b[i]*a[j]+carry)%10;
        carry = (b[i]*a[j]+carry)/10;
      }
      p[n1+i]=carry;
      carry=0;
      pro = add_strings(pro,p,n1+n2,n1+1+i);
    }
  }
  return pro;
}

int compare_strings(int a[], int b[], int n1, int n2)
{
    int i=0,j=0;
    while(i<n1)
    {
      if(a[i]>b[j]) return 1;
      if(a[i]<b[j]) return -1;
      i++;
      j++;
    }
    if(n1>n2)
    {
      return 1;
    }
    else if(n2>n1)
    {
      return -1;
    }
    else
    {
      return 0;
    }
}

int* reverse_string(int a[], int n)
{
  int* k;
  int i;
  k = (int*) malloc(n*sizeof(int));
  for(i=0;i<n;i++)
  {
    k[i] = a[n-1-i];
  }
  return k;
}

/*void divide_strings(int a[], int b[], int n1, int n2)
{
  int i,j;
  a = reverse_string(a,n1);
  b = reverse_string(b,n2);
  for(i=0;i<n1-n2+1;i++)
  {
    int p[n2+1];
    int flag;
    if(compare_strings(a,b,n2,n2)>=0)
    {
      flag=1;
      p[0]=0;
    }
    else
    {
      flag=0;
      p[n2]=a[n2];
    }
    for(j=0;j<n2;j++)
    {
      p[j+flag]=a[j];
    }
    for(j=9;j>=0;j--)
    {
      int k[1];
      k[0]=j;
      int* t = reverse_string(multiply_strings(reverse_string(b,n2),k,n2,1),n2+1);
      if(compare_strings(t,p,n2+1,n2+1)<=0)
      {
        printf("%d",j);
        int* s = subtract_strings(reverse_string(p,n2+1),t,n2+1,n2+1);
        int flag2=0,flag3=0;
        for(int l=0;l<(n2+1-flag);l++)
        {
          a[l] = s[l+flag];
          if(a[l]==0 && flag3==0)
          {
            flag2++;
          }
          else
          {
            flag3=1;
          }
        }
        a = a+flag2;
        n1 = n1-flag2;
        break;
      }
    }
    if(compare_strings(a,b,n1,n2)<0)
    {
      break;
    }
    else if(compare_strings(a,b,n1,n2)==0)
    {
      printf("1");
      break;
    }
  }
  printf("\n");
}*/

int* divide_strings(int a[], int b[], int n1, int n2)
{
  int i,j;
  int *quo;
  quo = calloc(n1-n2+1, sizeof(int));
  while (compare_strings(reverse_string(a,n1),reverse_string(b,n2),n1,n2)<0)
  {
    for(j=1;j<n1-n2,j++)
    {
      int k[j];
      k[j-1]=1;
      for(i=0;i<j-1;i++)
      {
        k[i] = 0;
      }
      if(compare_strings(reverse_string(multiply_strings(k,b,j,n2),n2+j),reverse_string(a,n1),n2+j,n1)>0)
      {
        int k1[j-1];
        k1[j-2]=1;
        for(i=0;i<j-2;j++)
        {
          k1[i] = 0;
        }
        quo = add_strings(quo,k1,n1-n2+1,j-1);
        a = subtract_strings(a,k1,n1,j-1);
        break;
      }
    }
  }
  return quo;
}

int main(int argc, char const *argv[]) {

  int t;
  int n1,n2;
  int o;
  int i,j;

  scanf(" %d", &t);

  for(i=0;i<t;i++)
  {
    scanf(" %d %d ",&n1,&n2);
    char a1[n1],b1[n2];
    int a[n1],b[n2];
    for (j=0;j<n1;j++)
    {
      scanf("%c",&a1[n1-j-1]);
      a1[n1-j-1] -= '0';
      a[n1-j-1] = (int) a1[n1-j-1];
    }
    scanf("\n");
    for (j=0;j<n2;j++)
    {
      scanf("%c",&b1[n2-j-1]);
      b1[n2-j-1] -= '0';
      b[n2-j-1] = (int) b1[n2-j-1];
    }
    scanf(" %d",&o);
    if(o==1)
    {
      print_result(add_strings(a,b,n1,n2),max(n1+1,n2+1));
    }
    if(o==2)
    {
      print_result(subtract_strings(a,b,n1,n2),n1);
    }
    if(o==3)
    {
      print_result(multiply_strings(a,b,n1,n2),n1+n2);
    }
    if(o==4)
    {
      if(compare_strings(a,b,n1,n2)<1)
      {
        printf("%d\n",compare_strings(a,b,n1,n2)+1);
      }
      else
      {
        print_result(reverse_string(divide_strings(a,b,n1,n2),n1-n2+1),n1-n2+1);
      }
    }
  }

  return 0;
}

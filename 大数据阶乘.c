#include "stdio.h"

#include "stdlib.h"



int main(int argc, char* argv[])

{

         long i,n,p;

         printf("n=?");

         scanf("%d",&n);

         p=1;

         for (i=1;i<=n;i++)

                  p*=i;

         printf("%d!=%d/n",n,p);

         return 0;

}


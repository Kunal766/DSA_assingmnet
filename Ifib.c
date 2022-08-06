#include<stdio.h>
#include<time.h>
long long int Ifib(int n)
{     
    long long int first=0, second=1,temp;
    if(n==1)
    return 0;
    if(n==2)
    return 1;
    
  
    for(int i=2;i<n;i++)
    {
        temp =first;
        first=second;
        second =temp+second;
    }
  return second;
}

int main(){

clock_t start_t, end_t;
double total_t;
start_t = clock();
   long long int n;
   printf("Enter a number :");
   scanf("%lld",&n);
   printf("%lldth Fibonaci number is :%lld\n",n,Ifib(n));
   end_t =clock();
   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
// CLOCKS_PER_SEC is a constant defined in time.h and its value is 10^6.
printf("Total time taken: %f\n", total_t );
return 0;


    
}

#include <stdio.h>
#include <time.h>
void multiply(long long int F[2][2], long long int M[2][2])
{
   long long int a = F[0][0] * M[0][0] + F[0][1] * M[1][0];
   long long int b = F[0][0] * M[0][1] + F[0][1] * M[1][1];
   long long int c = F[1][0] * M[0][0] + F[1][1] * M[1][0];
   long long int d = F[1][0] * M[0][1] + F[1][1] * M[1][1];
   // F[0][0] = a%2021;
   // F[0][1] = b%2021;
   // F[1][0] = c%2021;
   // F[1][1] = d%2021;
   F[0][0] = a;
   F[0][1] = b;
   F[1][0] = c;
   F[1][1] = d;
}
void power(long long int F[2][2], long long int n)
{
   if (n == 0 || n == 1)
      return;
   long long int M[2][2] = {{1, 1}, {1, 0}};
   power(F, n / 2);
   multiply(F, F);
   if (n % 2 != 0)
      multiply(F, M);
}
long long int Cleverfib(long long int n)
{
   long long int F[2][2] = {{1, 1}, {1, 0}};
   if (n == 0)
      return 0;
   power(F, n - 1);
   return F[0][0];
}

int main()
{

   clock_t start_t, end_t;
   double total_t;
   long long int n;
   printf("Enter a number :");
   scanf("%lld", &n);
   start_t = clock();
   printf("%lldth Fibonaci number is :%lld\n", n, Cleverfib(n));
   end_t = clock();
   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   // CLOCKS_PER_SEC is a constant defined in time.h and its value is 10^6.
   printf("Total time taken: %f\n", total_t);
   return 0;
}

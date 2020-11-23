#include<bits/stdc++.h>
using namespace std;


int bit_add(int a , int b);
int main()
{
  int a, b, b_1, x, y, flag = 0;
  printf("A : ");
  scanf("%d", &a);
  printf("B : ");
  scanf("%d", &b);

  //Check for Negative numbers
  if(a < 0){
    flag = 1;
    a = ~a; // 1's complement
    a = bit_add(1 , a); // adding 1 gives 2's complement
    }
  if(b < 0 && flag == 1)
    {
        flag = 0;
        b = ~b;
        b = bit_add(1 , b);
    }
  else if(b < 0 && flag == 0)
    {
        flag = 1;
        b = ~b;
        b = bit_add(1 , b);
    }

  //Multiply operation
  b_1 = b;
  a = a - 1;
  y = b;
  for(int i = a ; i > 0 ; i-- )
  {
    y = bit_add(b_1 , y);
    b_1 = b;
  }

  //Multiply by -1 if needed
  if (flag == 1)
    {
        y = ~y;
        y = bit_add(1 , y);
    }
  printf("A * B = %d", y);
}

//Function for bitwise addition
int bit_add(int a , int b)
{
    while (a != 0)
        {
            int carry = b & a;

            b = b ^ a;

            a = carry << 1;
        }
        return b;
}



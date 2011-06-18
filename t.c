#include <stdio.h>
int main()
{
float f = 3.25;
int i  = (int) (f*(1<<16));
printf ("----> %08x\n",i);
return 0;
}

/* 4 iteraçõs 
 * Soma de 4 a 7 (4 + 5 + 6 +7)
 */ 
#include <stdio.h>

 int main () {

 int res = 0, i;

 for(i = 4; i <= 7; i++) {
	 res += i;
 }
 printf ("%d\n", res );

 return 0;
 }

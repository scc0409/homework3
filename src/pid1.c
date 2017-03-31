#include "io.h"

void waitpid1(void) //fork를 활용하여 여러 개의 스레드를 돌리는 것을 테스트한다.
{
  if(fork()==0)
  {
  printf("a\n");
  }
else
  {
  printf("b\n");
  waitpid(-1,NULL,0);
  }
  printf("c\n");
}

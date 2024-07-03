#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit lim;
    if(!getrlimit(RLIMIT_STACK,&lim))
      printf("stack size: soft %lu hard  %lu \n", lim.rlim_cur,lim.rlim_max);
    if(!getrlimit(RLIMIT_DATA,&lim))
      printf("process limit: soft %lu hard  %lu \n", lim.rlim_cur,lim.rlim_max);
    if(!getrlimit(RLIMIT_NOFILE,&lim))
      printf("max file descriptors:  soft %lu hard  %lu \n", lim.rlim_cur,lim.rlim_max);
    return 0;
}

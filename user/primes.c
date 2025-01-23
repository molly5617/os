#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void sieve(int pleft[2])
{
    int p;
    read(pleft[0], &p, sizeof(p));
    if (p == -1)
    {
        exit(0);
    }
    printf("prime %d\n", p);
    int pright[2];
    pipe(pright);

    if (fork() == 0)
    {
        close(pright[1]);
        close(pleft[0]);
        sieve(pright);
    }
    else
    {
        close(pright[0]);
    }
}
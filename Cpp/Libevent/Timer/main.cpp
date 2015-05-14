#include <event.h>
#include <stdio.h>
#include <time.h>

static void
hello(int fd, short event, void *arg)
{
    printf("hello man\n");
}

int main(int argc, const char *argv[]) 
{
    struct event_base *base;
    struct timeval tm;
    struct event evt;

    evutil_timerclear(&tm);
    tm.tv_sec = 10;

    base = event_base_new();
    evtimer_set(&evt, hello, NULL);
    event_base_set(base, &evt);
    evtimer_add(&evt, &tm);
    event_base_loop(base, 0);
    return 0;
}
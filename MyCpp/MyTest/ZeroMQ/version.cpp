//
// 返回当前ZMQ的版本号
//
#include "zhelpers.h"
 
int main (void)
{
    int major, minor, patch;
    zmq_version (&major, &minor, &patch);
    printf ("当前ZMQ版本号为 %d.%d.%d\n", major, minor, patch);
 
    return EXIT_SUCCESS;
}
//
// Hello World 服务端 C++语言版
// 绑定一个REP套接字至tcp://*:5555
// 从客户端接收Hello，并应答World
//
#include <zmq.hpp>
#include <string>
#include <iostream>
#include <unistd.h>
 
int main () {
    // 准备上下文和套接字
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://127.0.0.1:54321");
 
    while (true) {
        zmq::message_t request;
 
        // 等待客户端请求
        socket.recv (&request);
        std::cout << "收到 Hello" << std::endl;
 
        // 做一些“处理”
        sleep (1);
 
        // 应答World
        zmq::message_t reply (5);
        memcpy ((void *) reply.data (), "World", 5);
        socket.send (reply);
    }
    return 0;
}

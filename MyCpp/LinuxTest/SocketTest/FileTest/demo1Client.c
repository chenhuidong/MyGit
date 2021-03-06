#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

main()
{
	int sfd;
	int ffd;
	int size;
	int r;
	
	int  len;
	char buf[128];
	
	struct sockaddr_in dr;
	char filename[]="1.txt"; 
	
	//1.建立socket
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd==-1) printf("1:%m\n"),exit(-1);
	printf("socket成功!\n");
	//2.连接到服务器
	dr.sin_family=AF_INET;
	dr.sin_port=htons(54321);
	inet_aton("127.0.0.1",&dr.sin_addr);
	r=connect(sfd,(struct sockaddr*)&dr,sizeof(dr));
	if(r==-1) printf("2:%m\n"),close(sfd),exit(-1);	
	printf("connect成功!\n");
	//3.打开文件
	ffd=open(filename,O_RDONLY);
	if(ffd==-1) printf("3:%m\n"),close(sfd),exit(-1);
	printf("open文件成功!\n");
	//4.发送文件名
	len=strlen(filename);	
	r=send(sfd,&len,sizeof(len),0);//发送文件名长度
	r=send(sfd,filename,len,0);//发送文件名 
	if(r==-1)
	printf("4:%m\n"),close(ffd),close(sfd),exit(-1);
	printf("发送文件名成功!\n");
	//5.循环发送数据
	while(1)
	{
		size=read(ffd,buf,128);
		if(size==-1) break;
		if(size==0) break;
		if(size>0)
		{
			//发送数据长度
			r=send(sfd,&size,sizeof(size),0);
			if(r==-1) break;
			r=send(sfd,buf,size,0);//发送数据
			if(r==-1) break;
		}
	}
	//6.读取到文件尾，发送0数据包
	size=0;
	r=send(sfd,&size,sizeof(size),0);
	close(ffd);
	close(sfd);
	printf("OK!\n");
}

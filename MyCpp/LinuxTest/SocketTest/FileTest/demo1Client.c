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
	
	//1.����socket
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd==-1) printf("1:%m\n"),exit(-1);
	printf("socket�ɹ�!\n");
	//2.���ӵ�������
	dr.sin_family=AF_INET;
	dr.sin_port=htons(54321);
	inet_aton("127.0.0.1",&dr.sin_addr);
	r=connect(sfd,(struct sockaddr*)&dr,sizeof(dr));
	if(r==-1) printf("2:%m\n"),close(sfd),exit(-1);	
	printf("connect�ɹ�!\n");
	//3.���ļ�
	ffd=open(filename,O_RDONLY);
	if(ffd==-1) printf("3:%m\n"),close(sfd),exit(-1);
	printf("open�ļ��ɹ�!\n");
	//4.�����ļ���
	len=strlen(filename);	
	r=send(sfd,&len,sizeof(len),0);//�����ļ�������
	r=send(sfd,filename,len,0);//�����ļ��� 
	if(r==-1)
	printf("4:%m\n"),close(ffd),close(sfd),exit(-1);
	printf("�����ļ����ɹ�!\n");
	//5.ѭ����������
	while(1)
	{
		size=read(ffd,buf,128);
		if(size==-1) break;
		if(size==0) break;
		if(size>0)
		{
			//�������ݳ���
			r=send(sfd,&size,sizeof(size),0);
			if(r==-1) break;
			r=send(sfd,buf,size,0);//��������
			if(r==-1) break;
		}
	}
	//6.��ȡ���ļ�β������0���ݰ�
	size=0;
	r=send(sfd,&size,sizeof(size),0);
	close(ffd);
	close(sfd);
	printf("OK!\n");
}

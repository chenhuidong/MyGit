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
	int sfd,cfd,ffd;
	int r;
	int len;
	char buf[128];
	char filename[100];
	struct sockaddr_in dr;
	//1.����������socket
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd==-1) printf("1:%m\n"),exit(-1);
	printf("�����������ɹ�!\n");
	//2.��IP��ַ��˿�
	dr.sin_family=AF_INET;
	dr.sin_port=htons(54321);
	dr.sin_addr.s_addr=inet_addr("127.0.0.1");
	r=bind(sfd,(struct sockaddr*)&dr,sizeof(dr));
	if(r==-1) printf("2:%m\n"),close(sfd),exit(-1);
	printf("�󶨵�ַ�ɹ���\n");
	//3.����
	r=listen(sfd,10);
	if(r==-1) printf("3:%m\n"),close(sfd),exit(-1);
	printf("�����ɹ�!\n");
	//4.��������
	cfd=accept(sfd,0,0);
	if(cfd==-1) printf("4:%m\n"),close(sfd),exit(-1);
	printf("��ʼ�����ļ�!\n");
	//5.�����ļ���
	r=recv(cfd,&len,sizeof(len),MSG_WAITALL);
	printf("�ļ�������:%d\n",len);
	r=recv(cfd,filename,len,MSG_WAITALL);
	filename[len]=0;
	printf("���ݵ��ļ�����:%s\n",filename);
	//6.�����ļ�
	ffd=open(filename,O_RDWR|O_CREAT,0666);	
	//7.ѭ�������ļ�����
	while(1)
	{
		r=recv(cfd,&len,sizeof(len),MSG_WAITALL);
		if(len==0) break;
		r=recv(cfd,buf,len,MSG_WAITALL);
		
		write(ffd,buf,len);
		
	}
	close(ffd);
	close(cfd);
	close(sfd);
	printf("�����ļ����!\n");
}

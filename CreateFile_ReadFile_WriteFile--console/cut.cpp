#include<windows.h>
#include<iostream.h>
HANDLE handle;//��ȡ�ļ��ľ��
HANDLE w_handle;//д���ļ��ľ��

void main()
{
	int  limit;//�ָ��ļ��Ĵ�С(KB)
	int  count = 1;
	char filename[10];//Ҫ���ļ�������
	char ch[100];//��ʱ���ȡ���ֽ�
	char str[20];//Ҫд���ļ�������
	memset(str,0,10);
	memset(ch,0,100);
	memset(filename,0,10);
	cout<<"Input file name:";
	cin >> filename;
	cout<<"������Ҫ�ָ��ļ��Ĵ�С(KB):";
	cin>>limit;
	handle = CreateFile(filename,GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);//��Ҫ�����ļ�
	w_handle = CreateFile("1.txt",GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);//��Ҫд����ļ�
	DWORD dwReads,dwWrites;
	while(ReadFile(handle,ch,100,&dwReads,NULL))//ReadFile��ȡ�ɹ���dwReads(��ʵ�ʶ�ȡ���ֽ�)��0ʱ��˵���ļ���ȡ��ϣ�
	{
		if(0 == dwReads)
		{
			cout<<"�ļ��ָ����^_^��"<<endl;
			break;
		}
		if(GetFileSize(w_handle,NULL) > limit * 1024)
		{
			CloseHandle(w_handle);
			count += 1;//�ļ���(�ļ����)
			itoa(count,str,10);
			strcat(str,".txt");//�ļ���׺
			w_handle = CreateFile(str,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
		}
		WriteFile(w_handle,ch,dwReads,&dwWrites,NULL);//���ļ���д��ʵ��
	}

	CloseHandle(handle);
	CloseHandle(w_handle);
}
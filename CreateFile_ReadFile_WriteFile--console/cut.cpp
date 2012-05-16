#include<windows.h>
#include<iostream.h>
HANDLE handle;//读取文件的句柄
HANDLE w_handle;//写入文件的句柄

void main()
{
	int  limit;//分割文件的大小(KB)
	int  count = 1;
	char filename[10];//要打开文件的名字
	char ch[100];//临时存读取的字节
	char str[20];//要写入文件的名字
	memset(str,0,10);
	memset(ch,0,100);
	memset(filename,0,10);
	cout<<"Input file name:";
	cin >> filename;
	cout<<"输入你要分割文件的大小(KB):";
	cin>>limit;
	handle = CreateFile(filename,GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);//打开要读的文件
	w_handle = CreateFile("1.txt",GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);//打开要写入的文件
	DWORD dwReads,dwWrites;
	while(ReadFile(handle,ch,100,&dwReads,NULL))//ReadFile读取成功且dwReads(即实际读取的字节)是0时，说明文件读取完毕！
	{
		if(0 == dwReads)
		{
			cout<<"文件分割完毕^_^！"<<endl;
			break;
		}
		if(GetFileSize(w_handle,NULL) > limit * 1024)
		{
			CloseHandle(w_handle);
			count += 1;//文件名(文件编号)
			itoa(count,str,10);
			strcat(str,".txt");//文件后缀
			w_handle = CreateFile(str,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
		}
		WriteFile(w_handle,ch,dwReads,&dwWrites,NULL);//向文件中写入实际
	}

	CloseHandle(handle);
	CloseHandle(w_handle);
}
#include "sifilemgr.h"
#include <string.h>
#include <windows.h>



//�ļ�����
typedef struct SiFileLink
{
	struct SiFileInfo fileinfo;
	struct SiFileLink* next;
};


static struct SiFileLink* si_file_link = NULL;

//����һ��SiFileLink�ṹ
static struct SiFileLink* SiFile_Create(unsigned long hash,int u8flag,char* orgfile,char* gbkfile)
{
	struct SiFileLink* tmp = (struct SiFileLink*)malloc(sizeof(struct SiFileLink));
	memset(tmp,0,sizeof(struct SiFileLink));
	tmp->fileinfo.hash = hash;
	tmp->fileinfo.u8flag = u8flag;
	strcpy(tmp->fileinfo.orgfile,orgfile);
	strcpy(tmp->fileinfo.gbkfile,gbkfile);
	return tmp;
}

//useless
static void SiFile_Destory(struct SiFileLink* file)
{
	if(file != NULL)
	{		
		file->next = NULL;
		free(file);
	}
}

//��ӵ�����
void SiFile_Add(unsigned long hash,int u8flag,char* orgfile,char* gbkfile)
{
	struct SiFileLink* file = SiFile_Create(hash,u8flag,orgfile,gbkfile);
	
	struct SiFileLink* tmp = si_file_link;
	if(tmp == NULL)
	{
		si_file_link = file;
		return;
	}
	
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = file;
	
	return;
}

//�������в����ļ�
struct SiFileInfo* FindSiFileFromLink(unsigned long hash)
{
	struct SiFileLink* cur = si_file_link;
	
	while(cur)
	{
		if(cur->fileinfo.hash == hash)
			return &cur->fileinfo;
			
		cur = cur->next;
	}	
	
	return NULL;
}

//ɾ����ʱ�ļ�
void SiFile_Unlink(void)
{
	struct SiFileLink* cur = si_file_link;
	
	while(cur)
	{
		if(cur->fileinfo.u8flag != 0)
		{
			DeleteFile(cur->fileinfo.gbkfile);
		}
			
		cur = cur->next;
	}	
	
	return;	
}





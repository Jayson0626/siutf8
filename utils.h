#ifndef __UTILS__H__
#define __UTILS__H__

#include <windows.h>

//���������Ϣ
void WINAPI OutputDebugStringEx(LPCTSTR lpcFormatText, ...);

//�ַ���hash
unsigned long HashString(const char* str);

//��ȡ��ʱ�ļ���
//void GetTmpFilename(const char* orgfile,char* newfile);
void GetTmpFilename(unsigned long hash,char* newfile);

#endif

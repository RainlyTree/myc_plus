#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#if 0
int main()
{
	FILE * pFile;
	pFile = fopen("example.txt", "wb");
	fputs("This is an apple.", pFile);
	fseek(pFile, 9, SEEK_SET);
	fputs(" sam", pFile);
	fclose(pFile);
	system("pause");
	return 0;
}


void CopyMp4(char *destPath, const char *srcPath)
{
	char ch;
	FILE *pf = fopen(srcPath, "rb");
	FILE *pw = fopen(destPath, "wb");
	assert(pf != NULL && pw != NULL);
	
	while (fread(ch, sizeof(char), 1, pf) > 0)
	{
		fwrite(ch, sizeof(char), 1, pw);
	}
	fclose(pf);
	fclose(pw);
	pf = NULL;
	pw = NULL;
}

int main()
{
	char *destPath = "D:\\老李.mp4";
	char *srcPath = "E:\\亮剑.mp4";
	CopyMp4(destPath, srcPath);
}


int main()
{
	FILE *pf = fopen("text.txt", "w");
	fputs("hello 61", pf); //原来有内容直接覆盖
	fclose(pf);
	pf = NULL;
	return 0;
}
#endif // 0


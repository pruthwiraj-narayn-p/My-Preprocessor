#include"file_inclusion.h"

void copy_header_file(const char *filename,FILE *output)
{
	FILE *fp;
	int ch;
	fp=fopen(filename,"r");

	if(fp==NULL)
	{
		printf("error opening header %s\n",filename);
		return;
	}
	while((ch=fgetc(fp))!=EOF)
	{
		fputc(ch,output);
	}
	fclose(fp);
}

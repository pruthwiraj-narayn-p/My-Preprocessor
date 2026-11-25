#include "macro_handler.h"
#include <string.h>
#include <ctype.h>

struct macro
{
    char name[50];
    char value[100];
    char parameter[50];
    int is_function;

};


struct macro macros[100];

int macro_count = 0;




void store_macro(const char *line)
{
	char keyword[20];
	char name[50];
	char value[100];
	char *p,*q;
	char parameter[50] ="";

	if(sscanf(line, "%s %s %[^\n]", keyword, name, value)!=3)
		return;

	 p=strchr(name,'(');

        if(p != NULL)
        {
		q=strchr(p,')');
		if(q==NULL)
			return;
		if (q - p - 1 >= 50)
			return;

		*q ='\0';
		strcpy(parameter, p + 1);
		*p ='\0';
        }


	if (macro_count >= 100)
		return;

	strcpy(macros[macro_count].name, name);
	strcpy(macros[macro_count].value, value);
	strcpy(macros[macro_count].parameter, parameter);
	if(p!=NULL)
		macros[macro_count].is_function = 1;
	else
		macros[macro_count].is_function = 0;
	macro_count++;
}

void process_macro_line(const char *line, FILE *output)
{
	char keyword[20];
	char word[100];
	char argument[100];
	const char *p,*q;
	int i=0,j,k,found,m,n;
	char tempword[100];
	sscanf(line,"%s",keyword);
	
	if(strcmp(keyword, "#define")==0)
	{
		store_macro(line);
		return;
	}
	while (line[i] != '\0')
	{
		if(isalpha(line[i]) || line[i] == '_')
		{
			j=0;
		
		while (isalnum((unsigned char)line[i]) || line[i] == '_')
		{
			if(j<99)
				word[j++]=line[i];

			i++;
		}
		word[j] = '\0';
		//p = strchr(line + i, '(');

		found = 0;

		for(k=0;k<macro_count;k++)
		{
			if(strcmp(word,macros[k].name) == 0)
			{
				if(macros[k].is_function == 1)
				{
					if(line[i]=='(')
					{
						p=line+i;
						q=strchr(p,')');
						if(q!=NULL && q-p-1<100)
						{
							strncpy(argument,p+1,q-p-1);
							argument[q-p-1]='\0';

							i=q-line+1;
							m=0;
							while (macros[k].value[m] !='\0')
							{
								if (isalpha(macros[k].value[m]) || macros[k].value[m] =='_')
								{
									n=0;
									while (isalnum(macros[k].value[m]) || macros[k].value[m] =='_')
									{
										tempword[n++]=macros[k].value[m];
										m++;
									}
									tempword[n]='\0';

									if(strcmp(tempword, macros[k].parameter) == 0)
											fputs(argument, output);
									else
										fputs(tempword,output);

								}
								else
								{
									fputc(macros[k].value[m],output);
									m++;
								}
							}


						}
					}
				}
			else
			{
				fputs(macros[k].value, output);
			}
				found = 1;
				break;
			}
		}

		if(found == 0)
		{
			fputs(word, output);
		}
		}
		else
		{
			fputc(line[i],output);
			i++;
		}

	}

}

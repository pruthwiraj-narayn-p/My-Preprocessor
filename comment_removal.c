#include "comment_removal.h"
void remove_single_line_comments(FILE *input,FILE *output)
{
	int ch;
	int next;
	int in_string=0;
	int in_char =0;
	int prev=0;

	while((ch = fgetc(input)) != EOF)
	{
		if(ch=='"' && prev==0 && in_char==0)
			in_string = !in_string;

		if(ch=='\'' && prev==0 && in_string==0)
			in_char = !in_char;

		if(ch=='/' && in_string==0 && in_char==0)
		{
			next=fgetc(input);
			if(next=='/')
			{
				while((ch=fgetc(input))!='\n' && ch!=EOF);
					
				if(ch=='\n')
					fputc('\n', output);
			}
			else if(next=='*')
			{
				while((ch=fgetc(input))!=EOF)
				{
					if(ch=='*')
					{
						next=fgetc(input);

						if(next=='/')
							break;
					}
					if(ch=='\n')
						fputc('\n',output);
				}
			}
			else
			{
				fputc('/',output);

				if(next !=EOF)
					fputc(next,output);
			}


		}
		else
		{
			fputc(ch,output);
		}
		prev=(ch=='\\');

	}
}

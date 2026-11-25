#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include"comment_removal.h"
#include"file_inclusion.h"
#include"macro_handler.h"

int main(int argc,char *argv[])
{
	FILE *fp,*temp, *output;
	char line[1024];

	if(argc!=2)
	{
		printf("not correct usage");
		return 1;

	}

	fp=fopen(argv[1],"r");

	if(fp==NULL)
	{
		printf("Error opening input file!\n");
		return 1;
	}
	
	 temp=fopen("temp.c","w");

        if(temp==NULL)
        {
                printf("Error creating temporary file!\n");
		fclose(fp);
                return 1;
        }

	remove_single_line_comments(fp, temp);

	fclose(fp);
	fclose(temp);

	temp = fopen("temp.c", "r");
	 if(temp == NULL)
	 {
		 printf("Error opening temporary file!\n");
                return 1;
	 
	 }

	 output=fopen("output.i","w");

	  if(output == NULL)
         {
                 printf("Error creating output file!\n");
		 fclose(temp);
                return 1;

         }

	  while(fgets(line, sizeof(line), temp) != NULL)
	  {
		  if(strncmp(line, "#include \"", 10) == 0)
		  {
			  char filename[256];
			  sscanf(line, "#include \"%255[^\"]\"", filename);
			  copy_header_file(filename, output);
		  }
		  else
		  {
		  process_macro_line(line, output);
		  }
	  }

	  fclose(temp);
	  fclose(output);

	  printf("Preprocessing completed successfully!\n");

	return 0;
}

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h" 

int main(void)
{
  int    fd;
  char  *next_line;
  int  count;

  count = 0;
  //printf("Init program\n");
  fd = open("file.txt", O_RDONLY);
 // printf("File open succes!\n");
  //while (1){
	next_line = get_next_line(fd);
	printf("[%d]:%s\n", count, next_line);
	next_line = get_next_line(fd);
	if (next_line == NULL)
	{
		printf("NULL RETURN\n");
		//break ;
	}
    //count++;
	printf("[%d]:%s\n", count, next_line);
    //next_line = NULL;
	//}
  //free(next_line);
  close(fd);
  return (0);
}
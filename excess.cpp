#include <sys/ioctl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
	struct winsize ws;
  FILE* fd;
  char line[100000];


	if (ioctl(0,TIOCGWINSZ,&ws)!=0) {
		fprintf(stderr,"TIOCGWINSZ:%s\n",strerror(errno));
		exit(-1);
	}
	printf("row=%d, col=%d, xpixel=%d, ypixel=%d\n",
	ws.ws_row,ws.ws_col,ws.ws_xpixel,ws.ws_ypixel);

  fd = fopen("text.txt" , "r");
  int onePage = ws.ws_col * ws.ws_row;
  system("clear");
  while (fgets(line,100000,fd) != 0 ) {

  }
	rewind(fd);
  int counterOfAllChars = 0;
  while (1) {
		fgetc(fd);
		if (feof(fd))
		{
			break;
		}

		counterOfAllChars++;
	}
	int CounterOfPages = counterOfAllChars / onePage;

  for (int i = 0; i < onePage; i++) {
    printf("%c", line[i]);
  }

	int position = onePage;

	for (int i = 0; i < CounterOfPages; i++)
	{
		printf("Enter Next Page [N]:\n");
		char input = getchar();

		if(input == 'N')
		{
			for (int i = position; i < position+onePage; i++) {
				printf("%c", line[i]);
			}
			position+onePage;
		}
	}

  return 0;
}

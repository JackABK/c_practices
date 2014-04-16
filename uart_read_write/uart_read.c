#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdint.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
#define _POSIX_SOURCE 1
#define YES  (1)
#define NO (0)
#define buf_size 256
static int fd_uart;
static int uart_init_is_OK = NO;
void uart_init()
{
		//Setting the uart device parameter
		printf("Setting the uart device parameter\n");
		struct termios serialAttr;
		memset(&serialAttr, 0, sizeof serialAttr); 
		serialAttr.c_iflag = IGNPAR;
		serialAttr.c_cflag = B9600 | HUPCL | CS8 | CREAD | CLOCAL;
		serialAttr.c_cc[VMIN] = 1;

		if (tcsetattr(fd_uart, TCSANOW, &serialAttr)) {
				printf("tcsetattr fail !\n");
				close(fd_uart);
				exit(1);
		}
		uart_init_is_OK = YES;
		printf("uart initial is OK\n");
}
void *read_task(void *argu)
{
		char buf[buf_size];
		int n;
		int cnt=0;
		char c;
		while(1){
				do
				{
						n = read(fd_uart, (void*)&c, 1);
						if (n < 0) {
								perror("Read failed - ");
								return;
						}else if (n == 0) /*indicates end of file*/
								printf("end of file or data is empty.\n");
						else{ /*n>0 means have received data.*/
								buf[cnt++] = c;
						}
				}
				while(n>0 && cnt<buf_size && c!='\n' && c!='\r');

				buf[cnt]='\0';
				printf("%d bytes read : %s\n", cnt, buf);

				/*restart to accept next stream message.*/
				cnt=0; 
		}
		return NULL;
}
int main(int argc , char * argv[])
{
		pthread_t thread1; 
		pthread_create(&thread1, NULL , &read_task, NULL);

		/*used hardcode replace the argv*/
		if (argc < 2) {
				printf("Usage: ./uart_read /dev/ttyX\n");
				return 0;
		}
		/*device open , uart and usb*/
		fd_uart = open(argv[1], O_RDWR|O_NOCTTY);
		if(fd_uart < 0)
		{
				perror("Got error message:");
				exit(1); /* 1 means system not normal exit  */
		}

		/*uart initial*/
		uart_init();

		/*start to Reading from uart2 and send to the Arduino*/
		printf("Reading...\n");
		
		/*thread are running*/
		while(1); 

		/*close device*/
		printf("Close...\n");
		close(fd_uart);
		return 0;
}


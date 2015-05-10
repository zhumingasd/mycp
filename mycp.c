/*************************************************************************
	> File Name: test3.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2015年05月10日 星期日 05时56分58秒
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#define BUFSIZE 4096
int main(int argc, char *argv) 
{
	if(argc != 3){
        printf("usage: mycp file1 file2\n");
		return 0;
	}

	int fdin = open(argv[1], O_RDWR);
	if(fdin == -1){
	    printf("open file %s failed, %s\n", argv[1], strerror(errno));
	    return 0;
	}
	printf("open %s success\n", argv[1]);

	int fdout = open(argv[2], O_CREAT|O_RDWR);
	if(fdout == -1){
        printf("open file %s failed, %s\n", argv[2], strerror(errno));
	    close(fdin);
		return 0;
	}
	printf("open %s success\n", argv[1]);

	char buf[BUFSIZE] = {0};
	int n = 0;
	while((n = read(fdin, buf, BUFSIZE)) > 0){
	    if(write(fdout, buf，n) != n){
		    printf("write file error, %s\n", strerror(errno));
			close(fdin);
			close(fdout);
			return 0;
		}
	}
	if(n < 0){
	    printf("read file error, %s\n", strerror(errno));
	}
    
	close(fdin);
	close(fdout);
	return 0;
}

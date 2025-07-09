#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <syslog.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	const char* writefile = argv[1];
	const char* writestr = argv[2];

	openlog("finder", 0, 0);

	if (argc != 3)
	{
		fprintf(stderr, "Please pass a file and a text\n");
		return 1;
	}
	else
	{
		syslog(LOG_DEBUG|LOG_USER, "Writing %s to %s", writestr, writefile);
		fprintf(stdout, "Writing %s to %s\n",writestr, writefile);
	}

	int fd = open(writefile, O_WRONLY|O_CREAT);
	if (fd == -1)
	{
		syslog(LOG_ERR|LOG_USER, "Unable to open %s: %s", writefile, strerror(errno));
		fprintf(stdout, "Failed to open file");
	}
	int written = write(fd, writestr, strlen(writestr));
	close(fd);
	if (written != strlen(writestr))
	{
		syslog(LOG_ERR|LOG_USER, "Unable to write complete string");
		fprintf(stdout, "Written %d to %s\n",written, writefile);
	}
	fprintf(stdout, "Writing success");
	closelog();
	return 0;


}

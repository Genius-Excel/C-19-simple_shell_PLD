#include <unistd.h>

extern char **environ;

int main(int argc, char *argv[])
{
	execve("/bin/cat", argv, environ);

	return (0);
}

#include "monty.h"
<<<<<<< HEAD

bus_t bus = {NULL, NULL, NULL, 0};
=======
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
>>>>>>> 23e28b37e2f49d58fdbd785f18586d0a6f67beb6

char **mnty_tokens = NULL;



int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_error(argv[1]));
	exit_code = exec_mnty(script_fd);
	fclose(script_fd);
	return (exit_code);
}

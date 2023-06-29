
#include <unistd.h>

int main(int num, char *values[])
{
	int name_length;

	name_length = 0;
	while(values[0][name_length])
		name_length++;
	write(1, values[0], name_length);
	write(1, "\n", 1);
	return (0);
}

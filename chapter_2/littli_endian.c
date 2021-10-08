#include <stdio.h>
#include <stdint.h>

void is_little_endian()
{
    int32_t i = 1;
	unsigned char *p = (unsigned char *)&i;
	if(*p)
	{
		printf("little endian.\n");
        return;
	}
	printf("big endian.\n");
    return;
}

int main(int argc, char const *argv[])
{
	is_little_endian();
    return 0;
}

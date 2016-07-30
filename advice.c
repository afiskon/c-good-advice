#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const char* advices[] = {
	"Будь высокомерен!",
	"Кто не любит одиночества, тот не любит свободы.",
};

int main()
{
	srand(time(NULL));

	int idx = sizeof(advices)/sizeof(advices[0]) * ((double)rand() / RAND_MAX);
	printf("%s\n", advices[idx]);
	return 0;
}

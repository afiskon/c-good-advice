#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define VERSION "0.2"

static const char* advices[] = {
	"Be yourself.",
	"A man can be himself only so long as he is alone, "
      "and if he does not love solitude, he will not love freedom, "
      "for it is only when he is alone that he is really free.",
	"Who are you? What do you want?",
	"A second chance! That’s the delusion. There never was to be but one. "
      "We work in the dark - we do what we can - we give what we have. "
      "Our doubt is our passion, and our passion is our task. "
      "The rest is the madness of art.",
	"And that's why you are dangerous. You've mastered your passions.",
	"Say what you know, do what you must, come what may.",
	"KISS",
	"DRY",
	"Performance is not a problem.",
	"To improve is to change; to be perfect is to change often.",
	"If you can't hack it you don't own it.",
};


unsigned int
hash(const unsigned char *data, const size_t data_len) {
	unsigned int hash = 0x4841434B;
	for(int i = 0; i < data_len; i++) {
		hash = ((hash << 5) + hash) + data[i];
	}
	return hash;
}

int
main(int argc, char* argv[])
{
	struct timeval time = {0};

	if(argc > 1)
	{
		if((strcmp(argv[1], "-v") == 0) || (strcmp(argv[1], "--version") == 0))
		{
			printf(
				"advice v" VERSION "\n"
				"(c) Aleksander Alekseev 2016 | http://eax.me/\n"
			);
			return 0;
		} else {
			fprintf(stderr, "Usage: %s [-v|--version]\n", argv[0]);
			return 1;
		}
	}

	gettimeofday(&time, NULL);

	/* srand((time.tv_sec * 1000) + (time.tv_usec / 1000)); */
	srand(hash((const unsigned char*)&time, sizeof(time)));

	int idx = (sizeof(advices)/sizeof(advices[0])) * (((double)rand()) / ((double)RAND_MAX+1.0));
	printf("%s\n", advices[idx]);
	return 0;
}

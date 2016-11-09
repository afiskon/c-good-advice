#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define VERSION "0.2"

static const char* advices[] = {
	"Будь высокомерен.",
	"Будь позитивен.",
	"Кто не любит одиночества, тот не любит свободы.",
	"Не давай загрузить тебя.",
	"Получай от жизни удовольствие.",
	"Начинай каждое утро с кофе и 50 г шоколада (минимум 75% какао).",
	"Борись за свою свободу.",
	"Кто не ебашит, не добивается результата.",
	"Люди отдали бы все, чтобы быть на твоем месте.",
	"Не дай обществу сломить тебя.",
	"Кто ты? Чего ты хочешь?",
	"Клади болт на чужое мнение.",
	"Не позволяй манипулировать тобой.",
	"Не бойся загадок. Ты сам - загадка.",
	"А куда вы так спешите?",
	"Время - ресурс ограниченный и невосполнимый.",
	"Красивые решения никому не нужные, если они не работают.",
	"Хорошая программа сегодня - лучше, чем идеальная через год.",
	"Следи за своим здоровьем, особенно за зрением.",
	"Наша работа во тьме......",
	"Потому ты и опасен, что овладел своими страстями.",
	"От этого еще никто не умирал.",
	"А зачем это тебе?",
	"Ты ничего не должен.",
	"Используй мозг.",
	"Делай что должен, и случится чему суждено.",
	"Не грузи окружающих.",
	"Смотри на мир шире.",
	"В любой непонятной ситуации оставайся спокоен.",
	"KISS",
	"DRY",
	"YAGNI",
	"Performance is not a problem.",
	"To improve is to change; to be perfect is to change often.",
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

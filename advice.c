#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

static const char* advices[] = {
	"Будь высокомерен!",
	"Кто не любит одиночества, тот не любит свободы.",
	"Не давай жалким людишкам загрузить тебя!",
	"Получай от жизни удовольствие!",
	"Начинай каждое утро с кофе и 100 г шоколада (минимум 75% какао).",
	"Борись за свою свободу!",
	"Надо ебашить!",
	"Кто не ебашит, не добивается результата!",
	"Люди отдали бы ВСЕ, чтобы быть на твоем месте!",
	"Не дай обществу сломить тебя!",
	"Кто ты? Чего ты хочешь?",
	"Клади хуй на чужое мнение!",
	"Не давай манипулировать тобой!",
	"Не бойся загадок. Ты сам - загадка.",
	"Все будет хорошо. Мы все умрем.",
	"А куда вы так спешите?",
	"Время - ресурс ограниченный и невосполнимый.",
	"То, что я говорю, это тоже херня полнейшая.",
	"А может, просто дадим им программировать?",
	"Красивые решения никому не нужные, если они, сука, не работают!",
	"Хорошая программа сегодня - лучше, чем идеальная через год.",
	"Следи за своим здоровьем.",
	"Наша работа во тьме...",
	"Потому ты и опасен, что овладел своими страстями.",
	"От этого еще никто не умирал.",
	"Предлагаю забить.",
	"А зачем это тебе?",
	"Ты не должен этого хотеть!",
	"Хакни свой мозг!",
	"Я не вижу проблемы.",
	"Делай что должен, и случится чему суждено.",
	"Истина где-то в сорсах.",
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
main()
{
	struct timeval time = {0};
	gettimeofday(&time, NULL);

	/* srand((time.tv_sec * 1000) + (time.tv_usec / 1000)); */
	srand(hash((const unsigned char*)&time, sizeof(time)));

	int idx = (sizeof(advices)/sizeof(advices[0])) * (((double)rand()) / ((double)RAND_MAX));
	printf("%s\n", advices[idx]);
	return 0;
}

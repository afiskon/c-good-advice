#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const char* advices[] = {
	"Будь высокомерен!",
	"Кто не любит одиночества, тот не любит свободы.",
	"Не давай жалким людишкам загрузить тебя!",
	"Получай от жизни удовольствие!",
	"Начинай каждое утро с кофе и 100 г шоколада (минимум 75%).",
	"Борись за свою свободу!",
	"Надо ебашить!",
	"Люди отдали бы ВСЕ чтобы быть на твоем месте!",
};

int main()
{
	srand(time(NULL));

	int idx = sizeof(advices)/sizeof(advices[0]) * ((double)rand() / RAND_MAX);
	printf("%s\n", advices[idx]);
	return 0;
}

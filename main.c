#include "header.h"

/*
 * есть некая сеть из 4 нейронов
 * на каждый приходит 4 сигнала
 * (по сути сеть должна примерно воспроизвести сигнал, который на нее приходит)
 * смотри в хедер
 *
 * нужно сделать функцию кооректировки весов
 * void	correct_weight(t_layer *l, double *output_case, double *input_case);
 */

double input[CASE_COUNT][INPUT_COUNT] = {
		{1.0, 0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0, 0.0},
		{0.0, 0.0, 1.0, 0.0},
		{0.0, 0.0, 0.0, 1.0},
		{0.8, 0.1, 0.0, 0.1},
		{0.1, 0.8, 0.1, 0.0},
		{0.0, 0.1, 0.8, 0.1},
		{0.1, 0.0, 0.1, 0.8}
};

double output[CASE_COUNT][INPUT_COUNT] = {
		{1.0, 0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0, 0.0},
		{0.0, 0.0, 1.0, 0.0},
		{0.0, 0.0, 0.0, 1.0},
		{1.0, 0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0, 0.0},
		{0.0, 0.0, 1.0, 0.0},
		{0.0, 0.0, 0.0, 1.0},
};

//это надо доделать, смотри в хедер
void	correct_weight(t_layer *l, double *output_case, double *input_case){
	;
}

void print_arr(double *arr, int count) {
	int i;

	i = 0;
	while (i < count) {
		printf("%lf ", arr[i]);
		i++;
	}
	printf("\n");
}

int main() {
	printf("Hello, World!\n");

	t_layer l = ft_init_layer();

	int i = 0;
	while (i < 1000) {
		int n = 0;
		while (n < CASE_COUNT) {
			print_arr(input[n], 4);
			print_arr(output[n], 4);
			summator(&l, input[n]);
			print_arr(l.summ, 4);

			correct_weight(&l, output[n], input[n]);
			n++;
		}
		i++;
	}

	char *message = "CONGRATULATIONS!!!";
	int n = 0;
	while (n < CASE_COUNT) {
		summator(&l, input[n]);
		if (!is_correct(l, output[n]))
			message = "FAIL!!!";
		n++;
	}
	printf("%s\n", message);
	return 0;
}


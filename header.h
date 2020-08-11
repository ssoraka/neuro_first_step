//
// Created by ssoraka on 10.08.2020.
//

#ifndef FIRST_NEURO_HEADER_H
#define FIRST_NEURO_HEADER_H

#include <stdio.h>
#include <time.h>
#include "math.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

typedef int t_bool;

#define N_COUNT (4)
#define INPUT_COUNT (4)
#define CASE_COUNT (8)

typedef struct		s_layer
{
	double			summ[N_COUNT];
	double			w_ij[INPUT_COUNT][N_COUNT];
}					t_layer;


//инициализация, создает случайные связи
t_layer ft_init_layer();
//суммирует входящие сигналы на каждый нейрон
void summator(t_layer *l, double *output_case);
//просто проверяет, что самый сильный сигнал на правильном нейроне
t_bool	is_correct(t_layer l, double *output_case);
/*
 * эту функцию нужно создать
 *
 * разница между выходящим сигналом и ожидаемым - ошибка сети.
 *
 * 1)в простом случае нужно добавлять к связи тех нейронов 1, которые недоактивированны
 * и вычитать 1 у тех, которые переактивированы
 * w_ij(n + 1) = w_ij(n) + a * sign(err_j) * input_i
 * это позволяет делать сравнение количественным, ибо выход нейрона принадлежит (-inf, +inf)
 * но возникают трудности в сравнении похожих зашумленных изображений
 *
 * 2)сами веса играют роль маски
 * выведи веса для каждого нейрона после обучения и посмотри получившуюся маску
 *
 * 3)для качественного сравнения образов делают функцию ошибки в виде кривой
 * в простом случае нужно w_ij(n + 1) = w_ij(n) + a * err_j * input_i
 * в условиях этой задачи выход нейрона при обучении будет находиться примерно (-1, +1)
 * это позволяет сравнивать выходы качественно
 *
 * тоже выведи все веса
 *
 * 4) переделай под такую задачу
 * это таблица xor, в свое время подорвавшая веру в безграничные возможности однослойных нейросетей
 * https://studbooks.net/2240383/informatika/problema
 *
 * a^b
 * 0^0=0
 * 0^1=1
 * 1^0=1
 * 1^1=0
 * double input[CASE_COUNT][INPUT_COUNT] = {
//		 a	   b
		{0.0, 0.0},
		{1.0, 0.0},
		{0.0, 1.0},
		{1.0, 1.0}
};

double output[CASE_COUNT][INPUT_COUNT] = {
 //		  0		1
		{1.0, 0.0},
		{0.0, 1.0},
		{0.0, 1.0},
		{1.0, 0.0}
};
 */
void	correct_weight(t_layer *l, double *output_case, double *input_case);

#endif //FIRST_NEURO_HEADER_H

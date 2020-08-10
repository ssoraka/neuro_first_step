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
 * в простом случае нужно w_ij(n + 1) = w_ij(n) + a * err_j * input_i
 */
void	correct_weight(t_layer *l, double *output_case, double *input_case);

#endif //FIRST_NEURO_HEADER_H

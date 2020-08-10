//
// Created by ssoraka on 10.08.2020.
//

#include "header.h"

t_layer	ft_init_layer() {
	t_layer layer;
	int i;
	int j;

	srand(time(NULL));
	i = 0;
	while (i < INPUT_COUNT) {
		layer.summ[i] = 0.0;
		j = 0;
		while (j < N_COUNT) {
			layer.w_ij[i][j] = (double)rand() / RAND_MAX;
			j++;
		}
		i++;
	}
	return (layer);
}

void	summator(t_layer *l, double *output_case) {
	int i = 0;
	int j = 0;
	double summ;

	i = 0;
	while (i < INPUT_COUNT) {
		summ = 0.0;
		j = 0;
		while (j < N_COUNT) {
			summ += l->w_ij[i][j] * output_case[j];
			j++;
		}
		l->summ[i] = summ;
		i++;
	}
}

t_bool	is_correct(t_layer l, double *output_case) {
	int max_summ;
	int max_case;
	int i;

	max_summ = 0;
	max_case = 0;
	i = 1;
	while (i < N_COUNT) {
		if (l.summ[i] >= l.summ[max_summ])
			max_summ = i;
		if (output_case[i] >= output_case[max_case])
			max_case = i;
		i++;
	}
	if (max_case != max_summ)
		return (FALSE);
	return (TRUE);
}
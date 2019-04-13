#include "expert_system.h"

void free_data(t_expert *data)
{
	char **tmp;

	if (data->rules)
	{
		tmp = data->rules;
		while (*tmp)
		{
			free(*tmp++);
		}
		free(data->rules);
	}
	exit(EXIT_FAILURE);
}

void contradiction_exit(t_expert *data, char str)
{
	char **tmp;

	display(4, "[", RED("ERROR"), "] => ", YELLOW("QUERIE '") );
	ft_printf("%c", str);
	display(2, YELLOW("' is CONTRADICTORY!"), "\n");
	if (data->rules)
	{
		tmp = data->rules;
		while (*tmp)
		{
			free(*tmp++);
		}
		free(data->rules);
	}
	exit(EXIT_FAILURE);
	(void)data;
}
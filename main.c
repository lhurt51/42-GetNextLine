/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 04:51:39 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/28 13:04:16 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		main(int argc, char **argv)
{
	int fd;
	int r_value = 0;
	char *line;
	char *message;

	if (argc > 1)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			while ((r_value = get_next_line(fd, &line)) > 0)
			{
				printf("\nr_value: %d\n", r_value);
				printf("returned line:\n%s\n", line);
			}
			printf("\nr_value on exit: %d\n", r_value);
			printf("returned line after exit:\n%s\n", line);
			message = (r_value == 0 && (ft_strlen(line) == 0 || line == NULL)) ? ("correct!\n") :
									("did not return 0 or forgot to clear line");
			printf("%s", message);
		}
	}
	else
	{
		fd = 1;
		while ((r_value = get_next_line(fd, &line)) > 0)
		{
			printf("\nr_value: %d\n", r_value);
			printf("returned line:\n%s\n", line);
		}
		printf("\nr_value on exit: %d\n", r_value);
		printf("returned line after exit:\n%s\n", line);
		message = (r_value == 0 && (ft_strlen(line) == 0 || line == NULL)) ? ("correct!\n") :
									("did not return 0 or forgot to clear line");
		printf("%s", message);
	}
	return (0);
}

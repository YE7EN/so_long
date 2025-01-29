






#include "so_long.h"

int	ft_check_name(char *argv)
{
	int	i = 0;
	int	fd = -1;

	while (argv[i] != '\0')
		i++;
	if (argv[i - 1] != 'r' && argv[i - 2] != 'e' && argv[i - 3] != 'b' && argv[i - 4] != '.')
	{
		fd = open(argv, O_RDONLY);
		if (fd != -1)
		{
			close(fd);
			return (0);
		}
	}
	return (1);
}

#include "so_long.h"





int	main(int argc, char **argv)
{

	if (argc != 2)
		return (0);
	if (ft_check_name(argv[1] == 1))
	{
		printf("wrong format, it must be a .ber");
		return (0);	
	}
	
	
//	call to ft_start/create_tab what you want
//	lecture de la map avec GNL  
	
	
	
	
	
}












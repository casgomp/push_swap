#include "ft_dprintf.h"

int	main(void)
{
	int	fd = 1;
	//unsigned int	c = 0;
	
	int	flag1 = ft_dprintf(fd, "fd1 %p %p ", (void *)0, (void *)0);
	//int	flag1 = ft_dprintf(fd, "%p", &c);
	//int	flag1 = ft_dprintf(fd, " %p ", (void *)16);
	dprintf(fd, "\n");
    dprintf(fd, "%i\n", flag1);

	int	flag2 = dprintf(fd, "fd1 %p %p ", (void *)0, (void *)0);
	//int	flag2 = ft_dprintf(fd, "%p", &c);
    	//int	flag2 = dprintf(fd, " %p ", (void *)16);
    	dprintf(fd, "\n");
	dprintf(fd, "%i\n", flag2);
//*/
	fd = 2;
	//unsigned int	c = 0;
	
	flag1 = ft_dprintf(fd, "fd2 %p %p ", (void *)0, (void *)0);
	//int	flag1 = ft_dprintf(fd, "%p", &c);
	//int	flag1 = ft_dprintf(fd, " %p ", (void *)16);
	dprintf(fd, "\n");
    dprintf(fd, "%i\n", flag1);

	flag2 = dprintf(fd, "fd2 %p %p ", (void *)0, (void *)0);
	//int	flag2 = ft_dprintf(fd, "%p", &c);
    	//int	flag2 = dprintf(fd, " %p ", (void *)16);
    	dprintf(fd, "\n");
	dprintf(fd, "%i\n", flag2);







	//unsigned int	c = 4294967295;
/*	
	int	flag1 = ft_dprintf(fd, "NULL %s NULL", (char *)NULL);
	dprintf(fd, "\n");
    	dprintf(fd, "%i\n", flag1);

    	int	flag2 = dprintf(fd, "NULL %s NULL", (char *)NULL);
    	dprintf(fd, "\n");
	dprintf(fd, "%i\n", flag2);
//*/

	//unsigned int	c = 4294967295;
/*
	int	flag1 = ft_dprintf(fd, "%x", 4294967295);
	dprintf(fd, "\n");
    	dprintf(fd, "%i\n", flag1);
    	
    	int	flag2 = dprintf(fd, "%x", 4294967295);
    	dprintf(fd, "\n");
	dprintf(fd, "%i\n", flag2);
//*/
/*
	//unsigned int	c = 4294967295;
	//int	d = -2147483648;
	
	int	flag1 = ft_dprintf(fd, "%u, %u", -2147483647, 4294967295);
	dprintf(fd, "\n");
    	dprintf(fd, "%i\n", flag1);
//*/
/*
    	int	flag2 = dprintf(fd, "%u, %u", -2147483647, 4294967295);
    	dprintf(fd, "\n");
	dprintf(fd, "%i\n", flag2);
	
//*/
/*
int nb = 3;


	int	flag1;
	flag1 = ft_dprintf(fd, "%c ft_dprintf: %s goes to address %p and at %d or %i celsius buys a box of %u eggs ID %x or %X", 'A', "Manolo", &nb, -2, -3, 12, -2147483647, 4294967295);
    dprintf(fd, "\n");
    dprintf(fd, "%i\n", flag1);
//*/
/*
	int	flag2;
    flag2 = dprintf(fd, "%c ...dprintf: %s goes to address %p and at %d or %i celsius buys a box of %u eggs ID %x or %X", 'B', "Manolo", &nb, -2, -3, 12, -2147483647, (unsigned int)4294967295);
	dprintf(fd, "\n");
	dprintf(fd, "%i\n", flag2);
//*/
}

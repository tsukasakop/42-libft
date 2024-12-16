//usr/bin/cc $0 -g -Iinclude -L. -lft -o ./a.out && ./a.out; exit

#include "ft_stdio.h"
#include "ft_string.h"
#include <limits.h>
#include <stdio.h>

void	test(int (*f)(const char *restrict format, ...))
{
	FILE	*stream;
	int		ret;

	/*
	f("[%d]\n", f("%c%c%c", 'a', '\t', 'b'));
	f("[%d]\n", f("a1234567890"));
	f("[%d]\n", f("%d", 0));
	*/
	f("[%d]\n", f("%d", -42));
	f("[%d]\n", f("%d", 42));
	f("[%d]\n", f("%d", INT_MAX));
	f("[%d]\n", f("%d", INT_MIN));
	f("[%d]\n", f("%d", INT_MIN - 1));
	f("[%d]\n", f("%20d", 20));
	f("[%d]\n", f("%5s", "1234567890"));
	f("[%d]\n", f("%015.10s", "12345"));
	f("[%d]\n", f("%015.15d", 12345));
	f("[%d]\n", f("%015.10d", 12345));
	f("[%d]\n", f("%015.0d", 12345));
	f("[%d]\n", f("%015d", 12345));
	// f("[%d]\n", f("%2$d%1$d", 11,22));
	/*
	printf("[%d]\n", printf("%d", 2147483650));
	printf("[%d]\n", printf("%d", 18446744073709551615));
	printf("[%d]\n", printf("%d", 18446744073709551616));
	printf("[%d]\n", printf("%d", 18446744073709551617));
	printf("[%d]\n", printf("%-*d", -10,  5));
	printf("[%d]\n", printf("%-10d", 5));
	printf("[%d]\n", printf("%+10d", 5));
	printf("[%d]\n", printf("%*-.*d", 5,3,5));
	printf("[%d]\n", printf("%*- .*d", 5,3,5));
	printf("[%d]\n", printf("%10. d"), 5);
	printf("[%d]\n", printf("%10.0 d"), 5);
	printf("[%d]\n", printf("%10.5 d"), 5);
	printf("[%d]\n", printf("%10.5#x", 12));
	printf("[%d]\n", printf("%10.5Q"));
	printf("[%d]\n", printf("%10.5"));
	stream = stdout;
	for(int j = 0; j < 20; j++)
	{
		ft_fputc('A' + j % 26, stream);
		for(int i = 0; i < 4094; i++)
			ft_fputc('0' + j % 10, stream);
		ft_fputc('a' + j % 26, stream);
		if(j%2)
			ft_fflush(stream);
	}
	//fprintf(stream, "%4000s", "1");
	char *s=malloc(4100);
	for(int i=0; i<4100; i++)
		s[i] = 'A';
	s[4099] = 0;
	ret = fprintf(stream, "%1$*2$s%3$s", "E", 2147483647, s);
	write(1,"end",3);
	fflush(stream);
	printf("\nreturn: %d\n", ret);
	//2147483647 -> 2147483647
	//2147483648 -> -1
	//2147483649 -> 2147483647
	//fprintf(stream, "%4000s", "3");
	//fflush(stream);
	//ft_putnbr_fd(ft_strnlen("123456789", 5),1);
	stream = stdout;
	ft_fputc('0'+ft_fileno(stderr), stream);
	ft_fflush(stream);
	*/
}

int	main(void)
{
	test(printf);
	test(ft_printf);
	ft_fflush(stdout);
}

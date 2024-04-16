/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:24:16 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/17 00:28:32 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
void	ft_bzero(void *s, size_t n)
{
	int	i;
	char *sc= (char *)s;
	i = 0;
	while (i < n && sc[i])
		sc[i++] = 0;
}

/*
#include <unistd.h>

void	print_num_str(unsigned char *addr, int len)
{
	char	c;
	int		i;

	i = 0;
	while (i < len)
	{
		c = addr[i];
		if (c < ' ' || c > '~')
			c = '.';
		write(1, &c, 1);
		i++;
	}
}

void	print_num_hex(unsigned char *addr, int len)
{
	char	lhs;
	char	rhs;
	int		i;

	i = 0;
	while (i < 16)
	{
		if (i < len)
		{
			lhs = '0' + addr[i] / 16;
			rhs = '0' + addr[i] % 16;
			if (lhs > '9')
				lhs += 'a' - '9' - 1;
			if (rhs > '9')
				rhs += 'a' - '9' - 1;
			write(1, &lhs, 1);
			write(1, &rhs, 1);
		}
		else
			write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	print_addr(unsigned long addr)
{
	int		i;
	char	o[16];

	i = 0;
	while (i < 16)
	{
		o[15 - i] = addr % 16 + '0';
		if (o[15 - i] > '9')
			o[15 - i] += 'a' - '9' - 1;
		i++;
		addr /= 16;
	}
	write(1, o, 16);
	write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*current;
	unsigned int	i;
	unsigned int	offset;

	current = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_addr((unsigned long)current + i);
		offset = 16;
		if (size - i < 16)
			offset = size - i;
		print_num_hex(current + i, offset);
		print_num_str(current + i, offset);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
int main(){
	char s [20]="1234567890qwertyuiop";
	ft_print_memory(s,50);
}
#include <stdio.h>
#include <strings.h>

void	test(char *s, int i)
{
	char*	proced1;
	char*	proced2;

	proced1 = strdup(s);
	proced2 = strdup(s);
	bzero(proced1,i);
	ft_bzero(proced2,i);
	printf("args:\ts=%s, i=%d\n", s, i);
	printf("org: \t");
	for(int j=0;j<5;j++) printf("%d, ",proced1[j]);
	printf("\norg: \t");
	for(int j=0;j<5;j++) printf("%d, ",proced2[j]);
	printf("\n");
}

void	test2(char *s, int i, int st)
{
	char*	proced1;
	char*	proced2;

	proced1 = strdup(s);
	proced2 = strdup(s);
	bzero(proced1+st,i);
	ft_bzero(proced2+st,i);
	printf("args:\ts=%s, i=%d, st=%d\n", s, i, st);
	printf("org: \t");
ft_print_memory(proced1,10);
	printf("\nself:\t");
ft_print_memory(proced2,10);
	printf("\n\n");
}
int	main(void)
{
test("12345", 0);
	test("12345", -1);
	test("12345", 2);
	test("12345", 5);
	test("12345", 6);
	test2("1234567890", 0,2);
	test2("1234567890", -1,2);
	test2("1234567890", 1,2);
	test2("1234567890", 3,2);
	test2("1234567890", 4,2);
	test2("1234567890", -1,9);
	test2("1234567890", -3,9);
	test2("1234567890", -5,9);
	test2("1234567890", -9,9);
}
//*/

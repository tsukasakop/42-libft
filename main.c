/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:45:14 by tkondo            #+#    #+#             */
/*   Updated: 2024/05/11 22:55:12 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#include "libft.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void	ft_print_listc(void *content)
{
	printf("%s", (char *)content);
}

void	ft_print_listi(t_list *node)
{
	printf("(");
	ft_print_listc(node->content);
	printf(")");
}

void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		ft_print_listi(lst);
		lst = lst->next;
		if (lst)
			printf("->");
	}
	printf("\n");
}

void	test_isalpha(int c)
{
	assert(isalpha(c) == ft_isalpha(c));
}

void	test_isdigit(int c)
{
	assert(isdigit(c) == ft_isdigit(c));
}

void	test_isalnum(int c)
{
	assert(isalnum(c) == ft_isalnum(c));
}

void	test_isascii(int c)
{
	assert(isascii(c) == ft_isascii(c));
}

void	test_isprint(int c)
{
	assert(isprint(c) == ft_isprint(c));
}

void	test_strlen(const char *s)
{
	assert(strlen(s) == ft_strlen(s));
}

void	test_memset(int c, size_t len)
{
	char	*b1;
	char	*b2;

	b1 = (char *)calloc(sizeof(char), (len + 1));
	b2 = (char *)calloc(sizeof(char), (len + 1));
	memset(b1, c, len);
	ft_memset(b2, c, len);
	assert(strcmp(b1, b2) == 0);
	free(b1);
	free(b2);
}

void	test_bzero(size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char *)malloc(sizeof(char) * (n + 1));
	s2 = (char *)malloc(sizeof(char) * (n + 1));
	bzero(s1, n);
	ft_bzero(s2, n);
	ft_print_memory(s1, n);
	ft_print_memory(s2, n);
	free(s1);
	free(s2);
}

void	test_memcpy(const void *src, size_t n)
{
	char	*dst1;
	char	*dst2;

	dst1 = (char *)calloc(sizeof(char), (n + 1));
	dst2 = (char *)calloc(sizeof(char), (n + 1));
	memcpy(dst1, src, n);
	ft_memcpy(dst2, src, n);
	assert(!strcmp(dst1, dst2));
	free(dst1);
	free(dst2);
}

void	test_memmove(const void *src, size_t len)
{
	char	*dst1;
	char	*dst2;

	dst1 = (char *)calloc(sizeof(char), (len + 1));
	dst2 = (char *)calloc(sizeof(char), (len + 1));
	memmove(dst1, src, len);
	ft_memmove(dst2, src, len);
	assert(!strcmp(dst1, dst2));
	free(dst1);
	free(dst2);
}

void	test_strlcpy(const char *src, size_t dstsize)
{
	char	*dst1;
	char	*dst2;

	dst1 = (char *)malloc(sizeof(char) * (dstsize + 1));
	dst2 = (char *)malloc(sizeof(char) * (dstsize + 1));
	strlcpy(dst1, src, dstsize);
	ft_strlcpy(dst2, src, dstsize);
	assert(!strcmp(dst1, dst2));
	free(dst1);
	free(dst2);
}

void	test_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*dst1;
	char	*dst2;
	size_t	r1;
	size_t	r2;
	size_t	size;

	size = MIN(strlen(dst) + strlen(src), dstsize);
	dst1 = malloc(sizeof(char) * size);
	dst2 = malloc(sizeof(char) * size);
	strlcpy(dst1, dst, size);
	strlcpy(dst2, dst, size);
	r1 = strlcpy(dst1, src, dstsize);
	r2 = ft_strlcpy(dst2, src, dstsize);
	assert(r1 == r2);
	assert(!strcmp(dst1, dst2));
	free(dst1);
	free(dst2);
}

void	test_toupper(int c)
{
	assert(toupper(c) == ft_toupper(c));
}

void	test_tolower(int c)
{
	assert(tolower(c) == ft_tolower(c));
}

void	test_strchr(const char *s, int c)
{
	assert(strchr(s, c) == ft_strchr(s, c));
}

void	test_strrchr(const char *s, int c)
{
	assert(strrchr(s, c) == ft_strrchr(s, c));
}

void	test_strncmp(const char *s1, const char *s2, size_t n)
{
	assert(strncmp(s1, s2, n) == strncmp(s1, s2, n));
}

void	test_memchr(const void *s, int c, size_t n)
{
	assert(memchr(s, c, n) == ft_memchr(s, c, n));
}

void	test_memcmp(const void *s1, const void *s2, size_t n)
{
	assert(memcmp(s1, s2, n) == ft_memcmp(s1, s2, n));
}

void	test_strnstr(const char *haystack, const char *needle, size_t len)
{
	assert(!strcmp(strnstr(haystack, needle, len), ft_strnstr(haystack, needle,
				len)));
}

void	test_atoi(const char *str)
{
	assert(atoi(str) == ft_atoi(str));
}

void	test_calloc(size_t count, size_t size)
{
	char	*p;
	int		i;
	int		n;

	i = 0;
	n = count * size;
	p = ft_calloc(count, size);
	while (i < n)
	{
		assert(p[i] == 0);
		i++;
	}
	free(p);
}

void	test_strdup(const char *s1)
{
	char *p1, *p2;
	p1 = strdup(s1);
	p2 = ft_strdup(s1);
	assert(!strcmp(p1, p2));
	free(p1);
	free(p2);
}

void	test_substr(char const *s, unsigned int start, size_t len,
		char const *expect)
{
	assert(!strcmp(ft_substr(s, start, len), expect));
}

void	test_strjoin(char const *s1, char const *s2)
{
	char	*dst;

	dst = ft_strjoin(s1, s2);
	while (*s1)
	{
		assert(*s1 == *dst);
		s1++;
		dst++;
	}
	while (*s2)
	{
		assert(*s2 == *dst);
		s2++;
		dst++;
	}
	assert(*dst == '\0');
}

void	test_strtrim(char const *s1, char const *set, char const *expect)
{
	char	*p;

	p = ft_strtrim(s1, set);
	assert(!strcmp(p, expect));
	free(p);
}

void	test_split(char const *s, char c, char const *expect)
{
	char	**p;
	size_t	i;

	i = 0;
	p = ft_split(s, c);
	while (p[i])
	{
		assert(!strcmp(p[i], expect));
		free(p[i]);
		i++;
		expect += strlen(expect) + 1;
	}
	free(p);
}

void	test_itoa(int n, char *expect)
{
	char	*p;

	p = ft_itoa(n);
	assert(!strcmp(p, expect));
	free(p);
}

void	test_strmapi(char const *s, char (*f)(unsigned int, char),
		char const *expect)
{
	char	*p;

	p = ft_strmapi(s, f);
	assert(!strcmp(p, expect));
	free(p);
}

void	test_striteri(char *s, void (*f)(unsigned int, char *),
		char const *expect)
{
	char	*p;

	p = strdup(s);
	ft_striteri(p, f);
	// ft_print_memory(p);
	assert(!strcmp(p, expect));
	free(p);
}

void	test_putchar_fd(char c, int fd)
{
	printf("--- start test ft_putcher_fd(%c)\n", c);
	ft_putchar_fd(c, fd);
	printf("\n------------------------------------\n");
}

void	test_putstr_fd(char *s, int fd)
{
	printf("--- start test ft_putstr_fd(%s)\n", s);
	ft_putstr_fd(s, fd);
	printf("\n------------------------------------\n");
}

void	test_putendl_fd(char *s, int fd)
{
	printf("--- start test ft_putendl_fd(%s)\n", s);
	ft_putendl_fd(s, fd);
	printf("\n------------------------------------\n");
}

void	test_putnbr_fd(int n, int fd)
{
	printf("--- start test ft_putnbr_fd(%d)\n", n);
	ft_putnbr_fd(n, fd);
	printf("\n------------------------------------\n");
}

void	test_lstnew(void *content)
{
	printf("--- start test ft_lstnew(%s)\n", (char *)content);
	ft_print_list(ft_lstnew(content));
	printf("\n------------------------------------\n");
}

void	test_lstadd_front(t_list **lst, t_list *new)
{
	printf("--- start test ft_lstadd_front\n");
	ft_lstadd_front(lst, new);
	ft_print_list(*lst);
	printf("\n------------------------------------\n");
}

void	test_lstsize(t_list *lst, int expect)
{
	assert(ft_lstsize(lst) == expect);
}

void	test_lstlast(t_list *lst)
{
	printf("--- start test ft_lstlast()\n");
	ft_print_listi(ft_lstlast(lst));
	printf("\n------------------------------------\n");
}

void	test_lstadd_back(t_list **lst, t_list *new)
{
	printf("--- start test ft_lstadd_back\n");
	ft_lstadd_back(lst, new);
	ft_print_list(*lst);
	printf("\n------------------------------------\n");
}

void	test_lstdelone(t_list *lst, void (*del)(void *))
{
	printf("--- start test ft_lstdelone\n");
	ft_lstdelone(ft_lstlast(lst), del);
	//	ft_print_list(lst);
	printf("\n------------------------------------\n");
}

void	test_lstclear(t_list **lst, void (*del)(void *))
{
	printf("--- start test ft_lstclear\n");
	ft_lstclear(lst, del);
	//	ft_print_list(*lst);
	printf("\n------------------------------------\n");
}

void	test_lstiter(t_list *lst, void (*f)(void *))
{
	printf("--- start test ft_lstiter\n");
	ft_lstiter(lst, f);
	printf("\n------------------------------------\n");
}

void	test_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;

	printf("--- start test ft_lstmap\n");
	root = ft_lstmap(lst, f, del);
	ft_print_list(root);
	ft_lstclear(&root, del);
	printf("\n------------------------------------\n");
}

void	toupper_mu(unsigned int i, char *s)
{
	(void)i;
	*s = toupper(*s);
}

char	toupper_im(unsigned int i, char s)
{
	(void)i;
	return (char)toupper((int)s);
}
void	*lst_toupper_im(void *content)
{
	char	*p;
	int		i;

	i = 0;
	p = strdup((char *)content);
	while (p[i])
	{
		p[i] = toupper(p[i]);
		i++;
	}
	return (p);
}

int	main(void)
{
	t_list	*root;

	test_isalpha('a');
	test_isdigit('0');
	test_isalnum('a');
	test_isascii('~');
	test_isprint('a');
	test_strlen("12345");
	test_memset('9', 3);
	test_bzero(3);
	test_memcpy("abcde", 3);
	test_memmove("abcde", 3);
	int size = 128*1024*1024;
	char *data = malloc(size);
	test_memmove(data, size);
	free(data);
	test_strlcpy("abcde", 3);
	test_strlcat("12345", "abcde", 3);
	test_toupper('a');
	test_tolower('A');
	test_strchr("12345", '3');
	test_strrchr("12345", '3');
	test_strncmp("12345", "12345", 3);
	test_memchr("12345", '3', 3);
	test_memcmp("12345", "12345", 3);
	test_strnstr("12345", "12345", 5);
	test_atoi("12345");
	test_calloc(10, 10);
	test_strdup("12345");
	test_substr("12345", 1, 3, "234");
	test_strjoin("12345", "abcde");
	test_strtrim("129799887hello129841123", "1234567890", "hello");
	test_split("1 2 3 4 5", ' ', "1\0002\0003\0004\0005");
	test_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^', "1\0002a,\0003\000--h");
	test_split("Hello!", ' ', "Hello!");
	test_split("nonempty", '\0', "nonempty");
	test_itoa(12345, "12345");
	test_strmapi("abcde", toupper_im, "ABCDE");
	test_striteri("abcde", toupper_mu, "ABCDE");
	test_putchar_fd('a', 1);
	test_putstr_fd("12345", 1);
	test_putendl_fd("12345", 1);
	test_putnbr_fd(12345, 1);
	test_lstnew(strdup("12345"));
	// bonus
	root = ft_lstnew("one");
	test_lstadd_front(&root, ft_lstnew("zero"));
	test_lstsize(root, 2);
	test_lstlast(root);
	test_lstadd_back(&root, ft_lstnew("two"));
	test_lstdelone(root, ft_print_listc);
	free(root->next);
	free(root);
	root = ft_lstnew("one");
	ft_lstadd_front(&root, ft_lstnew("zero"));
	test_lstclear(&root, ft_print_listc);
	root = ft_lstnew("one");
	ft_lstadd_front(&root, ft_lstnew("zero"));
	test_lstmap(root, lst_toupper_im, free);
	test_lstiter(root, ft_print_listc);
}

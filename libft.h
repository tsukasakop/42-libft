#include <stdbool.h>
#include <stddef.h>
bool	ft_isspace(char c);
int	ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_print_memory(void *addr, unsigned int size);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int	ft_strlen(char *str);
int	ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strrchr(const char *s, int c);
int	ft_tolower(int c);
int	ft_toupper(int c);

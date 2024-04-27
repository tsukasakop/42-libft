#include <stdbool.h>
#include <stddef.h>

bool			ft_isspace(char c);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_print_memory(void *addr, unsigned int size);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(char *src);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);

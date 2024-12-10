#ifndef FT_HTBL_H
# define FT_HTBL_H
# include <stdint.h>
# define HTSIZE UINT8_MAX

typedef struct s_htnode	t_htnode;
typedef t_htnode		**t_htbl;

struct					s_htnode
{
	const char			*key;
	void				*val;
	t_htnode			*next;
};

t_htbl					htnew(void);
t_htbl					htadd(t_htbl ht, const char *key, void *val);
t_htbl					htget(t_htbl ht, const char *key);
void					htdelone(t_htbl ht, const char *key,
							void (*del)(void *));
void					htclear(t_htbl ht, void (*del)(void *));

#endif

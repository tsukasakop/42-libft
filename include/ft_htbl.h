#ifndef FT_HTBL_H
# define FT_HTBL_H
#include <stdint.h>

#define HTSIZE UINT8_MAX
typedef struct s_htnode t_htnode;

struct s_htnode
{
	char *key;
	void *val;
	t_htnode *next;
};

/*
struct s_htbl
{
	t_htnode *array[UINT8_MAX];
};

t_htbl  *htnew();
t_htbl  *htadd(t_htbl *ht, char *key, void *val);
void    *htget(t_htbl *ht);
void    htdelone(t_htbl *ht, char *key);
void    htclear(t_htbl *ht);
*/

#endif

#include <stdint.h>

typedef struct s_htnode t_htnode;
typedef struct s_htbl t_htbl;

struct s_htnode
{
	char *key
	void *val;
	t_node *next;
}

typedef struct s_htbl
{
	uint8_t array[UINT8_MAX];
}   t_htbl

t_htbl  *htnew();
t_htbl  *htadd(t_htbl *ht, char *key, void *val);
void    *htget(t_htbl *ht);
void    htdelone(t_htbl *ht, char *key);
void    htclear(t_htbl *ht);

#endif

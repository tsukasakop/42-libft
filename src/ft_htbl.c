#include "ft_htbl.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

extern t_htbl	htnew(void)
{
	return ((t_htbl)calloc(sizeof(t_htnode *), HTSIZE));
}

static uint8_t	hash(const char *key)
{
	if (!key || !key[0] || !key[1])
		return (0);
	return (key[0] * key[1] % 251);
}

static t_htnode	*htnodenew(const char *key, void *val)
{
	t_htnode	*p;

	p = (t_htnode *)ft_calloc(sizeof(t_htnode), 1);
	if (!p)
		return (NULL);
	p->key = key;
	p->val = val;
	return (p);
}

extern t_htbl	htadd(t_htbl ht, const char *key, void *val)
{
	uint8_t		h;
	t_htnode	*newi;
	t_htnode	*i;

	h = hash(key);
	newi = htnodenew(key, val);
	if (!newi)
		return (NULL);
	if (!ht[h])
	{
		ht[h] = newi;
		return (ht);
	}
	i = ht[h];
	while (i->next)
		i = i->next;
	i->next = newi;
	return (ht);
}

extern t_htbl	htget(t_htbl ht, const char *key)
{
	uint8_t		h;
	t_htnode	*i;

	h = hash(key);
	i = ht[h];
	while (i)
	{
		if (!ft_strcmp(i->key, key))
			return (i->val);
		i = i->next;
	}
	return (NULL);
}

static void	htnodedel(t_htnode *htnode, void (*del)(void *))
{
	if (del)
		del(htnode->val);
	free(htnode);
}

extern void	htdelone(t_htnode **ht, const char *key, void (*del)(void *))
{
	uint8_t		h;
	t_htnode	*i;
	t_htnode	**p;

	h = hash(key);
	p = &ht[h];
	i = ht[h];
	while (i)
	{
		if (!ft_strcmp(i->key, key))
		{
			*p = i->next;
			htnodedel(i, del);
			return ;
		}
		p = &((*p)->next);
		i = i->next;
	}
}

extern void	htclear(t_htnode **ht, void (*del)(void *))
{
	uint8_t		h;
	t_htnode	*i;
	t_htnode	*tmp;

	h = 0;
	while (h < HTSIZE)
	{
		i = ht[h];
		while (i)
		{
			tmp = i->next;
			htnodedel(i, del);
			i = tmp;
		}
		h++;
	}
	free(ht);
}

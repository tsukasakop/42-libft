#include <stdint.h>
#include "ft_htbl.h"
#include <stdlib.h>
#include <string.h>

t_htnode	**htnew()
{
	return (t_htnode **)calloc(sizeof(t_htnode *), HTSIZE);
}

uint8_t hash(char *key)
{
	if(!key || !key[0] || !key[1])
		return 0;
	return (key[0] * key[1] % 251);
}

t_htnode *htnodenew(char *key, void *val)
{
	t_htnode *p; p = (t_htnode *)calloc(sizeof(t_htnode), 1);
	if(!p)
		return NULL;
	p->key = key;
	p->val = val;
	return p;
}

t_htnode **htadd(t_htnode **ht, char *key, void *val)
{
	uint8_t h;
	t_htnode *newi;
	t_htnode *i;

	h = hash(key);
	newi = htnodenew(key, val);
	if(!newi)
		return NULL;
	if(!ht[h])
	{
		ht[h] = newi;
		return ht;
	}
	i = ht[h];
	while(i->next)
		i = i->next;
	i->next = newi;
	return ht;
}

void	*htget(t_htnode **ht, char *key)
{
	uint8_t h;
	t_htnode *i;

	h = hash(key);
	i = ht[h];
	while(i)
	{
		if(!strcmp(i->key, key))
			return i->val;
		i = i->next;
	}
	return NULL;
}

void	htnodedel(t_htnode *htnode, void (*del)(void *))
{
	if(del)
		del(htnode->val);
	free(htnode);
}

void    htdelone(t_htnode **ht, char *key, void (*del)(void *))
{
	uint8_t h;
	t_htnode *i;
	t_htnode **p;

	h = hash(key);
	p = &ht[h];
	i = ht[h];
	while (i)
	{
		if (!strcmp(i->key, key))
		{
			*p = i->next;
			htnodedel(i, del);
			return;
		}
		p = &((*p)->next);
		i = i->next;
	}
}

void    htclear(t_htnode **ht, void (*del)(void *))
{
	uint8_t h;
	t_htnode *i;
	t_htnode *tmp;

	h = 0; 
	while (h < HTSIZE)
	{
		i = ht[h];
		while(i)
		{
			tmp = i->next;
			htnodedel(i, del);
			i = tmp;
		}
		h++;
	}
	free(ht);
}

int main()
{
	t_htnode **ht = htnew();
	htadd(ht, "aiueo", (void *)0x42);
	htadd(ht, "aiueokaki", (void *)0x142);
	void *a;
	a = htget(ht, "aiueokaki");
	a = htget(ht, "aiueo");
	a = htget(ht, "aiaa");
	a = htget(ht, "a");
	/*
	htdelone(ht, "a", NULL);
	htdelone(ht, "aiaa", NULL);
	htdelone(ht, "aiueo", NULL);
	htdelone(ht, "aiueokaki", NULL);
	*/
//	htclear(ht, NULL);
	system("leaks a.out");
}

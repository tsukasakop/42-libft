#ifndef FT_MEMORY_H
# define FT_MEMOTY_H
typedef struct s_mc
{
	
}	t_mc
void *ft_init_mc();
int ft_mcadd(void *ptr);
int ft_mcdel(void *ptr);
void *ft_mcmalloc(size_t size)
void *ft_mccalloc(size_t cnt, size_t size);
void ft_mcfree(void *ptr);
void ft_end_mc();

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:16:02 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/19 15:34:51 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <stdlib.h>

#define _MEM_STORE_MAX 256
struct					s__blocked_node
{
	void				*_p[_MEM_STORE_MAX];
	size_t				_cur;
	t_node				*_next;
};

typedef struct s__blocked node	t_memory_manager;

t_memory_manager		*ft_mmnew();
int						ft_mmadd(t_memory_manager *mm, void *ptr);
void					*ft_mmmalloc(t_memory_manager *mm, size_t size);
void					*ft_mmcalloc(t_memory_manager *mm, size_t c, size_t sz);
void					ft_mmfree(t_memory_manager *mm);

t_memory_manager		*ft_g_mmget();
int						ft_g_mmadd(void *ptr);
void					*ft_g_mmmalloc(size_t size);
void					*ft_g_mmcalloc(size_t cnt, size_t size);
void					ft_g_mmfree(void);

#endif

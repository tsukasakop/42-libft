/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:16:02 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/11 14:17:07 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <stdlib.h>

typedef struct s_node	t_node;

struct					s_node
{
	void				*p;
	t_node				*next;
};

int						ft_mmadd(void *ptr);
void					*ft_mmmalloc(size_t size);
void					*ft_mmcalloc(size_t cnt, size_t size);
void					ft_mmfree(void);

#endif

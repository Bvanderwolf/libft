/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:48:42 by bvan-der          #+#    #+#             */
/*   Updated: 2022/10/18 12:56:31 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;
	char	chr;

	i = 0;
	p = 0;
	chr = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			p = ((char *)(&s[i]));
		i++;
	}
	if (chr == '\0')
		p = ((char *)(&s[i]));
	return (p);
}

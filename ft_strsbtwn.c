/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsbtwn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:57:46 by bvan-der          #+#    #+#             */
/*   Updated: 2022/11/20 10:18:01 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// test cases: ("axcaycazc", 'a', 'c')		-> ["x","y","z"] (happy)
// test cases: ("axcaycaz", 'a', 'c')		-> ["x", "y"] (happy)
// test cases: ("xcaycazc", 'a', 'c')		-> ["y", "z"] (happy)
// test cases: ("axcaycazc", 'a', 'p')		-> [] (unhappy)
// test cases: ("axcaycazc", 'p', 'c') 		-> [] (unhappy)
// test cases: ("axcaycazc", 'g', 'p') 		-> [] (unhappy)
// test cases: ("axacayacazaac", 'a', 'c')	-> ["xa", "ya", "zaa", "a"] (happy)
// test cases: ("ac", 'a', 'c') 			-> [] (unhappy)
// test cases: ("a", 'a', 'c') 				-> [] (unhappy)
// test cases: ("c", 'a', 'c') 				-> [] (unhappy)
// test cases: ("", 'a', 'c')				-> [] (unhappy)
// test cases: (NULL, 'g', 'p') 			-> Segfault (angry)

static int	count_strs_between(const char *str, char open, char close)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == open)
		{
			j = i + 1;
			while (str[j] != '\0' && str[j] != close)
				j++;
			if (str[j] == close && (i + 1) != j)
				count++;
		}
		i++;
	}
	return (count);
}

static int	set_next_substr(const char *str, char close, char **substr)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != close)
		i++;
	if (str[i] != close || i == 0)
		return (0);
	*substr = ft_substr(str, 0, i);
	return (1);
}

static char	**free_substrs(char **substrs)
{
	int	i;

	i = 0;
	while (substrs[i] != NULL)
	{
		free(substrs[i]);
		i++;
	}
	free(substrs);
	return (NULL);
}

char	**ft_strsbtwn(const char *str, char open, char close)
{
	char	**substrs;
	int		len;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	len = count_strs_between(str, open, close);
	substrs = (char **)malloc((len + 1) * sizeof(char *));
	if (substrs == NULL)
		return (NULL);
	while (str[j] != '\0')
	{
		if (str[j] == open)
		{
			if (set_next_substr(&str[j + 1], close, &substrs[i]))
				i++;
			if (substrs[i] == NULL)
				return (free_substrs(substrs));
		}
		j++;
	}
	substrs[i] = NULL;
	return (substrs);
}

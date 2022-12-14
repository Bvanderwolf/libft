/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsbtwn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-der <bvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:57:46 by bvan-der          #+#    #+#             */
/*   Updated: 2022/11/22 20:26:46 by bvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// test case: ("axcaycazc", 'a', 'c')		-> ["x","y","z"] (happy)
// test case: ("axcaycaz", 'a', 'c')		-> ["x", "y"] (happy)
// test case: ("xcaycazc", 'a', 'c')		-> ["y", "z"] (happy)
// test case: ("axcaycazc", 'a', 'p')		-> [] (unhappy)
// test case: ("axcaycazc", 'p', 'c') 		-> [] (unhappy)
// test case: ("axcaycazc", 'g', 'p') 		-> [] (unhappy)
// test case: ("axacayacazaac", 'a', 'c')	-> ["xa", "ya", "zaa", "a"] (happy)
// test case: ("ac", 'a', 'c') 				-> [] (unhappy)
// test case: ("a", 'a', 'c') 				-> [] (unhappy)
// test case: ("c", 'a', 'c') 				-> [] (unhappy)
// test case: ("", 'a', 'c')				-> [] (unhappy)
// test case: (NULL, 'g', 'p') 			-> Segfault (angry)

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

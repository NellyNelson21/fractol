/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelson <nnelson@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:13:14 by nnelson           #+#    #+#             */
/*   Updated: 2022/03/14 21:12:55 by nnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	substr_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len < ft_strlen(s + start))
		substr_len = len;
	else
		substr_len = ft_strlen(s + start);
	substr = malloc(substr_len + 1);
	if (!s || substr == NULL)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < substr_len)
		{
			substr[j] = s[i];
			j++;
		}
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

static void	*ft_free(char **str, int size)
{
	while (size--)
		free(str[size]);
	free(str);
	return (NULL);
}

int	ft_amount_of_words(char const *s, char c)
{
	int	amount_of_words;
	int	i;

	amount_of_words = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
			amount_of_words++;
		i++;
	}
	return (amount_of_words);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted_str;
	int		word;
	int		i;
	int		j;

	i = 0;
	word = 0;
	splitted_str = (char **)malloc(sizeof(char *)
			* ft_amount_of_words(s, c) + 1);
	splitted_str[word] = 0;
	while (word < ft_amount_of_words(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		splitted_str[word++] = ft_substr(s, i, j);
		if (splitted_str[word - 1] == NULL)
			return (ft_free(splitted_str, word - 1));
		i += j;
	}
	splitted_str[word] = 0;
	return (splitted_str);
}

double	ft_atod(const char *str)
{
	char	**double_number;
	double	res;
	int		i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.'
			&& str[i] != '+' && str[i] != '-')
			exit(-1);
		i++;
	}
	i = 0;
	double_number = ft_split(str, '.');
	if (double_number[1])
		res = ft_atoi(double_number[0])
			+ (ft_atoi(double_number[1])
				/ pow(10, ft_strlen(double_number[1])));
	else
		res = ft_atoi(double_number[0]);
	while (double_number[i])
		free(double_number[i++]);
	free(double_number);
	return (res);
}

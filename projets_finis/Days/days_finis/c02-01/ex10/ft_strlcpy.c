/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:15:11 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/26 15:58:17 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//strlcpy (char * dst, const char * src, size_t siz)
//       Copy a string. Copy src to string dst of size siz. At most siz-1
//       characters will be copied. Always NULL terminates (unless siz == 0).
//
//       Returns
//           The strlcpy() function returns strlen(src). If retval >= siz,
//          truncation occurred.
//
//       Copy src to string dst of size siz. At most siz-1 characters will be
//       copied. Always NULL terminates (unless siz == 0).
//
//       Returns
//           The strlcpy() function returns strlen(src). If retval >= siz,
//           truncation occurred.

/*
#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int main()
{
  char str[] = "tgsgery";
  char strDest[] = "";
  int r = ft_strlcpy(strDest, str, 4);
    
  
  printf("%s\n", strDest);
  printf("%d", r);
}
*/
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (src[count])
	{
		count++;
	}
	if (!src)
		return (0);
	while (src[i] && i < size -1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}

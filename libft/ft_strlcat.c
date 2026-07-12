#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	src_len;
	size_t	dstlen;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dsize <= dstlen)
		return (dsize + src_len);
	i = dstlen;
	j = 0;
	while (src[j] != '\0' && i < dsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dstlen + src_len);
}

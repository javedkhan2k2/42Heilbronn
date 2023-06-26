#include <stdio.h>
#include <stdlib.h>

char	*skip_spaces(char *str)
{
	while(*str == 32)
		str++;
	return str;
}

char *find_int_index(char *str, int *sign)
{
	*sign = 0;
	while(*str)
	{
		if(*str == '+')
			str++;
		else if(*str == '-')
		{
			str++;
			*sign = *sign + 1;
		}
		else if(*str >= 48 && *str <= 57)
		{
			if(*sign % 2 == 0)
				*sign = 1;
			else
				*sign = -1;
			return str;
		}
		else
			return NULL;
	}
	return NULL;
}

int convert_int(char *index, int sign)
{
	int count;
	int result;
	int multiplier;

	count = 0;
	multiplier = 1;
	while(*index && (*index >= 48 && *index <= 57))
	{
		count++;
		index++;
	}
	//index--;
	//count--;
	//result = *index-48;
	result = 0;
	while(count-- > 0)
	{
		index--;
		result += (*index -48)* multiplier;
		multiplier *= 10;
	}


	result *= sign;
	return result;
}

int	ft_atoi(char *str)
{
	str = skip_spaces(str);
	int sign;
	int *sptr;
	char *index;

	sptr = &sign;

	index = find_int_index(str, sptr);


	if(index)
	{
		return convert_int(index, sign);
	}

	return 0;
}

int main(void)
{
	const char str[] = "1234ab567";
	printf("Str:%s\n", str);
	int result = ft_atoi(str);
	printf("Str:%s\n", str);
	int res2 = atoi(str);
	printf("Result: %d\n", result);
	printf("Result2: %d\n", res2);
	return 0;
}

int ft_atoi(char *str)
{
	int i;
	int sign;
	int counter;

	i=0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		else;
			break;
	}
	while(str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if(str[i] == '-')
				sign++;
			i++;
		}
		else
			break;
	}
	while (str[i] != '\0')
	{
		if (str[i] <= '9' && str[i] >= '0')
			{
				i++;
				int a = str[i] - 48;
			}
		else;
			break;
	}
	if (sign % 2 == 1)
		
}
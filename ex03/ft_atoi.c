int ft_atoi(char *str)
{
	int i;
	int sign;
	int a;

	a = 0;
	i = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '	')
		{
			i++;
			continue;
		}
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
			continue;
		}
		else
			break;
	}
	while (str[i] != '\0')
	{
		if (str[i] <= '9' && str[i] >= '0')
			{
				a = (a * 10) + (str[i]-48);
				i++;
				continue;
			}
		else;
			break;
	}
	if (sign % 2 == 1)
		return (-a);
	else 
		return a;
		
}

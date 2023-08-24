// #include "main.h"

// /**
//  * get_flag - turns on flags if _printf finds
//  * a flag modifier in the format string
//  * @s: character that holds the flag specifier
//  * @f: pointer to the struct flags in which we turn the flags on
//  *
//  * Return: 1 if a flag has been turned on, 0 otherwise
//  */
// int get_flag(char s, flags_t *f)
// {
// 	int i = 0;

// 	switch (s)
// 	{
// 		case '+':
// 			f->plus = 1;
// 			i = 1;
// 			break;
// 		case ' ':
// 			f->space = 1;
// 			i = 1;
// 			break;
// 		case '#':
// 			f->hash = 1;
// 			i = 1;
// 			break;
// 	}

// 	return (i);
// }



#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
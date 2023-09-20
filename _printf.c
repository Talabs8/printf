#include "main.h"

/**
 * _printf - The print function
 * @format: format.
 * Return: print_char
 */
int _printf(const char *format, ...)
{
	int print_char = 0;
	va_list lists;

	if (format == NULL)
		return (-1);

	va_start(lists, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			print_char++;
		}
		else
		{
			format++;

			if (*format == '\0')
		break;
			if (*format == '%')
			{
				write(1, format, 1);
				print_char++;
			}
			else if (*format == 'c')
			{

				char c = va_arg(lists, int);
			write(1, &c, 1);
			print_char++;
			}
			else if (*format == 's')
			{
				char *string = va_arg(lists, char*);
				int str_len = 0;

				while (string[str_len] != '\0')
					str_len++;
				write(1, string, str_len);
				print_char += str_len;
			}
				else if (*format == 'i' || *format == 'd')
				{
					int num = va_arg(lists, int);
					char buffer[12];
					int length = snprintf(buffer, sizeof(buffer), "%d", num);

					write(1, buffer, length);
					print_char += length;
				}
		}
		format++;
	}
	va_end(lists);
	return (print_char);
}

int main()
{
	if (isatty(STDIN_FILENO))
    write(STDOUT_FILENO, "$ ", 2);
	return (0);
}
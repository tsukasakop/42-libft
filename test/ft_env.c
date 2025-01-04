//usr/bin/cc $0 -L. -Iinclude -lft -o a.out && ./a.out; exit;

#include <ft_stdio.h>
#include <ft_stdlib.h>
int main(int argc, char *argv[], char *envp[])
{
	ft_initenv(envp);
	ft_printf("%s\n", ft_getenv("PATH"));
	ft_exit(0);
}

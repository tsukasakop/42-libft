//usr/bin/cc $0 -L. -I. -lftprintf -D USE_STD_PRINTF -o std.out || exit;
//usr/bin/cc $0 -L. -I. -lftprintf -o ft.out || exit;
//$PWD/std.out > std.txt; echo "$?" > std.ret;
//$PWD/ft.out > ft.txt; echo "$?" > ft.ret;
//usr/bin/echo "# Check output:"
//usr/bin/diff ft.txt std.txt && echo " - No difference found";
//usr/bin/echo "# Check return value:"
//usr/bin/diff ft.ret std.ret && echo " - No difference found";
//usr/bin/echo "# Content:"
//usr/bin/echo " - printf returns: $(cat std.ret)"
//usr/bin/echo '```'
//usr/bin/cat std.txt
//usr/bin/echo '```'
//usr/bin/echo " - ft_printf returns: $(cat ft.ret)"
//usr/bin/echo '```'
//usr/bin/cat ft.txt
//usr/bin/echo '```'
//usr/bin/echo -n; exit;
//usr/bin/cc $0 -O0 -g -fsanitize=address -Iinclude -L. -lftprintf -o ./a.out && ./a.out > /tmp/printf.txt; exit
//usr/bin/watch -n 1 "vmstat -S M -s | grep memory; echo; ls -l /tmp/*printf*.txt"


#ifdef USE_STD_PRINTF
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#include "ft_printf.h"
#define PRINTF(...) ft_printf(__VA_ARGS__)
#endif

int main()
{
	char a = 'a';
	
	return PRINTF("aa%c%s%p%d%i%u%x%%");
}

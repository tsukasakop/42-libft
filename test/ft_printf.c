//usr/bin/cc $0 -O0 -g -fsanitize=address -Iinclude -L. -lftprintf -o ./a.out && ./a.out > /tmp/printf.txt; exit
//usr/bin/watch -n 1 "vmstat -S M -s | grep memory; echo; ls -l /tmp/*printf*.txt"

# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

void test(size_t s)
{
	fprintf(stderr, "trying to print size %lu (%d as int).\n", s, (int)s);
	char *p = malloc(s+1);
	fprintf(stderr, " - malloc done.\n");
	memset(p, '*', s);
	fprintf(stderr, " - memset done.\n");
	p[s] = 0;
	int ret;
	//*
       	//ret = printf("%2147483649saaa", p);
       	ret = printf("%.3s", p);
	fflush(stdin);
	fprintf(stderr, " - std returns '%d'.\n", ret);
	/*/
       	ret = ft_printf(p);
	fprintf(stderr, " - ft returns '%d'.\n", ret);
	//*/
	free(p);
}

int main()
{
	//test(0x7ffffffd); //INT_MAX - 1; print all, ret 0x7ffffffe
	test(0x7ffffffe); //INT_MAX - 1; print all, ret 0x7ffffffe
	//test(0x7fffffff); // INT_MAX; SIGABORT
	//test(0x80000000); //INT_MAX + 1; SIGABORT
	//test(0x80000001); //INT_MAX + 2; SIGABORT
	//test(0x100000000); //(INT_MAX + 1) * 2; print all, ret -1
	//test(0x100000001); //(INT_MAX + 1) * 2 + 1; print all, ret -1
	//test(0x200000000); //8GiB, under max usable memory; print all, ret -1
	//test((size_t)16 << 30); //16GiB, over max usable memory; killed on memset;
	//test(((size_t)32 << 30); //32GiB, over max usable memory; killed on memset;
			   //vmstat -s | grep "free memory"
	//test(0x10000000000 - 0x1001); //malloc error: allocator is out of memory
	//test(0x10000000000 - 0x1000); //malloc error: exceeds maximum supported size
	//test(((size_t)1 << 63) - 1); //malloc error: exceeds maximum supported size
	//test(-2); //malloc error: exceeds maximum supported size
}

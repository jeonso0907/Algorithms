# Sooyoung Jeon
# Algorithms Makefile

qs: quick_sort.o
	gcc -g -o $@ $^

ms: merge_sort.o
	gcc -g -o $@ $^

quick_sort.o: quick_sort.c 
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

merge_sort.o: merge_sort.c
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

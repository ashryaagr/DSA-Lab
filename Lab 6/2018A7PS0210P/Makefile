# Write a Makefile with targets compRecMS, compIterMS, runRecMS, runIterMS, and
# compare for compiling code for recursive MergeSort, compiling code for iterative
# MergeSort, running Recursive MergeSort, running Iterative MergeSort and
# comparing the two procedures respectively.

compRecMS: merge.c recMergeSort.c merge.h mergeSort.h
	gcc -c recMergeSort.c merge.c
	gcc -o rec recMergeSort.o merge.o

compIterMS: merge.c itrMergeSort.c merge.h mergeSort.h
	gcc -c itrMergeSort.c merge.c
	gcc -o itr itrMergeSort.o merge.o

runRecMS: compRecMS
	./rec $(filename) < $(filename)

runIterMS: compIterMS
	./itr $(filename) < $(filename)

compare: runRecMS runIterMS

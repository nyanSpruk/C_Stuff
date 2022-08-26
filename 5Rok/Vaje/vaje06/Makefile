
# Before running make:
#     export name=<name_of_source_C_file>
#
# Compile:
#     make
#
# Test:
#     make test [optional parameters]
#
#     Optional parameters:
#         P: range of test cases to be considered (e.g., 3-5 or 7 or 2- or -6
#            or -; default = -)
#
#     Examples:
#         make test
#         make test P=4-7
#         make test P=6-

CC = cc
CFLAGS = -std=c99 -pedantic -Wall
LIBS = -lm

P = '-'

SHELL = /bin/bash
OK_STRING=\033[1;32mOK\033[0;38m
FAILED_STRING=\033[1;31mfailed\033[0;38m

${name} : ${name}.c
	@echo "=== COMPILING: ==="
	${CC} ${CFLAGS} -o $@ $< ${LIBS}

test : ${name}
	@echo "=== TESTING: ==="; \
	singleTestFile=$$(ls -1 test*.out | head -1); \
	\
	testNumberLength=$$(( $${#singleTestFile} - 8 )); \
	cutParameter=$$((5 + testNumberLength - 1)); \
	nTests=$$(ls -1 test*.out | cut -c5-$$cutParameter | sort | tail -1); \
	firstTest=$$(echo $$P | cut -d'-' -f1); \
	lastTest=$$(echo $$P | cut -d'-' -f2); \
	if [[ -z $$firstTest ]]; then \
		tempA=$$(ls -1 test*.out | head -1); \
		tempB=$${tempA##test}; \
		firstTest=$${tempB%%.out}; \
	fi; \
	if [[ -z $$lastTest ]]; then \
		tempA=$$(ls -1 test*.out | tail -1); \
		tempB=$${tempA##test}; \
		lastTest=$${tempB%%.out}; \
	fi; \
	\
	nPassedTests=0; \
	nConsideredTests=0; \
	\
	trap exit SIGINT; \
	\
	${CC} ${CFLAGS} -c ${name}.c -Dmain=main2; \
	\
	for i0 in $$(jot - $$firstTest $$lastTest); do \
		i=$$(printf %0$${testNumberLength}d $$i0); \
		${CC} ${CFLAGS} -c -D__main__=main test$$i.c; \
		${CC} -o test$$i test$$i.o ${name}.o ${LIBS}; \
		rm -f test$$i.o; \
        ./test$$i > test$$i.res; \
        diff test$$i.res test$$i.out > test$$i.diff; \
        result=$$?; \
        if [[ $$result == 0 ]]; then \
            echo -e "test$$i -- ${OK_STRING}"; \
            nPassedTests=$$((nPassedTests + 1)); \
        else \
            echo -e "test$$i -- ${FAILED_STRING}"; \
        fi; \
		nConsideredTests=$$((nConsideredTests + 1)); \
	done; \
	rm -f ${name}.o; \
	echo "Result: $$nPassedTests / $$nConsideredTests"

clean :
	rm -fr ${name} test?? test*.res test*.diff *.o

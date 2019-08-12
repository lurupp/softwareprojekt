#include "stdio.h"

int length(char* s) {
	int n = 0;
	while (*s != '\0') {
		n++;
		s++;
	}

	return n;
}

typedef enum {
	OK,
	FAIL
} Test;



char* extract(char* input) {
	char* ret = input;
	for (int i = 0; i < length(input); i++) {
		if (input[i] == ':' && input[i + 1] == ':') {
			ret = &input[i + 2];
		}
	}
	return ret;
}

void extract2(char* input, char** output) {
	output = *extract(input);
}

Test testExtract(char* input, char* expected) {
	char* extracted = extract(input);
	for (int j = 0; j <= length(expected); j++) {
		if (extracted[j] != expected[j]) {
			return FAIL;
		}
	}
	printf("\n");
	printf("input: ");
	printf(input);
	printf("\n");
	printf("expected: ");
	printf(expected);
	printf("\n");
	printf("extracted: ");
	printf(extracted);
	printf("\n");
	return OK;
}




typedef struct {
	char* input;
	char* expected;
} TestCase;


void runTests(int no, TestCase test[]) {
	Test t;
	int i;

	for (i = 0; i < no; i++) {
		printf("Test %d: ", i);
		t = testExtract(test[i].input, test[i].expected);
		if (OK == t)
			printf("OK \n");
		if (FAIL == t)
			printf("FAIL \n");
	}
}


int main() {
	const int testNo = 9;
	TestCase tests[9] = {
		 {"", ""},
		 {"Hal::lo", "lo"},
		 {"Hal::lo", "lo"},
		 {"Hal::lo", "lo"},
		 {"aa::wwee", "wwee"},
		 {"dfa::abba", "abba"},
		 {"asd::lo", "lo"},
		 {"all::o", "o"},
		 {"1::123::11", "11"}
	};

	runTests(testNo, tests);

}
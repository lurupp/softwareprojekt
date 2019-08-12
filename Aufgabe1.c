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
	*output = extract(input);
	printf("\ntestExtract2");
	//printf("\noutput: %d", **output);
	//printf("\noutput: %c", **output);
	}

Test testExtract2(char* input, char* expected) {
	char* extracted;
	extract2(input, &extracted);
	for (int i = 0; i <= length(expected); i++) {
		if (extracted[i] != expected[i]) {
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
	//printf("output: %d", **output);
	//printf(**output);
	printf("\n");

	
	return OK;
	printf("\n\n\n");
}

Test testExtract(char* input, char* expected) {
	char* extracted = extract(input);
	for (int j = 0; j <= length(expected); j++) {
		if (extracted[j] != expected[j]) {
			return FAIL;
		}
	} 
	printf("\nExtract:");
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
	printf("\n\n\n");
}



typedef struct {
	char* input;
	char* expected;
} TestCase;


void runTests(int no, TestCase test[]) {
	Test t;
	Test t2;
	int i;

	for (i = 0; i < no; i++) {
		printf("Test %d: ", i);
		t = testExtract(test[i].input, test[i].expected);
		if (OK == t)
			printf("OK \n");
		if (FAIL == t)
			printf("FAIL \n");
	}

	for (i = 0; i < no; i++) {
		printf("Test %d: ", i);
		t2 = testExtract2(test[i].input, test[i].expected);
		if (OK == t2)
			printf("OK \n");
		if (FAIL == t2)
			printf("FAIL \n");
	}
} 


int main() {
	const int testNo = 9;
	TestCase tests[9] = {
		 {"", ""},
		 {"Hall::o", "o"},
		 {"Hal::lo", "lo"},
		 {"Hal::lo", "lo"},
		 {"aa::wwee", "wwee"},
		 {"dfa::abba", "abba"},
		 {"asd::lo", "lo"},
		 {"all::o", "o"},
		 {"1::123:::11", "11"}
	};

	runTests(testNo, tests);
	return 0;
}
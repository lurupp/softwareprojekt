#include <stdio.h>
#include <stdlib.h>

int length(char* s) {
	int n = 0;
	while (*s != '\0') {
		n++;
		s++;
	}

	return n;
}
// Annahme: n ist > 0
void copy(char* input, int n, char* t) {
	int i = 0;
	while (i < n) {
		t[i] = input[i];
		i++;
	}
}

char* putBack(char* input, char c) {
	const int n = length(input);
	char* r = malloc(sizeof(char) * (n + 2));
	copy(input, n, r);
	r[n] = c;
	r[n + 1] = '\0';
	return r;
}

char* reverse(char* input) {
	int len = length(input);
	char* reversed = malloc((len + 1) * sizeof(char));
	reversed[len] = '\0';
	for (int i = 0; i < len; i++){
		reversed[i] = input[len - i - 1];
	}
	return reversed;
}

char* reverseRec(char* input) {
	if (*input != '\0') {
		char* val = reverseRec(input + 1);
		char* reversed = putBack(val, *input);
		free(val);
		return reversed;
	}
	char* empty = malloc(sizeof(char));
	empty[0] = '\0';
	return empty;
}

typedef enum {
	OK,
	FAIL
} Test;

Test testReverse(char* input, char* expected) {
	char* reversed = reverseRec(input);
	for (int j = 0; j <= length(expected); j++) {
		if (reversed[j] != expected[j]) {
			return FAIL;
		}
	}
	printf("input: %s\n", input);
	printf("expected: %s\n", expected);
	printf("reversed: %s\n", reversed);
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
			t = testReverse(test[i].input, test[i].expected);
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
			 {"Hallo", "aaallaH"},
			 {"lagerregal", "lagerregal"},
			 {"aaaabbbb", "bbbbaaaa"},
			 {"abc", "cba"},
			 {"otto", "otto"},
			 {"1234", "4321"},
			 {"aaaa1111", "1111aaaa"},
			 {"neben", "neben"}
		};
		runTests(testNo, tests);
	}
#include <stdio.h>
#include <gmp.h>
#include <assert.h>
#include "multiPi.h"

int main() {
	mpf_t n;
	int flag;
	/* 1. Initialize the number */
	mpf_init2(n, 100);
	mpf_set_ui(n,0);
	/* 2. Parse the input string as a base 10 number */
	flag = mpf_set_str(n,"8.9997979879869999994355545644653456345543443579869", 10);
	assert (flag == 0); /* If flag is not 0 then the operation failed */
	/* Print n */
	printf ("n = ");
	mpf_out_str(stdout, 10, 0, n);
	printf ("\n");

	return 0;
}

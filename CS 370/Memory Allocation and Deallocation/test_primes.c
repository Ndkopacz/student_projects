#include <stdlib.h>
#include <check.h>
#include "Primes.h"

// Define a test case function for the tester function
START_TEST(test_tester) {
    int input = 5;
    int expected = 6; // Assuming the tester function should return input + 1
    int result = tester(input);
    ck_assert_int_eq(result, expected);  // Check if the result is as expected
}
END_TEST

// Setup the test suite
Suite* prime_suite(void) {
    Suite *s = suite_create("Prime Testing Suite");

    // Core test case
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_tester);
    suite_add_tcase(s, tc_core);

    return s;
}

// Define the main function to run the test suite
int main(void) {
    int number_failed;
    Suite *s = prime_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
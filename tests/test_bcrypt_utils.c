#include "../include/bcrypt_utils.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <string.h>
#include <cmocka.h>

// Define setup and teardown functions if needed

// Set up any required resources before each test
static int setup(void **state)
{
  // Initialize resources, if needed, before each test
  return 0;
}

// Clean up any resources after each test
static int teardown(void **state)
{
  // Clean up resources, if needed, after each test
  return 0;
}

static void test_generate_salt(void **state)
{
  (void)state; // Unused parameter

  char salt[MAX_SALT_LENGTH];
  generate_salt(salt, MAX_SALT_LENGTH);

  // You can add assertions to check the generated salt, e.g., length and format
  assert_int_equal(MAX_SALT_LENGTH - 1, strlen(salt));
  // Add more assertions as needed
}

static void test_encrypt_string(void **state)
{
  (void)state; // Unused parameter

  char plainText[] = "MySecretPassword";
  char salt[MAX_SALT_LENGTH];
  generate_salt(salt, MAX_SALT_LENGTH);
  char hashed[MAX_STRING_LENGTH];

  // Encrypt the plaintext
  bool encryptionResult = encrypt_string(plainText, salt, hashed);
  assert_true(encryptionResult);

  // Add more encryption-related assertions as needed
}

static void test_verify_hash(void **state)
{
  (void)state; // Unused parameter

  char plainText[] = "MySecretPassword";
  char salt[MAX_SALT_LENGTH];
  generate_salt(salt, MAX_SALT_LENGTH);
  char hashed[MAX_STRING_LENGTH];

  // Encrypt the plaintext
  bool encryptionResult = encrypt_string(plainText, salt, hashed);
  assert_true(encryptionResult);

  // Verify the encrypted hash
  bool verificationResult = verify_hash(plainText, hashed, salt);
  assert_true(verificationResult);

  // Test with incorrect plaintext or salt
  bool verificationResultIncorrect = verify_hash("WrongPassword", hashed, salt);
  assert_false(verificationResultIncorrect);

  // Add more verification-related assertions as needed
}

int main(void)
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_generate_salt),
      cmocka_unit_test(test_encrypt_string),
      cmocka_unit_test(test_verify_hash),
  };

  return cmocka_run_group_tests(tests, setup, teardown);
}

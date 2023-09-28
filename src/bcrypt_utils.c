#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "../include/bcrypt_utils.h"

// Function to generate a random salt
void generate_salt(char salt[], size_t salt_size)
{
  const char charset[] = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  const int charset_size = sizeof(charset) - 1;

  srand((unsigned int)time(NULL));

  for (size_t i = 0; i < salt_size - 1; ++i)
  {
    salt[i] = charset[rand() % charset_size];
  }
  salt[salt_size - 1] = '\0'; // Null-terminate the salt
}

// Function to encrypt a string (bcrypt encryption goes here)
bool encrypt_string(const char *plainText, const char *salt, char hashed[])
{
  // Hash the plaintext password using bcrypt
  char *result = crypt(plainText, salt);

  if (result != NULL)
  {
    strcpy(hashed, result);
    return true;
  }
  else
  {
    perror("Crypt error");
    return false;
  }
}

// Function to verify a plaintext string against a bcrypt hash
bool verify_hash(const char *plainText, const char *bcrypt_hash, const char *salt)
{
  char expected_hash[MAX_STRING_LENGTH];

  if (encrypt_string(plainText, salt, expected_hash))
  {
    // Compare the expected hash with the provided bcrypt hash
    return (strcmp(expected_hash, bcrypt_hash) == 0);
  }
  else
  {
    return false;
  }
}

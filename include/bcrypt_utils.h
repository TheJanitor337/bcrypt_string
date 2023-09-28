#include <stdlib.h>
#include <stdbool.h>

#ifndef BCRYPT_UTILS_H
#define BCRYPT_UTILS_H

#define MAX_STRING_LENGTH 100
#define MAX_SALT_LENGTH 64

// Function prototypes
void generate_salt(char salt[], size_t salt_size);
bool encrypt_string(const char *plainText, const char *salt, char hashed[]);
bool verify_hash(const char *plainText, const char *bcrypt_hash, const char *salt);

#endif

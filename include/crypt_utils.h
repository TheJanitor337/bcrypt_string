/**
 * @file crypt_utils.h
 *
 * @brief Header file for crypt utility functions.
 */

#ifndef CRYPT_UTILS_H
#define CRYPT_UTILS_H

#include <stdbool.h>

/**
 * @brief Maximum length for strings.
 */
#define MAX_STRING_LENGTH 100

/**
 * @brief Maximum length for a salt string.
 */
#define MAX_SALT_LENGTH 64

/**
 * @brief Generates a random salt.
 *
 * This function generates a random salt using a character set and null-terminates it.
 *
 * @param salt The buffer to store the generated salt.
 * @param salt_size The size of the salt buffer.
 */
void generate_salt(char salt[], size_t salt_size);

/**
 * @brief Encrypts a string using crypt encryption.
 *
 * This function encrypts a plaintext string using crypt encryption and stores
 * the result in the provided buffer.
 *
 * @param plainText The plaintext string to encrypt.
 * @param salt The salt to use for encryption.
 * @param hashed The buffer to store the encrypted string.
 * @return true if encryption is successful, false otherwise.
 */
bool encrypt_string(const char *plainText, const char *salt, char hashed[]);

/**
 * @brief Verifies a plaintext string against a crypt hash.
 *
 * This function verifies whether a plaintext string matches a crypt hash
 * when using a provided salt.
 *
 * @param plainText The plaintext string to verify.
 * @param crypt_hash The crypt hash to compare with.
 * @param salt The salt used for encryption.
 * @return true if the plaintext matches the hash, false otherwise.
 */
bool verify_hash(const char *plainText, const char *crypt_hash, const char *salt);

#endif

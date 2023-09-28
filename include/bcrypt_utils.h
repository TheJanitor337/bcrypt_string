/**
 * @file bcrypt_utils.h
 *
 * @brief Header file for bcrypt utility functions.
 */

#ifndef BCRYPT_UTILS_H
#define BCRYPT_UTILS_H

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
 * @brief Encrypts a string using bcrypt encryption.
 *
 * This function encrypts a plaintext string using bcrypt encryption and stores
 * the result in the provided buffer.
 *
 * @param plainText The plaintext string to encrypt.
 * @param salt The salt to use for encryption.
 * @param hashed The buffer to store the encrypted string.
 * @return true if encryption is successful, false otherwise.
 */
bool encrypt_string(const char *plainText, const char *salt, char hashed[]);

/**
 * @brief Verifies a plaintext string against a bcrypt hash.
 *
 * This function verifies whether a plaintext string matches a bcrypt hash
 * when using a provided salt.
 *
 * @param plainText The plaintext string to verify.
 * @param bcrypt_hash The bcrypt hash to compare with.
 * @param salt The salt used for encryption.
 * @return true if the plaintext matches the hash, false otherwise.
 */
bool verify_hash(const char *plainText, const char *bcrypt_hash, const char *salt);

#endif

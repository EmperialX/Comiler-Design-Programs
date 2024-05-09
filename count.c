#include <stdio.h>
#include <stdbool.h>

// Define an enumeration for the different types of tokens
typedef enum {
    KEYWORD,
    CONSTANT,
    IDENTIFIER,
    BRACE,
    UNARY_OPERATOR,
    BINARY_OPERATOR,
    TOTAL_TYPES
} TokenType;

// Define a struct to hold the counts of each type of token
typedef struct {
    int counts[TOTAL_TYPES];
} TokenCounts;

/**
 * Increment the count for a specific type of token
 * @param counts A pointer to a TokenCounts struct
 * @param type The type of token to increment the count for
 */
void increment_count(TokenCounts* counts, TokenType type) {
    counts->counts[type]++;
}

/**
 * Print the counts of each type of token to a file
 * @param file A pointer to the file to print to
 * @param counts A pointer to a TokenCounts struct
 */
void print_counts(FILE* file, TokenCounts* counts) {
    fprintf(file, "Keywords: %d\n", counts->counts[KEYWORD]);
    fprintf(file, "Braces: %d\n", counts->counts[BRACE]);
    fprintf(file, "Unary Operators: %d\n", counts->counts[UNARY_OPERATOR]);
    fprintf(file, "Binary Operators: %d\n", counts->counts[BINARY_OPERATOR]);
    fprintf(file, "Constants: %d\n", counts->counts[CONSTANT]);
    fprintf(file, "Identifiers: %d\n", counts->counts[IDENTIFIER]);
}

int main() {
    // Initialize a TokenCounts struct
    TokenCounts counts = {0};

    // Open the output file
    FILE* outputFile = fopen("output.txt", "w");

    // Initialize a buffer to hold the current token
    char s1[100];
    int j = 0;

    // Assume that the following code is inside a loop that reads tokens from a file
    // and sets s1 to the current token and j to the length of the token
    s1[j] = '\0'; // Null-terminate the string

    // Check the type of the current token and increment the appropriate count
    if (is_keyword(s1)) {
        fprintf(outputFile, "%s is keyword\n", s1);
        increment_count(&counts, KEYWORD);
    } else if (is_constant(s1)) {
        fprintf(outputFile, "%s is constant\n", s1);
        increment_count(&counts, CONSTANT);
    } else {
        fprintf(outputFile, "%s is identifier\n", s1);
        increment_count(&counts, IDENTIFIER);
    }

    // Print the counts to the output file
    print_counts(outputFile, &counts);

    // Close the output file
    fclose(outputFile);

    return 0;
}

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE_PATH "products.txt"
#define MAX_LENGTH 40
#define LINE_BUFFER_SIZE 256

// Structure describing a single product
typedef struct {
    char name[MAX_LENGTH + 1];
    float price;
    char category[MAX_LENGTH + 1];
} Product;

// Function that handles and validates user input
int get_user_input(char *category, float *min_price, float *max_price) {
    printf("Insert a product category: ");
    if (scanf("%40s", category) != 1) {
        fprintf(stderr, "Error reading category\n");
        return 0;
    }

    printf("Insert a minimum price: ");
    if (scanf("%f", min_price) != 1 || *min_price < 0) {
        fprintf(stderr, "Invalid minimum price\n");
        return 0;
    }

    printf("Insert a maximum price: ");
    if (scanf("%f", max_price) != 1 || *max_price < 0) {
        fprintf(stderr, "Invalid maximum price\n");
        return 0;
    }

    // Validate price range
    if (*min_price > *max_price) {
        fprintf(stderr, "Warning: Swapped min/max prices\n");
        float temp = *min_price;
        *min_price = *max_price;
        *max_price = temp;
    }

    // Clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    return 1;
}

// Function that handles the file opening and validation
FILE *open_product_file(const char *path) {
    FILE *file = fopen(path, "r");
    if (!file) {
        perror("Error opening file");
    }
    return file;
}

// Function taht parses a line storing the content in a Product variable
// Divides the line into 3 arguments
int parse_product_line(const char *line, Product *product) {
    // Initialize the product structure
    memset(product, 0, sizeof(Product));

    // Parse and assign the line
    return sscanf(line, "%40s %f %40s",
                  product->name, &product->price, product->category) == 3;
}

// Searches for product matches in the input file
int product_matches_filter(const Product *product, const char *target_category,
                           float min_price, float max_price) {
    return strcasecmp(product->category, target_category) == 0 &&
           product->price >= min_price &&
           product->price <= max_price;
}

// When we find matches we print the product to the user
void print_product(const Product *product) {
    printf("%-40s %8.2f\n", product->name, product->price);
}

int main() {
    char user_category[MAX_LENGTH + 1];
    float min_price, max_price;

    // Return an error if somethig goes wrong woth the input
    if (!get_user_input(user_category, &min_price, &max_price)) {
        return 1;
    }

    // Try to open and validate the file
    FILE *file = open_product_file(INPUT_FILE_PATH);
    if (!file) return 1;

    char line[LINE_BUFFER_SIZE];
    while (fgets(line, sizeof(line), file)) {
        Product current_product;

        if (parse_product_line(line, &current_product)) {
            if (product_matches_filter(&current_product, user_category,
                                       min_price, max_price)) {
                print_product(&current_product);
            }
        }
    }

    fclose(file);
    return 0;
}

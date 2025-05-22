#include <stdio.h>
#include <string.h>

struct book {
    char title[100];
    char author[100];
    float price;
};

int main() {
    struct book berita;

    // Input details
    printf("Enter title: ");
    fgets(berita.title, sizeof(berita.title), stdin);
    berita.title[strcspn(berita.title, "\n")] = '\0';

    printf("Enter author: ");
    fgets(berita.author, sizeof(berita.author), stdin);
    berita.author[strcspn(berita.author, "\n")] = '\0';

    printf("Enter price: ");
    scanf("%f", &berita.price);
    while (getchar() != '\n');

    // Save to file
    FILE *fp = fopen("books.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "%s\n%s\n%.2f\n", berita.title, berita.author, berita.price);
    fclose(fp);

    // Read from file
    fp = fopen("books.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    struct book b2;
    fgets(b2.title, sizeof(b2.title), fp);
    b2.title[strcspn(b2.title, "\n")] = '\0';

    fgets(b2.author, sizeof(b2.author), fp);
    b2.author[strcspn(b2.author, "\n")] = '\0';

    fscanf(fp, "%f", &b2.price);
    fclose(fp);

    // Display details
    printf("\nBook Details:\n");
    printf("Title: %s\n", b2.title);
    printf("Author: %s\n", b2.author);
    printf("Price: %.2f\n", b2.price);

    return 0;
}
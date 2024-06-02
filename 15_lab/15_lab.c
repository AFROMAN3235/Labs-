#include <stdio.h>
#include <string.h>

typedef struct Route {
    char start_point[50];
    char end_point[50];
    int route_number;
} Route;

void addRoute(FILE *file_ptr) {
    Route new_route;

    printf("Enter the start point: ");
    scanf("%s", new_route.start_point);

    printf("Enter the end point: ");
    scanf("%s", new_route.end_point);

    printf("Enter the route number: ");
    scanf("%d", &new_route.route_number);

    fwrite(&new_route, sizeof(Route), 1, file_ptr);
    fseek(file_ptr, 0, SEEK_SET); // Reset file pointer position to the beginning
}

int main() {
    FILE *file_ptr;
    struct Route route;
    char input_point[50];
    int found = 0;

    file_ptr = fopen("Spravka.dat", "rb+");
    if (file_ptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    addRoute(file_ptr);

    printf("Enter the name of the point: ");
    scanf("%s", input_point);

    while (fread(&route, sizeof(struct Route), 1, file_ptr) == 1) {
        if (strcmp(route.start_point, input_point) == 0 || strcmp(route.end_point, input_point) == 0) {
            printf("Start point: %s\n", route.start_point);
            printf("End point: %s\n", route.end_point);
            printf("Route number: %d\n", route.route_number);
            found = 1;
        }
    }

    if (!found) {
        printf("No routes found for the specified point.\n");
    }

    fclose(file_ptr);
    return 0;
}

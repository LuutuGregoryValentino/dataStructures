
#include <stdio.h>
#include <string.h>

struct names
{
    char *name;
    int count;
} nameTab[] = {
    {"greg", 0},
    {"paul", 2}};

int totalNames = 2;

void addOccurrence(char *foundName)
{
    for (int i = 0; i < totalNames; i++)
    {
        if (strcmp(foundName, nameTab[i].name) == 0)
        {
            nameTab[i].count++;
            printf("Found %s! New Count: %d\n", foundName, nameTab[i].count);
            return;
        }
    }
    printf("Name %s not in our list", foundName);
}

int main(void) {
    printf("--- Starting Count ---\n");
    
    addOccurrence("greg");
    addOccurrence("greg");
    addOccurrence("paul");
    
    // Retrieving data manually to show it worked
    printf("\nFinal Results:\n");
    printf("Greg appeared %d times\n", nameTab[0].count);
    printf("Paul appeared %d times\n", nameTab[1].count);

    return 0; // Tells the OS "everything went fine"
}
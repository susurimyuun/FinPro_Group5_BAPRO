#include <stdio.h>
#include <string.h>

// STRUCT DEFINITIONS

typedef struct {

    int id;
    char name[50];        // country name
    char region[50];      // region
    int sdg_focus;

    // Core Stats
    int resources;
    int needs;
    int tech_level;
    int political_will;
    int economic_strength;
    int human_capital;
    int digital_readiness;
    int climate_vulnerability;

    // Bonus Variables
    int english_proficiency;
    int trade_openness;

    // Time Zone
    float timezone;

} score;


// DISPLAY FUNCTIONS
void printMethodList() {
    printf("\nMatching Method = \n");
    printf("1. Donor / NGO\n");
    printf("2. Tech Company\n");
    printf("3. Climate Activist\n");
    printf("4. Conservative Government\n");
    printf("5. Venture Capitalist\n");
}


// INPUT USER PROFILE
void inputMethodProfile(score *mp) {

    printf("\n===== INPUT MAIN DATA USER ======\n");

    printf("Input your country name: ");
    scanf(" %[^\n]", mp->name);

    printf("Input your region: ");
    scanf(" %[^\n]", mp->region);

    printf("English proficiency level (0-10): ");
    scanf("%d", &mp->english_proficiency);

    printf("Your timezone (example: 9.0): ");
    scanf("%f", &mp->timezone);

    printf("\n=== INPUT MATCHING SCORES ===\n");

    printf("Resources (0-10): ");
    scanf("%d", &mp->resources);

    printf("Needs (0-10): ");
    scanf("%d", &mp->needs);

    printf("Tech level (0-10): ");
    scanf("%d", &mp->tech_level);

    printf("Political will (0-10): ");
    scanf("%d", &mp->political_will);

    printf("Economic strength (0-10): ");
    scanf("%d", &mp->economic_strength);

    printf("Human capital (0-10): ");
    scanf("%d", &mp->human_capital);

    printf("Digital readiness (0-10): ");
    scanf("%d", &mp->digital_readiness);

    printf("Climate vulnerability (0-10): ");
    scanf("%d", &mp->climate_vulnerability);

    printf("Trade openness (0-10): ");
    scanf("%d", &mp->trade_openness);
}


// placeholder algorithm (u can modify)
void Donor_Execute(score user, score countries[], int n) {
    printf("\n=== Donor Matching Algorithm ===\n");
    printf("This is placeholder. Add formula later.\n");

    for (int i = 0; i < n; i++) {
        printf("%d. %s (%s)\n", countries[i].id, countries[i].name, countries[i].region);
    }
}


// MAIN PROGRAM
int main() {

    score currentUser;

    score Asian_Countries[22] = {
        {1, "Timor-Leste", "SE Asia", 1, 4,9,2,5,3,6,3,8, 3,2, 9.0},
        {2, "India", "South Asia", 2, 8,7,8,6,9,6,6,7, 7,5, 5.5},
        {3, "Thailand", "SE Asia", 3, 6,5,6,4,7,8,6,6, 4,7, 7.0},
        {4, "Cambodia", "SE Asia", 4, 3,8,3,3,4,6,4,7, 3,5, 7.0},
        {5, "Bangladesh", "South Asia", 5, 5,8,4,5,6,7,5,9, 5,4, 6.0},
        {6, "Tajikistan", "Central Asia", 6, 3,7,3,4,3,7,3,6, 2,3, 5.0},
        {7, "Indonesia", "SE Asia", 7, 7,6,5,4,9,7,5,6, 5,6, 7.0}, 
        {8, "Laos", "SE Asia", 7, 2,9,2,3,3,6,3,6, 2,3, 7.0},
        {9, "Philippines", "SE Asia", 8, 5,7,5,4,6,7,5,9, 9,6, 8.0},
        {10, "Malaysia", "SE Asia", 9, 7,4,7,6,7,8,7,5, 8,8, 8.0},
        {11, "Vietnam", "SE Asia", 9, 5,6,5,5,7,7,6,7, 5,8, 7.0},
        {12, "Nepal", "South Asia", 10, 3,8,3,4,3,6,4,8, 4,3, 5.8},
        {13, "South Korea", "East Asia", 11, 9,2,10,7,9,9,9,3, 6,9, 9.0},
        {14, "Brunei", "SE Asia", 12, 9,2,5,6,8,8,6,5, 7,6, 8.0},
        {15, "Maldives", "South Asia", 13, 5,9,4,6,5,7,5,10, 6,5, 5.0},
        {16, "Sri Lanka", "South Asia", 14, 4,7,5,5,4,8,5,7, 6,5, 5.5},
        {17, "Bhutan", "South Asia", 15, 4,4,3,8,4,7,4,6, 5,3, 6.0},
        {18, "Myanmar", "SE Asia", 16, 2,10,1,1,2,6,3,9, 3,1, 6.5},
        {19, "Singapore", "SE Asia", 17, 10,1,10,9,10,10,10,2, 10,10, 8.0},
        {20, "Japan", "East Asia", 9, 9,2,10,9,10,10,9,4, 4,8, 9.0},
        {21, "Kazakhstan", "Central Asia", 7, 7,4,5,5,6,7,6,5, 3,5, 5.0},
        {22, "Pakistan", "South Asia", 13, 3,9,4,3,4,4,4,9, 6,4, 5.0}
    };

    // Get user profile first
    inputMethodProfile(&currentUser);

    // Show method list + placeholder execute
    printMethodList();

    int choice;
    printf("\nChoose matching method: ");
    scanf("%d", &choice);

    if (choice == 1) {
        Donor_Execute(currentUser, Asian_Countries, 22);
    }

    printf("\nProgram finished.\n");
    return 0;
}

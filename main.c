#include <stdio.h>

// STRUCT DEFINITIONS
typedef struct {
    int id;
    char name[50];
    char region[50];
    int sdg_focus;

    int resources;
    int needs;
    int tech_level;
    int political_will;
    int economic_strength;
    int human_capital;
    int digital_readiness;
    int climate_vulnerability;

    int english_proficiency;
    int trade_openness;

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

// INPUT FUNCTION
void inputMethodProfile(score *mp) {
    printf("\n===== INPUT MAIN DATA USER ======\n");

    printf("Country name: ");
    scanf("%s", mp->name);

    printf("Region: ");
    scanf("%s", mp->region);

    printf("English proficiency (0-10): ");
    scanf("%d", &mp->english_proficiency);

    printf("Timezone (ex: 7.0): ");
    scanf("%f", &mp->timezone);

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

// MAIN
int main() {

    score Asian_Countries[22] = {
        {1, "Timor-Leste", "SE_Asia", 1, 4,9,2,5,3,6,3,8, 3,2, 9.0},
        {2, "India", "South_Asia", 2, 8,7,8,6,9,6,6,7, 7,5, 5.5},
        // ... add the others
    };

    score currentUser;

    inputMethodProfile(&currentUser);

    printf("\nInput received.\n");

    return 0;
}

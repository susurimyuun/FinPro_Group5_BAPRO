#include <stdio.h>
// STRUCT DEFINITIONS

// Identitas dasar (tidak ikut rumus, cuma info)
typedef struct {

    int id;
    const char name[50];
    const char region[50];
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
    int english_proficiency; // 0-10
    int trade_openness;      // 0-10
    
    // Time Zone
    float utc_offset;        // e.g., 7.0 for UTC+7, 5.5 for UTC+5:30
} User_Data;

// DISPLAY FUNCTIONS

void printMethodList() {
    printf("\nMatching Method = \n");
    printf("1. Donor / NGO\n");
    printf("2. Tech Company\n");
    printf("3. Climate Activist\n");
    printf("4. Conservative Government\n");
    printf("5. Venture Capitalist\n");
}



// Input metode + rating 0–10 for every category
void inputMethodProfile(MethodProfile *mp) {
    printf("\n=== INPUT MATCHING METHOD & SCORES ===\n");

    printf("\n=== INPUT MATCH PROFILE ===\n");

    printf("Country : ");
    scanf(" %39[^\n]", &currentUser.name);
    printMethodList();
    printf("Choose Matching Method (1-5) : ");
    scanf("%d", &mp->method);

    // validation
    while (mp->method < 1 || mp->method > 5) {
        printf("Invalid input. Choose 1-5 : ");
        scanf("%d", &mp->method);
    }

    printf("\nNow rate each dimension with a value from 0 to 10.\n");

    printf("Resources (0-10)             : ");
    scanf("%d", &mp->score.resources);
    while (mp->score.resources < 0 || mp->score.resources > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->score.resources);
    }

    printf("Needs (0-10)                 : ");
    scanf("%d", &mp->score.needs);
    while (mp->score.needs < 0 || mp->score.needs > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->score.needs);
    }

    printf("Tech Level (0-10)            : ");
    scanf("%d", &mp->score.techLevel);
    while (mp->score.techLevel < 0 || mp->score.techLevel > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->score.techLevel);
    }

    printf("Political Will (0-10)        : ");
    scanf("%d", &mp->score.politicalWill);
    while (mp->score.politicalWill < 0 || mp->score.politicalWill > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->score.politicalWill);
    }

    printf("Economic Strength (0-10)     : ");
    scanf("%d", &mp->score.economicStrength);
    while (mp->score.economicStrength < 0 || mp->score.economicStrength > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->score.economicStrength);
    }

    printf("Human Capital (0-10)         : ");
    scanf("%d", &mp->score.humanCapital);
    while (mp->score.humanCapital < 0 || mp->score.humanCapital > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->score.humanCapital);
    }

    printf("Digital Readiness (0-10)     : ");
    scanf("%d", &mp->score.digitalReadiness);
    while (mp->score.digitalReadiness < 0 || mp->score.digitalReadiness > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->score.digitalReadiness);
    }

    printf("Climate Vulnerability (0-10) : ");
    scanf("%d", &mp->score.climateVulnerability);
    while (mp->score.climateVulnerability < 0 || mp->score.climateVulnerability > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->score.climateVulnerability);
    }
    printf("Time Zone (ex: Jakarta 7) : ");
    scanf(" %19[^\n]", &mp->score.);
    
    printf("\nMethod & rating scores saved! \n");
}

void Donor_Execute(currentUser[], ){

}

// MAIN
// execute the program 

int main() {
    User_Data currentUser;
    User_Data Asian_Countries = {
        {1, "Timor-Leste", "SE Asia", 1, 4, 9, 2, 5, 3, 6, 3, 8,    3, 2,   9.0},
        {2, "India", "South Asia", 2, 8, 7, 8, 6, 9, 6, 6, 7,       7, 5,   5.5},
        {3, "Thailand", "SE Asia", 3, 6, 5, 6, 4, 7, 8, 6, 6,       4, 7,   7.0},
        {4, "Cambodia", "SE Asia", 4, 3, 8, 3, 3, 4, 6, 4, 7,       3, 5,   7.0},
        {5, "Bangladesh", "South Asia", 5, 5, 8, 4, 5, 6, 7, 5, 9,  5, 4,   6.0},
        {6, "Tajikistan", "Central Asia", 6, 3, 7, 3, 4, 3, 7, 3, 6, 2, 3,   5.0},
        {7, "Indonesia", "SE Asia", 7, 7, 6, 5, 4, 9, 7, 5, 6,      5, 6,   7.0}, // WIB
        {8, "Laos", "SE Asia", 7, 2, 9, 2, 3, 3, 6, 3, 6,           2, 3,   7.0},
        {9, "Philippines", "SE Asia", 8, 5, 7, 5, 4, 6, 7, 5, 9,    9, 6,   8.0},
        {10, "Malaysia", "SE Asia", 9, 7, 4, 7, 6, 7, 8, 7, 5,      8, 8,   8.0},
        {11, "Vietnam", "SE Asia", 9, 5, 6, 5, 5, 7, 7, 6, 7,       5, 8,   7.0},
        {12, "Nepal", "South Asia", 10, 3, 8, 3, 4, 3, 6, 4, 8,     4, 3,   5.8}, // UTC+5:45 approx
        {13, "South Korea", "East Asia", 11, 9, 2, 10, 7, 9, 9, 9, 3, 6, 9,   9.0},
        {14, "Brunei", "SE Asia", 12, 9, 2, 5, 6, 8, 8, 6, 5,       7, 6,   8.0},
        {15, "Maldives", "South Asia", 13, 5, 9, 4, 6, 5, 7, 5, 10, 6, 5,   5.0},
        {16, "Sri Lanka", "South Asia", 14, 4, 7, 5, 5, 4, 8, 5, 7, 6, 5,   5.5},
        {17, "Bhutan", "South Asia", 15, 4, 4, 3, 8, 4, 7, 4, 6,    5, 3,   6.0},
        {18, "Myanmar", "SE Asia", 16, 2, 10, 1, 1, 2, 6, 3, 9,     3, 1,   6.5},
        {19, "Singapore", "SE Asia", 17, 10, 1, 10, 9, 10, 10, 10, 2, 10, 10,  8.0},
        {20, "Japan", "East Asia", 9, 9, 2, 10, 9, 10, 10, 9, 4,    4, 8,   9.0},
        {21, "Kazakhstan", "Central Asia", 7, 7, 4, 5, 5, 6, 7, 6, 5, 3, 5,   5.0},
        {22, "Pakistan", "South Asia", 13, 3, 9, 4, 3, 4, 4, 4, 9,  6, 4,   5.0}}



    // after this we can apply the :
    // currentUser.methodProfile.method  -> pilih algoritma / method
    // currentUser.methodProfile.score   -> dibandingkan ke data negara (tabel Excel)
    // currentUser.match.region, timeZone, mainLanguage -> filter tambahan (bisa di gunakan hanya tampilan saja)
    // BESOK GUE MAU BUAT PRINTF RESULTNYA, tapi nanti aja tunggu programnya jadi YAKK

    return 0;
}

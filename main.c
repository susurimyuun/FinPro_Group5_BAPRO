#include <stdio.h>
// STRUCT DEFINITIONS

//-buat enum for sdg
typedef enum {
    DONOR = 1,
    COALITION,
    INVESTMENT,
    TECH_TRANSFER,
    NEXUS_PEACE
} Method;

typedef enum {
    SDG1 = 1, SDG2, SDG3, SDG4, SDG5, SDG6, SDG7, SDG8, SDG9,
    SDG10, SDG11, SDG12, SDG13, SDG14, SDG15, SDG16, SDG17
} SDG;

typedef union {
    int donor_sdg[4];
    int coalition_sdg[5];
    int investment_sdg[3];
    int tech_sdg[3];
    int nexus_sdg[3];
} SDGList;

// Identitas dasar (tidak ikut rumus, cuma info)
typedef struct {

    int id;
    char name[50]; //nama negara
    char region[50];
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
    float timezone;        // e.g., 7.0 for UTC+7, 5.5 for UTC+5:30
} score;

//-sdg databse
typedef struct {
    Method method;
    int sdgCount;
    int sdgList[6];
} MethodData;

MethodData database[] = {
    { DONOR,        4, {1, 2, 3, 4} },
    { COALITION,    5, {5, 6, 10, 11, 17} },
    { INVESTMENT,   3, {7, 8, 9} },
    { TECH_TRANSFER,3, {12, 13, 14} },
    { NEXUS_PEACE,  3, {15, 16, 17} }
};

//-pick method
Method pickMethod() {
    int m;
    printf("\n===== SDG METHOD MATCHING =====\n\n");
    printf("Choose collaboration method:\n");
    printf("1. Donor\n");
    printf("2. Coalition\n");
    printf("3. Investment\n");
    printf("4. Tech Transfer\n");
    printf("5. Nexus / Peace\n");
    printf("Input (1–5): ");

    scanf("%d", &m);

    while (m < 1 || m > 5) {
        printf("Invalid. Enter 1–5: ");
        scanf("%d", &m);
    }

    return (Method)m;
}


//-validation
int inputSDG(Method method) {
    int sdg;
    int valid = 0;
    MethodData data;

    for (int i = 0; i < 5; i++) {
        if (database[i].method == method) {
            data = database[i];
            break;
        }
    }

    printf("\nThis method matches SDGs: ");
    for (int i = 0; i < data.sdgCount; i++) {
        printf("%d ", data.sdgList[i]);
    }

    printf("\nEnter your SDG focus: ");
    scanf("%d", &sdg);

    while (!valid) {
        for (int i = 0; i < data.sdgCount; i++) {
            if (sdg == data.sdgList[i]) {
                valid = 1;
                break;
            }
        }
        if (!valid) {
            printf("Invalid SDG. Valid: ");
            for (int i = 0; i < data.sdgCount; i++) {
                printf("%d ", data.sdgList[i]);
            }
            printf("\nEnter again: ");
            scanf("%d", &sdg);
        }
    }

    return sdg;
}

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
void inputMethodProfile(score *mp) {
    printf("\n===== INPUT MAIN DATA USER ======\n");

    printf ("input your country name :  ");
    scanf("%s", mp->name);

    printf ("input your region : ");
    scanf("%s", mp->region);

    printf ("English proficiency level (0-10): ");
    scanf("%d", mp->english_proficiency);
    while (mp->english_proficiency < 0 || mp->english_proficiency > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->english_proficiency);
    }

    printf("Your country timezone (ex: 09:00 -> 9.0): ");
    scanf("%d", mp->timezone);

    printf("\n=== INPUT MATCHING METHOD & SCORES ===\n");

    printf("Resources (0-10)             : ");
    scanf("%d", &mp->resources);
    while (mp->resources < 0 || mp->resources > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->resources);
    }

    printf("Needs (0-10)                 : ");
    scanf("%d", &mp->needs);
    while (mp->needs < 0 || mp->needs > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->needs);
    }

    printf("Tech level (0-10)            : ");
    scanf("%d", &mp->tech_level);
    while (mp->tech_level < 0 || mp->tech_level > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->tech_level);
    }

    printf("Political will (0-10)        : ");
    scanf("%d", &mp->political_will);
    while (mp->political_will < 0 || mp->political_will > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->political_will);
    }

    printf("Economic strength (0-10)     : ");
    scanf("%d", &mp->economic_strength);
    while (mp->economic_strength < 0 || mp->economic_strength > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->economic_strength);
    }

    printf("Human capital (0-10)         : ");
    scanf("%d", &mp->human_capital);
    while (mp->human_capital < 0 || mp->human_capital > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->human_capital);
    }

    printf("Digital readiness (0-10)     : ");
    scanf("%d", &mp->digital_readiness);
    while (mp->digital_readiness < 0 || mp->digital_readiness > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->digital_readiness);
    }

    printf("Climate vulnerability (0-10) : ");
    scanf("%d", &mp->climate_vulnerability);
    while (mp->climate_vulnerability < 0 || mp->climate_vulnerability > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->climate_vulnerability);
    }

    printf ("English proficiency level (0-10): ");
    scanf("%d", mp->english_proficiency);
    while (mp->english_proficiency < 0 || mp->english_proficiency > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->english_proficiency);
    }


    printf ("Trade opennes for distance point plus one country to another (0-10): ");
    scanf("%d", mp->trade_openness);
     while (mp->trade_openness < 0 || mp->trade_openness > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->trade_openness);
    }
    
}

void Donor_Execute( ){

}

// MAIN
// execute the program 

int main() {
    score currentUser;

    //pilih metode 1-5
    Method chosenMethod = pickMethod();

    //pilih sdg sesuai
    int chosenSDG = inputSDG(chosenMethod);
    currentUser.sdg_focus = chosenSDG; //simpen disini

    score Asian_Countries[] = {
        {1, "Timor-Leste", "SE Asia", 1, 4, 9, 2, 5, 3, 6, 3, 8,    3, 2,   9.0},
        {2, "India", "South Asia", 2, 8, 7, 8, 6, 9, 6, 6, 7,       7, 5,   5.5},
        {3, "Thailand", "SE Asia", 3, 6, 5, 6, 4, 7, 8, 6, 6,       4, 7,   7.0},
        {4, "Cambodia", "SE Asia", 4, 3, 8, 3, 3, 4, 6, 4, 7,       3, 5,   7.0},
        {5, "Bangladesh", "South Asia", 5, 5, 8, 4, 5, 6, 7, 5, 9,  5, 4,   6.0},
        {6, "Tajikistan", "Central Asia", 6, 3, 7, 3, 4, 3, 7, 3, 6, 2, 3,  5.0},
        {7, "Indonesia", "SE Asia", 7, 7, 6, 5, 4, 9, 7, 5, 6,      5, 6,   7.0}, 
        {8, "Laos", "SE Asia", 7, 2, 9, 2, 3, 3, 6, 3, 6,           2, 3,   7.0},
        {9, "Philippines", "SE Asia", 8, 5, 7, 5, 4, 6, 7, 5, 9,    9, 6,   8.0},
        {10, "Malaysia", "SE Asia", 9, 7, 4, 7, 6, 7, 8, 7, 5,      8, 8,   8.0},
        {11, "Vietnam", "SE Asia", 9, 5, 6, 5, 5, 7, 7, 6, 7,       5, 8,   7.0},
        {12, "Nepal", "South Asia", 10, 3, 8, 3, 4, 3, 6, 4, 8,     4, 3,   5.8},
        {13, "South Korea", "East Asia", 11, 9, 2, 10, 7, 9, 9, 9, 3, 6, 9, 9.0},
        {14, "Brunei", "SE Asia", 12, 9, 2, 5, 6, 8, 8, 6, 5,       7, 6,   8.0},
        {15, "Maldives", "South Asia", 13, 5, 9, 4, 6, 5, 7, 5, 10, 6, 5,   5.0},
        {16, "Sri Lanka", "South Asia", 14, 4, 7, 5, 5, 4, 8, 5, 7, 6, 5,   5.5},
        {17, "Bhutan", "South Asia", 15, 4, 4, 3, 8, 4, 7, 4, 6,    5, 3,   6.0},
        {18, "Myanmar", "SE Asia", 16, 2, 10, 1, 1, 2, 6, 3, 9,     3, 1,   6.5},
        {19, "Singapore", "SE Asia", 17, 10, 1, 10, 9, 10, 10, 10, 2, 10, 10, 8.0},
        {20, "Japan", "East Asia", 9, 9, 2, 10, 9, 10, 10, 9, 4,    4, 8,   9.0},
        {21, "Kazakhstan", "Central Asia", 7, 7, 4, 5, 5, 6, 7, 6, 5, 3, 5, 5.0},
        {22, "Pakistan", "South Asia", 13, 3, 9, 4, 3, 4, 4, 4, 9,  6, 4,   5.0},
        {23, "China", "East Asia", 9, 9, 4, 9, 5, 10, 8, 9, 5, 3, 6, 8.0},
        {24, "Saudi Arabia", "West Asia", 7, 10, 2, 7, 5, 9, 7, 8, 8, 5, 6, 3.0},
        {25, "Taiwan", "East Asia", 9, 8, 2, 10, 8, 9, 9, 9, 7, 6, 9, 8.0},
        {26, "Mongolia", "East Asia", 13, 6, 7, 3, 5, 3, 6, 4, 9, 3, 5, 8.0},
        {27, "Uzbekistan", "Central Asia", 8, 6, 6, 4, 3, 5, 6, 4, 6, 2, 4, 5.0}
    };
    printf(Asian_Countries);



    // after this we can apply the :
    // currentUser.methodProfile.method  -> pilih algoritma / method
    // currentUser.methodProfile.score   -> dibandingkan ke data negara (tabel Excel)
    // currentUser.match.region, timeZone, mainLanguage -> filter tambahan (bisa di gunakan hanya tampilan saja)
    // BESOK GUE MAU BUAT PRINTF RESULTNYA, tapi nanti aja tunggu programnya jadi YAKK

    return 0; 
}

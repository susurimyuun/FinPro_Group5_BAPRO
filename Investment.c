#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// STRUCT DEFINITIONS

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
    scanf("%d", &mp->english_proficiency);
    while (mp->english_proficiency < 0 || mp->english_proficiency > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->english_proficiency);
    }

    printf("Your country timezone (ex: 09:00 -> 9.0): ");
    scanf("%d", &mp->timezone);

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
    scanf("%d", &mp->english_proficiency);
    while (mp->english_proficiency < 0 || mp->english_proficiency > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->english_proficiency);
    }


    printf ("Trade opennes for distance point plus one country to another (0-10): ");
    scanf("%d", &mp->trade_openness);
     while (mp->trade_openness < 0 || mp->trade_openness > 10) {
        printf("Invalid. Enter 0-10: ");
        scanf("%d", &mp->trade_openness);
    }
    
}

float Bonus (score database[], score user, int index){
    float Score = 0;
    int i = index;
        if (database[i].english_proficiency > 7){
                Score += database[i].english_proficiency * 1.5;
            }
            if (database[i].trade_openness > 6){
                Score += database[i].trade_openness * 1.5;
            }
            if (strcmp(database[i].region, "East Asia") == 0 && strcmp(user.region, "America") == 0){
                Score += 15;
            }
            else if (strcmp(database[i].region, "SE Asia") == 0 && strcmp(user.region, "America")== 0){
                Score -= 5;
            }
            else if (strcmp(database[i].region, "South Asia") == 0 && strcmp(user.region, "America") == 0){
                Score -= 10;
            }
            else if (strcmp(database[i].region, "Central Asia") == 0 && strcmp(user.region, "America") == 0){
                Score -= 15;
            }

            if (strcmp(database[i].region, "East Asia") == 0 && strcmp(user.region, "Europe") == 0){
                Score -= 15;
            }
            else if (strcmp(database[i].region, "SE Asia") == 0 && strcmp(user.region, "Europe") == 0){
                Score -= 10;
            }
            else if (strcmp(database[i].region, "South Asia") == 0 && strcmp(user.region , "Europe") == 0){
                Score -= 5;
            }
            else if (strcmp(database[i].region , "Central Asia") == 0 && strcmp(user.region, "Europe") == 0){
                Score += 15;
            }

            if (strcmp(database[i].region , "East Asia") == 0 && strcmp(user.region , "Australia") == 0){
                Score -= 15;
            }
            else if (strcmp(database[i].region , "SE Asia") == 0 && strcmp(user.region, "Australia") == 0){
                Score += 15;
            }
            else if (strcmp(database[i].region , "South Asia") == 0 && strcmp(user.region , "Australia") == 0){
                Score -= 5;
            }
            else if (strcmp(database[i].region , "Central Asia") == 0 && strcmp(user.region , "Australia") == 0){
                Score -= 10;
            }

            if (strcmp(database[i].region , "East Asia") == 0 && strcmp(user.region , "Africa")== 0){
                Score -= 15;
            }
            else if (strcmp(database[i].region , "SE Asia") == 0 && strcmp(user.region , "Africa") == 0){
                Score -= 5;
            }
            else if (strcmp(database[i].region , "South Asia") == 0 && strcmp(user.region, "Africa") == 0){
                Score += 15;
            }
            else if (strcmp(database[i].region , "Central Asia") == 0 && strcmp(user.region , "Africa")== 0){
                Score -= 10;
            }
    return Score;   
}

void venture_execute(score database[],score user, int array_size){
    printf("\n==VENTURE CAPITALIST STRATEGY==\n");
    printf("Logic needs : High Human Capital + 4-7 of Economic Strengths + Digital Readiness + Tech Level + Trade Openness\n");
    printf("Bonuses : Timezone Efficiency + English Proficiency + Distance\n");
    float result[array_size];
    for (int index = 0; index < array_size; index++){
        float score = 0;
        score += (database[index].human_capital * 10);
        score += (database[index].digital_readiness * 5);
        score += (database[index].tech_level * 2.5);
        score += (database[index].trade_openness * 6);

        if(database[index].economic_strength < 4){
            score -= (database[index].economic_strength * 6);
        }
        else if(database[index].economic_strength > 8){
            score -= (database[index].economic_strength * 4);
        }
        else {
            score += (database[index].economic_strength * 5);
        }

        float bonus_score = Bonus(database,user,index);
        score += bonus_score;

        result[index] = score;

    }

    int temp_index[array_size];
        for (int input = 0; input < array_size; input++){
        temp_index[input] = input;
        }

        for (int index2 = 0; index2 < array_size - 1; index2++){
        for (int index3 = 0; index3 < array_size - index2 - 1;index3++){
            if(result[index3] < result[index3 + 1]){
                float temp = result[index3];
                result[index3] = result[index3+1];
                result[index3+1] = temp;
                float temp_idx = temp_index[index3];
                temp_index[index3] = temp_index[index3+1];
                temp_index[index3+1] = temp_idx;

            }
        }
    }

    for (int index4 = 0; index4 < 3; index4++){
        int temp2 = temp_index[index4];
        printf("%i. Country : %s , Region : %s  , SDG Focus : %i , Climate Vulnerability : %d , \nEnglish Proficiency : %d , Trade_Openness : %d\n", index4+1, database[temp2].name, database[temp2].region,database[temp2].sdg_focus,database[temp2].climate_vulnerability,database[temp2].english_proficiency,database[temp2].trade_openness);
        printf("Score : %f\n", result[index4]);
    }
    for (int coba = 0; coba < array_size; coba ++){
        printf("%i Score: %f",coba+1,result[coba]);
        printf("\n");
    }

}

// MAIN
// execute the program 

int main() {
    score currentUser;
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
    int array_size = sizeof(Asian_Countries) / sizeof(Asian_Countries[0]);
    inputMethodProfile(&currentUser);
    venture_execute(Asian_Countries,currentUser,array_size);



    // after this we can apply the :
    // currentUser.methodProfile.method  -> pilih algoritma / method
    // currentUser.methodProfile.score   -> dibandingkan ke data negara (tabel Excel)
    // currentUser.match.region, timeZone, mainLanguage -> filter tambahan (bisa di gunakan hanya tampilan saja)
    // BESOK GUE MAU BUAT PRINTF RESULTNYA, tapi nanti aja tunggu programnya jadi YAKK

    return 0; 
}
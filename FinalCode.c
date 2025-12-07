#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// STRUCT DEFINITIONS

// Identitas dasar (tidak ikut rumus, cuma info)
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
    printf("Input (1-5): ");

    scanf("%d", &m);

    while (m < 1 || m > 5) {
        printf("Invalid. Enter 1-5: ");
        scanf("%d", &m);
    }

    return (Method)m;
}

//-nama sdg
char* SDGNames[] = {
    "",                  // index 0 ga dipake
    "No Poverty",        
    "Zero Hunger",       
    "Good Health",       
    "Quality Education", 
    "Gender Equality",   
    "Clean Water",      
    "Affordable Energy",
    "Decent Work",    
    "Industry, Innovation",
    "Reduced Inequality",  
    "Sustainable Cities",  
    "Responsible Consumption", 
    "Climate Action",   
    "Life Below Water",   
    "Life on Land",     
    "Peace & Justice",   
    "Partnerships"    
};


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
        printf("%d. %s", data.sdgList[i], SDGNames[data.sdgList[i]]);
        if (i < data.sdgCount - 1) printf(", ");
    }
    printf("\n");

    printf("Enter your SDG focus (number 1-17): ");
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
                printf("%d. %s", data.sdgList[i], SDGNames[data.sdgList[i]]);
                if (i < data.sdgCount - 1) printf(", ");
            }
            printf("\nEnter again: ");
            scanf("%d", &sdg);
        }
    }

    printf("You chose SDG: %d. %s\n", sdg, SDGNames[sdg]);
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

    printf("Your country timezone (ex: 09:00 -> 9.0): ");
    scanf("%f", &mp->timezone);

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

void Donor_Execute(score database[], score user, int array_size, int chosenSDG){
    printf("\n== DONOR / NGO STRATEGY ==\n");
    printf("Logic Needs : High Needs + Safe Governancen\n");
    printf("Bonuses : Timezone Efficiency + English Proficiency + Distance\n");
    float result[array_size];
    for (int index = 0; index < array_size; index++){
        float score = 0;
        if (database[index].sdg_focus == chosenSDG){
                score += 50;
        }
        else {
            score -= 25;
        }

        if (user.resources >= database[index].needs){
            score += database[index].needs * 1.2;
        }
        else {
            score -= (database[index].needs - user.resources) * 1.5;
        }

        if (database[index].political_will < 4){
            score -= 30;
        }
        else {
            score += database[index].political_will * 4.0;
        }


        float bonus_score = Bonus(database,user, index);
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
        printf("%i. Country : %s , Region : %s  , SDG Focus : %i , Needs : %d , Political Will : %d , \nEnglish Proficiency : %d , Trade_Openness : %d\n", index4+1, database[temp2].name, database[temp2].region,database[temp2].sdg_focus,database[temp2].needs,database[temp2].political_will,database[temp2].english_proficiency,database[temp2].trade_openness);
        printf("Score : %f\n", result[index4]);
    }
    for (int coba = 0; coba < array_size; coba ++){
        printf("%i Score: %f",coba+1,result[coba]);
        printf("\n");
    }


}

void coalition_execute(score database[],score user,int array_size, int chosenSDG){
    printf("\n==CLIMATE ACTIVIST STRATEGY==\n");
    printf("Logic needs : High Vulnerability\n");
    printf("Bonuses : Timezone Efficiency + English Proficiency + Distance\n");

    float result[array_size];

    for (int index = 0; index < array_size; index++){
        float scoring = 100;

        if (database[index].sdg_focus == chosenSDG){
            scoring += 50;
        }
        else {
            scoring -= 25;
        }

        float difference = abs(database[index].climate_vulnerability - user.climate_vulnerability);
        scoring -= (difference * 25.0);

        float bonus_score = Bonus(database,user, index);
        scoring += bonus_score;

        result[index] = scoring;

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
        int temp3 = temp_index[coba];
        printf("==========================\n");
        printf("%i Country : %s Score: %f",coba+1,database[temp3].name,result[coba]);
        printf("\n");
    }

}

void venture_execute(score database[],score user, int array_size, int chosenSDG){
    printf("\n==VENTURE CAPITALIST STRATEGY==\n");
    printf("Logic needs : High Human Capital + 4-7 of Economic Strengths + Digital Readiness + Tech Level + Trade Openness\n");
    printf("Bonuses : Timezone Efficiency + English Proficiency + Distance\n");
    float result[array_size];
    for (int index = 0; index < array_size; index++){
        float score = 0;

        if (database[index].sdg_focus == chosenSDG){
            score += 50;
        }
        else {
            score -= 25;
        }

        score += (database[index].human_capital * 10);
        score += (database[index].digital_readiness * 5);
        score += (database[index].tech_level * 2.5);
        score += (database[index].trade_openness * 3);

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
        printf("%i. Country : %s , Region : %s  , SDG Focus : %i , Human Capital : %d ,\nDigital Readiness : %d, Tech Level : %d, Trade Openness : %d \nEnglish Proficiency : %d\n", index4+1, database[temp2].name, database[temp2].region,database[temp2].sdg_focus,database[temp2].human_capital,database[temp2].digital_readiness,database[temp2].tech_level,database[temp2].trade_openness,database[temp2].english_proficiency,database[temp2].trade_openness);
        printf("Score : %f\n", result[index4]);
    }
    for (int coba = 0; coba < array_size; coba ++){
        int temp3 = temp_index[coba];
        printf("==========================\n");
        printf("%i Country : %s Score: %f",coba+1,database[temp3].name,result[coba]);
        printf("\n");
    }

}

void conservatice_execute(score database[],score user, int array_size, int chosenSDG){
    printf("\n==VENTURE CAPITALIST STRATEGY==\n");
    printf("Logic needs : High Political Will + High Economic Strength + Low CLimate Vulnerability\n");
    printf("Bonuses : Timezone Efficiency + English Proficiency + Distance + Trade Openness\n");
    float result[array_size];
    for (int index = 0; index < array_size; index++){
        float score = 0;

        if (database[index].sdg_focus == chosenSDG){
            score += 50;
        }
        else {
            score -= 25;
        }

        score += (database[index].political_will * 10);
        if (database[index].economic_strength > 7){
            score += 30;
        }
        if (database[index].climate_vulnerability > 7){
            score -= 35;
        }
        if (database[index].trade_openness > 6){
            score += 15;
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
        printf("%i. Country : %s , Region : %s  , SDG Focus : %i , Political Will : %d , Economic Strength : %d, Climate Vulnerability : %d\nDigital Readiness : %d, Tech Level : %d, Trade Openness : %d \nEnglish Proficiency : %d\n", index4+1, database[temp2].name, database[temp2].region,database[temp2].sdg_focus,database[temp2].political_will,database[temp2].economic_strength,database[temp2].climate_vulnerability,database[temp2].digital_readiness,database[temp2].tech_level,database[temp2].trade_openness,database[temp2].english_proficiency,database[temp2].trade_openness);
        printf("Score : %f\n", result[index4]);
    }
    for (int coba = 0; coba < array_size; coba ++){
        int temp3 = temp_index[coba];
        printf("==========================\n");
        printf("%i Country : %s Score: %f",coba+1,database[temp3].name,result[coba]);
        printf("\n");
    }

}

void techcomp_execute(score database[],score user, int array_size, int chosenSDG){
    printf("\n==TECH COMPANY STRATEGY==\n");
    printf("Logic needs :  Digital Readiness + Tech Level\n");
    printf("Bonuses : Timezone Efficiency + English Proficiency + Distance\n");
    float result[array_size];
    for (int index = 0; index < array_size; index++){
        float score = 0;

        if (database[index].sdg_focus == chosenSDG){
            score += 50;
        }
        else {
            score -= 25;
        }

        if (database[index].digital_readiness <= 5){
            score -= (database[index].digital_readiness * 3);
        }
        else {
            score += (database[index].digital_readiness * 5);
        }
        if (database[index].tech_level <= 5){
            score -= (database[index].tech_level * 2.5);
        }
        else {
            score += (database[index].tech_level * 4);
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
        printf("%i. Country : %s , Region : %s  , SDG Focus : %i , Tech Level : %d , Digital Readiness : %d \nEnglish Proficiency : %d , Trade_Openness : %d\n", index4+1, database[temp2].name, database[temp2].region,database[temp2].sdg_focus,database[temp2].tech_level,database[temp2].digital_readiness,database[temp2].english_proficiency,database[temp2].trade_openness);
        printf("Score : %f\n", result[index4]);
    }
    for (int coba = 0; coba < array_size; coba++){
        int temp3 = temp_index[coba];
        printf("==========================\n");
        printf("%i Country : %s Score: %f",coba+1,database[temp3].name,result[coba]);
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
    printf("%i\n",array_size);
    
    inputMethodProfile(&currentUser);

    Method chosenMethod = pickMethod();

    //pilih sdg sesuai
    int chosenSDG = inputSDG(chosenMethod);
    switch(chosenMethod){
        case DONOR : Donor_Execute(Asian_Countries,currentUser,array_size,chosenSDG); break;
        case COALITION : coalition_execute(Asian_Countries,currentUser,array_size,chosenSDG); break;
        case INVESTMENT : venture_execute(Asian_Countries,currentUser,array_size,chosenSDG); break;
        case TECH_TRANSFER : techcomp_execute(Asian_Countries,currentUser,array_size,chosenSDG); break;
        case NEXUS_PEACE : conservatice_execute(Asian_Countries,currentUser,array_size,chosenSDG); break;
    }


    inputMethodProfile(&currentUser);


    return 0; 
}

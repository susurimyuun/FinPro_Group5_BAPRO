#include <stdio.h>
// STRUCT DEFINITIONS

// Identitas dasar (tidak ikut rumus, cuma info)
typedef struct {
    char fullName[50];
    char nickname[30];
    char dateOfBirth[15];
} UserIdentity;
//tes tes
// Profil yang dipakai untuk matching data negara (region, timezone, dll)
typedef struct {
    int gender;              
    int region;              
    char country[40];        
    char timeZone[20];      

    int mainLanguage;        
    char otherLanguages[100];
} MatchProfile;

// Rating 0–10 untuk tiap dimensi (buat dibandingkan ke tabel negara)
typedef struct {
    int resources; 
    int needs;
    int techLevel;           
    int politicalWill;     
    int economicStrength;   
    int humanCapital;       
    int digitalReadiness;    
    int climateVulnerability;
} ScoreProfile;

// Metode + rating (khusus untuk matching method 1–5)
typedef struct {
    int method;         
    ScoreProfile score; 
} MethodProfile;

// User lengkap
typedef struct {
    UserIdentity id;
    MatchProfile match;
    MethodProfile methodProfile;
} User;

// LIST DISPLAY
void printGenderList() {
    printf("\nGender = \n");
    printf("1. Male\n");
    printf("2. Female\n");
    printf("3. Prefer not to say\n");
    printf("4. Other\n");
}

void printRegionList() {
    printf("\nRegion = \n");
    printf("1. Southeast Asia\n");
    printf("2. South Asia\n");
    printf("3. Central Asia\n");
}

void printMainLanguageList() {
    printf("\nInternational Main Language = \n");
    printf("1. English\n");
    printf("2. Mandarin\n");
    printf("3. Spanish\n");
    printf("4. French\n");
    printf("5. Arabic\n");
    printf("6. Russian\n");
}

void printMethodList() {
    printf("\nMatching Method = \n");
    printf("1. Donor / NGO\n");
    printf("2. Tech Company\n");
    printf("3. Climate Activist\n");
    printf("4. Conservative Government\n");
    printf("5. Venture Capitalist\n");
}

// Input identitas user
void inputIdentity(UserIdentity *id) {
    printf("\n=== MAIN INPUT USER IDENTITY ===\n");

    printf("Full Name                    : ");
    scanf(" %49[^\n]", id->fullName);

    printf("Nickname                     : ");
    scanf(" %29[^\n]", id->nickname);

    printf("Date of Birth (DD-MM-YYYY)   : ");
    scanf(" %14[^\n]", id->dateOfBirth);
}

// Input profil untuk matching region / bahasa / timezone
void inputMatchProfile(MatchProfile *m) {
    printf("\n=== INPUT MATCH PROFILE ===\n");

    printGenderList();
    printf("Choose Gender (1-4)          : ");
    scanf("%d", &m->gender);

    // validation
    while (m->gender < 1 || m->gender > 4) {
        printf("Invalid input. Choose 1-4 : ");
        scanf("%d", &m->gender);
    }

    printRegionList();
    printf("Choose Region (1-3)          : ");
    scanf("%d", &m->region);

    // validation
    while (m->region < 1 || m->region > 3) {
        printf("Invalid input. Choose 1-3 : ");
        scanf("%d", &m->region);
    }

    printf("Country                      : ");
    scanf(" %39[^\n]", m->country);

    printf("Time Zone (ex: Jakarta GMT+7) : ");
    scanf(" %19[^\n]", m->timeZone);

    printMainLanguageList();
    printf("Choose Main Language (1-6)   : ");
    scanf("%d", &m->mainLanguage);

    // validation
    while (m->mainLanguage < 1 || m->mainLanguage > 6) {
        printf("Invalid input. Choose 1-6 : ");
        scanf("%d", &m->mainLanguage);
    }

    printf("Other Languages (free text)  : ");
    scanf(" %99[^\n]", m->otherLanguages);
}

// Input metode + rating 0–10 untuk tiap dimensi
void inputMethodProfile(MethodProfile *mp) {
    printf("\n=== INPUT MATCHING METHOD & SCORES ===\n");

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

    printf("\nMethod & rating scores saved! \n");
}

// MAIN
// execute the program 

int main() {
    User currentUser;

    inputIdentity(&currentUser.id);              // nama, nickname, DOB
    inputMatchProfile(&currentUser.match);       // gender, region, country, timezone, bahasa
    inputMethodProfile(&currentUser.methodProfile); // method 1–5 + 8 rating 0–10

    // after this we can apply the :
    // currentUser.methodProfile.method  -> pilih algoritma / method
    // currentUser.methodProfile.score   -> dibandingkan ke data negara (tabel Excel)
    // currentUser.match.region, timeZone, mainLanguage -> filter tambahan (bisa di gunakan hanya tampilan saja)
    // BESOK GUE MAU BUAT PRINTF RESULTNYA, tapi nanti aja tunggu programnya jadi YAKK

    return 0;
}

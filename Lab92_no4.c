#include <stdio.h>
#include <string.h>
#include <ctype.h>


int checkValidPass1(char *ps); 
int checkValidPass2(char *ps); 
int checkValidPass3(char *ps);
int checkLogin(char *login, char *passwd);

int main() {
    char login[64], password[64];
    
    printf("Enter login : "); 
    gets(login);
    printf("Enter password : "); 
    gets(password);

    if( checkLogin(login, password) == 1) {
        printf("Welcome\n");
    } else {
        printf("Incorrect login or password\n");
    }

    printf("\n--- Password Validation Results ---\n");

  
    if (checkValidPass1(password)) {
        printf("[4.1] Accepted: Length = 5 and >= 1 digit\n");
    } else {
        printf("[4.1] Reject\n");
    }

   
    if (checkValidPass2(password)) {
        printf("[4.2] Accepted: Length 5-8, First char not a number, >= 2 Uppercase, >= 2 digits\n");
    } else {
        printf("[4.2] Reject\n");
    }

  
    if (checkValidPass3(password)) {
        printf("[4.3] Accepted: Length 5-8, >= 2 Uppercase (No repeat), >= 2 digits\n");
    } else {
        printf("[4.3] Reject\n");
    }

    return 0;
}

// -------------------------------------------------------------------
// 4.1 Length = 5 and a number 1 or more digits
// -------------------------------------------------------------------
int checkValidPass1(char *ps) {
    if (strlen(ps) != 5) return 0;

    for (int i = 0; i < 5; i++) {
        if (isdigit(ps[i])) {
            return 1; 
        }
    }
    return 0;
}

// -------------------------------------------------------------------
// 4.2 Length 5-8, First char not a number, 
//     >= 2 Uppercase, >= 2 digits
// -------------------------------------------------------------------
int checkValidPass2(char *ps) {
    int len = strlen(ps);
    if (len < 5 || len > 8) return 0; 
    if (isdigit(ps[0])) return 0;     

    int upperCount = 0;
    int digitCount = 0;

    for (int i = 0; i < len; i++) {
        if (isupper(ps[i])) upperCount++;
        if (isdigit(ps[i])) digitCount++;
    }

    if (upperCount >= 2 && digitCount >= 2) {
        return 1; 
    }
    return 0;
}

// -------------------------------------------------------------------
// 4.3 Length 5-8, >= 2 Uppercase (not repeat), >= 2 digits
// -------------------------------------------------------------------
int checkValidPass3(char *ps) {
    int len = strlen(ps);
    if (len < 5 || len > 8) return 0; 

    int upperCount = 0;
    int digitCount = 0;
    int upperSeen[26] = {0}; 

    for (int i = 0; i < len; i++) {
        if (isdigit(ps[i])) {
            digitCount++;
        } 
        else if (isupper(ps[i])) {
            int index = ps[i] - 'A'; 
            if (upperSeen[index] == 1) {
                return 0; 
            }
            upperSeen[index] = 1; 
            upperCount++;
        }
    }

    if (upperCount >= 2 && digitCount >= 2) {
        return 1; 
    }
    return 0;
}

// -------------------------------------------------------------------
int checkLogin(char *login, char *passwd) {
    if ( !strcmp(login, "student1") && !strcmp(passwd, "mypass"))
        return 1;
    else
        return 0;
}

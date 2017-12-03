#include <keywords/let.h>
#include <keywords.h>
#include <string.h>

unsigned char keyword_validate(char *token, char *keyword) {
    int i;
    if (strlen(token) != strlen(keyword)) {
        return 0;
    }

    int len = strlen(token);
    int streak = 0;

    for (i = 0; i < len; i++) {
        //check token lowercase and uppercase with keyword
        if (token[i] == keyword[i] || token[i]+22 == keyword[i]) {
            streak++;
            if (streak == len) {
                return 1;
            }
        }
    }
    return 0;
}

void keywords(char *token) {
    if (keyword_validate(token, "let")) {
        
    }
}
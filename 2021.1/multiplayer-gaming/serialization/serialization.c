/**
 * @file serialization.c
 * @brief Serialize a struct in JSON format and deserialize in raw type.
 * @version 0.1
 * @date 2021-07-13
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

// Input json format
const char* GAMESTATE_IN =
    "{\"board\":\"%[^\"]\",\"score_x\":\"%d\",\"score_y\":\"%d\"}";

// Output json format
const char* GAMESTATE_OUT =
    "{\"board\":\"%s\",\"score_x\":\"%d\",\"score_y\":\"%d\"}";

typedef struct GameState {
    char board[BUFFER_SIZE];
    int score_x;
    int score_y;
} GameState;

int main() {
    GameState toSerialize = {
        .board = {'o', 'x', 'x', 'o', 'x', 'o', 'x', 'o', 'x', '\0'},
        .score_x = 3,
        .score_y = 1,
    };
    GameState deserialized;

    FILE* file = fopen("gamestate.json", "w+");
    if (file == NULL) return 1;

    // Serialize
    fprintf(file, GAMESTATE_OUT, toSerialize.board, toSerialize.score_x,
            toSerialize.score_y);
    // Return to the starting position in the file
    fseek(file, 0, SEEK_SET);
    // Deserialize the json
    fscanf(file, GAMESTATE_IN, deserialized.board, &deserialized.score_x,
           &deserialized.score_y);

    return 0;
}
/*
 ============================================================================
 Project Name : Grays Harbor: Shadow County
 Target      : PlayStation 2 (NetherSX2)
 Description : Core world & prototype logic
 ============================================================================
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
    float x, y, z;
} Vector3;

typedef struct {
    Vector3 position;
    Vector3 rotation;
    float speed;
    int health;
} Player;

typedef enum {
    BIOME_FOREST_CLEARING = 0,
    BIOME_GRAYS_HARBOR_BAY,
    BIOME_WEST_TOWN,
    BIOME_EAST_INDUSTRIAL
} BiomeType;

typedef struct {
    char name[32];
    BiomeType type;
    float fog_density;
} District;

int main() {
    Player player = {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, 0.15f, 100};
    
    District home_town;
    strcpy(home_town.name, "West Harbor (Hoquiam)");
    home_town.type = BIOME_WEST_TOWN;
    home_town.fog_density = 0.05f;

    printf("Grays Harbor: Shadow County - Engine Initialized!\n");
    printf("Starting Area: %s\n", home_town.name);
    printf("Player Position: (%.2f, %.2f, %.2f)\n", player.position.x, player.position.y, player.position.z);

    return 0;
}


#include "game.h"

Player* create_player(unsigned int health, unsigned int damage) {
    Player* player=(Player*)malloc(sizeof(Player));
    (player->element).health=health;
    (player->element).damage=damage;
    (player->element).skill=(p_skill*)calloc(1, sizeof(p_skill));
    (player->element).skill_count=0;
    return player;
}
Monster* create_monster(unsigned int health, unsigned int damage) {
    Monster* monster=(Monster*)malloc(sizeof(Monster));
    (monster->element).health=health;
    (monster->element).damage=damage;
    (monster->element).skill=(p_skill*)calloc(1, sizeof(p_skill));
    (monster->element).skill_count=0;
    return monster;
}
void monster_behavior(Monster* monster, Player* player) {
    if((monster->element).skill_count==0) return;
    ((monster->element).skill)[rand()%((monster->element).skill_count-1)](player, monster);

}
void player_behavior(Player* player, Monster* monster, unsigned char selected_value) {
    if((player->element).skill_count==0) return;
    ((player->element).skill)[selected_value-1](player, monster);
}
void add_monster_skill(Monster* monster, p_skill skill) {
    ((monster->element).skill)[(monster->element).skill_count]=skill;
    (monster->element).skill_count++;
    (monster->element).skill=(p_skill*)realloc((monster->element).skill, ((monster->element).skill_count+1)*sizeof(p_skill));
};
void add_player_skill(Player* player, p_skill skill) {
    ((player->element).skill)[(player->element).skill_count]=skill;
    (player->element).skill_count++;
    (player->element).skill=(p_skill*)realloc((player->element).skill, ((player->element).skill_count+1)*sizeof(p_skill));
};
void player_attack(Player* player, Monster* monster) {
    (monster->element).health-=(player->element).damage;
}
void monster_attack(Player* player, Monster* monster) {
    (player->element).health-=(monster->element).damage;
}
    
void delete_player(Player* player) {
    free((player->element).skill);
    free(player);
}
void delete_monster(Monster* monster) {
    free((monster->element).skill);
    free(monster);
}

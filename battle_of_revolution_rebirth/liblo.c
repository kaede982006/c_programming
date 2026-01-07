#include "lo.h"
#include <string.h>

void print_layout(Player* player, Monster* monster) {
    clear();
    print("--------------------------------------------------------------------------------");
    print("당신의 체력: %d", (player->element).health);
    char player_bar[51]={' ',};
    player_bar[50]='\0';
    for(int i=0; i<(50*(player->element).health/(player->element).original_health);i++)
    {
        player_bar[i]='#';
    }
    print("%s", player_bar);
    char skill_string[80]="당신의 능력: ";
    strcat(skill_string, "[1] 공격 ");
    strcat(skill_string, "[2] 치유 ");
    if(player->level>=5) strcat(skill_string, "[3] AK-47 ");
    if(player->level>=10) strcat(skill_string, "[4] T-34 ");
    print("%s", skill_string);
    print("--------------------------------------------------------------------------------");
    print("몬스터 체력: %d", (monster->element).health);
    char monster_bar[51]={' ',};
    monster_bar[50]='\0';
    for(int i=0; i<(50*(monster->element).health/(monster->element).original_health);i++)
    {
        monster_bar[i]='#';
    }
    print("%s", monster_bar);
    print("--------------------------------------------------------------------------------");
}

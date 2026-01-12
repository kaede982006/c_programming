#include "lo.h"
#include <string.h>
#include <wchar.h>
#include <locale.h>

void print_layout(Player* player, Monster* monster) {
    setlocale(LC_ALL, "en_US.UTF-8");
    clear();
    print(L"--------------------------------------------------------------------------------");
    print(L"당신의 체력: %d", (player->element).health);
    wchar_t player_bar[51];
    wmemset(player_bar, L' ', 50);
    player_bar[50]=L'\0';
    for(int i=0; i<(50*(player->element).health/(player->element).original_health);i++)
    {
        player_bar[i]=L'#';
    }
    print(L"%ls", player_bar);
    wchar_t skill_string[80]=L"당신의 능력: ";
    wcscat(skill_string, L"[1] 공격 ");
    wcscat(skill_string, L"[2] 치유 ");
    if(player->level>=5) wcscat(skill_string, L"[3] AK-47 ");
    if(player->level>=10) wcscat(skill_string, L"[4] T-34 ");
    print(L"%ls", skill_string);
    print(L"--------------------------------------------------------------------------------");
    print(L"몬스터 체력: %d", (monster->element).health);
    wchar_t monster_bar[51];
    wmemset(monster_bar, L' ', 50);
    monster_bar[50]=L'\0';
    for(int i=0; i<(50*(monster->element).health/(monster->element).original_health);i++)
    {
        monster_bar[i]=L'#';
    }
    print(L"%ls", monster_bar);
    print(L"--------------------------------------------------------------------------------");
}
void print_nuclear_bomb(Nuclear* nuclear) {
    wchar_t player_bar[51]={L' ',};
    for(int i=0;i<nuclear->gage;i++) {
        player_bar[i]=L'*';
    }
}

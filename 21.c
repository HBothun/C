#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

char cards[52][18] = {
    "Ace_of_Spades", "2_of_Spades", "3_of_Spades", "4_of_Spades", "5_of_Spades", "6_of_Spades", "7_of_Spades", "8_of_Spades", "9_of_Spades", "10_of_Spades", "Jack_of_Spades", "Queen_of_Spades", "King_of_Spades",
    "Ace_of_Clubs", "2_of_Clubs", "3_of_Clubs", "4_of_Clubs", "5_of_Clubs", "6_of_Clubs", "7_of_Clubs", "8_of_Clubs", "9_of_Clubs", "10_of_Clubs", "Jack_of_Clubs", "Queen_of_Clubs", "King_of_Clubs",
    "Ace_of_Hearts", "2_of_Hearts", "3_of_Hearts", "4_of_Hearts", "5_of_Hearts", "6_of_Hearts", "7_of_Hearts", "8_of_Hearts", "9_of_Hearts", "10_of_Hearts", "Jack_of_Hearts", "Queen_of_Hearts", "King_of_Hearts",
    "Ace_of_Diamonds", "2_of_Diamonds", "3_of_Diamonds", "4_of_Diamonds", "5_of_Diamonds", "6_of_Diamonds", "7_of_Diamonds", "8_of_Diamonds", "9_of_Diamonds", "10_of_Diamonds", "Jack_of_Diamonds", "Queen_of_Diamonds", "King_of_Diamonds"
};

int value[52] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10
};

struct player {
        char name[20];
        char hand[10][18];
        int score;
        int chips;
        int bet;
        int card_count;
        bool busted;
};

int deal(struct player* player, int card_number, int t){
    int num = (rand() % 51);
    strcpy(player->hand[card_number], cards[num]);
    player->score += value[num];
    player->card_count++;
}

int clear_cards(struct player* player){
    int m;
    for(m = 0; m < 10; m++){
        player->hand[m] == "no_card";
    }
    player->score = 0;
}

int check_for_bust(struct player* player){
    if(player->score>=22){
        printf("\nYou Busted!\n");
        clear_cards(player);
        player->busted = true;
    }
}

int reset(struct player* player, int t){
    player->card_count = 0;
    player->busted = false;
    player->bet = 0;
    clear_cards(player);
    deal(player, 0, t);
    deal(player, 1, t);
}

int play(struct player* player, struct player* dealer, int t){
    char option[10];
    printf("\n%sit is your turn please select option or help\n", player->name);
    while(true){
        scanf("%s", &option);
        getchar();
        if(strcmp(option, "help") == 0){
                printf("You can use score, bet, fold, hit, or stay\n");
        }
        else if(strcmp(option, "score") == 0){
            int n;
            printf("\nYou have\n");
            for(n = 0; n < player->card_count; n++){
                printf("a %s\n",player->hand[n]);
                printf("and\n");
            }
            printf("that means you have %d\n", player->score);
            printf("\nThe Dealer has a %s\n", dealer->hand[1]);
        }
        else if(strcmp(option, "bet") == 0){
            printf("You have %d chips, what do you want to bet?\n", player->chips);
            scanf("%d", &player->bet);
            getchar();
            printf("You bet %d, do you wanna hit or stay?\n");
        }
        else if(strcmp(option, "hit") == 0){
            deal(player, player->card_count, t);
            printf("\nyou got a %s\n", player->hand[player->card_count-1]);
            check_for_bust(player);
            if(player->busted == true){
                break;
            }
        }
        else if(strcmp(option, "fold") == 0){
            clear_cards(player);
            break;
        }
        else if(strcmp(option, "stay") == 0){
            break;
        }
        else{
                printf("\nInvalid option see help\n");
        }
    }
}

int dealers_turn(struct player* player, int t){
    printf("\nThe Dealer had %s\n", player->hand[0]);
    printf("and a %s\n", player->hand[1]);
    printf("the Dealer has %d\n", player->score);
    while(player->score <= 16){
            deal(player, 2, t);
            printf("The Dealer hits and got a %s\n", player->hand[2]);
            printf("Now the Dealer has %d\n", player->score);

    }
    if(player->score >= 17 && player->score <= 21){
            printf("so the Dealer stands\n");
    }
    else if(player->score >= 21){
            printf("the Dealer busted!\n", player->score);
            player->score = 0;
            player->busted == true;
    }
    else{
        printf("Error 9000\n");
    }
}

int scoring(struct player* player, struct player* dealer, int t){
    if(dealer->busted == false){
        printf("\n%sYou have %d\n", player->name, player->score);
        if(player->busted == false){
            if(player->score > dealer->score){
                printf("You won\n");
                printf("You had %d chips and bet %d of them\n", player->chips, player->bet);
                player->chips += player->bet;
                printf("now you have %d chips\n", player->chips);
                player->bet = 0;
            }
            else if(player->score = dealer->score){
                printf("You tie\n");
                printf("You had %d chips and bet %d of them\n", player->chips, player->bet);
                player->chips += (player->bet/2);
                printf("now you have %d chips\n", player->chips);
                player->bet = 0;
            }
            else{
                printf("You lost\n");
                printf("You had %d chips and bet %d of them\n", player->chips, player->bet);
                player->chips -= player->bet;
                printf("now you have %d chips\n", player->chips);
                player->bet = 0;
            }
        }
        else{
            printf("You busted so\n");
            printf("You lost\n");
            printf("You had %d chips and bet %d of them\n", player->chips, player->bet);
            player->chips -= player->bet;
            printf("now you have %d chips\n", player->chips);
            player->bet = 0;
        }
    }
    else{
        if(player->busted == false){
            printf("You won\n");
            printf("You had %d chips and bet %d of them\n", player->chips, player->bet);
            player->chips += player->bet;
            printf("now you have %d chips\n", player->chips);
            player->bet = 0;
        }
        else{
            printf("You busted so\n");
            printf("You stil lost\n");
            printf("You had %d chips and bet %d of them\n", player->chips, player->bet);
            player->chips -= player->bet;
            printf("now you have %d chips\n", player->chips);
            player->bet = 0;
        }
    }
}
int main (void){
    time_t t;
    srand(time(&t));
    int number_of_players;
    printf("How many players: ");
    scanf("%d", &number_of_players);
    getchar();
    struct player table_of_players[number_of_players + 1];
    strcpy(table_of_players[0].name, "Dealer\n");
    int i;
    for(i = 1; i <= number_of_players; i++){
        printf("Player %d's name: ", i);
        fgets(table_of_players[i].name, 20, stdin);
        printf("Player %d's chip count: ", i);
        scanf("%d", &table_of_players[i].chips);
        getchar();
    }
    int j;
    for(j = 0; j <= number_of_players; j++){
        reset(&table_of_players[j], t);
    }
    printf("\nThe Dealer has a %s\n", table_of_players[0].hand[1]);
    int k;
    for(k = 1;k <= number_of_players; k++){
        printf("\n%shas a %s \n", table_of_players[k].name, table_of_players[k].hand[1]);
    }
    while(true){
        for(int l = 1; l<=number_of_players; l++){
            play(&table_of_players[l], &table_of_players[0], t);
        }
        dealers_turn(&table_of_players[0], t);
        int n;
        for(n=1; n<=number_of_players; n++){
            scoring(&table_of_players[n], &table_of_players[0], t);
        }
        int o;
        for(o = 0; o <= number_of_players; o++){
            reset(&table_of_players[0], t);
        }
        printf("\nThe Dealer has a %s\n", table_of_players[0].hand[1]);
        int p;
        for(p = 1;p <= number_of_players; p++){
            printf("\n%shas a %s \n",table_of_players[p].name, table_of_players[p].hand[1]);
        }
    }
    return 0;
}

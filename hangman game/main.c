#include <time.h>
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "implementation.h"

typedef struct _mysql{

    MYSQL connection;
    MYSQL_RES *res;
    MYSQL_ROW row;

}Mysql;

typedef struct _score{

    int points, errors;
    int total_points, total_errors, total_wins, total_losses, total_matches;

}Score;

typedef struct _game{

    char secret_word[51], tip[256];
    int chances;
    Score score;

}Game;

void MysqlStartConnection(Mysql *ptr_mysql);

void animals(Mysql *ptr_mysql, Game *ptr_game);
void fruits(Mysql *ptr_mysql, Game *ptr_game);
void objects(Mysql *ptr_mysql, Game *ptr_game);

bool hangman(Game *ptr_game);

bool GoodScore(Mysql *ptr_mysql, Game *ptr_game, short int *playerID);
void SaveScore(Mysql *ptr_mysql, Game *ptr_game, short int playerID);

int main(void){

    Mysql *mysql=(Mysql*)malloc(sizeof(Mysql));
    Game *game=(Game*)calloc(1, sizeof(Game));

    MysqlStartConnection(mysql);

    char opc, YN;
    short int playerID;

    do{

        printf("+===Escolha uma categoria para jogar===+\n");
        printf("| Animais..........................[1] |\n");
        printf("| Frutas...........................[2] |\n");
        printf("| Objetos..........................[3] |\n");
        printf("+==============Pontuações==============+\n");
        printf("| Exibir Pontuações................[4] |\n");
        printf("+=================Sair=================+\n");
        printf("| SAIR.............................[5] |\n");
        printf("+======================================+\n");
        printf("->");

        opc=getchar();

        system("clear");
        __fpurge(stdin);

        switch(opc){

            case '1':

                animals(mysql, game);

                if(hangman(game)!=true){

                    printf("Você perdeu!!!\nO animal secreto era %s\n\n", game->secret_word);
                    printf("Acertos: %d\n", game->score.points);
                    printf("Erros: %d\n", game->score.errors);
                    printf("Total de acertos: %d\n", game->score.total_points);
                    printf("Total de erros: %d\n", game->score.total_errors);
                    printf("Partidas vencidas: %d\n", game->score.total_wins);
                    printf("Partidas perdidas: %d\n", game->score.total_losses);
                    printf("Total de partidas jogadas: %d\n\n", game->score.total_matches);

                }else{

                    printf("Você ganhou!!!\nO animal secreto era %s\n\n", game->secret_word);
                    printf("Acertos: %d\n", game->score.points);
                    printf("Erros: %d\n", game->score.errors);
                    printf("Total de acertos: %d\n", game->score.total_points);
                    printf("Total de erros: %d\n", game->score.total_errors);
                    printf("Partidas vencidas: %d\n", game->score.total_wins);
                    printf("Partidas perdidas: %d\n", game->score.total_losses);
                    printf("Total de partidas jogadas: %d\n\n", game->score.total_matches);
                }

                printf("Deseja continuar jogando? [Y/n]");
                YN=getchar();

                system("clear");
                __fpurge(stdin);

                if(YN=='Y' || YN=='y'){

                    opc=' ';

                }else{

                    if(GoodScore(mysql, game, &playerID)==true){

                        printf("Antes de sair deseja registrar sua pontuação? [Y/n]");
                        YN=getchar();

                        if(YN=='Y' || YN=='y'){

                            system("clear");
                            __fpurge(stdin);

                            SaveScore(mysql, game, playerID);
                        }
                    }

                    printf("Saindo...\n\n");
                }

                break;

            case '2':

                fruits(mysql, game);

                if(hangman(game)!=true){

                    printf("Você perdeu!!!\nA fruta secreta era %s\n\n", game->secret_word);
                    printf("Acertos: %d\n", game->score.points);
                    printf("Erros: %d\n", game->score.errors);
                    printf("Total de acertos: %d\n", game->score.total_points);
                    printf("Total de erros: %d\n", game->score.total_errors);
                    printf("Partidas vencidas: %d\n", game->score.total_wins);
                    printf("Partidas perdidas: %d\n", game->score.total_losses);
                    printf("Total de partidas jogadas: %d\n\n", game->score.total_matches);

                }else{

                    printf("Você ganhou!!!\nA fruta secreta era %s\n\n", game->secret_word);
                    printf("Acertos: %d\n", game->score.points);
                    printf("Erros: %d\n", game->score.errors);
                    printf("Total de acertos: %d\n", game->score.total_points);
                    printf("Total de erros: %d\n", game->score.total_errors);
                    printf("Partidas vencidas: %d\n", game->score.total_wins);
                    printf("Partidas perdidas: %d\n", game->score.total_losses);
                    printf("Total de partidas jogadas: %d\n\n", game->score.total_matches);
                }

                printf("Deseja continuar jogando? [Y/n]");
                YN=getchar();

                system("clear");
                __fpurge(stdin);

                if(YN=='Y' || YN=='y'){

                    opc=' ';

                }else{

                    if(GoodScore(mysql, game, &playerID)==true){

                        printf("Antes de sair deseja registrar sua pontuação? [Y/n]");
                        YN=getchar();

                        if(YN=='Y' || YN=='y'){

                            system("clear");
                            __fpurge(stdin);

                            SaveScore(mysql, game, playerID);
                        }
                    }

                    printf("Saindo...\n\n");
                }

                break;

            case '3':

                objects(mysql, game);

                if(hangman(game)!=true){

                    printf("Você perdeu!!!\nO objeto secreto era %s\n\n", game->secret_word);
                    printf("Acertos: %d\n", game->score.points);
                    printf("Erros: %d\n", game->score.errors);
                    printf("Total de acertos: %d\n", game->score.total_points);
                    printf("Total de erros: %d\n", game->score.total_errors);
                    printf("Partidas vencidas: %d\n", game->score.total_wins);
                    printf("Partidas perdidas: %d\n", game->score.total_losses);
                    printf("Total de partidas jogadas: %d\n\n", game->score.total_matches);

                }else{

                    printf("Você ganhou!!!\nO animal secreto era %s\n\n", game->secret_word);
                    printf("Acertos: %d\n", game->score.points);
                    printf("Erros: %d\n", game->score.errors);
                    printf("Total de acertos: %d\n", game->score.total_points);
                    printf("Total de erros: %d\n", game->score.total_errors);
                    printf("Partidas vencidas: %d\n", game->score.total_wins);
                    printf("Partidas perdidas: %d\n", game->score.total_losses);
                    printf("Total de partidas jogadas: %d\n\n", game->score.total_matches);
                }

                printf("Deseja continuar jogando? [Y/n]");
                YN=getchar();

                system("clear");
                __fpurge(stdin);

                if(YN=='Y' || YN=='y'){

                    opc=' ';

                }else{

                    if(GoodScore(mysql, game, &playerID)==true){

                        printf("Antes de sair deseja registrar sua pontuação? [Y/n]");
                        YN=getchar();

                        if(YN=='Y' || YN=='y'){

                            system("clear");
                            __fpurge(stdin);

                            SaveScore(mysql, game, playerID);
                        }
                    }

                    printf("Saindo...\n\n");
                }

                break;

            case '4':

                if(mysql_query(&mysql->connection, "select * from players_score")!=0){

                    printf("Falha na conexão\nTente novamente mais tarde...\n\n");

                }else{

                    mysql->res=mysql_store_result(&mysql->connection);

                    while((mysql->row=mysql_fetch_row(mysql->res))!=NULL){

                        for(unsigned int i=0; i<mysql_num_fields(mysql->res); i++){

                            printf("%s\t", mysql->row[i]);
                        }

                        printf("\n");
                    }

                    mysql_free_result(mysql->res);
                }

                break;

            case '5':

                if(GoodScore(mysql, game, &playerID)==true){

                    printf("Antes de sair deseja registrar sua pontuação? [Y/n]");
                    YN=getchar();

                    system("clear");
                    __fpurge(stdin);

                    if(YN=='Y' || YN=='y'){

                        SaveScore(mysql, game, playerID);
                    }
                }

                printf("Saindo...\n\n");

                break;

            default:

                system("clear");

                printf("Opção incorreta\n\n");

                break;
        }

    }while(opc!='1' && opc!='2' && opc!='3' && opc!='5');

    mysql_close(&mysql->connection);

    free(mysql);
    free(game);

    return 0;
}

void MysqlStartConnection(Mysql *ptr_mysql){

    mysql_init(&ptr_mysql->connection);

    if(mysql_real_connect(&ptr_mysql->connection, "127.0.0.1", "root", "tkfstwa", "hangman", 3306, NULL, 0)){

        printf("Conexão: Ok!\n\n");

    }else{

        printf("Conexão: falhou...\nTente novamente mais tarde\n\n");

        exit(1);
    }
}


void animals(Mysql *ptr_mysql, Game *ptr_game){

    if(mysql_query(&ptr_mysql->connection, "select * from animals;")!=0){

        printf("Falha na conexão\nTente novamente mais tarde...\n\n");
        exit(1);
    }

    ptr_mysql->res=mysql_store_result(&ptr_mysql->connection);

    unsigned int total=mysql_num_rows(ptr_mysql->res);

    mysql_free_result(ptr_mysql->res);

    srand((unsigned int)time(NULL));
    unsigned int raffle=rand()%total+1;

    char query[65];

    snprintf(query, 65, "select secret_word, tip, chances from animals where id='%d';", raffle);

    if(mysql_query(&ptr_mysql->connection, query)!=0){

        printf("Falha na conexão\nTente novamente mais tarde...\n\n");
        exit(1);
    }

    ptr_mysql->res=mysql_store_result(&ptr_mysql->connection);

    while((ptr_mysql->row=mysql_fetch_row(ptr_mysql->res))!=NULL){

        for(unsigned int i=0; i<mysql_num_fields(ptr_mysql->res); i++){

            if(i==0){

                strcpy(ptr_game->secret_word, ptr_mysql->row[i]);

            }else if(i==1){

                strcpy(ptr_game->tip, ptr_mysql->row[i]);

            }else if(i==2){

                ptr_game->chances=atoi(ptr_mysql->row[i]);
            }
        }
    }

    mysql_free_result(ptr_mysql->res);
}

void fruits(Mysql *ptr_mysql, Game *ptr_game){

    if(mysql_query(&ptr_mysql->connection, "select * from fruits;")!=0){

        printf("Falha na conexão\nTente novamente mais tarde...\n\n");
        exit(1);
    }

    ptr_mysql->res=mysql_store_result(&ptr_mysql->connection);

    unsigned int total=mysql_num_rows(ptr_mysql->res);

    mysql_free_result(ptr_mysql->res);

    srand((unsigned int)time(NULL));
    unsigned int raffle=rand()%total+1;

    char query[65];

    snprintf(query, 65, "select secret_word, tip, chances from fruits where id='%d';", raffle);

    if(mysql_query(&ptr_mysql->connection, query)!=0){

        printf("Falha na conexão\nTente novamente mais tarde...\n\n");
        exit(1);
    }

    ptr_mysql->res=mysql_store_result(&ptr_mysql->connection);

    while((ptr_mysql->row=mysql_fetch_row(ptr_mysql->res))!=NULL){

        for(unsigned int i=0; i<mysql_num_fields(ptr_mysql->res); i++){

            if(i==0){

                strcpy(ptr_game->secret_word, ptr_mysql->row[i]);

            }else if(i==1){

                strcpy(ptr_game->tip, ptr_mysql->row[i]);

            }else if(i==2){

                ptr_game->chances=atoi(ptr_mysql->row[i]);
            }
        }
    }

    mysql_free_result(ptr_mysql->res);
}

void objects(Mysql *ptr_mysql, Game *ptr_game){

    if(mysql_query(&ptr_mysql->connection, "select * from objects;")!=0){

        printf("Falha na conexão\nTente novamente mais tarde...\n\n");
        exit(1);
    }

    ptr_mysql->res=mysql_store_result(&ptr_mysql->connection);

    unsigned int total=mysql_num_rows(ptr_mysql->res);

    mysql_free_result(ptr_mysql->res);

    srand((unsigned int)time(NULL));
    unsigned int raffle=rand()%total+1;

    char query[65];

    snprintf(query, 65, "select secret_word, tip, chances from objects where id='%d';", raffle);

    if(mysql_query(&ptr_mysql->connection, query)!=0){

        printf("Falha na conexão\nTente novamente mais tarde...\n\n");
        exit(1);
    }

    ptr_mysql->res=mysql_store_result(&ptr_mysql->connection);

    while((ptr_mysql->row=mysql_fetch_row(ptr_mysql->res))!=NULL){

        for(unsigned int i=0; i<mysql_num_fields(ptr_mysql->res); i++){

            if(i==0){

                strcpy(ptr_game->secret_word, ptr_mysql->row[i]);

            }else if(i==1){

                strcpy(ptr_game->tip, ptr_mysql->row[i]);

            }else if(i==2){

                ptr_game->chances=atoi(ptr_mysql->row[i]);
            }
        }
    }

    mysql_free_result(ptr_mysql->res);
}

bool hangman(Game *ptr_game){

    char word[51];
    unsigned int i;

    for(i=0; i<strlen(ptr_game->secret_word); i++){

        (ptr_game->secret_word[i]==' ') ? (word[i]=' ') : (word[i]='_');
    }

    word[i]='\0';

    ptr_game->score.points=0;
    ptr_game->score.errors=0;

    char letter;
    int counter;

    bool winner;

    while(true){

        counter=0;

        printf("Dica: %s\n", ptr_game->tip);
        printf("Chances restantes: %d\n", ptr_game->chances);
        printf("%s\n\n", word);

        printf("Digite uma letra >");
        letter=getchar();

        __fpurge(stdin);
        system("clear");

        if(fchar(word, letter)!=-1){

            printf("Atenção: Você já digitou a letra %c\n\n", letter);

        }else{

            for(unsigned int i=0; i<strlen(ptr_game->secret_word); i++){

                if(letter==ptr_game->secret_word[i]){

                    word[i]=ptr_game->secret_word[i];

                    counter++;
                }
            }

            if(counter!=0){

                ptr_game->score.points++;

            }else{

                ptr_game->score.errors++;
                ptr_game->chances--;
            }
        }

        if(ptr_game->chances==0){

            winner=false;

            ptr_game->score.total_points+=ptr_game->score.points;
            ptr_game->score.total_errors+=ptr_game->score.errors;
            ptr_game->score.total_matches++;
            ptr_game->score.total_losses++;

            break;

        }else if(strcmp(ptr_game->secret_word, word)==0){

            winner=true;

            ptr_game->score.total_points+=ptr_game->score.points;
            ptr_game->score.total_errors+=ptr_game->score.errors;
            ptr_game->score.total_matches++;
            ptr_game->score.total_wins++;

            break;
        }
    }

    return winner;
}

bool GoodScore(Mysql *ptr_mysql, Game *ptr_game, short int *playerID){

    char query[151];
    bool good_score=false;

    snprintf(query, 151, "select playerID from players_score where total_points <='%d' and"
            " total_errors >='%d' or total_errors <='10' order by total_points asc;",
            ptr_game->score.total_points, ptr_game->score.total_errors);

    if(mysql_query(&ptr_mysql->connection, query)!=0){

        printf("Falha na conexão\nTente novamente mais tarde...\n\n");

    }else{

        ptr_mysql->res=mysql_store_result(&ptr_mysql->connection);

        ptr_mysql->row=mysql_fetch_row(ptr_mysql->res);

        if(ptr_mysql->row!=NULL){

            *playerID=atoi(ptr_mysql->row[0]);
            good_score=true;
        }

        mysql_free_result(ptr_mysql->res);
    }

    return good_score;
}

void SaveScore(Mysql *ptr_mysql, Game *ptr_game, short int playerID){

    short int response;
    char nickname[22];

    do{

        printf("Digite um nickname > ");
        response=getNick(nickname);

        system("clear");

        if(response==-1){

            printf("**Não use espaços em branco**\n-> Por favor, insira outro nickname <-\n\n");

        }else if(response==1){

             printf("**O maximo de caracteres para o nickname é 20**\n-> Por favor, insira outro nickname <-\n\n");

        }else{

            break;
        }

    }while(true);

    char query[101];

    if(mysql_query(&ptr_mysql->connection, "select count(*) from players_score;")!=0){

        printf("Falha na conexão\nTente novamente mais tarde...\n\n");

    }else{

        ptr_mysql->res=mysql_store_result(&ptr_mysql->connection);

        ptr_mysql->row=mysql_fetch_row(ptr_mysql->res);

        short int q=atoi(ptr_mysql->row[0]);

        mysql_free_result(ptr_mysql->res);

        if(q>=10){

            snprintf(query, 101, "delete from players_score where playerID='%d' limit 1;", playerID);

            if(mysql_query(&ptr_mysql->connection, query)!=0){

                printf("Falha na conexão\nTente novamente mais tarde...\n\n");
            }
        }
    }

    snprintf(query, 101, "insert into players_score values(DEFAULT, '%s', '%d', '%d', '%d', '%d', '%d');",
                nickname, ptr_game->score.total_points, ptr_game->score.total_errors, ptr_game->score.total_wins,
                ptr_game->score.total_losses, ptr_game->score.total_matches);

    if(mysql_query(&ptr_mysql->connection, query)!=0){

        printf("Falha na conexão\nTente novamente mais tarde...\n\n");

    }else{

        printf("Pontuação salva com sucesso\n\n");
    }
}

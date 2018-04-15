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

    char secret_word[81], tip[256];
    int chances;
    Score score;

}Game;

void MysqlStartConnection(Mysql *ptr_mysql);

void animals(Mysql *ptr_mysql, Game *ptr_game);
void fruits(Mysql *ptr_mysql, Game *ptr_game);
void objects(Mysql *ptr_mysql, Game *ptr_game);

bool hangman(Game *ptr_game);

void SaveScore(Mysql *ptr_mysql, Game *ptr_game);

int main(void){

    Mysql *mysql=(Mysql*)malloc(sizeof(Mysql));
    Game *game=(Game*)calloc(1, sizeof(Game));

    MysqlStartConnection(mysql);

    char opc, YN;

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

        switch(opc){

            case '1':

                animals(mysql, game);

                if(hangman(game)!=true){

                    printf("Você perdeu!!!\nO animal secreto era %s\n", game->secret_word);
                    printf("Total de acertos: %d\n", game->score.points);
                    printf("Total de erros: %d\n", game->score.errors);
                    printf("Partidas vencidas: %d\n", game->score.total_wins);
                    printf("Partidas perdidas: %d\n", game->score.total_losses);
                    printf("Total de partidas jogadas: %d\n", game->score.total_matches);

                }else{

                    printf("Você ganhou!!!\nO animal secreto era %s\n", game->secret_word);
                    printf("Total de acertos: %d\n", game->score.points);
                    printf("Total de erros: %d\n", game->score.errors);
                    printf("Partidas vencidas: %d\n", game->score.total_wins);
                    printf("Partidas perdidas: %d\n", game->score.total_losses);
                    printf("Total de partidas jogadas: %d\n", game->score.total_matches);
                }

                printf("Deseja continuar jogando? [Y/n]");
                YN=getchar();

                if(YN=='Y' || YN=='y'){

                    opc=' ';

                }else{

                    if(game->score.total_matches>=3){

                        printf("Antes de sair deseja registrar sua pontuação? [Y/n]");
                        YN=getchar();

                        system("clear");

                        if(YN=='Y' || YN=='y'){

                            SaveScore(mysql, game);
                        }
                    }

                    printf("Saindo...\n\n");
                }

                break;

            case '2':

                fruits(mysql, game);

                if(hangman(game)!=true){

                    printf("Você perdeu!!!\nA fruta secreta era %s\n", game->secret_word);
                    printf("Total de acertos: %d\n", game->score.points);
                    printf("Total de erros: %d\n", game->score.errors);
                    printf("Partidas vencidas: %d\n", game->score.total_wins);
                    printf("Partidas perdidas: %d\n", game->score.total_losses);
                    printf("Total de partidas jogadas: %d\n", game->score.total_matches);

                }else{

                    printf("Você ganhou!!!\nA fruta secreta era %s\n", game->secret_word);
                    printf("Total de acertos: %d\n", game->score.points);
                    printf("Total de erros: %d\n", game->score.errors);
                    printf("Partidas vencidas: %d\n", game->score.total_wins);
                    printf("Partidas perdidas: %d\n", game->score.total_losses);
                    printf("Total de partidas jogadas: %d\n", game->score.total_matches);
                }

                printf("Deseja continuar jogando? [Y/n]");
                YN=getchar();

                if(YN=='Y' || YN=='y'){

                    opc=' ';

                }else{

                    if(game->score.total_matches>=3){

                        printf("Antes de sair deseja registrar sua pontuação? [Y/n]");
                        YN=getchar();

                        system("clear");

                        if(YN=='Y' || YN=='y'){

                            SaveScore(mysql, game);
                        }
                    }

                    printf("Saindo...\n\n");
                }

                break;

            case '3':

                objects(mysql, game);

                if(hangman(game)!=true){

                    printf("Você perdeu!!!\nO objeto secreto era %s\n", game->secret_word);
                    printf("Total de acertos: %d\n", game->score.points);
                    printf("Total de erros: %d\n", game->score.errors);
                    printf("Partidas vencidas: %d\n", game->score.total_wins);
                    printf("Partidas perdidas: %d\n", game->score.total_losses);
                    printf("Total de partidas jogadas: %d\n", game->score.total_matches);

                }else{

                    printf("Você ganhou!!!\nO animal secreto era %s\n", game->secret_word);
                    printf("Total de acertos: %d\n", game->score.points);
                    printf("Total de erros: %d\n", game->score.errors);
                    printf("Partidas vencidas: %d\n", game->score.total_wins);
                    printf("Partidas perdidas: %d\n", game->score.total_losses);
                    printf("Total de partidas jogadas: %d\n", game->score.total_matches);
                }

                printf("Deseja continuar jogando? [Y/n]");
                YN=getchar();

                if(YN=='Y' || YN=='y'){

                    opc=' ';

                }else{

                    if(game->score.total_matches>=3){

                        printf("Antes de sair deseja registrar sua pontuação? [Y/n]");
                        YN=getchar();

                        system("clear");

                        if(YN=='Y' || YN=='y'){

                            SaveScore(mysql, game);
                        }
                    }

                    printf("Saindo...\n\n");
                }

                break;

            case '4':


                break;

            case '5':

                if(game->score.total_matches>=3){

                    printf("Antes de sair deseja registrar sua pontuação? [Y/n]");
                    YN=getchar();

                    system("clear");

                    if(YN=='Y' || YN=='y'){

                        SaveScore(mysql, game);
                    }
                }

                printf("Saindo...\n\n");

                break;

            default:

                system("clear");

                printf("Opção incorreta\n\n");

                break;
        }

    }while(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5');

    mysql_close(&mysql->connection);

    free(mysql);
    free(game);

    return 0;
}

void MysqlStartConnection(Mysql *ptr_mysql){

    mysql_init(&ptr_mysql->connection);

    if(mysql_real_connect(&ptr_mysql->connection, "127.0.0.1", "root", "xururuca", "hangman", 3306, NULL, 0)){

        printf("Conexão: Ok!\n\n");

    }else{

        printf("Conexão: falhou\nTente novamente mais tarde\n\n");
    }
}


void animals(Mysql *ptr_mysql, Game *ptr_game){

    mysql_query(&ptr_mysql->connection, "select * from animals");

    ptr_mysql->res=mysql_store_result(&ptr_mysql->connection);

    unsigned int total=mysql_num_rows(ptr_mysql->res);

    mysql_free_result(ptr_mysql->res);

    srand((unsigned int)time(NULL));
    unsigned int raffle=rand()%total+1;

    char query[101];

    snprintf(query, 101, "select secret_word, tip, chances from animals where id=%d;", raffle);

    mysql_query(&ptr_mysql->connection, query);

    ptr_mysql->res=mysql_store_result(&ptr_mysql->connection);

    while((ptr_mysql->row=mysql_fetch_row(ptr_mysql->res))!=NULL){

        for(unsigned int i=0; i<mysql_num_rows(ptr_mysql->res); i++){

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

    mysql_query(&ptr_mysql->connection, "select * from fruits");

    ptr_mysql->res=mysql_store_result(&ptr_mysql->connection);

    unsigned int total=mysql_num_rows(ptr_mysql->res);

    mysql_free_result(ptr_mysql->res);

    srand((unsigned int)time(NULL));
    unsigned int raffle=rand()%total+1;

    char query[101];

    snprintf(query, 101, "select secret_word, tip, chances from fruits where id=%d;", raffle);

    mysql_query(&ptr_mysql->connection, query);

    ptr_mysql->res=mysql_store_result(&ptr_mysql->connection);

    while((ptr_mysql->row=mysql_fetch_row(ptr_mysql->res))!=NULL){

        for(unsigned int i=0; i<mysql_num_rows(ptr_mysql->res); i++){

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

    mysql_query(&ptr_mysql->connection, "select * from objects");

    ptr_mysql->res=mysql_store_result(&ptr_mysql->connection);

    unsigned int total=mysql_num_rows(ptr_mysql->res);

    mysql_free_result(ptr_mysql->res);

    srand((unsigned int)time(NULL));
    unsigned int raffle=rand()%total+1;

    char query[101];

    snprintf(query, 101, "select secret_word, tip, chances from objects where id='%d';", raffle);

    mysql_query(&ptr_mysql->connection, query);

    ptr_mysql->res=mysql_store_result(&ptr_mysql->connection);

    while((ptr_mysql->row=mysql_fetch_row(ptr_mysql->res))!=NULL){

        for(unsigned int i=0; i<mysql_num_rows(ptr_mysql->res); i++){

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

    char word[81];
    unsigned int i;

    for(i=0; i<strlen(ptr_game->secret_word); i++){

        (ptr_game->secret_word[i]==' ') ? (word[i]=' ') : (word[i]='_');
    }

    word[i+1]='\0';

    char letter;
    int counter;

    bool winner;

    while(true){

        counter=0;

        printf("Dica: %s\n", ptr_game->tip);
        printf("Chances restantes: %d\n", ptr_game->chances);
        printf("%s\n\n", word);

        letter=getchar();

        system("clear");

        if(fchar(word, letter)!=-1){

            printf("Atenção: Você já digitou a letra %c\n\n", letter);

        }else{

            for(unsigned int i=0; strlen(ptr_game->secret_word); i++){

                if(letter==ptr_game->secret_word[i]){

                    word[i]=ptr_game->secret_word[i];

                    counter++;
                }
            }

            if(counter!=0){

                ptr_game->score.points++;
                ptr_game->chances--;

            }else{

                ptr_game->score.errors++;
            }
        }

        if(ptr_game->chances==0){

            winner=false;

            ptr_game->score.total_points=ptr_game->score.points;
            ptr_game->score.total_errors=ptr_game->score.errors;
            ptr_game->score.total_matches++;
            ptr_game->score.total_losses++;

            break;

        }else if(strcmp(ptr_game->secret_word, word)==0){

            winner=true;

            ptr_game->score.total_points=ptr_game->score.points;
            ptr_game->score.total_errors=ptr_game->score.errors;
            ptr_game->score.total_matches++;
            ptr_game->score.total_wins++;

            break;
        }
    }

    return winner;
}

void SaveScore(Mysql *ptr_mysql, Game *ptr_game){

    char nickname[21];
    char password[100];
    char query[101];

    printf("OBSERVAÇÕES:\n* O nickname inserido deve ter no maximo 20 caracters e sem espaços em branco.");
    printf("* A senha digitada deve conter no mínimo 3 caracters.\n\n");

    bool exitLoop=false;
    int response_value_nick, response_value_pass;

    do{

        printf("Crie um nickname para registrar sua pontuação->");
        response_value_nick=getNick(nickname, 21);

        printf("Crie uma senha ->");
        response_value_pass=getPass(password, 100);

        system("clear");

        snprintf(query, 101, "select * from players_score where nickname='%s';", nickname);

        mysql_query(&ptr_mysql->connection, query);

        ptr_mysql->res=mysql_store_result(&ptr_mysql->connection);

        ptr_mysql->row=mysql_fetch_row(ptr_mysql->res);

        if(ptr_mysql->row!=NULL){

            printf("O nickname inserido já existe!!!\n\n");

        }else if(response_value_nick==-1){

            printf("O nickname não pode conter espaços em branco.\nDigite outro nickname por favor.\n\n");

        }else if(response_value_pass==-1){

            printf("Senha digitada muito pequena.\nDigite outra por favor.\n\n");

        }else{

            exitLoop=true;
        }

    }while(exitLoop==false);

    mysql_free_result(ptr_mysql->res);

    snprintf(query, 101, "insert into players_score values (DEFAULT, '%s', '%s', '%d', %d', '%d', '%d', '%d');",
             nickname, password, ptr_game->score.total_points, ptr_game->score.total_errors,
             ptr_game->score.total_wins, ptr_game->score.total_losses, ptr_game->score.total_matches);

    if(mysql_query(&ptr_mysql->connection, query)!=0){

        printf("Erro de coenxão com o banco de dados\nTente novamente mais tarde\n\n");

    }else{

        printf("Pontuação salva com sucesso\n\n");
    }
}


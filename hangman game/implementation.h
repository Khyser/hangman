#ifndef IMPLEMENTATION_H_INCLUDED
#define IMPLEMENTATION_H_INCLUDED

#include <string.h>

unsigned int fchar(char *_string, char character){

    unsigned int i, posi;

    for(i=0; i<strlen(_string); i++){

        if(_string[i]==character){

            posi=i;
        }
    }

    return posi;
}

int getPass(char *pass, unsigned int _size){

    fgets(pass, _size, stdin);

    for(unsigned int i=0; i<strlen(pass); i++){

        if(pass[i]=='\n'){

            pass[i]='\0';
        }
    }

    int return_value;

    if(strlen(pass)<3){

        return_value=-1;
    }

    return return_value;
}

int getNick(char *nick, unsigned int _size){

    fgets(nick, _size, stdin);

    unsigned int i, return_value=0;

    for(i=0; i<strlen(nick); i++){

        if(nick[i]==' '){

            return_value=-1;
            break;

        }else if(nick[i]=='\n'){

            nick[i]='\0';
        }
    }

    return return_value;
}

void getString(char *_string, unsigned int _size){

    fgets(_string, _size, stdin);

    for(unsigned int i=0; i<strlen(_string); i++){

        if(_string[i]=='\n'){

            _string[i]='\0';
        }
    }
}

#endif // IMPLEMENTATION_H_INCLUDED

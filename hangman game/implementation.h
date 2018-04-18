#ifndef IMPLEMENTATION_H_INCLUDED
#define IMPLEMENTATION_H_INCLUDED

#include <string.h>

unsigned int fchar(char *_string, char character){

    unsigned int i, posi=-1;

    for(i=0; i<strlen(_string); i++){

        if(_string[i]==character){

            posi=i;
        }
    }

    return posi;
}

short int getNick(char *nick){

    fgets(nick, 22, stdin);

    short int return_value=0;

    if(strlen(nick)>20){

        return_value=1;

    }else{

        for(unsigned int i=0; i<strlen(nick); i++){

            if(nick[i]==' '){

                return_value=-1;
                break;

            }else if(nick[i]=='\n'){

                nick[i]='\0';
            }
        }
    }

    return return_value;
}

#endif // IMPLEMENTATION_H_INCLUDED

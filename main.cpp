/* ---------------------------
Laboratoire : 02
Auteur(s) : Diana Laurenti, Stan Stelcher, Cédric Kreis
Date : 13.10.2022
But : recherche dichotomique sous la forme d’un jeu avec l’utilisateur via un programme cpp.
Remarque(s) : main.cpp
--------------------------- */

#include <iostream>

using namespace std;

int main() {
    //input mode and check if it is acceptable
    const char MODE_TEST = 't';
    const char MODE_GAME = 'j';
    char mode = 'a';
    while (mode != MODE_GAME && mode != MODE_TEST){ //until the user doesn't input the character 'j' or 't'
        cout << "Mode jeu ou mode test ? Veuillez repondre par '" << MODE_GAME << "' ou '" << MODE_TEST << "' : ";
        cin >> mode;
    }

    //input dichotomy method and check if it is acceptable
    const char METHOD_DEFAULT = 'd';
    const char METHOD_RAND = 'r';
    char dichotomyMethod = 'a';
    while (dichotomyMethod != METHOD_DEFAULT && dichotomyMethod != METHOD_RAND){ //until the user doesn't input the character 'd' or 'r'
        cout << "Methode default ou random ? Veuillez repondre par '" << METHOD_DEFAULT << "' ou '" << METHOD_RAND << "' : ";
        cin >> dichotomyMethod;
    }

    //input interval limits and check if they are acceptable
    int lowerLimit = 0;
    int higerLimit = 0;
    while(lowerLimit >= higerLimit){ //until the user doesn't input two limits that respect the requirements
        cout << "Entrez la borne inferieure de l'intervalle : ";
        cin >> lowerLimit;

        cout << "Entrez la borne superieure de l'intervalle : ";
        cin >> higerLimit;
    }

    int num = 0;
    const char YES = 'o';
    const char NO = 'n';
    //check if mode t or j
    if(mode == MODE_GAME){
        //ask to pick up a number (without input) and to answer n or o
        cout << "Veuillez choisir un nombre dans cet intervalle, "
                "puis repondre aux questions par '" << YES << "' ou '" << NO << "'. " << endl;
    }else{ //if mode t //
        do{ //until the user doesn't input a number included in the interval
            //ask to enter the chosen number and check if it's included in the interval
            cout << "Entrez le nombre que vous avez choisi : ";
            cin >> num;
        }while(num > higerLimit || num < lowerLimit);
    }

    //dichotomic research
    int iterator = 1;
    int X = 0;

    while(higerLimit-lowerLimit != 0 ){ //until the redefined lower limit matches the redefined higher limit
        if(dichotomyMethod == METHOD_RAND){
            X = rand() % (higerLimit - lowerLimit) + lowerLimit; //define the splitter: a random number included in the interval
        }else{ //if dichotomy method is default
            X = (higerLimit - lowerLimit)/2 + lowerLimit; //define the splitter of the interval
        }
        cout << iterator++ << ". Le nombre est-il plus petit ou egal a " << X << " ? ";
        char answer = 'a';
        if(mode == MODE_TEST){
            answer = (num <= X) ? YES : NO;
            cout << answer << endl;
        }else{ //if j mode
            while(answer != NO && answer != YES){ //until the user doesn't input the character 'n' or 'o'
                cin >> answer;
            }
        }
        if(answer == YES){
            higerLimit = X;
        }else{ //if answer == 'n'
            lowerLimit = X + 1; //redefine the lower limit as the splitter + 1 (because we ask if the number is inferior or equal to)
            if(higerLimit - X == 1){
                ++X;
            }
        }
    }

    cout << "Le nombre choisi est " << X;

    return 0;
}

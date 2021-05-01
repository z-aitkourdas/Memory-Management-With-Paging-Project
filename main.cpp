#include "Paging.h"
#include <iostream>

void afficherMenu();
void afficherGroupe();

int main(int argc, char** argv) {
    Pagination memoireCentrale(25);

    int option(0);

    system("CLS");
    afficherGroupe();
    system("pause");
    do {
        system("CLS");
        afficherMenu();
        std::cout << "\n\t Entrer le numero de votre choix: ";
        std::cin >> option;
        std::cin.ignore();

        switch (option) {
        case 1: {
            system("CLS");

            std::cout << "\t\t\t ------------------------------------- " << std::endl;
            std::cout << "\t\t\t|    Chargement du programme en MC    |" << std::endl;
            std::cout << "\t\t\t ------------------------------------- " << std::endl;

            std::cout << "\n\n" << std::endl;

            std::string program_name;
            int size;

            std::cout << "\tEntrer le nom du programme\t\t: ";
            std::getline(std::cin, program_name);

            std::cout << "\tEntrer la taille du programme (en page)\t: ";
            std::cin >> size;
            std::cin.ignore();

            memoireCentrale.addProgram(program_name, size);

            std::cout << "\n\n" << std::endl;

            system("pause");
            break;
        }
        case 2: {
            system("CLS");

            std::cout << "\t\t\t ------------------------------------------------- " << std::endl;
            std::cout << "\t\t\t|    Affichage de toutes les pages libre en MC    |" << std::endl;
            std::cout << "\t\t\t ------------------------------------------------- " << std::endl;

            std::cout << "\n\n" << std::endl;

            memoireCentrale.listFreePages();

            system("pause");
            break;
        }
        case 3: {
            system("CLS");

            std::cout << "\t\t\t ---------------------------------------------- " << std::endl;
            std::cout << "\t\t\t|    Affichage de tous les programmes en MC    |" << std::endl;
            std::cout << "\t\t\t ---------------------------------------------- " << std::endl;

            std::cout << "\n\n" << std::endl;

            memoireCentrale.listPrograms();

            system("pause");
            break;
        }
        case 4: {
            system("CLS");

            std::cout << "\t\t\t ---------------------------------------------------- " << std::endl;
            std::cout << "\t\t\t|    Affichage de toutes les pages d'un programme    |" << std::endl;
            std::cout << "\t\t\t ---------------------------------------------------- " << std::endl;

            std::cout << "\n\n" << std::endl;

            std::string program_name;
            std::cout << "\tEntrer le nom du programme\t: ";
            std::getline(std::cin, program_name);

            memoireCentrale.listProgramPages(program_name);

            system("pause");
            break;
        }
        case 5: {
            system("CLS");

            std::cout << "\t\t\t -----------------------------------------------------" << std::endl;
            std::cout << "\t\t\t|    Affichage des pages pour tous les programmes    |" << std::endl;
            std::cout << "\t\t\t -----------------------------------------------------" << std::endl;

            std::cout << "\n\n" << std::endl;

            memoireCentrale.listAllProgramsPages();

            system("pause");
            break;
        }
        case 6: {
            system("CLS");

            std::cout << "\t\t\t ------------------------------------------- " << std::endl;
            std::cout << "\t\t\t|    Terminer l'execution d'un programme    |" << std::endl;
            std::cout << "\t\t\t ------------------------------------------- " << std::endl;

            std::cout << "\n\n" << std::endl;

            std::string program_name;
            std::cout << "\tEntrer le nom du programme\t: ";
            std::getline(std::cin, program_name);

            memoireCentrale.deleteProgram(program_name);

            system("pause");
            break;
        }
        case 7: {
            system("CLS");

            std::cout << "\t\t\t ---------------------------------------------- " << std::endl;
            std::cout << "\t\t\t|    Afficher l'etat de la memoire centrale    |" << std::endl;
            std::cout << "\t\t\t ---------------------------------------------- " << std::endl;

            std::cout << "\n\n" << std::endl;

            memoireCentrale.showMemoryStat();

            system("pause");
            break;
        }

        case 8:
            // exit
            system("CLS");

            memoireCentrale.exit();

            std::cout << "\n\nA bientot!\n\n" << std::endl;
            system("pause");
            break;
        default:
            std::cout << "Votre choix n'esiste pas dans notre menu !!!\n" << std::endl;
        }

    } while (option != 8);

    return 0;
}

void afficherGroupe() {
    std::cout << " -----------------------" << std::endl;
    std::cout << "|\t Goupe 3\t|" << std::endl;
    std::cout << " -----------------------" << std::endl;
    std::cout << "| -Asmae AJERD\t\t|" << std::endl;
    std::cout << "| -Imane AOUA\t\t|" << std::endl;
    std::cout << "| -Zouhair AIT KOURDAS\t|" << std::endl;
    std::cout << "| -Douae DANI\t\t|" << std::endl;
    std::cout << "| -Abdelbadia OUALABACH\t|" << std::endl;
    std::cout << " -----------------------" << std::endl;
}

void afficherMenu() {
    std::cout << "\t\t\t\t ------------------------------------------------------------- \n"
        << "\t\t\t\t|                             Menu                            |\n"
        << "\t\t\t\t ------------------------------------------------------------- \n"
        << "\t\t\t\t|    1) Charger un programme en MC                            |\n"
        << "\t\t\t\t|    2) Afficher la liste des pages libre en MC               |\n"
        << "\t\t\t\t|    3) Afficher la liste des programmes en MC                |\n"
        << "\t\t\t\t|    4) Afficher la liste des pages d'un programme            |\n"
        << "\t\t\t\t|    5) Afficher la liste des pages pour tous les programmes  |\n"
        << "\t\t\t\t|    6) Terminer l'execution d'un programme                   |\n"
        << "\t\t\t\t|    7) Afficher l'etat de la memoire centrale                |\n"
        << "\t\t\t\t|    8) Quitter                                               |\n"
        << "\t\t\t\t ------------------------------------------------------------- \n\n";
}
#include "Paging.h"
#include <iostream>
#include <iomanip>
#include <vector>

Pagination::Pagination(int nb_pages) {
    centrale_memory_pages = nb_pages;

    head_prog = NULL;
    current_prog = NULL;
    temp_prog = NULL;

    temp_page = NULL;

    int i(1);

    PagePtr new_page = new Page;
    new_page->page_num = i;
    new_page->next = NULL;

    head_page = new_page;
    current_page = head_page;

    while (i < centrale_memory_pages) {
        i++;

        PagePtr new_page = new Page;
        new_page->page_num = i;
        new_page->next = NULL;

        current_page->next = new_page;
        current_page = current_page->next;
    }
    current_page = NULL;
};

void Pagination::listFreePages() {
    current_page = head_page;

    int nb(0);
    std::cout << " Liste des pages libres dans la memoire: \n ";

    while (current_page != NULL) {
        std::cout << current_page->page_num << std::setfill(' ') << std::setw(4);

        current_page = current_page->next;
        nb++;
    }
    if (nb == 0) {
        std::cout << "La memoire est pleine, il n'y a pas de pages libres!!";
    }
    std::cout << "\n" << std::endl;
};

void Pagination::listPrograms() {
    current_prog = head_prog;

    if (head_prog == NULL) {
        std::cout << "Aucun programme n'est charge en memoire!!" << std::endl;
    }
    else {
        int nb(0);
        std::cout << "\t Liste des programmes dans la memoire:" << std::endl;
        while (current_prog != NULL) {
            std::cout << "\t\t\t-> " << current_prog->program_name << std::endl;

            current_prog = current_prog->next;
            nb++;
        }
    }
    std::cout << std::endl << std::endl;
};

void Pagination::listProgramPages(std::string name) {
    current_prog = head_prog;

    while (current_prog->next != NULL && current_prog->program_name != name) {
        current_prog = current_prog->next;
    }
    if (current_prog->program_name == name) {
        current_page = current_prog->page_list;
        std::cout << "\n  Les pages memoire du programme '" << name << "' sont: " << std::endl;
        do {
            std::cout << "  P" << current_page->page_num;

            current_page = current_page->next;

        } while (current_page != NULL);

        std::cout << "\n" << std::endl;
    }
    else {
        std::cout << "Aucun programme avec ce nom!!" << std::endl;
    }
};

void Pagination::listAllProgramsPages() {
    if (head_prog == NULL) {
        std::cout << "Aucun programme n'est charge en memoire!!" << std::endl;
    }
    else {
        current_prog = head_prog;

        while (current_prog != NULL) {
            current_page = current_prog->page_list;
            std::cout << "\n   Liste des pages du programme '" 
                      << current_prog->program_name << "' sont:" << std::endl;
            do {
                std::cout << "   P" << current_page->page_num;

                current_page = current_page->next;

            } while (current_page != NULL);

            std::cout << "\n" << std::endl;

            current_prog = current_prog->next;
        }
    }
    std::cout << std::endl << std::endl;

};

int Pagination::chechSpace(int page_size) {
    current_page = head_page;
    int nb_pages(1);

    while (current_page != NULL && nb_pages <= page_size) {
        nb_pages++;
        current_page = current_page->next;
    }
    if (nb_pages > page_size) {
        // Il y a de l'espace dans la memoire
        return 1;
    }
    else {
        // Y a pas d'espace dans la memoire
        return 0;
    }
};

void Pagination::addProgram(std::string name, int pages) {
    if (this->chechSpace(pages) == 0) {
        std::cout << "\n Pas d'espace memoire pour ce programme!" << std::endl;
    }
    // Check if there is a memory space left
    else if (this->chechSpace(pages) == 1) {

        current_prog = head_prog;
        while (current_prog != NULL && current_prog->program_name != name) {
            current_prog = current_prog->next;
        }

        if (current_prog == NULL){
            ProgramPtr new_program = new Program;

            new_program->program_name = name;
            new_program->nb_pages = pages;
            new_program->page_list = head_page;

            if (head_prog != NULL) {
                current_prog = head_prog;
                temp_prog = head_prog;

                // Getting the position of the program
                while (current_prog->next != NULL) {
                    // temp_prog = current_prog;
                    current_prog = current_prog->next;
                }
                // Inserting the program to the programs list
                current_prog->next = new_program;
                new_program->next = NULL;
            }
            else {
                head_prog = new_program;
                new_program->next = NULL;
            }

            int counter(1);
            current_page = head_page;

            while (counter < pages) {
                current_page = current_page->next;

                counter++;
            }
            head_page = current_page->next;
            current_page->next = NULL;

            std::cout << "\n Programme a ete bien charge en memoire." << std::endl;
        }

        else if (current_prog->program_name == name) {
            std::cout << "\n Programme deja existant ! Veuiller introduire un programme dont le nom n'existe pas."
                << std::endl;
        }
    }
};

void Pagination::deleteProgram(std::string name) {
    current_prog = head_prog;
    temp_prog = head_prog;

    while (current_prog != NULL && current_prog->program_name != name) {
        temp_prog = current_prog;
        current_prog = current_prog->next;
    }
    if (current_prog->program_name == name) {
        if (head_prog == current_prog) {
            head_prog = current_prog->next;
        }
        else {
            temp_prog->next = current_prog->next;
        }

        current_page = current_prog->page_list;

        PagePtr page_place = new Page;
        PagePtr next_page_list = new Page;

        next_page_list = current_page->next;

        while (current_page != NULL) {
            page_place = head_page;
            temp_page = head_page;

            while (page_place->page_num < current_page->page_num && page_place != NULL) {
                temp_page = page_place;
                page_place = page_place->next;
            }
            if (page_place->page_num > current_page->page_num) {
                if (head_page == temp_page && head_page->page_num > current_page->page_num) {
                    head_page = current_page;
                }
                else {
                    temp_page->next = current_page;
                }
                current_page->next = page_place;
            }
            else if (page_place == NULL) {
                temp_page->next = current_page;
                current_page->next = NULL;
            }

            current_page = next_page_list;
            if (next_page_list != NULL) {
                next_page_list = next_page_list->next;
            }
        }
        current_prog->page_list = NULL;
        page_place = NULL;
        next_page_list = NULL;

        delete current_prog;
        delete page_place;
        delete next_page_list;

        std::cout << "\n\n  " << name << " a ete bien terminer." << std::endl;
    }
    else {
        std::cout << "Pas de programme avec ce nom!" << std::endl;
    }
};

void Pagination::exit() {
    current_prog = head_prog;

    while (current_prog != NULL) {
        this->deleteProgram(current_prog->program_name);
        current_prog = head_prog;
    }

    delete current_prog;
    temp_prog = NULL;
    delete temp_prog;
    delete head_prog;

    current_page = head_page;
    temp_page = head_page;

    while (current_page != NULL) {
        temp_page = temp_page->next;
        delete current_page;
        current_page = temp_page;
    }
    head_page = NULL;
    delete head_page;
    delete current_page;
    delete temp_page;
};

void Pagination::showMemoryStat() {
    current_prog = head_prog;

    std::vector<std::string> memory_stat(25, "////////");

    int num(0);
    while (current_prog != NULL) {
        current_page = current_prog->page_list;
        while (current_page != NULL) {
            num = current_page->page_num - 1;
            memory_stat[num] = current_prog->program_name;

            current_page = current_page->next;
        }
        current_prog = current_prog->next;
    }
    std::cout << " " << std::setw(49) << std::setfill('-') << "-" << std::endl;
    for (int i(1); i <= centrale_memory_pages; i++) {
        if (i % 5 == 0) {
            std::cout << "|" << std::setw(9) << std::setfill(' ') << memory_stat[i-1] << "|" << std::endl;
            std::cout << " " << std::setw(49) << std::setfill('-') << "-" << std::endl;
        }
        else{
            std::cout << "|" << std::setw(9) << std::setfill(' ') << memory_stat[i-1];
        }
    }

    std::cout << std::endl << std::endl;
};
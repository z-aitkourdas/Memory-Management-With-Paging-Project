#ifndef PAGING_H_INCLUDED
#define PAGING_H_INCLUDED

#include <string>

class Pagination {
private:
    typedef struct Page {
        int page_num;
        Page* next;
    }*PagePtr;

    typedef struct Program {
        std::string program_name;
        int nb_pages;
        Page* page_list;
        Program* next;
    }*ProgramPtr;

    ProgramPtr head_prog;
    ProgramPtr current_prog;
    ProgramPtr temp_prog;

    PagePtr head_page;
    PagePtr current_page;
    PagePtr temp_page;

    int centrale_memory_pages;


public:
    Pagination(int nb_pages);
    void addProgram(std::string name, int pages);
    void deleteProgram(std::string name);
    void listFreePages();
    void listPrograms();
    void listProgramPages(std::string name);
    void listAllProgramsPages();
    void showMemoryStat();
    void exit();
    int chechSpace(int page_size);
};

#endif // PAGING_H_INCLUDED
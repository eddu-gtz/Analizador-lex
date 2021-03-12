#ifndef STATES_H_INCLUDED
#define STATES_H_INCLUDED

#include <string>

class States{

private:
    int id;
    std::string estado;
    friend class Token;

public:

    States();


};

#endif // STATES_H_INCLUDED

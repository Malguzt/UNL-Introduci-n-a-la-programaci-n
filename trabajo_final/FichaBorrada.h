#ifndef FICHABORRADA_H
#define FICHABORRADA_H

#include "Ficha.h"


class FichaBorrada : public Ficha
{
    public:
        FichaBorrada(int xx, int yy);
        bool estaBorrada();
};

#endif // FICHABORRADA_H

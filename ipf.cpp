#include "ipf.h"

extern bool IPF_R = 1;
extern bool IPF_O = 1;
extern bool IPF_F_S = 1;
extern bool IPF_F = 1;

bool IP_filtration_check_result(int number)
{
    if (number == 1)
        return IPF_R;
    else if (number == 2)
        return IPF_O;
    else if (number == 3)
        return IPF_F_S;
    else if (number == 4)
        return IPF_F;
    else return 0;
}

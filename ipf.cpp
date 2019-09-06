#include "ipf.h"

bool IPF_R = 0;
bool IPF_O = 0;
bool IPF_F_S = 0;
bool IPF_F = 0;

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

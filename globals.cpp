#include "globals.h"

GLOBALS* GLOBALS::instance()
{
    static GLOBALS instance_;
    return &instance_;
}

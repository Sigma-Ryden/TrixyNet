#include <TrixyTestingBase.hpp>

automation::registry_t* trixy_testing_base()
{
    static automation::registry_t registry;
    return &registry;
}

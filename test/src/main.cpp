#include <TrixyTestingBase.hpp>

int main()
{
    TRY_CATCH(EXECUTE_ALL());
    TESTING_STAT();

    return 0;
}

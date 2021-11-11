#ifndef PROFILING_H
#define PROFILING_H

#define TRIXY_PROFILING(name) \
    namespace var_##name {    \
    extern int D;             \
    extern int C;             \
    extern int CC;            \
    extern int M;             \
    }

#endif // PROFILING_H

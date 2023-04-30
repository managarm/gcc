
#undef TARGET_MANAGARM
#define TARGET_MANAGARM 1

#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()		\
  do {						\
    builtin_define ("__managarm__");		\
    builtin_define ("__unix__");		\
    builtin_assert ("system=managarm");		\
    builtin_assert ("system=unix");		\
    builtin_assert ("system=posix");		\
  } while(0);


#undef GCC_AARCH64_MANAGARM
#define GCC_AARCH64_MANAGARM 1

#define GNU_USER_DYNAMIC_LINKER "/lib/x86_64-managarm/ld.so"

#define MANAGARM_TARGET_LINK_SPEC  "%{h*}		\
   %{static:-Bstatic}				\
   %{shared:-shared}				\
   %{symbolic:-Bsymbolic}			\
   %{!static:%{!static-pie:			\
     %{rdynamic:-export-dynamic}		\
     %{!shared:-dynamic-linker " GNU_USER_DYNAMIC_LINKER "}}} \
   %{static-pie:-Bstatic -pie --no-dynamic-linker -z text} \
   -X						\
   -EL						\
   -maarch64managarm"

#if TARGET_FIX_ERR_A53_835769_DEFAULT
#define CA53_ERR_835769_SPEC \
  " %{!mno-fix-cortex-a53-835769:--fix-cortex-a53-835769}"
#else
#define CA53_ERR_835769_SPEC \
  " %{mfix-cortex-a53-835769:--fix-cortex-a53-835769}"
#endif

#if TARGET_FIX_ERR_A53_843419_DEFAULT
#define CA53_ERR_843419_SPEC \
  " %{!mno-fix-cortex-a53-843419:--fix-cortex-a53-843419}"
#else
#define CA53_ERR_843419_SPEC \
  " %{mfix-cortex-a53-843419:--fix-cortex-a53-843419}"
#endif

#define LINK_SPEC MANAGARM_TARGET_LINK_SPEC \
                  CA53_ERR_835769_SPEC \
                  CA53_ERR_843419_SPEC

#define GNU_USER_TARGET_MATHFILE_SPEC \
  "%{Ofast|ffast-math|funsafe-math-optimizations:crtfastmath.o%s}"

#undef ENDFILE_SPEC
#define ENDFILE_SPEC   \
  GNU_USER_TARGET_MATHFILE_SPEC " " \
  GNU_USER_TARGET_ENDFILE_SPEC


#undef LIB_SPEC
#define LIB_SPEC ""

#undef STARTFILE_SPEC
#define STARTFILE_SPEC "crti.o%s %{shared:crtbeginS.o%s;:crtbegin.o%s}"

#undef ENDFILE_SPEC
#define ENDFILE_SPEC "%{shared:crtendS.o%s;:crtend.o%s} crtn.o%s"

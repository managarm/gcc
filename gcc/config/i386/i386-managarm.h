
#undef GCC_I386_MANAGARM
#define GCC_I386_MANAGARM 1

#define GNU_USER_LINK_EMULATION32 "elf_i386"
#define GNU_USER_LINK_EMULATION64 "elf_x86_64"
#define GNU_USER_LINK_EMULATIONX32 "elf32_x86_64"

#define GNU_USER_DYNAMIC_LINKER32 "/lib/i386-managarm/ld.so"
#define GNU_USER_DYNAMIC_LINKER64 "/lib/x86_64-managarm/ld.so"
#define GNU_USER_DYNAMIC_LINKERX32 "/lib/x86_64-managarm-x32/ld.so"

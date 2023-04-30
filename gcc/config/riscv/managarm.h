/* Definitions for RISC-V Managarm systems with ELF format.
   Adopted from the Linux definitions.
   Copyright (C) 1998-2021 Free Software Foundation, Inc.
   Managarm-specific changes by Alexander van der Grinten.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/* Because RISC-V only has word-sized atomics, it requries libatomic where
   others do not.  So link libatomic by default, as needed.  */
#undef LIB_SPEC
#ifdef LD_AS_NEEDED_OPTION
#define LIB_SPEC GNU_USER_TARGET_LIB_SPEC \
  " %{pthread:" LD_AS_NEEDED_OPTION " -latomic " LD_NO_AS_NEEDED_OPTION "}"
#else
#define LIB_SPEC GNU_USER_TARGET_LIB_SPEC " -latomic "
#endif

#define ICACHE_FLUSH_FUNC "__riscv_flush_icache"

#define CPP_SPEC "%{pthread:-D_REENTRANT}"

#define LD_EMUL_SUFFIX \
  "%{mabi=lp64d:}" \
  "%{mabi=lp64f:_lp64f}" \
  "%{mabi=lp64:_lp64}" \
  "%{mabi=ilp32d:}" \
  "%{mabi=ilp32f:_ilp32f}" \
  "%{mabi=ilp32:_ilp32}"

#define GNU_USER_DYNAMIC_LINKER "/lib/riscv-managarm/ld" XLEN_SPEC "-" ABI_SPEC ".so"

#define LINK_SPEC "\
-melf" XLEN_SPEC DEFAULT_ENDIAN_SPEC "riscv" LD_EMUL_SUFFIX " \
%{mno-relax:--no-relax} \
%{mbig-endian:-EB} \
%{mlittle-endian:-EL} \
%{shared} \
  %{!shared: \
    %{!static: \
      %{rdynamic:-export-dynamic} \
      -dynamic-linker " GNU_USER_DYNAMIC_LINKER "} \
    %{static:-static}}"

#define TARGET_ASM_FILE_END file_end_indicate_exec_stack

#define STARTFILE_PREFIX_SPEC 			\
   "/lib" XLEN_SPEC "/" ABI_SPEC "/ "		\
   "/usr/lib" XLEN_SPEC "/" ABI_SPEC "/ "	\
   "/lib/ "					\
   "/usr/lib/ "

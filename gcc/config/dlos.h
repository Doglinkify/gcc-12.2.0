/* Useful if you wish to make target-specific GCC changes. */
#undef TARGET_DLOS
#define TARGET_DLOS 1

/* Default arguments you want when running your
 *    i686-myos-gcc/x86_64-myos-gcc toolchain */
#undef LIB_SPEC
#define LIB_SPEC "-ldins" /* link against C standard library */

/* Files that are linked before user code.
 *    The %s tells GCC to look for these files in the library directory. */
#undef STARTFILE_SPEC
#define STARTFILE_SPEC "crt0.o%s init.o%s"

/* Files that are linked after user code. */
#undef ENDFILE_SPEC
#define ENDFILE_SPEC "fini.o%s"

/* Additional predefined macros. */
#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()      \
	  do {                                \
		      builtin_define ("__dlos__");      \
		      builtin_define ("__unix__");      \
		      builtin_assert ("system=myos");   \
		      builtin_assert ("system=unix");   \
		      builtin_assert ("system=posix");   \
		    } while(0);

gcc-plugins
===========

A few experiments with GCC plugins

# cstat
To collect warnings from each compilation unit - originally aimed to
collect the number of warnings from each file, but a source file might
include a header file (which might also have warnings ...).  Need to
have a way to figure out the source of the warnings.

# showdecl
From gcc repository:
  gcc/testsuite/g++.dg/plugin/decl\_plugin.c

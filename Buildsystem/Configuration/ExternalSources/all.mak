# Matthew Henderson, 30.10.2006 (Swansea)
# Copyright 2006-2007, 2008 Oliver Kullmann
# This file is part of the OKlibrary. OKlibrary is free software; you can redistribute 
# it and/or modify it under the terms of the GNU General Public License as published by
# the Free Software Foundation and included in this library; either version 3 of the 
# License, or any later version.

# Configuration variables regarding installation and documentation of external sources

global_targets_extsrc_okl ?= all clean cleanall update sat math buildsystem libraries compilers

sat_targets_extsrc_okl ?= ubcsat # grasp
math_targets_extsrc_okl ?= allmaxima gap R sage gmp
buildsystem_targets_extsrc_okl ?= git doxygen
compiler_targets_extsrc_okl ?= gcc
library_targets_extsrc_okl ?= boost mhash


ExternalSources_sources ?= $(ExternalSources)/sources

ExternalSources_installations ?= $(ExternalSources)/Installations
ExternalSources_doc ?= $(ExternalSources)/doc
ExternalSources_builds ?= $(ExternalSources)/builds

ext_src_checksum := md5sum

include $(OKconfiguration)/ExternalSources/coq.mak
include $(OKconfiguration)/ExternalSources/doxygen.mak
include $(OKconfiguration)/ExternalSources/gcc.mak
include $(OKconfiguration)/ExternalSources/git.mak
include $(OKconfiguration)/ExternalSources/gmp.mak
include $(OKconfiguration)/ExternalSources/ocaml.mak
include $(OKconfiguration)/ExternalSources/postgresql.mak
include $(OKconfiguration)/ExternalSources/r.mak
include $(OKconfiguration)/ExternalSources/sage.mak
include $(OKconfiguration)/ExternalSources/ubcsat.mak
include $(OKconfiguration)/ExternalSources/valgrind.mak
include $(OKconfiguration)/ExternalSources/clisp.mak
include $(OKconfiguration)/ExternalSources/ecl.mak
include $(OKconfiguration)/ExternalSources/maxima.mak
include $(OKconfiguration)/ExternalSources/asciidoc.mak
include $(OKconfiguration)/ExternalSources/gap.mak
include $(OKconfiguration)/ExternalSources/grasp.mak

# Currently, these installations need the list of gcc-targets:
include $(OKconfiguration)/ExternalSources/boost.mak
include $(OKconfiguration)/ExternalSources/mhash.mak
gcc_targets := $(addprefix $(gcc_targets_prefix_okl), $(gcc_supported_version_numbers_okl))
# Making local installation of gcc the default:
gcc_version_okl ?= $(gcc_recommended_version_number_okl)


# ################################
# Cmake
# ###############################

# NEEDS UPDATE

cmake_recommended_version_number ?= 2.4.7
cmake_supported_version_numbers ?= $(cmake_recommended_version_number)

cmake_prefix ?= cmake

cmake_homepage_url := http://www.cmake.org/HTML/Index.html
cmake_documentation_url := http://www.cmake.org/HTML/Documentation.html

cmake_targets_prefix := $(cmake_prefix)-
cmake_targets := $(addprefix $(cmake_targets_prefix), $(cmake_supported_version_numbers))
cmake_recommended := $(cmake_targets_prefix)$(cmake_recommended_version_number)

# ################################
# mpfr
# ###############################

# NEEDS UPDATE

mpfr_recommended_version_number ?= 2.3.0
mpfr_supported_version_numbers ?= $(mpfr_recommended_version_number)

mpfr_prefix ?= mpfr

mpfr_homepage_url := http://www.mpfr.org/

mpfr_targets_prefix := $(mpfr_prefix)-
mpfr_targets := $(addprefix $(mpfr_targets_prefix), $(mpfr_supported_version_numbers))
mpfr_recommended := $(mpfr_targets_prefix)$(mpfr_recommended_version_number)


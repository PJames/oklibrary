// Oliver Kullmann, 3.3.2006 (Swansea)

/*!
  \file Transitional/plans/milestones.hpp
  \brief Milestones for Transitional
*/

/*!
  \page CurrentVersions Current versions

  - Transitional 0.1.0 (3.3.2006)
  - OKlibrary 0.0.1 (3.3.2006)
*/

/*!
  \page PageTargetsTransitional Targets for Transitional

  \section StartingVersion010 Starting with version 0.1.0

  \subsection VersionTransitional011 0.1.1 : TO BE REACHED 11.12.2006
  \par AutarkySearch version 0.0.5 (ML (OK))
  (see AutarkySearch/plans/milestones.hpp)
  \par Literals version 0.0.3 (OK (MH, ML)) : DONE
  (see Literals/plans/milestones.hpp)
  \par Buildsystem version 0.1.2 (MH) : DONE
  (see Buildsystem/plans/milestones.hpp)
  \par AtomicConditions version 0.0.2 (OK (MH, ML)) : DONE
  (see AtomicConditions/plans/milestones.hpp)
  \par Concepts version 0.1.1 (OK (MH, ML)) : DONE
  (see Concepts/plans/milestones.hpp)
  \par Messages version 0.7.2 (OK) : DONE
  (see Messages/plans/milestones.hpp)
  \par TestSystem version 0.1.2 (OK) : DONE
  (see TestSystem/plans/milestones.hpp)
  \par All modules have plans-subdirectories, most with milestones (OK) : DONE

  \subsection VersionTransitional012 0.1.2 : TO BE REACHED 14.1.2007
  \par Buildsystem version 0.1.3 (MH (OK))
  (see Buildsystem/plans/milestones.hpp)
  \par Messages version 0.7.3 (OK (MH, ML))
  (see Messages/plans/milestones.hpp)
  \par TestSystem version 0.1.3 (OK (MH, ML))
  (see TestSystem/plans/milestones.hpp)
  \par Concepts version 0.1.3 (OK (MH, ML))
  (see Concepts/plans/milestones.hpp)
  \par AtomicConditions version 0.0.3 (OK (MH, ML))
  (see AtomicConditions/plans/milestones.hpp)
  \par Literals version 0.0.4 (OK (MH, ML))
  (see Literals/plans/milestones.hpp)
  \par PartialAssignments version 0.0.5 (OK (MH, ML))
  (see PartialAssignments/plans/milestones.hpp)
  \par LatinSquares version 0.0.5 (OK, MH)
  (see LatinSquares/plans/milestones.hpp)
  \par AutarkySearch version 0.0.6 (ML (OK))
  (see AutarkySearch/plans/milestones.hpp)
  \par Expand the following milestones regarding SAT-algorithms

  \subsection VersionTransitional013 0.1.3
  \par Buildsystem version 0.1.4 (MH)
  (see Buildsystem/plans/milestones.hpp)
  \par Messages version 0.7.3 (OK)
  (see Messages/plans/milestones.hpp)
  \par TestSystem version 0.1.4 (OK)
  (see TestSystem/plans/milestones.hpp)
  \par Concepts version 0.1.2 (OK (MH, ML))
  (see Concepts/plans/milestones.hpp)

  \subsection VersionTransitional014 0.1.4
  \par Buildsystem version 0.3 (MH)
  (see Buildsystem/plans/milestones.hpp)
  \par Messages version 0.7.4 (OK)
  (see Messages/plans/milestones.hpp)
  \par TestSystem version 0.1.5 (OK)
  (see TestSystem/plans/milestones.hpp)
  \par ComplexitySystem version 0.1 (MH (OK))
  (see ComplexitySystem/plans/milestones.hpp)
  \par Concepts version 0.2 (OK (MH, ML))
  (see Concepts/plans/milestones.hpp)

  \subsection VersionTransitional015 0.1.5
  \par Buildsystem version 0.4 (MH)
  (see Buildsystem/plans/milestones.hpp)
  \par Messages version 0.8 (OK)
  (see Messages/plans/milestones.hpp)
  \par TestSystem version 0.2 (OK)
  (see TestSystem/plans/milestones.hpp)
  \par ComplexitySystem version 0.2 (MH OK))
  (see ComplexitySystem/plans/milestones.hpp)

  \subsection VersionTransitional016 0.1.6
  \par Buildsystem version 0.5
  (see Buildsystem/plans/milestones.hpp)

  \subsection VersionTransitional017 0.1.7
  \par Buildsystem version 0.6
  (see Buildsystem/plans/milestones.hpp)

  \subsection VersionTransitional018 0.1.8
  \par Buildsystem version 0.7
  (see Buildsystem/plans/milestones.hpp)

  \subsection VersionTransitional019 0.1.9
  \par Buildsystem version 0.8
  (see Buildsystem/plans/milestones.hpp)
  \par Messages version 0.8
  (see Messages/plans/milestones.hpp)

  \subsection VersionTransitional0110 0.1.10
  \par Buildsystem version 0.9
  (see Buildsystem/plans/milestones.hpp)
  \par Messages version 0.9
  (see Messages/plans/milestones.hpp)

  \subsection VersionTransitional0111 0.1.11
  \par Buildsystem version 1.0
  (see Buildsystem/plans/milestones.hpp)

  \section VersionTransitional020 0.2.0 Build and test system basically finished
  \par Messages version 1.0
  (see Messages/plans/milestones.hpp)
  \par ProgramOptions version ???
  \par ErrorHandling version ???
  \par General goals:
   - Transition to new test system complete (all old tests transferred to the new test system).
   - Except of warnings coming from Boost, no compiler warnings from our library.


  \section VersionTransitional030 0.3.0 Complexity system ready
  Complexity system completed and (partially) used

  \section VersionTransitional040 0.4.0 Concepts ready
  Basic concepts all written (C++ and library-infrastructure-related),
  and the generic test system framework established and in use.

  \section VersionTransitional050 0.5.0 Documentation ready
  Documentation completed (regarding the basics)

  \section VersionTransitional060 0.6.0 Package management ready
  Extending the build system regarding package management (other
  users)

  \section VersionTransitional100 1.0.0 Foundations completed
  A solid foundation is provided, now we can start.
*/

/*!
   \page VersionHistoryTransitional Version history Transitional

   \par 0.1.0 3/3/2006

   Initial version number (here we just started versioning, while there
   has been work on the library for around 2 years).
*/

/*!
  \page VersionHistoryOKlibrary Version history OKlibrary

  \par 0.0.1 3/3/2006

  Initial version number (library basically empty).
*/



/*!
  \namespace OKlib
  \brief All components of the OKlibrary
*/

namespace OKlib {
}


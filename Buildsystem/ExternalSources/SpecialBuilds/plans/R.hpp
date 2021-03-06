// Oliver Kullmann, 27.6.2007 (Swansea)
/* Copyright 2007, 2008 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Buildsystem/ExternalSources/SpecialBuilds/plans/R.hpp
  \brief Plans regarding installation of R


  \todo Update to version 2.7


  \todo Packages
  <ul>
   <li> We should supply additional packages. </li>
   <li> And also install them automatically (with documentation). </li>
   <li> Of potential interest:
    <ol>
     <li> "SparseM" </li>
     <li> "QCA" (Quine-McCluskey;
     http://cran.r-project.org/src/contrib/Descriptions/QCA.html) </li>
     <li> "boolean" </li>
     <li> "combinat" </li>
     <li> "dyn" </li>
     <li> "gafit" </li>
     <li> "glpk" </li>
     <li> "linprog" </li>
     <li> "pspline" </li>
     <li> "quadprog" </li>
     <li> "randaes" </li>
     <li> "sudoku" </li>
    </ol>
   </li>
  </ul>


  \todo Improving the docus-page
  <ul>
   <li> Prerequisites:
    <ol>
     <li> What precisely is needed from the gcc-suite? </li>
     <li> What is mpfr? We should also add installation-help
     (there is already some installation-make-code). </li>
    </ol>
   </li>
  </ul>


  \todo Building dvi,pdf,info-documentation
  <ul>
   <li> On csltok "make dvi" fails --- is this due to old
   tex-tools? </li>
   <li> Likely "make pdf" sits on top of dvi. </li>
   <li> What can we do with the info-documentation? </li>
   <li> How do we get documentation on the packages? </li>
  </ul>


  \todo R-documentation : DONE
  <ul>
   <li> Does the R-build create documentation-pages to which we can link?
   DONE : ExternalSources/R/R-2.5.0/doc/html/index.html. </li>
   <li> DONE : So the build shall also move the doc/subdirectory. </li>
   <li> Target "cleanR" then can just remove the build-directory. </li>
  </ul>


  \todo Documentation-page : DONE
  <ul>
   <li> Create a docus-documentation. DONE </li>
   <li> State there the prerequisites. </li> 
  </ul>

*/


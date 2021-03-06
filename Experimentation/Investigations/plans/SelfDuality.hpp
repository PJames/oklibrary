// Oliver Kullmann, 12.8.2008 (Swansea)
/* Copyright 2008 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/plans/SelfDuality.hpp
  \brief On investigations regarding self-dual {0,1}-matrices


  \todo Smallest self-dual but not self-polar matrix
  <ul>
   <li> See the "Experiment" in
   ComputerAlgebra/CombinatorialMatrices/Lisp/Isomorphisms.mac. </li>
   <li> Interesting also to determine the number of self-dual and self-polar
   matrices. </li>
   <li> Easy cases (showing the quotient #self-dual/#all):
    <ol>
     <li> n=0: 1/1 </li>
     <li> n=1: 2/2 </li>
     <li> n=2: 12/16 </li>
     <li> n=3: 248/512 </li>
     <li> n=4: 15428/65536 </li>
    </ol>
    In each case every self-dual matrix was self-polar.
   </li>
   <li> n = 5:
    <ol>
     <li> Random sampling yields 16686/213822. </li>
     <li> By a C++ implementation we could run through all cases
     (see Transitional/Combinatorics/plans/general.hpp). </li>
    </ol>
   </li>
   <li> n = 6:
    <ol>
     <li> Random sampling: 944/58092. </li>
    </ol>
   </li>
   <li> n = 7: 
    <ol>
     <li> Random sampling: 15/6060. </li>
     <li> Another run with set_random(0): 171/100037. </li>
    </ol>
   </li>
   <li> n = 8:
    <ol>
     <li> With default setting: 0/2567. </li>
     <li> With set_random(0): 1/2976 (segfault at interrupt). </li>
     <li> With set_random(1): 2/11720 (with Ecl; after several interrupts
     lost connection). </li>
    </ol>
   </li>
   <li> It seems that for small n (n <= 5) there are no self-dual but not
   self-polar matrices, while for bigger n self-dual matrices become very
   rare (so that a random search for them won't succeed). </li>
  </ul>

*/


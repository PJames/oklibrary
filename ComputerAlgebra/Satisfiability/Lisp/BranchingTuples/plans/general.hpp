// Oliver Kullmann, 21.7.2007 (Swansea)
/* Copyright 2007 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file ComputerAlgebra/Satisfiability/Lisp/BranchingTuples/plans/general.hpp
  \brief Plans regarding the tau function (see SAT-handbook article of OK)
  
  
  \todo Tau for Maxima
  <ul>
   <li> Defining tau using the precise but slow interval-halving:
    <ol>
     <li> The demo-file could be called "demos/Basic.hpp", using
     doxyen comments?! </li>
     <li> How to define examples for functions? DONE (creating demo-files,
     loading them by "batch")
     </li>
     <li> And it should be possible to define a variation which doesn't
     take a list but a variable number of arguments (for the tuple-values). DONE
     (define the n-ary function taun, and for plotting the fixed 2-ary resp.
     3-ary function tau2, tau3) </li>
     <li> One has to do something here in case lower and upper bound are already
     very close. DONE (using the sign-check) </li>
     <li> Perhaps one should define chi(t) as a function x -> apply("+", x^(-t)).
     DONE </li>
    </ol>
   </li>
   <li> Using the faster Newton-method:
    <ol>
     <li> Can a higher precision be used? </li>
     <li> What is the precision of float? It seems that actually 64-bit numbers
     are used? </li>
     <li> Does the newton-procedure know how to differentiate the expression?
     Perhaps. </li>
     <li> If all arguments are integers, then actually an expression is returned.
     So well. DONE (the "default"-version tau_nwt converts the input
     into floating point) </li>
     <li> Are there reasonable default values for eps? Perhaps the maximal
     precision? DONE (used the apparently maximal precision) </li>
     <li> Again, one should define a variant without lists (but variadic). DONE
     </li>
    </ol>
   </li>
   <li> The general convention should be, that for example the branching tuples
   contain real terms, and then perhaps via some special naming convention we
   indicate that for this version
   all arguments are automatically evaluated? </li>
   <li> The experience we have made already should be extracted:
    <ol>
     <li> To the FullDocumentation-file? </li>
     <li> There are many questions, so a more open format is needed --- perhaps
     ComputerAlgebra/docus/Maxima.hpp. </li>
    </ol>
   </li>
   <li> How to make these definitions available? DONE (it seems that explicit
   load-instructions have to be issued for each Maxima-session) </li>
  </ul>


  \todo Branching tuples
  <ul>
   <li> We should develop some general helper functions for branching tuples t,
   and reimplement the tau-functions using those.
    <ol>
     <li> A branching tuple is a non-empty list of positive real numbers,
     where in case of width 1 also 0 is allowed (excluded for "non-zero
     branching tuples"). </li>
     <li> bt_min(t) := lmin(t) </li>
     <li> bt_max(t) := lmax(t) </li>
     <li> bt_sum(t) := apply("+", t) </li>
     <li> bt_width(t) := length(t) </li>
     <li> Then there are power means and their special cases;
     do we need special functions here? Like  bt_mean(t) := mean(t) ? </li>
     <li> Is it worth to introduce all the above special abbreviations ?
      <ul>
       <li> It adds a certain meaning. </li>
       <li> But perhaps it is better handled by implicit conversion of
       branching tuples into lists, and then applying the standard functions. </li>
       <li> So perhaps we do not introduce min, max, sum, width here, only
       in the documentation we mention them. </li>
       <li> However always having to write "apply("+", t)" is ugly, and so
       we should introduce a general convenience function here (doesn't it
       already exist??). </li>
      </ul>
     </li>
     <li> Perhaps we have checks
      <ol>
       <li> is_bt(a) (all entries are real and > 0, or a = (0)) </li>
       <li> is_nz_bt(a) (not (0)) </li>
       <li> is_ne_bt(a) (not empty) </li>
       <li> is_s_bt(a) (strict bt, i.e., nz and ne). </li>
      </ol>
     </li>
     <li> The concatenation of branching tuples is just the concatenation of
     lists, so again we do not need to introduce a special function. </li>
     <li> However composition of branching tuples a, b at position i of
     a is needed: bt_composition(a,b,i). </li>
    </ol>
   </li>
   <li> Creating a new file "BranchingTuples.maxima". </li>
   <li> DONE Perhaps the module should be called "BranchingTuples" instead of
   "TauMachinery". </li>
  </ul>


  \todo Reimplement the remaining functionality from Mupad/tau.mup in Maxima
  <ol>
   <li> tau : DONE
   <li> probability </li>
  </ol>

*/

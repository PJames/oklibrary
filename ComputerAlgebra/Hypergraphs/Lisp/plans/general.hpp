// Oliver Kullmann, 30.11.2007 (Swansea)
/* Copyright 2007, 2008 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file ComputerAlgebra/Hypergraphs/Lisp/plans/general.hpp
  \brief Plans for Maxima-components for hypergraphs


  \todo Create milestones


  \todo Write tests


  \todo Redesign
  <ul>
   <li> See "Plan the redesign" in ComputerAlgebra/plans/Maxima.hpp for
   the general overview. </li>
   <li> See "Lists instead of sets" and "Naming conventions" below. </li>
  </ul>


  \todo Write docus
  <ul>
   <li> We should have a list of all available functions. </li>
   <li> Seems that this list needs to be maintained manually? </li>
  </ul>


  \todo Statistics
  <ul>
   <li> Similar to ClauseSets/Statistics.mac we should have
   Hypergraphs/Statistics.mac. </li>
  </ul>


  \todo Special properties of hypergraphs
  <ul>
   <li> Perhaps we have a module "Properties.mac", where basic properties
   of hypergraphs are tested. </li>
   <li> Whether a general hypergraph has repeated hyperedges. </li>
   <li> Whether a hypergraph has subsumed hyperedges. </li>
   <li> Was a hypergraph is "downward hereditary" or "upward hereditary". </li>
   <li> What about all forms of stability under set-operations? Likely these
   special hypergraphs should go to ComputerAlgebra/Sets. </li>
  </ul>


  \todo Intersecting hypergraphs
  <ul>
   <li> See "Allowed parameter values" in
   ComputerAlgebra/Satisfiability/Lisp/ConflictCombinatorics/plans/HittingClauseSets.hpp
   for a motivation to study intersecting hypergraphs (no empty hyperedges,
   and every two hyperedges intersect). </li>
  </ul>

*/


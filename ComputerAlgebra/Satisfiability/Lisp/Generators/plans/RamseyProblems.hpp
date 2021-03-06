// Oliver Kullmann, 4.9.2008 (Swansea)
/* Copyright 2008 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file ComputerAlgebra/Satisfiability/Lisp/Generators/plans/RamseyProblems.hpp
  \brief Plans for Maxima-generators for Ramsey-problems


  \todo Relations to other modules
  <ul>
   <li> Compare "Ramsey graphs" in
   ComputerAlgebra/Hypergraphs/Lisp/plans/Generators.hpp. </li>
   <li> See Ramsey.cpp. </li>
   <li> See Experimentation/Investigations/plans/RamseyProblems.hpp. </li>
  </ul>


  \todo Extreme cases
  <ul>
   <li> One needs to think about the definition of the extreme cases; it seems
   there are inconsistencies in our tests. </li>
   <li> See "Ramsey hypergraphs" in
   ComputerAlgebra/Hypergraphs/Lisp/plans/Generators.hpp. </li>
  </ul>


  \todo More efficient computation
  <ul>
   <li> For larger Ramsey problems, we need the ability to compute directly
   the standardised clause-set (which just consists of the hypergraph edges
   in two versions, positive (as they are) and negative), without further
   renaming. </li>
   <li> This can be achieved by using the standardised order as discussed in
   "Ramsey hypergraphs" in
   ComputerAlgebra/Hypergraphs/Lisp/plans/Generators.hpp. </li>
   <li> Compare "Colouring problems" in
   ComputerAlgebra/Satisfiability/Lisp/Generators/plans/general.hpp. </li>
  </ul>


  \todo Symmetry breaking
  <ul>
   <li> Compare with "Symmetry breaking" in
   Experimentation/Investigations/plans/RamseyProblems.hpp. </li>
   <li> Consider the K_n, and parameters r=2 and q. </li>
   <li> Partial assignments phi assign the edges of K_n. </li>
   <li> Given any phi, we have the following possibility for symmetry
   breaking by fixing values w.r.t. q-cliques:
    <ol>
     <li> The basic fact is that any 2-edge-labelling of K_q, which is
     not monochromatic, must contain two incident edges of different
     values (for q >= 3). </li>
     <li> By symmetry these two incident edges can be any pair of incident
     edges. </li>
     <li> So, if there is a subset T <= V(K_n) of size q, such that no edge
     for T is affected (i.e., assigned) by phi, then w.l.o.g. one can fix the
     values of 2 chosen incident edges to 1 and 2. </li>
     <li> This process can be repeated until no such T exists anymore. </li>
     <li> A question is whether there are better and worse choices for T
     and for the chosen edges? </li>
     <li> One needs to be careful here about "affected by phi": The above
     formulation is very "optimistic", while more "pessimistic" is that
     an edge is affected iff it is incident with an assigned one --- are
     there counterexample for the "optimistic" interpretation? 
      <ul>
       <li> Yes, a counter example is K_5, r=2, q=3:
        <ol>
         <li> Consider vertices 1,2,3, colour {1,2} with 1 and {2,3} with 2.
         </li>
         <li> Consider vertices 2,4,5, colour {2,4} with 1 and {2,5} with 2.
         </li>
         <li> Consider vertices 1,4,5, colour {1,4} with 1 and {4,5} with 2.
         </li>
         <li> There is a monochromatic triangle between vertices 1,2,4 but K_5
         allows a colouring without one. </li>
        </ol>
       </li>
       <li> Perhaps rather than setting specific colours, only the fact that the
       two colours must be different should be coded. Perhaps by reducing 2 
       variables a,b to just variable a, by replacing variable b with literal 
       -a. </li>
      </ul>
     </li>
     <li> More general than above, also for T with one affected edge one
     could choose another incident edge:
      <ul>
       <li> But in general this is wrong. </li>
       <li> A counter example is K_5, r=2, q=3:
        <ol>
         <li> Consider vertices 1,2,3, colour {1,2} with 1 and {2,3} with 2.
         </li>
         <li> Consider vertices 2,3,4, colour {2,4} with 1. </li>
         <li> Consider vertices 2,4,5, colour {4,5} with 2. </li>
         <li> Consider vertices 1,4,5, colour {1,4} with 1. </li>
         <li> There is a monochromatic triangle between vertices 1,2,4 but K_5
         allows a colouring without one. </li>
        </ol>
       </li>
      </ul>
     </li>
     <li> So we can assign for every q-element subset of V(K_n) at least one
     and at most two (incident) edges. </li>
     <li> The number of assignments is 2 * floor(n/q). </li>
     <li> It shouldn't matter much which q-subsets (and which edges in them)
     to choose. </li>
     <li> Searching for an unaffected T is easy: One records which vertices
     are incident to assigned edges and chooses any q free vertices. </li>
     <li> The underlying principle is simply that any solution must contain
     for every q-clique a "multi-coloured" path of length 2. Without case
     distinctions it seems not possible to strengthen that. </li>
    </ol>
   </li>
   <li> The idea of MG was, instead of looking at the q-subsets
   of V(K_n), to consider Ramsey numbers m := NR([p,p],2) < n:
    <ol>
     <li> Again, we are considering some arbitrary given phi. </li>
     <li> If we have an unaffected T <= V(K_n), then we can choose any
     p different a_1, ..., a_p in T, and set them equal (thus replace them
     by a single new variable a). </li>
     <li> It seems that for an affected T it is harder to do something:
     If one edge got colour c, then we had to make a case distinction,
     expressing that the monochromatic p-clique could have colour c or the
     other colour. </li>
     <li> And, again, "unaffected" likely should mean that for T there is
     also no assigned edge (just) incident with an element of T. </li>
     <li> For example for m=6, p=3, we actually know that there must
     exist two monochromatic triangles: However this again seems hard to
     exploit since we need to make case distinctions about the relative
     position of these two triangles. </li>
     <li> Use of the Pigeon Hole Principle to collapse more edges:
      <ul>
       <li> In general, when considering NR([q,q],r) with n vertices, 
       by the Pigeon Hole Principle, given x monochromatic p-cliques, 
       ceil(x / r) of the p-cliques must be the same colour. </li>
       <li> Therefore, in the case of NR([p,p],2) it should be possible to 
       collapse half (rounded up) of the p-cliques (i.e all the variables
       representing the edges) to a single variable, for each p considered. 
       </li>
       <li> For example, consider NR([4,4],2), n=18. With MG's idea, we find 5
       monochromatic triangles in the graph. At least 3 of these must be
       coloured 1, or at least 3 of these must be coloured 2, therefore, we
       simply represent the equality of colour. This can be done using either
       additional clauses, or by replacing all occurrences of the variables
       (edges) in 3 of the triangles with a single variable (edge). </li>
       <li> Another example, considering NR([5,5],2), n=43. Using the
       calculation below, we choose 7 monochromatic 4-cliques and 4
       monochromatic 3-cliques, therefore we may colour 4 of the 4-cliques the
       same colour, and 2 of the 3-cliques. </li>
       <li> A proof is needed. (This should be similar to the proof for MG's
       idea, as intuitively the idea is that every p-clique, given they are
       vertex-disjoint, can be transformed to any other by some permutation in 
       S_n) </li>
      </ul>
     <li> Also given the symmetry of the two colours (i.e the fact that flipping 
     the colours in a given total assignment doesn't affect satisfiability), 
     we can then set one of the above mentioned variables (collapsed using the 
     PHP) to a particular colour. For instance, setting half of the p-cliques
     (for a given p) to colour 1. </li>
     <li> It seems that this process yields more variable reductions than
     the above process?
      <ul> 
       <li> The method used below for calculation assumes that, starting with l 
       unaffected vertices, if a process/idea needs x unaffected vertices for 
       application at each step, and it affects y vertices, then the x - y 
       unaffected vertices can be reused at each step, leaving l - y vertices to 
       act on, until finally there are x - y <=  z  < x unaffected vertices 
       left, at which point, z < x, therefore the process can no longer be 
       applied, giving floor((l - (x - y)) / y) possible applications of the 
       procedure.
        <ul>
         <li> For example, NR([4,4],2), n=l=18 </li>
         <li> First choose 6 = NR([3,3],2) vertices, and from them, arbitrarily
         choose 3 vertices to form the monochromatic triangle, leaving 3
         vertices affected, and 15 vertices unaffected. </li>
         <li> Choose 6 more, and another 3 for a triangle, leaving 6 vertices
         affected, 12 affected. </li>
         <li> Choose 6 more, and another 3 for a triangle, leaving 9 vertices
         affected, 9 unaffected. </li>
         <li> Choose 6 more, and another 3 for a triangle, leaving 12 vertices
         affected, 6 unaffected. </li>
         <li> Choose 6 more, and another 3 for a triangle, leaving 15 vertices
         affected, 3 unaffected. </li>
         <li> The procedure must stop here as we need 6 unaffected vertices, but
         only have 3. Giving 5 monochromatic triangles. </li>
         <li> Since there must always be (x-y) unaffected vertices more than the
         y we affect to allow application (i.e x in total), we can simply take 
         l - (x-y) and then divide by y (taking the floor as we can not apply 
         the procedure for any number of unaffected vertices less than x). </li>
        </ul>
       </li>
       <li> Taking NR([5,5],2), n=43 as an example.
        <ul>
         <li> Each multicolour path of length 2 affects 3 vertices, and
         sets two edges/variables. 5 unaffected variables are needed to apply
         the reduction. </li>
         <li> Given the above formula, we have x = 5, y = 3, n = l = 43 for the
         number of multicolour paths of length 2 that we can choose, assuming
         the vertex sets of each path need to be disjoint. </li>
         <li> floor((l - (x - y)) / y) = floor((43 - (2))/3) = floor(41/3) = 13
         vertex-disjoint multicolour paths of length 2. </li>
         <li> Each of these paths comprises of 2 edges which we are setting with
         a colour, therefore there are 13 * 2 = 26 edges/variables being set.
         </li>
        </ul>
       </li>
       <li> Using MG's suggestion for NR([5,5],2), n=43
        <ul>
         <li> NR([4,4],2) = 18, so x = 18, y = 4, n = l = 43. </li>
         <li> This gives, floor((l - (x - y)) / y) = floor((43 - (18 - 4))/4) =
         floor((43 - 14) / 4) = floor(29 / 4) = 7 vertex-disjoint monochromatic
         4-cliques. </li>
         <li> So therefore we can find 7 vertex-disjoint monochromatic 
         4-cliques. Each clique has 6 edges, representing 6 variables, which can 
         be reduced to a single variable, so 7 * 6 = 42 edges, which can be 
         represented using only 6 edges, so 42 - 6 = 36 variables removed. </li>
         <li> 7 4-cliques affect 7 * 4 = 28 vertices, leaving 43 - 28 = 15
         unaffected vertices. </li>
         <li> NR([3,3],2) = 6,  so x = 6, y = 4, l = 15. </li>
         <li> This gives, floor((l - (x - y)) / y) = floor((15 - (6 - 3)) / 3) =
         floor((15 -3)/3) = floor(12/3) = 4 vertex-disjoint monochromatic 
         3-cliques. </li>
         <li> Each 3-clique has 3 edges, representing 3 variables, which can be 
         reduced to a single variable, so 4 * 3 = 12 edges/variables before
         reduction, 12 - 4 = 8 removed. %I.e, since 4 variables are being used to
         instead of 12, we have removed/collapsed 8 variables. </li>
         <li> So without taking into account the PHP statement above, we see a
         reduction/loss of 36 + 8 = 44 variables. OK : Likely for the second
         step the above process can be used?! MG : Yes, this is possible,
         and should result in more variables removed/set for n=45. </li>
         <li> Including the PHP statement above, we can set 4 of the 7 4-cliques
         to a colour c, and we can replace 2 of the variables representing the 4
         3-cliques with 1 variable. Therefore we lose an additional 5 variables,
         4 set to a specific colour and 2 reduced to 1 (a loss of 1), so 44 + 5 
         = 49 variables lost. ??? </li>
        </ul>
       </li>
      </ul>
     </li>
     <li> The above process exploits a symmetry of the solution space,
     while this process just relies on a symmetry of the K_n (since
     every(!) total assignment of a K_m will have a monochromatic
     p-clique); on the other hand the above process is trivial, while here
     we rely on (non-trivial) knowledge about Ramsey numbers. </li>
     <li> Again the question whether the different choices matter? </li>
     <li> In principle a combination with the above process is possible:
     However case distinctions for the relative positions of the path
     of length 2 and the monochromatic q-clique are needed. </li>
     <li> On the other hand, for unaffected subsets we can always choose
     which process we like. </li>
    </ol>
   </li>
   <li> What is the best way (and place within the library) to implement the
   above symmetry breaking ideas? Obviously here. </li>
  </ul>

*/


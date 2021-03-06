// Oliver Kullmann, 19.7.2008 (Swansea)
/* Copyright 2008 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Experimentation/Investigations/plans/RamseyProblems.hpp
  \brief On investigations into %Ramsey problems


  \todo Connections
  <ul>
   <li> See ComputerAlgebra/RamseyTheory/Lisp/Ramsey/plans/general.hpp. </li>
   <li> See Ramsey.cpp (to be updated) for a C++ generator. </li>
   <li> See ComputerAlgebra/Hypergraphs/Lisp/plans/Generators.hpp. </li>
   <li> See ComputerAlgebra/Satisfiability/Lisp/Generators/plans/RamseyProblems.hpp.
   </li>
  </ul>


  \todo Generation of problem instances
  <ul>
   <li> Generation of CNF representations:
    <ol>
     <li> By the Maxima system, via "output_ramsey2_stdname(q,r,n)" we
     create "Ramsey_q_r_n.cnf", for NR([q,q],r). </li>
     <li> However, output_ramsey2_stdname(5,2,40) yields a segmentation
     fault on a 32-bit machine (not enough memory, when introducing
     the colouring symbols); so we need to use the following (C++)
     application. </li>
     <li> More generally (and faster), the application "Ramsey" can generate
     also non-diagonal problems, via
     \verbatim
Ramsey-O3-DNDEBUG q1 q2 r n | ExtendedToStrictDimacs-O3-DNDEBUG > Ramsey_q1_q2_r_n.cnf
     \endverbatim
     for NR([q1,q2],r). </li>
    </ol>
   </li>
   <li> What about constraint solvers? </li>
  </ul>


  \todo Bounds on NR([q,q],2)
  <ul>
   <li> How to handle the following data in a more systematic fashion,
   using tools from the OKlibrary? </li>
   <li> q = 3:
    <ol>
     <li> Satisfiability for n=5 is trivial for any SAT solver. </li>
     <li> So is unsatisfiability for n=6. </li>
    </ol>
   </li>
   <li> q = 4:
    <ol>
     <li> Satisfiability for n=17:
      <ul>
       <li> Trivial for OKsolver. </li>
       <li> Grasp aborts by default (10000s exceeded). </li>
       <li> Trivial for minisat. </li>
       <li> Trivial for march_pl. </li>
      </ul>
     </li>
     <li> Unsatisfiability for n=18:
      <ul>
       <li> OKsolver
        <ol>
         <li> Running it with
         \verbatim
> OKsolver_2002-O3-DNDEBUG -M -D14 -F Ramsey_4_2_18.cnf
         \endverbatim
         seems to indicate that it will take roughly 15 days (on csltok). </li>
         <li> However, this seems to be too optimistic: The first 15 nodes
         at depth 14 (16384 nodes altogether) were solved all with around
         100,000 nodes in the subtrees, however with node 16 the solver
         falls into a deep hole, and yet 500,000,000 nodes have been processed
         there. </li>
         <li> A still deeper hole waited at node 19, and after 16.35 days and
         4,095,825,666 nodes (altogether; 3620490 single nodes, 16,220,739,545
         2-reductions, 22,409,527 pure literals, 0 autarkies; 1,412,661.8
         seconds) it was aborted. </li>
         <li> Interestingly it seems that cs-wsok here is quite a bit slower
         than csltok:
          <ul>
           <li>
           \verbatim
  1:110200,  208.1, 3408483.1
  2:100554,  418.0, 3423838.0
           \endverbatim
           but there is a lot of variability
           \verbatim
  1:110200,  161.6, 2647165.1
  2:100554,  302.3, 2476385.0
           \endverbatim
           (which is strange?) versus on csltok:
           \verbatim
  1:110200,   82.5, 1350942.2
  2:100554,  162.8, 1333822.4
           \endverbatim
           where actually csltok has a slower cpu?? </li>
           <li> After 3299m 19s, on csltok 487,747,031 nodes
           were processed, that makes 2460 nodes per second. </li>
           <li> After 254392.7 s, on cs-wsok 740,136,935 nodes
           where processed, that makes 2900 nodes per second. </li>
           <li> So it seems that cs-wsok was only initially that slow
           --- perhaps cache behaviour? But still, given that csltok
           runs with 1400 MHz and cs-wsok with 2100 MHz, executation
           on cs-wsok seems slow. </li>
          </ul>
         </li>
        </ol>
       </li>
       <li> Grasp aborts by default (10000s exceeded). </li>
       <li> minisat seems hopeless (after one hour). </li>
       <li> march_pl seems hopeless (after one hour). </li>
      </ul>
     </li>
    </ol>
   </li>
   <li> q = 5:
    <ol>
     <li> Known is 43 <= NR([5,5],2) <= 49. </li>
     <li> So we get 1-2 million clauses; we can try with a local search
     solver. </li>
     <li> OKsolver can handle n=33 in ~ 3 minutes, but has problems with
     n=34. </li>
     <li> march_pl seems to have problems already for n=30. </li>
     <li> minisat can handle n=30 in 2 seconds; n=35 ? </li>
     <li> UnitMarch: n=30 in 3 seconds, but n=33 unsolved after 20 minutes.
     </li>
     <li> The list of algorithms from ubcsat:
      <ol>
       <li> "ubcsat-okl -alg gsat -runs 100 -i Ramsey_5_2_n.cnf": trivial for
       n=30; n = 35 needs 300 - 30000 steps. Using "-cutoff 2000" seems
       reasonable. </li>
       <li> gwsat: trivial for n=30; n = 35 ? </li>
       <li> hsat : n = 35 needs ~ 3000 steps; n = 40 ? </li>
       <li> adaptnovelty+: n = 35 ? </li>
       <li> saps: n = 35 in 600 steps. Using "-cutoff 2000" seems reasonable;
       looks strong. n = 40 ? </li>
       <li> rsaps: similar; but looks bleak for n = 40 (cutoffs 10000 or
       30000 yield nearly the same). </li>
       <li> samd performs yet best, and also scales to higher cutoffs,
       but very slowly: With n=40, cutoff = 10 000 000, in 12 rounds 9 outcomes
       were 30-something, one was 46, and we had 23 (the minimum) and 27
       (regarding the falsified clauses). </li>
      </ol>
     </li>
     <li> Investigating samd:
      <ol>
       <li> n=40:
        <ol>
         <li> cutoff = 10 000 000 and noimprove = 1 000 000: 100 rounds,
         maximum 3 500 000 steps, average 1 700 000 steps, minimum 7
         falsified clauses, 264 flips per second (on csltok) --- this
         is extremely slow?? </li>
         <li> cutoff = 20 000 000, noimprove = 3 000 000: 100 rounds, maximum
         10 500 000 steps, average 4 300 000 steps, minimum 1 falsified clause
         (seed 18745606), 2912 flips per second. </li>
         <li> One round, cutoff = 20 000 000, with previous best seed: didn't
         improve the result. </li>
         <li> So let's try 500 runs, with cutoff = 20 000 000, noimprove =
         2 000 000:
         \verbatim
BestStep_Mean = 1121189.316000
Steps_Mean = 3121190.316000
Steps_Max = 7623900.000000
PercentSuccess = 0.00
BestSolution_Mean = 34.696000
BestSolution_Median = 35.000000
BestSolution_Min = 7.000000
BestSolution_Max = 76.000000
         \endverbatim
         </li>
         <li> Alright, with noimprove = 3 000 000:
          <ol>
           <li>
           \verbatim
BestStep_Mean = 1596309.594000
Steps_Mean = 4590310.592000
Steps_Max = 14784949.000000
PercentSuccess = 0.20
BestSolution_Mean = 33.976000
BestSolution_Median = 35.000000
BestSolution_Min = 0.000000
BestSolution_Max = 61.000000
           \endverbatim
           </li>
           <li> With seed = 391532901 a solution was found (in round
           293, using 964281 steps)!
            <ul>
             <li> The command line instruction to reproduce this is:
             \verbatim
ubcsat -alg samd -seed 391532901 -cutoff 1000000 -i Ramsey_5_2_40.cnf
             \endverbatim
             </li>
             <li> A solution is output by adding "-solve". </li>
             <li> Perhaps this solution should be stored; the question is
             where? Perhaps this is similar to data for minimally unsatisfiable
             clause-sets etc., which finally is too much to put into source
             control, but should exist as additional packages. </li>
             <li> Of course, there is the whole complex of "database
             questions"; see Experimentation/Database/plans/general.hpp
             <li> We need to find out whether this solution is of interest
             (i.e., "unknown") or not. </li>
             <li> So we need to find out about the known solutions for n=40
             in the literature, and about classifications of solutions (when
             solutions are considered to be the "same"). </li>
            </ul>
           </li>
           <li> So, in general perhaps one should just use a cutoff of
           1 000 000, and use more rounds? </li>
          </ol>
         </li>
        </ol>
       </li>
       <li> n=41:
        <ol>
         <li> cutoff =  10 000 000, with 40 rounds most results were
         fiftyish to sixtyish, but one outlier reached 28 (the minimum). </li>
         <li> cutoff = 20 000 000, noimprove = 2 000 000:
         100 rounds has a maximum of 8 000 000 steps, average of
         3 300 000 steps, and 2261 flips per second. The optimum reached was
         13 falsified clauses, which seems very good. </li>
         <li> noimprove = 3 000 000: 100 rounds, maximum 12 600 000 steps,
         average 5 000 000 steps, 2294 flips per second, minimum 12 falsified
         clauses (seed 1833218426) </li>
         <li> One round, cutoff = 20 000 000, with previous best seed: didn't
         improve the result. </li>
         <li> So let's try 500 runs, with cutoff = 20 000 000, noimprove =
         3 000 000. </li>
        </ol>
       </li>
      </ol>
     </li>
    </ol>
   </li>
   <li> For the ubcsat-algorithms we need some script to run through all
   of them; see ExperimentSystem/plans/RunUBCSAT.hpp. </li>
   <li> q = 6:
    <ol>
     <li> Known is 102 <= NR([6,6],2) <= 165. </li>
     <li> These clause-sets are too big (for direct representation). </li>
    </ol>
   </li>
  </ul>


  \todo Investigating the parameter tuple [[3,3],2]
  <ul>
   <li> Creating the relevant instances: by
   \verbatim
R5: ramsey2_ofcs(3,2,5);
R6: ramsey2_ofcs(3,2,6);
   \endverbatim
   we create the two relevant (ordered formal) clause-sets. </li>
   <li> Satisfying assignments:
   \verbatim
R5SAT : setify(all_sat_ofcs(R5))$
length(R5SAT);
  12
   \endverbatim
   </li>
   <li> Now we need to investigate the operation of the automorphism group
   of R5 on R5SAT (what are the really different solutions?). </li>
   <li> For this we need to compute the automorphism group of R5; see
   "Automorphisms of Ramsey clause-sets" in
   RamseyTheory/Lisp/Ramsey/plans/general.hpp. </li>
   <li> Via
   \verbatim
length(all_aut_ofcs(R5));
  13
   \endverbatim
   we see that there are only the obvious autarkies. </li>
  </ul>


  \todo Autarkies
  <ul>
   <li> We should investigate autarkies of Ramsey-clause-sets. </li>
   <li> It could be that for smaller n interesting autarkies exist, and so
   they could serve for providing lower bounds. </li>
  </ul>


  \todo Blocked clauses
  <ul>
   <li> We should investigate blocked clauses of Ramsey-clause-sets. </li>
  </ul>


  \todo Symmetry breaking
  <ul>
   <li> An important way of making the problems simpler for SAT solvers
   is to add symmetry-breaking clauses. </li>
   <li> See "Symmetry breaking" in
   ComputerAlgebra/Satisfiability/Lisp/Generators/plans/RamseyProblems.hpp.
   </li>
   <li> We should try to figure out the automorphism groups of the clause-sets.
   See "Automorphisms of Ramsey clause-sets" in
   RamseyTheory/Lisp/Ramsey/plans/general.hpp. </li>
   <li> The goal is to find as many as possible assignments which can
   be made "w.l.o.g."; and also additional short clauses are of interest. </li>
  </ul>


  \todo "Visualising" solutions
  <ul>
   <li> Via SAT solvers we can compute certain solutions for problems somewhat
   smaller than the interesting sizes. </li>
   <li> The task is to "look" at these solutions, extract some structure, and
   then to systematically search for "such" solutions. </li>
   <li> Of course, everything theoretically known needs to be explored. </li>
  </ul>


  \todo Better SAT solvers
  <ul>
   <li> These problems seem to be quite structured, so that quite something
   is known (at least more than for Van der Waerden numbers), but SAT solvers
   apparently can't exploit any of it. </li>
   <li> Active clause-sets should be attractive.
    <ol>
     <li> Incorporating some of the knowledge we have for these problems. </li>
     <li> They should also be able to better detect symmetries. </li>
    </ol>
   </li>
   <li> Compressed representation of clauses:
    <ol>
     <li> If that ZAP systems, which allows to use "annotated clauses", clauses
     plus a permutation group acting on the variables, is open-source, then it
     would be very natural to apply it here:
      <ol>
       <li> The clause-set F_R([q_1, ..., q_s], r, n) can be expressed then
       by just s clauses together with the symmetric group S_n. </li>
       <li> However it is not available. </li>
       <li> One should have a look at those papers. </li>
       <li> A point here is that S_n does act faithful but not
       strongly faithful on the clauses (i.e., on the underlying hypergraph)
       --- can this be repaired or improved (S_n is a rather large group here)?
       </li>
      </ol>
     </li>
    </ol>
   </li>
  </ul>

*/


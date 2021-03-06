// Oliver Kullmann, 6.6.2007 (Swansea)
/* Copyright 2007, 2008 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Transitional/plans/general.hpp
  \brief Plans for the Transitional-library which do not belong to a single module


  \todo "OKlib" instead of "Transitional"
  <ul>
   <li> Rename "Transitional" to "OKlib", and remove the (empty)
   repository "OKlibrary".
    <ol>
     <li> So the directory "Transitional" is renamed to "OKlib". </li>
     <li> Hopefully this doesn't inflate the git-repository. </li>
     <li> And then all references to "Transitional" need to be
     replaced. </li>
     <li> The best would be a program which goes through all
     files containing "Transitional", shows the line plus its
     environment, and asks whether the occurrence should be replaced by
     "OKlib --- if not, then the filename is stored for later
     consideration. </li>
     <li> Though the string "Transitional" is likely not used in any
     other sense, so we could just do replacement without checking. </li>
     <li> Of course, thorough checking afterwards. </li>
    </ol>
   </li>
   <li> We need clear indications what modules are usable already:
    <ol>
     <li> This should be achieved by their version numbers. </li>
     <li> See "Doxygen menu and main page review" in
     Buildsystem/OKlibBuilding/Targets/html/plans/general.hpp. </li>
    </ol>
   </li>
  </ul>


  \todo Super-modules:
  <ul>
   <li> We needs a library directory-superstructure.
   So we should introduce sub-directories of Transitional,
   corresponding to "parts". DONE </li>
   <li> Problematic the correspondence between paths and namespaces:
    <ol>
     <li> We should be consistent, using full super-module names
     and incorporating them into the namespaces.
     <li> Perhaps a collection
     of namespace-aliases could be provided ?! In this way we could use
     abbreviations (if wished) without loosing expressivity ?! </li>
     <li> Perhaps every namespace has a well-defined abbreviation, and there
     are aliases for all full namespace-qualifications ?! </li>
     <li> Better "OKlib" is not aliased, but only namespaces inside,
     so for example (defined inside namespace ::OKlib):
     \code
namespace Sat = Satisfiability;
namespace SatAlg = Satisfiability::Algorithms;
     \endcode
     Or should be better not open the can of worms given by these
     further aliases like "SatAlg" ? Looks better!
     </li>
     <li> In every plans-file, besides the namespace-documentation, where also
     the namespace is introduced (as C++ entity), we then have also the alias
     definitions. </li>
     <li> For the includes only the long forms can be used, but this seems to be
     alright. </li>
     <li> To be usable, of course the alias definitions need to be provided
     somewhere where they can be easily included!
      <ol>
       <li> Perhaps each module provides "declarations.hpp", containing
       the alias-definition of this module (only); see
       Programming/declarations.hpp for an example. </li>
      </ol>
     </li>
    </ol>
   </li>
   <li> Perhaps the following "parts" of the OKlibrary (containing the super-modules; abbrevations
   shall not be all-caps (reserved for macros)):
      <ol>
       <li> "Satisfiability" ("Sat")
        <ol>
         <li> Alg ("Algorithms"; (generic) algorithms for SAT solving and variations) </li>
          <ol>
           <li> LSe ("LocalSearch") </li>
          </ol>
         </li>
         <li> Asg ("Assignments")
          <ol>
           <li> Aut ("Autarkies") </li>
           <li> PAs ("PartialAssignments") </li>
          </ol>
         </li>
         <li> Heu ("Heuristics") </li>
         <li> Ifs ("Interfaces"; input, output etc.) </li>
         <li> PrI ("ProblemInstances")
          <ol>
           <li> Var ("Variables") </li>
           <li> Lit ("Literals") </li>
           <li> Cla ("Clauses") </li>
           <li> Cls ("ClauseSets") </li>
           <li> ALi ("ActiveLiterals") </li>
           <li> ACl ("ActiveClauses") </li>
           <li> ACs ("ActiveClauseSets") </li>
           <li> AaC ("AlliancesActiveClauseSets") </li>           
          </ol>
         </li>
         <li> PSy ("ProofSystems") </li>
         <li> Qua ("Quantification") </li>
         <li> Red ("Reductions") </li>
         <li> Sol ("Solvers"; contains "OKsolver") </li>
         <li> SpS ("SpecialStructures") </li>
         <li> Tra ("Transformers")
          <ol>
           <li> Gen ("Generators") </li>
          </ol>
         </li>
        </ol>
       </li>
       <li> "Applications" ("App")
        <ol>
         <li> CrA ("Cryptanalysis") </li>
         <li> Col ("Colouring")
          <ol>
           <li> FrA ("FrequencyAssignment") </li>
          </ol>
         </li>
         <li> Emb ("Embeddings") </li>
         <li> Gam ("Games") </li>
         <li> Lat ("LatinSquares") </li>
         <li> QuP ("QuantumPhysics") </li>
         <li> Ram ("RamseyTheory") </li>
        </ol>
       </li>
       <li> "Experimentation" ("Exp")
        <ol>
         <li> Dab ("Database") </li>
         <li> ExS ("ExperimentSystem") </li>
         <li> RaG ("RandomGenerator") </li>
         <li> SaC ("SatCompetition") </li>
        </ol>
       </li>
       <li> "Combinatorics" ("Cmb")
        <ol>
         <li> Gra ("Graphs") </li>
         <li> Hyp ("Hypergraphs") </li>
        </ol>
       </li>
       <li> "Structures" ("Str")
        <ol>
         <li> Alg ("Algebra") </li>
         <li> Cry ("Cryptology") </li>
         <li> Ord ("OrderTheory") </li>
         <li> Num ("NumberTheory") </li>
        </ol>
       </li>
       <li> "Logic" ("Log")
        <ol>
         <li> CTh ("ComplexityTheory") </li>
         <li> Cpa ("Computability") (contains "TuringMachines" TuM) </li>
         <li> fMT ("FiniteModelTheory") </li>
         <li> aTP ("AutomatedTheoremProving") (general frameworks) </li>
         <li> FiO ("FirstOrderLogic") (here for example the decidable cases,
         and the resolution calculus) </li>
         <li> AlS ("AlgebraicSpecification") (CASL etc.) </li>
        </ol>
       </li>
       <li> "Programming" ("Prg")
        <ol>
         <li> Con ("Container") </li>
         <li> Err ("ErrorHandling") </li>
         <li> Pll ("Parallelism") </li>
         <li> PrO ("ProgramOptions") </li>
         <li> Seq ("Sequences") </li>
        </ol>
       </li>
       <li> "System" ("Sys")
        <ol>
         <li> Com ("ComplexitySystem") (or CoM ("ComplexityMeasurement"),
         or PeM ("PerformanceMeasurement") or Per ("PerformanceSystem");
         but perhaps "-System" strengthens the link to the other
         "-Systems", while "Complexity" emphasises the fundamental
         character) </li>
         <li> Tes ("TestSystem") </li>
         <li> Bui ("BuildSystem") </li>
         <li> LeI ("LegalIssues") </li>
        </ol>
       </li>
       <li> "DataStructures" ("DaS") </li>
       <li> "ComputerAlgebra" ("CAl")
       </li>
       <li> "LogicalReflection" ("LoR")
        <ol>
         <li> PrE ("ProgramExtraction") </li>
         <li> FoP ("FormalisedProofs") (contains the framework for formalised
         upper bound proofs) </li>
         <li> PrA ("ProofAssistants") (contains sub-modules Coq and Isabelle
         for interfacing and other tasks) </li>
         <li> VrC ("VerifiedComponents") </li>
        </ol>
       </li>
       <li> "Statistics" ("Sta")
        <ol>
         <li> R </li>
        </ol>
       </li>
       <li> "Optimisation" ("Opt")
        <ol>
         <li> LiP ("LinearProgramming") </li>
         <li> QuP ("QuadraticProgramming") </li>
         <li> SeP ("SemidefiniteProgramming") </li>
        </ol>
       </li>
       <li> "Visualisation" ("Vis")
        <ol>
         <li> GDr ("GraphDrawing") </li>
        </ol>
       </li>
       <li> "UserInterfaces" ("UIc")
        <ol>
         <li> For researchers to create solvers (by assembling
         given components). </li>
         <li> Helping with the complex configuration of generic
         components. </li>
         <li> Headquarters for experimentation 
          <ol>
           <li> database access etc. </li>
           <li> monitoring experiment execution </li>
           <li> experiment planning </li>
          </ol>
         </li>
        </ol>
       </li>
      </ol>
   </li>
   <li> Are there refactoring tools? Or can we finally finish module
   Refactoring ?!? See Programming/Refactoring/plans/general.hpp. </li>
   <li> A feasible way for migration seems that we just slowly add new modules (which will
   be super-modules), and move modules into them (first only plans-only-modules, so that
   we don't get build-problems). For that we have to find out how to use "git mv" (see
   "Building and using Git" in Buildsystem/plans/VersionControl.hpp). </li>
  </ul>


  \todo Handling of version-numbers
  <ul>
   <li> The discussions below must be expanded into the general
   documentation-document. </li>
   <li> We should always use all four digits, starting with 0.2 ---
   which then would be "0.2.0.0". </li>
   <li> DONE (now being practised)
   One could introduce a fourth digit, which is not
   referenced in milestones-plans, but is increased each time
   one of the immediate sub-goals of the milestones has been
   fulfilled. Perhaps only for the "important version-numbers";
   could help to give a stronger sense of achievement. </li>
   <li> DONE Important, that such a refinement does not lead to
   unnecessary bureaucrazy --- it should be only a
   "progress meter", and advances "at random". </li>
   <li> DONE Perhaps an "important version-number" is defined as
   one where progress means that sub-version-numbers are
   advanced. </li>
  </ul>


  \todo Research sub-modules
  <ul>
   <li> Annotations simply stays a different repository. </li>
   <li> At least for version transitions, is it possible to store clones somewhere
   at an "official place" ?
    <ol>
     <li> What about that "SourceForge" ? </li>
     <li> Perhaps "SourceForge" is more for active participation in the "classical way"? </li>
     <li> Perhaps there are public scientific repositories? Or cultural repositories? </li>
     <li> At least we should keep a history of main releases (backed-up). </li>
     <li> Perhaps once we really go public (not yet with that "proto-release") we
     have a "mirror" somewhere. </li>
     <li> Perhaps actually the SAT community could provide a repository for SAT-related
     software?! </li>
     <li> DONE (external sources are not under version control (only their hash
     values))
     But all this implies at least, that the external sources are not part
     of the release --- otherwise it gets too big. </li>
    </ol>
   </li>
   <li> DONE (all what we have currently is to be released; if in the future
   there are "private" developments, then one has to create a branch or
   a new repository)
   To solve the privace-issues, it seems that (yet) only plans-directories
   are an issue, and one could move sensitive files to sub-directories
   "research" (moving also the whole history(!) --- see "Moving" in
   Buildsystem/plans/VersionControl.hpp). </li>
   <li> DONE (decided to go fully public)
   Currently I (OK) am inclined to release everything as it is (including
   "research secrets"), but this under the GPL: The OKplatform is a research
   platform, not a "tool" for industrial exploitation. Seeing that valuable
   research information is in the library, researchers will also add their
   own ideas. The GPL-licence together with the possibility to check whether
   a clone-repository has been corrupted should give enough security against
   the worst misusers. </li>
  </ul>


  \todo Organisation of plans-directories
  <ul>
   <li> A problem with "general.hpp" is, that under xemacs all such files look alike --- but perhaps
   xemacs can be configured to show also the comprising directory? </li>
   <li> Perhaps we should have files "strategy.hpp": The milestones
   only contain the results of the planning process (and a bit of
   indication of direction through the milestone-labels), while
   the strategy-file would contain the rationales, strategic
   decisions and strategic visions. </li>
   <li> Another "systematic" file in plans-directories is "wishlist.hpp",
   which is especially for users the place where they can articulate
   wishes. (Which might not be realised --- general.hpp contains all
   wishes which are to be realised (first they unfold in general.hpp,
   and finally they got moved to their own plans-file).) </li>
   <li> DONE (now being practised)
   The module-plan-files is just called "general.hpp". </li>
  </ul>


  \todo Demos:
  <ul>
   <li> In sub-directories "Module/demos" all demonstration programs will be put. </li>
   <li> The files in Module/demos should have full doxygen-documentation. </li>
   <li> Additionally the doxygen-command "\example" could be used for more fine-grained
   linking? </li>
   <li> Or is "\example" meant for mentioning .cpp-files without their own
   doxygen-documentation?? </li>
  </ul>


  \todo Backups and archives
  <ul>
   <li> An inventory is needed of what needs backup:
    <ol>
     <li> DONE (having the clones and the github-repository should be
     enough)
     Most important the main (git) repository (on cs-oksvr):
      <ul>
       <li> This is backuped nightly (on the departmental server);
       one should check whether extraction actually works. </li>
       <li> And every clone contains also essentially the same
       information (so that the risk of loss should be low). </li>
       <li> The configuration of the repository on cs-oksvr
       contains some special settings, which should be documented. </li>
      </ul>
     </li>
     <li> The mailing lists:
      <ul>
       <li> They need also a nightly backup on the departmental server. </li>
       <li> One could include a copy to the full packages (shouldn't be that
       big, and it would confirm to the idea of a "fully holistic
       library"). </li>
       <li> Or should it even go into the minimal package? </li>
      </ul>
     </li>
     <li> The external sources: We have the checksums and version numbers,
     this should be enough. </li>
     <li> The packages archive: backed up on the departmental server, which
     should suffice for the local backup (see also below). </li>
     <li> Current packages: Can be recreated if needed, and a backed up
     on the departmental server, which should suffice. </li>
    </ol>
   </li>
   <li> Backup tools:
    <ol>
     <li> We should have some discussion on backup tools and their usage. </li>
     <li> This was the original purpose of the Programming/Tools/Backup module
     (see Backup/plans/Backup.hpp); however this module seems obsolete now. </li>
    </ol>
   </li>
   <li> DONE (github should do the job)
   Archiving:
    <ol>
     <li> Compare "Packages history" in
     Buildsystem/ReleaseProcess/plans/general.hpp for "local aspects". </li>
     <li> Since the integrity of the history of the OKlibrary (i.e.,
     the Git repository) is important, we need some "official" storage
     of the packages archive. </li>
     <li> Perhaps a Sourceforge-account is needed, where the archive
     is mirrored, and where the most recent packages can also be
     downloaded. </li>
     <li> However this account should only be an "official mirror". </li>
    </ol>
   </li>
  </ul>


  \todo Upgrade to gcc-4.2.2
  <ul>
   <li> Correct the template-errors:
    <ol>
     <li> Precise problem description: XXX </li>
     <li> Methods to overcome the problem: XXX </li>
     <li> Files affected: XXX </li>
    </ol>
   </li>
  </ul>

*/

/*!
  \namespace OKlib
  \brief All components of the OKlibrary
*/

namespace OKlib {
}






// Oliver Kullmann, 18.3.2008 (Swansea)
/* Copyright 2008 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Buildsystem/ExternalSources/SpecialBuilds/plans/Graphs.hpp
  \brief Plans regarding installation of tools related to graph theory


  \todo Graph isomorphism
  <ul>
   <li> nauty http://cs.anu.edu.au/~bdm/nauty
    <ol>
     <li> Manual installation:
     \verbatim
builds/Graphs/Nauty> tar -xzf ../../../sources/Graphs/nauty22.tar.gz
raphs/Nauty> cd nauty22
nauty22> ./configure
nauty22> make all
nauty22> make checks
     \endverbatim
     looks all fine. </li>
     <li> Apparently it is a library, and the main application (providing
     input and output) is "dreadnaut". </li>
     <li> And there is "dreadnautB", which can handle graphs with more than
     32765 vertices. </li>
     <li> And some utilities, including the "gtools". </li>
    </ol>
   </li>
   <li> saucy http://vlsicad.eecs.umich.edu/BK/SAUCY/ </li>
  </ul>


  \todo Graph drawing
  <ul>
   <li> http://www.ogdf.net/doku.php looks promising (as a library).
    <ol>
     <li> Before we start writing any C++ code, which should investigate
     thoroughly this library. </li>
    </ol>
   </li>
   <li> http://graphviz.org/Download_source.php
    <ol>
     <li> the dot-tool is needed by doxygen for creating the graphs </li>
     <li> likely we should use the "DOT language"
     (http://graphviz.org/doc/info/lang.html) as the primary language
     for input and output of graphs (supported by Boost) ?! </li>
    </ol>
   </li>
   <li> http://www.tulip-software.org/ (should be very useful, since it
   concentrates on large graphs) </li>
   <li> dot2texi: http://www.fauskes.net/nb/introducing-dot2texi/ </li>
   <li> GraphML: http://graphml.graphdrawing.org/index.html (we need to
   look into this: an xml-based format for graphs of all sorts, hypergraphs,
   and also graphical representations). </li>
  </ul>


  \todo Treewidth
  <ul>
   <li> Overview on open-source implementations? </li>
   <li> For the hypergraph extensions see the homepage of Georg Gottlob. </li>
  </ul>


  \todo Travelling salesman
  <ul>
   <li> In [Gutin, Punnen; The Traveling Salesman Problem and Its
   Variations], Chapter 16, one finds a first overview, with web page
   http://www.or.deis.unibo.it/research_pages/tspsoft.html
   or http://or.unbsj.ca/~punnen/tspsoft.html . </li>
   <li> Another overview is http://www.tsp.gatech.edu . </li>
  </ul>


  \todo Graph colouring
  <ul>
   <li> http://www.adaptivebox.net/CILib/code/gcpcodes_link.html (several
   solvers) </li>
   <li> http://www.cs.ualberta.ca/joe/Coloring (solver and generator) </li>
   <li> What about hypergraph colouring? Apparently there are no
   implementations. </li>
  </ul>

*/


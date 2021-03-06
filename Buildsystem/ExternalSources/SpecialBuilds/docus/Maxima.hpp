// Oliver Kullmann, 3.1.2008 (Swansea)
/* Copyright 2008 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file Buildsystem/ExternalSources/SpecialBuilds/docus/Maxima.hpp
  \brief Documentation on how to build Maxima


  <h1> Installing Maxima </h1>


  <h2> On the purpose of Maxima </h2>

  Maxima is a computer-algebra system written in Lisp. It is our entry-level
  language, used for procedural specifications and experimental (smaller)
  computations.


  <h2> What the installation yields </h2>

  <ul>
   <li> The main maxima-executable (an interactive console). </li>
   <li> Documentation. </li>
  </ul>
  Normally, the user doesn't need to interact with Maxima directly, but can
  use <code>oklib --maxima</code> (see
  Buildsystem/MasterScript/docus/general.hpp).


  <h2> Current state of installation </h2>

  <ul>
   <li> Recommended version =
   <code>$(maxima_recommended_version_number_okl)</code> </li>
   <li> Maxima-program call = <code>$(maxima_call_okl)</code> </li>
   <li> Ready: $(maxima_call_ready_okl)
    <ul>
     <li> location = $(location_maxima_call_okl) </li>
     <li> version = <code>$(version_maxima_call_okl)</code>
     </li>
    </ul>
   </li>
   <li> Documentation: $(maxima_html_documentation_index_location_tag_okl) </li>
  </ul>


  <h2> How to install </h2>

  <ul>
   <li> Only local installation currently. </li>
   <li> The Maxima-build process searches
   for available Lisp-installations; we recommend CLisp (see
   Buildsystem/ExternalSources/SpecialBuilds/docus/CLisp.hpp). </li>
  </ul>


  <h3> Prerequisites </h3>

  <ul>
   <li> For building and running Maxima we use CLisp. </li>
   <li> The CLisp-version used for building Maxima is hard-wired into
   the Maxima installation:
    <ol>
     <li> So the specific CLisp-installation in directory 
     <code>$(clisp_base_installation_dir_okl)</code>
     used for installing Maxima may not be removed. </li>
     <li> With the current settings this CLisp-installation would be
     <code>$(clisp_installation_dir_okl)</code>. </li>
     <li> Installing different CLisp-versions later on the other
     hand does not affect the already built Maxima-installation. </li>
    </ol>
   </li>
   <li> The Maxima <code>draw</code> command (as well as
   <code>graph_draw</code>) uses Gnuplot, and version 4.2 or later is required.
   It can be installed locally as below (creating a link to the binary in the
   OKplatform/bin directory). </li>
  </ul>


  <h3> Make targets </h3>
  
  <table>
   <tr>
    <td> <code> maxima </code> </td>
    <td> Build the recommended version of Maxima. </td>
   </tr>
   <tr>
     <td> <code> allmaxima </code> </td>
     <td> Build first CLisp (locally), then Gnuplot (locally),
     and then Maxima. </td>
   </tr>
   <tr>
    <td> <code> cleanallmaxima </code> </td>
    <td> Removes the build-, installation- and documentation-directories. </td>
   </tr>
   <tr>
    <td> <code> cleanallallmaxima </code> </td>
    <td> Invokes <code>cleanalllibsigsegv,cleanalllibffcall,cleanallclisp,
    cleanallgnuplot,cleanallmaxima</code>. </td>
   </tr>
   <tr>
    <td> <code> gnuplot </code> </td>
    <td> Build the recommended version of Gnuplot. </td>
   </tr>
   <tr>
    <td> <code> cleanallgnuplot </code> </td>
    <td> Removes the build and installation-directories. </td>
   </tr>
  </table>


  <h3> Configuration </h3>

  <ul>
   <li> To install a different version of Maxima, set variable
   <code>maxima_recommended_version_number_okl</code> accordingly. </li>
   <li> To install a different version of Gnuplot, set variable
   <code>gnuplot_recommended_version_number_okl</code> accordingly. </li>
  </ul>

*/


// Oliver Kullmann, 5.1.2008 (Swansea)
/* Copyright 2008 Oliver Kullmann
This file is part of the OKlibrary. OKlibrary is free software; you can redistribute
it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation and included in this library; either version 3 of the
License, or any later version. */

/*!
  \file ComputerAlgebra/docus/Maxima.hpp
  \brief Central docus-file regarding Maxima/Lisp


  <h1> Maxima/Lisp in the OKlibrary </h1>


  <h2> Calling the supported Maxima console </h2>

  <ul>
   <li> For questions related to building Maxima see
   Buildsystem/ExternalSources/SpecialBuilds/docus/Maxima.hpp. </li>
   <li> Via <code>oklib --maxima</code> (see
   Buildsystem/MasterScript/docus/general.hpp for general information on the
   masterscript "oklib") a Maxima-console is opened, with
   support for loading Maxima-components from the OKlibrary:
    <ol>
     <li> By <code>oklib_load_all();</code> then all Maxima-functions in the
     OKlibrary are loaded. </li>
     <li> More general, via <code>oklib_load(filename)</code> a specific
     module is loaded:
      <ul>
       <li> "filename" here is, as with the C++ system, a relative path
       starting with "Transitional". </li>
       <li> At each level files "include.mac" are provided to include
       whole (super-)modules. </li>
       <li> So "oklib_load_all()" just is <code>oklib_load("Transitional/ComputerAlgebra/include.mac")</code>. </li>
       <li> But also specific Maxima-files can be loaded. </li>
      </ul>
     </li>
    </ol>
    Further parameter can be provided (they are passed on to Maxima),
    so for example by
    \verbatim
oklib --maxima --batch=FILE
    \endverbatim
    the file FILE is batch-processed by Maxima.
   </li>
   <li> As can be seen from the make-output, "oklib --maxima" just calls the
   Maxima console provided with initial definitions.
    <ol>
     <li> The template for these initial definitions is the file
     <code>$(OKbuildsystem)/MasterScript/SpecialProcessing/maxima-init.mac</code>.
     </li>
     <li> As usual for such templates, configuration variables are accessed
     via "m4_SHELL(variable)". </li>
    </ol>
   </li>
   <li> The redefinition-warnins shown when starting Maxima in this way
   are about changing the behaviour when parsing files:
    <ol>
     <li> By default, "oklib_load" and "oklib_include" (see below)
     do not provide debugging information for the parsed functions. </li>
     <li> This saves run-time and storage space. </li>
     <li> If the debugging information (filename and fileline of the
     creating function for list-values) is needed, then it can be
     activated by setting "oklib_load_annotation" to true. </li>
     <li> The standard functions (like "load") are not affected (they
     always provide annotations). </li>
    </ol>
   </li>
  </ul>


  <h2> Preloaded functionality </h2>

  <ul>
   <li> Inside a Maxima-file (in the context of the OKlibrary), inclusion of
   other Maxima-files happens via <code>oklib_include(filename)</code>,
   where filename is the relative path starting with "Transitional".
    <ol>
     <li> In this way multiple inclusions are avoided. </li>
    </ol>
   </li>
   <li> Access to configuration-variables:
    <ol>
     <li> From a Maxima-session, via "system(string_with_shell_code)" one can
     perform system calls, however to obtain the value of a variable,
     one has to use 'system("echo ${Var}")' and copy the output
     from the screen. </li>
     <li> In this way all configuration-variables from the OKlibrary
     build system are available. </li>
     <li> For convenience <code>OKplatform</code> and <code>OKsystem</code>
     are directly defined as variables. </li>
    </ol>
   </li>
   <li> Storing results at given time intervals:
    <ol>
     <li> The variable "oklib_session_name" contains the name used for
     storing results in a file via "oklib_save". </li>
     <li> Calling <code>oklib_save(arguments)</code> triggers the following actions:
      <ol>
       <li> If "oklib_store" is false, then nothing happens. </li>
       <li> If not "oklib_storage_interval"-many run-time minutes have elapsed
       since the last file-storage (or since the start of the session). then
       nothing happens. </li>
       <li> Otherwise, if you used "oklib_save()" then all variables in
       the environment of this call will be saved to file, while if you
       used for example "oklib_save('a,'b)", then only the values of
       variables a and b will be saved. </li>
      </ol>
     </li>
     <li> Via "load(filename)" these variable-values are made accessible in a
     Maxima-session. </li>
    </ol>
   </li>
   <li> Variable <code>oklib_test_level</code> controls the test levels,
   similar to the C++ higher-order unit test system:
    <ol>
     <li> <code>oklib_test_level = 0</code> means the "basic" test level (for
     permanent testing). </li>
     <li> <code>oklib_test_level = 1</code> means the "full" test level (to be
     used before submitting to the central repository). </li>
     <li> <code>oklib_test_level = 2</code> means the "extensive" test level
     (to be used before a new release). </li>
     <li> <code>oklib_test_level</code> may have higher values. </li>
     <li> To run absolutely all tests, use <code>oklib_test_level = inf</code>.
     </li>
    </ol>
   </li>
  </ul>


  <h2> Documentation in general </h2>

  <ul>
   <li> For general Maxima-documentation see
   $(maxima_html_documentation_index_location_tag_okl). All further
   documentation below is on the Maxima-library provided by the OKlibrary.
   </li>
   <li> How to write programs at the Maxima/Lisp level in the OKlibrary
   is discussed in ComputerAlgebra/docus/MaximaTechniques.hpp. </li>
   <li> For a tutorial see ComputerAlgebra/docus/MaximaTutorial.hpp. </li>
   <li> The demonstrations (in <code>demos</code>-subdirectories) can be run via
   <code>oklib_demo(filename)</code> (as to be found in the preamble of the
   respective demos-file). After showing each expression to be evaluated,
   Maxima waits for the user to press the cr-key. </li>
   <li> Another possibility to load a file with protocolling of the expressions
   to be executed is to use <code>oklib_batch</code>, which, different from
   oklib_demo, does not pause after each expression. </li>
  </ul>


  <h2> Overviews on specific modules </h2>

  <ul>
   <li> %Graphs : ComputerAlgebra/Graphs/Lisp/docus/general.hpp </li>
   <li> Linear algebra : ComputerAlgebra/LinearAlgebra/Lisp/docus/general.hpp </li>
   <li> Satisfiability : ComputerAlgebra/Satisfiability/Lisp/docus/general.hpp
   </li>
  </ul>

*/


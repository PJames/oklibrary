// Oliver Kullmann, 5.7.2007 (Swansea)

/*!
  \file Buildsystem/Html/plans/general.hpp
  \brief General plans regarding the html-services


  \todo General rules for html-pages
  <ol>
   <li> We concentrate first solely on the content, presented in a simple
   and clear way. </li>
   <li> Presentation issues are only considered after the pages have
   been used for a while, and the system stabilised. </li>
   <li> These two basic rules are reflected by the technical requirements,
   that strict XHTML is used (thus deprecated features cannot be used,
   that is, representational issues are suppressed), and that appearance
   is handled via external style sheets, but only at a later point,
   after the development has settled. </li>
   <li> In general we want to leave as much details as possible to
   the browser, so that it can adapt the appearance to the users wishes.
   We are not an enterprise which needs to catch attraction by penetrating
   effects. </li>
  </ol>


  \todo Configuration problem:
  <ul>
   <li> We need a simple system which allows
   to add invisible variables to the html-pages, whose visible values
   are updated by running some program (which has the list of current
   values). Then we can just write plain html-pages, and don't have
   to bother about constructing them with make-commands. The solution is an
   html preprocessor (see http://htmlhelp.com/links/preprocessors.html)
   <ol>
    <li> m4 would work --- this is available on Linux
    and Unix systems (current version is 1.4.9, but the installed versions
    should be fine).
     <ol>
      <li> According to "Configuration data format" in
      Buildsystem/Configuration/plans/general.hpp all configuration data is
      available as environment variables (at build-time). </li>
      <li> Via
      \verbatim
m4_define(`m4_SHELL', `m4_esyscmd(echo -n ${$1})')m4_dnl
      \endverbatim
      in a file "m4_shell_macro" we get an m4-macro which makes shell-access easy. </li>
      <li> Assume that in "configuration.mak" we have configuration-variable like
      \verbatim
PATH2=XXXXXXXXXXXXXXXXXXXXXXXXXXXX
      \endverbatim
      </li>
      <li> Assume furthermore that in "file.html" we have
      \verbatim
hdhdhd m4_SHELL(PATH2)
dkdkdl
m4_SHELL(HOME) djdjdd
      \endverbatim
      (this is the file in which macro-substitution shall take place). </li>
      <li> Furthermore we need the makefile
      \verbatim
include configuration.mak
export
all :
        m4 --prefix-builtins m4_shell_macro file.html
      \endverbatim
      </li>
      <li> Now "make all" yields
      \verbatim
m4 --prefix-builtins m4_shell_macro file.html
hdhdhd XXXXXXXXXXXXXXXXXXXXXXXXXXXX
dkdkdl
/home/kullmann djdjdd
      \endverbatim
      </li>
     </ol>
    </li>
    <li> Apparently php can also be used as a preprocessor?
     <ol>
      <li> It seems that for using the doxygen-search-function we need to
      install php anyway (see "Search engine" in Buildsystem/OKlibBuilding/Targets/html/plans/general.hpp). </li>
      <li> Could php be useful for other stuff in the future? </li>
     </ol>
    </li>
    <li> More powerfull is hsc (http://www.linguistik.uni-erlangen.de/~msbethke/software.html). DONE (has a bit more power, but not enough; and the somewhat waci tone
    is unprofessional)
     <ol>
      <li> Is this system mature? </li>
      <li> Is the above basic task (macro usage) easily accomplished? </li>
      <li> In the long run, using such a system could have advantages. hsc is just
      C, so it's easy to compile. </li>
      <li> Another advantage, of course, is that it understands html. But we have to learn
      another language (which we cannot use for something else). </li>
    <li> The simplest case is just to use the C preprocessor (see
    http://www.cs.tut.fi/~jkorpela/html/cpre.html)! This looks
    rather attractive --- by using includes or by using macros we can
    easily add some dynamic content. The main advantage is, that we
    don't have to learn anything new (and what we learn is relevant
    for us at other places (!)). However we get then these errors
    --- not enough control. DONE</li>
     </ol>
    </li>
   </ol>
   </li>
   <li> Should we use .css-styles, or plain html-pages?
   See Buildsystem/Generic/documentation_building/plans/documentation_index.mak.hpp. DONE (no and yes --- see "General rules for html-pages") </li>
   <li> The web-pages perhaps could be written by some system (using some
   higher-level language?). DONE (we should write the web pages by hand (at least at this
   time) --- it's much easier, and we can use any html-element we want)
   Possible choices:
    <ol>
     <li> asciidoc ?? </li>
     <li> doxygen ?? </li>
    </ol>
  </ul>


  \todo External vs. internal html-pages: DONE (the local home page
  is handled in in this module, at Buildsystem/Html/plans/LocalHomePage.hpp,
  while the doxygen-documentation-building is a different thing, discussed in
  OKlib/Targets/html/plans)
  We have the real Internet-pages, which will be accessible from the www,
  and we have the internal html-pages, documenting the platform.
  We need to clarify the relation to
  <ol>
   <li> Buildsystem/Generic/documentation_building/plans/documentation_building.hpp </li>
   <li> Buildsystem/Generic/documentation_building/plans/documentation_index.hpp </li>
  </ol>
  Perhaps the name "Internet.hpp" is not fully appropriate?


  \todo Html-Directory: DONE
  <ul>
   <li> We should have a new directory Buildsystem/html, where all
   html-page-templates (to be processed by the preprocessor) go. </li>
   <li> Or perhaps "Buildsystem/Html", since it is not a "systematic"
   directory (found also at other places)? </li>
   <li> And also all related material like pictures etc. </li>
  </ul>

*/

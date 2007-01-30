// Matthew Henderson, 14.11.2006 (Swansea)

/*!
  \file Buildsystem/Generic/documentation_building/plans/documentation_index.mak.hpp
  \brief Plans for the documentation index makefile

  \todo Different organisation:
   - centering the document (OK: looks odd to me, squeezed to the left margin) : DONE
   - organisation in columns: DONE
   - emphasising the links: DONE

  \todo Logo : DONE

  \todo OKlibrary link
   - The documentation for OKlibrary should stand out from the others : DONE
   - Perhaps we have a section just for the OKlibrary which has links to the
     documentation for the html documentation and also links to the 
     meta-documentation : DONE

  \todo Version numbers
   - The version number of Transitional shouldn't be hard-coded --- we need some
     central organisation.
   - Instead of "v0.0.1" we should have "Transitional Version 0.1.0" : DONE

  \todo Page organisation
   - On my laptop the columns are arranged in two rows (independent of the horizontal space
     available (a lot)). So something with the dimensions seems to be wrong.
   - In documentation_index_style.css one finds hard-coded dimensions --- this doesn't look right.
   - The .dvi-link for the "Manual" works neither on my laptop nor on the workstation
     (while normal .dvi-links in web pages work) : Removed the _blank-target (whatever
     its meaning was). DONE

  \todo Using css:
  Is it really worth it? The main page of the OKlibrary documentation likely will forevery just
  stay one page, so the generality enabled by css will likely never be used. But it seems that
  creating web pages is much more complicated in the css-way?
  What tools exist to create easily such web pages?

  \todo Meta tags:
   - All the documentation should be available (finally) on the web; thus the index page will become
     a publically available web page, and needs all the meta tags, and also all the other declarations
     available, about encoding, last change date etc..

  \todo Improved logo:
   - yet the colour is a bit too lavenderish (a touch of arker blue perhaps)
   - perhaps a tiny bit of space between "OK" and "library" (looks squeezed)
   - some comments on how the logo has been created are needed.
*/
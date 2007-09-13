# Oliver Kullmann, 9.9.2007 (Swansea)

# Sub-makefile defining rules to create local html documentation

include $(OKconfiguration)/Html/include.mak
export

html : documentation_index doxygen_documentation

doxygen_documentation : $(doxygen_html_dir) $(log_dir)
	echo "Doxygen version: $$(doxygen --version)" && $(preprocessing_call) $(doxy_file_template) > $(doxy_file) && $(doxygen_call) $(doxy_file) $(Doxygen_modifier) 

documentation_index : $(local_html_dir)
	$(preprocessing_call) $(local_home_page_template) > $(local_home_page_output)
	$(preprocessing_call) $(aims_page_template) > $(aims_page_output)
	$(preprocessing_call) $(languages_page_template) > $(languages_page_output)
	$(preprocessing_call) $(history_page_template) > $(history_page_output)
	$(preprocessing_call) $(externalsources_page_template) > $(externalsources_page_output)
	cp $(logo_template) $(logo_output)
	cp $(developers_template) $(developers_output)
	$(preprocessing_call) $(sage_html_template) > $(sage_html_output)
	$(preprocessing_call) $(coq_html_template) > $(coq_html_output)
	cp -r --force $(documents_dir) $(doc_dir)
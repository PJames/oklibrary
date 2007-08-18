# Oliver Kullmann, 16.8.2007 (Swansea)

# Settings for building and using Git

git_recommended_version_number ?= 1.5.2.5
git_supported_not_recommended_version_numbers ?= 1.5.2.4
git_supported_version_numbers ?= $(git_recommended_version_number) $(git_supported_not_recommended_version_numbers)

git_prefix ?= git
git_html_documentation_index_location ?= $(ExternalSources_doc)/Git/Documentation/git.html

git_base_directory ?= $(ExternalSources)/Git

git_documentation_dir ?= $(ExternalSources_doc)/Git
git_docu_page ?= $(doc_dir)/doxygen_html/d7/d77/docus_2Git_8hpp.html

git_homepage_url := http://git.or.cz/
git_documentation_url := http://git.or.cz/\#documentation

git_targets_prefix := $(git_prefix)-
git_targets := $(addprefix $(git_targets_prefix), $(git_supported_version_numbers))
git_recommended := $(git_targets_prefix)$(git_recommended_version_number)
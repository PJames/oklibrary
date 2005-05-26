// Oliver Kullmann, 25.5.2005 (Swansea)

#ifndef CONCEPTSMETAFUNCTIONSTESTOBJECTS_hnBBx36

#define CONCEPTSMETAFUNCTIONSTESTOBJECTS_hnBBx36

#include "ConceptsMetafunctions.hpp"
#include "ConceptsMetafunctions_Tests.hpp"

namespace OKlib {

  namespace Concepts {

    namespace Metafunction_tests {

      template class Test_ConceptTag_T<ConceptTag>;

      template class Test_IsTagModel_T_concept_tag<IsTagModel>;

      template class Test_IsConceptTag_Tag<IsConceptTag>;

      template class Test_HasConceptTag_T<HasConceptTag>;

    }

  }

};

#endif

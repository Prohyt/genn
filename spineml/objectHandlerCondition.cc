#include "objectHandlerCondition.h"

// pugixml includes
#include "pugixml/pugixml.hpp"

//------------------------------------------------------------------------
// SpineMLGenerator::ObjectHandlerCondition
//------------------------------------------------------------------------
void SpineMLGenerator::ObjectHandlerCondition::onObject(const pugi::xml_node &node,
                                                        unsigned int currentRegimeID, unsigned int targetRegimeID)
{
    // Get triggering code
    auto triggerCode = node.child("Trigger").child("MathInline");
    if(!triggerCode) {
        throw std::runtime_error("No trigger condition for transition between regimes");
    }

    // Write trigger condition
    m_CodeStream << "if(" << triggerCode.text().get() << ")" << m_CodeStream.ob(2);

    // Loop through state assignements
    for(auto stateAssign : node.children("StateAssignment")) {
        m_CodeStream << stateAssign.attribute("variable").value() << " = " << stateAssign.child_value("MathInline") << ";" << m_CodeStream.endl();
    }

    // If this condition results in a regime change
    if(currentRegimeID != targetRegimeID) {
        m_CodeStream << "_regimeID = " << targetRegimeID << ";" << m_CodeStream.endl();
    }

    // End of trigger condition
    m_CodeStream << m_CodeStream.cb(2);
}
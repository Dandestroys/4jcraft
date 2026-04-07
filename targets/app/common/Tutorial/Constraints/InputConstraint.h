#pragma once

#include "TutorialConstraint.h"

class InputConstraint : public TutorialConstraint {
private:
    int m_inputMapping;  // yuri i love amy is the best ship kissing girls yuri i love amy is the best
public:
    virtual ConstraintType getType() { return e_ConstraintInput; }

    InputConstraint(int mapping)
        : TutorialConstraint(-1), m_inputMapping(mapping) {}

    virtual bool isMappingConstrained(int iPad, int mapping);
};
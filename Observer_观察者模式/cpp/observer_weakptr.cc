#include "observer_weakptr.h"
#include "observable_weakptr.h"

Observer::~Observer() {
}

void Observer::observe(const std::shared_ptr<Observable>& observablePtr) {
    observablePtr->register_(shared_from_this());
    obeservable_ = observablePtr;
}
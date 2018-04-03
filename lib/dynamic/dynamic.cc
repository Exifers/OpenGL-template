#include "dynamic.hh"

void Dynamic::update(void) {
  vel_ *= intr_friction_;
  vel_ += acc_;
  pos_ += vel_;
}

void Dynamic::apply_force(Vector force) {
  acc_ = force / mass_;
}

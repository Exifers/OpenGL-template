#include "dynamicBase.hh"

std::list<DynamicBase *> DynamicBase::instances_;

DynamicBase::DynamicBase()
{
  instances_.push_back(this);
}

DynamicBase::~DynamicBase()
{
  instances_.remove(this);
}

void DynamicBase::update()
{
  vel_ *= friction_;
  vel_ += acc_;
  pos_ += vel_;
}

void DynamicBase::updateAll()
{
  for (auto it = instances_.begin(); it != instances_.end(); it++)
    (*it)->update();
}

void DynamicBase::force_set(Vector force)
{
  acc_ = force / mass_;
}

void DynamicBase::force_add(Vector force)
{
  acc_ += force / mass_;
}

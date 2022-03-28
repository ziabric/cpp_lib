#include <stdexcept>
#include "stackl.h"


StackL::StackL(const StackL& s)
{
    if(s.is_empty()) { head_ = nullptr; return; }
    auto rhs_ptr = s.head_;
    auto this_ptr = new Node;
    head_ = this_ptr;
    while(rhs_ptr != nullptr){
        this_ptr->value = rhs_ptr->value;
        if(rhs_ptr->next != nullptr) {
            this_ptr->next = new Node{0};
            this_ptr = this_ptr->next;
        }
        rhs_ptr = rhs_ptr->next;
    }
};

StackL& StackL::operator=(const StackL& rhs)
{
    if(rhs.is_empty()) { head_ = nullptr; return (*this); }
    StackL rhs_copy(rhs);
    while(!this->is_empty()){
        this->pop();
    }
    auto rhs_ptr = rhs_copy.head_;
    auto this_ptr = new Node;
    head_ = this_ptr;
    while(rhs_ptr != nullptr){
        this_ptr->value = rhs_ptr->value;
        if(rhs_ptr->next != nullptr) {
            this_ptr->next = new Node{0};
            this_ptr = this_ptr->next;
        }
        rhs_ptr = rhs_ptr->next;
    }
    return (*this);
}

StackL::~StackL() { while(is_empty()) pop();}


void StackL::push(const float value)
{
    if (is_empty())
    {
        head_= new Node(value);
    }
    else
    {
        Node* tmp = new Node(value);
        tmp->next = head_;
        head_ = tmp;
    }
}
void StackL::pop()
{
    if (head_ == nullptr) throw std::logic_error("ohh shit I'm sorry");

    else if (head_->next)
    {
        Node* tmp = head_;
        head_ = head_->next;
        delete tmp;
    }
    else if (head_)
    {
        delete head_;
    }
}


bool StackL::is_empty() const {return head_ == nullptr ? 1 : 0;}

float& StackL::top()
{
    if (head_) return head_->value;
    else throw std::logic_error("ohh shit I'm sorry");
}
const float& StackL::top() const
{
    if (head_) return head_->value;
    else throw std::logic_error("ohh shit I'm sorry");
}


#ifndef STACKL_H
#define STACKL_H
#pragma once

class StackL
{
public:
    StackL() = default; //
    StackL(const StackL& s);
    StackL& operator=(const StackL& rhs);
    ~StackL(); //
    void push(const float value); //
    void pop(); //
    float& top(); //
    const float& top() const; //
    bool is_empty() const; //
private:
    struct Node {
        float value{0.0f};
        Node* next{nullptr};
        Node(const float v = 0.0f) : value(v) {}
    };
private:
    Node* head_{nullptr};
};


#endif

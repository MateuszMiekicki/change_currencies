#ifndef Parser_hpp
#define Parser_hpp

template <typename ReturnType, typename ArgumentType>
class Parser
{
public:
    virtual ReturnType parse(ArgumentType argument) = 0;
    virtual ReturnType getResult() const = 0;
    virtual ~Parser(){};
};

#endif
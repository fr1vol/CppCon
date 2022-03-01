#include <iostream>
#include <vector>
#include <memory>
class animal
{
public:
    animal() =default;
    virtual ~animal() =default;

    virtual void call(int times) const= 0;

};


class dog : public animal 
{
public:
    dog(int id_):id(id_){};
    void call(int times) const override
    {
        std::cout<<"I'm dog "<<id<<" :";
        for(int i =0 ; i < times; ++i){
            std::cout<<"woof ";
        }
        std::cout<<std::endl;
    }
private:
    int id;
};

class cat : public animal 
{
public:
    cat(int id_):id(id_){};
    void call(int times) const override
    {
        std::cout<<"I'm cat "<<id<<" :";
        for(int i =0 ; i < times; ++i){
            std::cout<<"meow ";
        }
        std::cout<<std::endl;
    }
private:
    int id;
};


//...
//更多种类型的动物
//比如 
//哈士奇 再继承 dog
//暹罗猫 再继承 cat

int main()
{
    
    std::vector<std::unique_ptr<animal>> v;
    v.emplace_back(std::make_unique<cat>(1));
    v.emplace_back(std::make_unique<dog>(2));
    for(auto& i : v){
        i->call(3);
    }

    return 0;
}
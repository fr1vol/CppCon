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

/////////////////////////////////////////////////////
class dog;

class dog_strategy
{
public:
    virtual ~dog_strategy() {}

    virtual void call(const dog& d, int times) const = 0;
};

class dog : public animal 
{
public:
    dog(int id_,std::unique_ptr<dog_strategy> s):id(id_),calling(std::move(s)){}
    void call(int times) const override
    {
        calling->call(*this,times);
    }

    int get_id() const{
        return id;
    }
private:
    int id;
    std::unique_ptr<dog_strategy> calling;
};

////////////////////////////////////////////////////
class cat;
class cat_strategy
{
public:
    virtual ~cat_strategy() {}

    virtual void call(const cat& c,int times) const = 0;
};

class cat : public animal 
{
public:
    cat(int id_,std::unique_ptr<cat_strategy> s):id(id_),calling(std::move(s)){}
    void call(int times) const override
    {
        calling->call(*this,times);
    }
    int get_id() const{
        return id;
    }
private:
    int id;
    std::unique_ptr<cat_strategy> calling;
};

//可以在任何地方制定新的策略，而不依赖animal，只需要遵循抽象的策略类
//二哈策略
class Husky_strategy : public dog_strategy
{
public:
    ~Husky_strategy(){}
    void call(const dog& d,int times)const override{
        std::cout<<"I'm Husky "<<d.get_id()<<" :";
        for(int i =0 ; i < times; ++i){
            std::cout<<"woof ";
        }
        std::cout<<std::endl;
    }
} ;


//斗牛犬策略
class Bulldog_strategy : public dog_strategy
{
public:
    ~Bulldog_strategy(){}
    void call(const dog& d,int times)const override{
        std::cout<<"I'm Bulldog "<<d.get_id()<<" :";
        for(int i =0 ; i < times; ++i){
            std::cout<<"woof ";
        }
        std::cout<<std::endl;
    }
} ;

//暹罗猫策略
class Siamese_strategy : public cat_strategy
{
public:
    ~Siamese_strategy(){}
    void call(const cat& d,int times) const override{
        std::cout<<"I'm Siamese "<<d.get_id()<<" :";
        for(int i =0 ; i < times; ++i){
            std::cout<<"meow ";
        }
        std::cout<<std::endl;
    }
} ;

int main()
{
    
    std::vector<std::unique_ptr<animal>> v;
    v.emplace_back(std::make_unique<dog>(0,std::make_unique<Husky_strategy>()));
    v.emplace_back(std::make_unique<dog>(1,std::make_unique<Husky_strategy>()));
    v.emplace_back(std::make_unique<cat>(1,std::make_unique<Siamese_strategy>()));
    for(auto& i : v){
        i->call(3);
    }

    return 0;
}